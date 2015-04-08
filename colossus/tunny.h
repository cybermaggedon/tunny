
#include <stdexcept>
#include <string>
#include <vector>

#include <colossus/teleprinter.h>
#include <colossus/elemental.h>

class tunny : public cipher_stream {
public:

    static const int num_x1_pins = 41;
    static const int num_x2_pins = 31;
    static const int num_x3_pins = 29;
    static const int num_x4_pins = 26;
    static const int num_x5_pins = 23;

    static const int num_m1_pins = 61;
    static const int num_m2_pins = 37;

    static const int num_s1_pins = 43;
    static const int num_s2_pins = 47;
    static const int num_s3_pins = 51;
    static const int num_s4_pins = 53;
    static const int num_s5_pins = 59;

    tunny() { 
	next_chi = 0; prev_chi = 0; cur_chi = 0;
	cur_psi = 0; prev_psi = 0;
	prev2_input = 0; prev_input = 0;
	limitation = nolim;
    }
    virtual ~tunny() {}

    std::vector<bool> x1, x2, x3, x4, x5;    
    std::vector<bool>::iterator xp1, xp2, xp3, xp4, xp5;

    std::vector<bool> s1, s2, s3, s4, s5;    
    std::vector<bool>::iterator sp1, sp2, sp3, sp4, sp5;

    std::vector<bool> m1, m2;
    std::vector<bool>::iterator mp1, mp2;

    typedef enum { nolim, x2lim, s1lim, x2p5lim, x2s1p5lim } limitation_type;

    limitation_type limitation;

    void get_chi_positions(std::vector<unsigned int>& pos) {
	pos.clear();
	pos.push_back(xp1 - x1.begin());
	pos.push_back(xp2 - x2.begin());
	pos.push_back(xp3 - x3.begin());
	pos.push_back(xp4 - x4.begin());
	pos.push_back(xp5 - x5.begin());
    }

    void get_psi_positions(std::vector<unsigned int>& pos) {
	pos.clear();
	pos.push_back(sp1 - s1.begin());
	pos.push_back(sp2 - s2.begin());
	pos.push_back(sp3 - s3.begin());
	pos.push_back(sp4 - s4.begin());
	pos.push_back(sp5 - s5.begin());
    }

    void get_mu_positions(std::vector<unsigned int>& pos) {
	pos.clear();
	pos.push_back(mp1 - m1.begin());
	pos.push_back(mp2 - m2.begin());
    }

    static void text2pins(const std::string& text, std::vector<bool>& pins, 
			  int num);

    // This deals with the LZ40 machine: No chi wheel contribution to first
    // letter.  FIXME: Need to be able to disable for LZ42?

    tpchar_t prev_chi;
    tpchar_t cur_chi;
    tpchar_t next_chi;

    tpchar_t prev_psi;
    tpchar_t cur_psi;

    tpchar_t cur_mu;

    tpchar_t prev2_input;
    tpchar_t prev_input;

    bool cur_tm;
    bool cur_bm;

    virtual void tick(tpchar_t);

    tpchar_t get_chi() { return cur_chi; }
    tpchar_t get_psi() { return cur_psi; }
    tpchar_t get_mu() { return cur_mu; }
    bool get_tm() { return cur_tm; }
    bool get_bm() { return cur_bm; }

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

    virtual void set_mu_pins(const std::string& w1, const std::string& w2) {
	text2pins(w1, m1, num_m1_pins);
	text2pins(w2, m2, num_m2_pins);
	mp1 = m1.begin();
	mp2 = m2.begin();
    }

    void set_chi_positions(unsigned int w1, unsigned int w2, 
			   unsigned int w3, unsigned int w4,
			   unsigned int w5, bool count_from_one=true);
    void set_chi_positions(const std::vector<unsigned int>& s,
			   bool count_from_one=true) {
	if (s.size() != 5) throw std::out_of_range("Vector should be size 5");
	set_chi_positions(s[0], s[1], s[2], s[3], s[4], count_from_one);
    }

    void set_psi_positions(unsigned int w1, unsigned int w2, 
			   unsigned int w3, unsigned int w4,
			   unsigned int w5, bool count_from_one=true);
    void set_psi_positions(const std::vector<unsigned int>& s,
			   bool count_from_one=true) {
	if (s.size() != 5) throw std::out_of_range("Vector should be size 5");
	set_psi_positions(s[0], s[1], s[2], s[3], s[4], count_from_one);
    }

    void set_mu_positions(unsigned int w1, unsigned int w2,
			  bool count_from_one=true);
    void set_mu_positions(const std::vector<unsigned int>& s,
			  bool count_from_one=true) {
	if (s.size() != 2) throw std::out_of_range("Vector should be size 2");
	set_mu_positions(s[0], s[1], count_from_one);
    }

    void decrypt(const std::vector<tpchar_t>& in,
		 std::vector<tpchar_t>& out) {

	tpchar_t prev = 0;

	for(std::vector<tpchar_t>::const_iterator it = in.begin();
	    it != in.end();
	    it++) {

	    tick(prev);

	    tpchar_t c = *it;

	    prev = *it;
	    
	    c ^= get_chi();
	    c ^= get_psi();

	    out.push_back(c);

	}

    }

};
