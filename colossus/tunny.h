
#include <stdexcept>
#include <string>
#include <vector>

#include <colossus/teleprinter.h>
#include <colossus/elemental.h>

/**
 * Class implementing the Tunny / Lorenz LZ40/LZ42 cipher system.
 */
class tunny : public cipher_stream {
public:

    static const int num_x1_pins = 41;      // Pins on the 1st chi wheel.
    static const int num_x2_pins = 31;	    // Pins on the 2nd chi wheel.
    static const int num_x3_pins = 29;	    // Pins on the 3rd chi wheel.
    static const int num_x4_pins = 26;	    // Pins on the 4th chi wheel.
    static const int num_x5_pins = 23;	    // Pins on the 5th chi wheel.

    static const int num_m1_pins = 61;	    // Pins on the 1st mu wheel.
    static const int num_m2_pins = 37;	    // Pins on the 2nd mu wheel.

    static const int num_s1_pins = 43;	    // Pins on the 1st psi wheel.
    static const int num_s2_pins = 47;	    // Pins on the 2nd psi wheel.
    static const int num_s3_pins = 51;	    // Pins on the 3rd psi wheel.
    static const int num_s4_pins = 53;	    // Pins on the 4th psi wheel.
    static const int num_s5_pins = 59;	    // Pins on the 5th psi wheel.

    // Constructor.
    tunny() { 
	prev_chi = 0; cur_chi = 0;
	cur_psi = 0; prev_psi = 0;
	prev2_plain = 0; prev_plain = 0;
	limitation = nolim;
    }

    // Destructor.
    virtual ~tunny() {}

    // Limitation - describes the cipher feedback into the total motor (TM)
    // stream from basic motor (BM) and other wheels.  Values are:
    // nolim: No limitation in use.  TM = BM.
    // x2lim: Feedback from second chi wheel, one step back.
    // x2s1lim: Feedback from first psi wheel, one step back.
    // x2p5lim: Feedback from 2nd chi wheel and 5th plaintext impulse.
    // x2s1p5lim: Feedback from 2nd chi, 1st psi and 5th plaintext impulse.
    typedef enum { nolim, x2lim, x2s1lim, x2p5lim, x2s1p5lim } limitation_type;

private:

    // Chi wheel pin settings.
    std::vector<bool> x1, x2, x3, x4, x5;    

    // Chi wheel positions - iterators into the chi wheel vectors.
    std::vector<bool>::iterator xp1, xp2, xp3, xp4, xp5;

    // Psi wheel pin settings.
    std::vector<bool> s1, s2, s3, s4, s5;    

    // Psi wheel positions - iterators into the psi wheel vectors.
    std::vector<bool>::iterator sp1, sp2, sp3, sp4, sp5;

    // Mu wheel pin settings.
    std::vector<bool> m1, m2;

    // Mu wheel positions - iterators into the mu wheel vectors.
    std::vector<bool>::iterator mp1, mp2;

    // Cipher 'limitation'
    limitation_type limitation;

    // Convert a pin description string into a vector of pins.  Pin description
    // string consists of a string containing ex (x) and dit (.) characters.
    static void text2pins(const std::string& text, std::vector<bool>& pins, 
			  int num);

    // Encrypt mode.
    bool encrypt;

public:

    void set_encrypt_mode(bool e) { encrypt = e; }
    void set_encrypt() { encrypt = true; }
    void set_decrypt() { encrypt = false; }

    // Set the limitation in use.
    void set_limitation(limitation_type t) { limitation = t; }

    // Get the chi wheel positions.
    void get_chi_positions(std::vector<unsigned int>& pos) {
	pos.clear();
	pos.push_back(xp1 - x1.begin());
	pos.push_back(xp2 - x2.begin());
	pos.push_back(xp3 - x3.begin());
	pos.push_back(xp4 - x4.begin());
	pos.push_back(xp5 - x5.begin());
    }

    // Get the psi wheel positions.
    void get_psi_positions(std::vector<unsigned int>& pos) {
	pos.clear();
	pos.push_back(sp1 - s1.begin());
	pos.push_back(sp2 - s2.begin());
	pos.push_back(sp3 - s3.begin());
	pos.push_back(sp4 - s4.begin());
	pos.push_back(sp5 - s5.begin());
    }

    // Get the mu wheel positions.
    void get_mu_positions(std::vector<unsigned int>& pos) {
	pos.clear();
	pos.push_back(mp1 - m1.begin());
	pos.push_back(mp2 - m2.begin());
    }

    tpchar_t prev_chi;			    // Previous chi value.
    tpchar_t cur_chi;			    // Current chi value.

    tpchar_t prev_psi;			    // Previous psi vlaue.
    tpchar_t cur_psi;			    // Current psi value.

    tpchar_t cur_mu;			    // Current mu value.

    tpchar_t prev2_plain;		    // Previous^2 plain.
    tpchar_t prev_plain;		    // Previous plain.

