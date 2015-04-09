
#include <colossus/teleprinter.h>

class paper_tape : public clockable, public input {
private:
    std::vector<tpchar_t> tape;
    std::vector<tpchar_t>::iterator ptr;
    tpchar_t cur_value;

public:
    virtual void load(const std::string& s) {
	tape.clear();
	for(std::string::const_iterator it = s.begin(); it != s.end(); it++) {
	    tape.push_back(teleprinter::from_char(*it));
	}
	ptr = tape.begin();

    };

    virtual void rewind() { ptr = tape.begin(); }

    virtual void tick() {
	if (ptr == tape.end()) throw std::out_of_range("Reach end of tape");
	cur_value = *ptr;
//	std::cerr << (int) cur_value << " ";
	ptr++;
    }
    virtual tpchar_t get_value() {
	return cur_value;
    }
};