    bool cur_bm;			    // Current basic motor.
    bool cur_tm;			    // Current total motor.

    // Step the cipher, moving wheels and updating cipher key values.
    // letter=current input letter.
    virtual void step(tpchar_t input, tpchar_t output);

    tpchar_t get_chi() { return cur_chi; }  // Get chi value.
    tpchar_t get_psi() { return cur_psi; }  // Get psi value.
    tpchar_t get_mu() { return cur_mu; }    // Get mu value.
    bool get_tm() { return cur_tm; }	    // Get total motor.
    bool get_bm() { return cur_bm; }	    // Get basic motor.

    // Set chi pins.  w1-w5 are pins settings consisting of strings containing
    // ex (x) and dit (.) characters.
    void set_chi_pins(const std::string& w1, const std::string& w2, 
		      const std::string& w3, const std::string& w4,
		      const std::string& w5) {
	text2pins(w1, x1, num_x1_pins);
	text2pins(w2, x2, num_x2_pins);
	text2pins(w3, x3, num_x3_pins);
	text2pins(w4, x4, num_x4_pins);
	text2pins(w5, x5, num_x5_pins);
	xp1 = x1.begin();
	xp2 = x2.begin();
	xp3 = x3.begin();
	xp4 = x4.begin();
	xp5 = x5.begin();
    }

    // Set psi pins.  w1-w5 are pins settings consisting of strings containing
    // ex (x) and dit (.) characters.
    void set_psi_pins(const std::string& w1, const std::string& w2, 
		      const std::string& w3, const std::string& w4,
		      const std::string& w5) {
	text2pins(w1, s1, num_s1_pins);
	text2pins(w2, s2, num_s2_pins);
	text2pins(w3, s3, num_s3_pins);
	text2pins(w4, s4, num_s4_pins);
	text2pins(w5, s5, num_s5_pins);
	sp1 = s1.begin();
	sp2 = s2.begin();
	sp3 = s3.begin();
	sp4 = s4.begin();
	sp5 = s5.begin();
    }

    // Set mu pins.  w1-w2 are pins settings consisting of strings containing
    // ex (x) and dit (.) characters.
    virtual void set_mu_pins(const std::string& w1, const std::string& w2) {
	text2pins(w1, m1, num_m1_pins);
	text2pins(w2, m2, num_m2_pins);
	mp1 = m1.begin();
	mp2 = m2.begin();
    }

    // Set chi positions, integer counts from start of wheel.
    // count_from_one=true means counts start from 1, not 0.
    void set_chi_positions(unsigned int w1, unsigned int w2, 
			   unsigned int w3, unsigned int w4,
			   unsigned int w5, bool count_from_one=true);

    // Set chi positions, integer counts from start of wheel.
    // count_from_one=true means counts start from 1, not 0.
    void set_chi_positions(const std::vector<unsigned int>& s,
			   bool count_from_one=true) {
	if (s.size() != 5) throw std::out_of_range("Vector should be size 5");
	set_chi_positions(s[0], s[1], s[2], s[3], s[4], count_from_one);
    }

    // Set psi positions, integer counts from start of wheel.
    // count_from_one=true means counts start from 1, not 0.
    void set_psi_positions(unsigned int w1, unsigned int w2, 
			   unsigned int w3, unsigned int w4,
			   unsigned int w5, bool count_from_one=true);

    // Set psi positions, integer counts from start of wheel.
    // count_from_one=true means counts start from 1, not 0.
    void set_psi_positions(const std::vector<unsigned int>& s,
			   bool count_from_one=true) {
	if (s.size() != 5) throw std::out_of_range("Vector should be size 5");
	set_psi_positions(s[0], s[1], s[2], s[3], s[4], count_from_one);
    }

    // Set mu positions, integer counts from start of wheel.
    // count_from_one=true means counts start from 1, not 0.
    void set_mu_positions(unsigned int w1, unsigned int w2,
			  bool count_from_one=true);

    // Set mu positions, integer counts from start of wheel.
    // count_from_one=true means counts start from 1, not 0.
    void set_mu_positions(const std::vector<unsigned int>& s,
			  bool count_from_one=true) {
	if (s.size() != 2) throw std::out_of_range("Vector should be size 2");
	set_mu_positions(s[0], s[1], count_from_one);
    }

    void decrypt(const std::vector<tpchar_t>& in,
		 std::vector<tpchar_t>& out) {

	tpchar_t prev_in = 0;
	tpchar_t prev_out = 0;

	for(std::vector<tpchar_t>::const_iterator it = in.begin();
	    it != in.end();
	    it++) {

	    step(prev_in, prev_out);

	    tpchar_t c = *it;

	    prev_in = *it;
	    
	    c ^= get_chi();
	    c ^= get_psi();

	    out.push_back(c);

	    prev_out = c;

	}

    }

    tpchar_t process(tpchar_t in) {

	tpchar_t out = in;
	out ^= get_chi();
	out ^= get_psi();

	step(in, out);

	return out;

    }

};
