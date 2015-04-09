
#include <stdint.h>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>

#include <colossus/elemental.h>
#include <colossus/tunny.h>
#include <colossus/teleprinter.h>
#include <colossus/paper_tape.h>
#include <colossus/bus.h>
#include <colossus/logic_unit.h>
#include <colossus/counting_unit.h>

class colossus {
private:
public:

    paper_tape z;
    bus q;
    logic_unit panel;
    counting_unit c;
    tunny l;

    unsigned int chi_starts[5];
    unsigned int chi_cur_step[5];

    typedef enum { fast, slow, off } step_type;

    step_type x1s, x2s, x3s, x4s, x5s;

    void step_x1();
    void step_x2();
    void step_x3();
    void step_x4();
    void step_x5();

    void step();

    colossus() : q(z, l), panel(q, c) {}

    virtual void load_tape(const std::string& s) { z.load(s); }

    void set_chi_stepping(step_type w1, step_type w2, step_type w3,
			  step_type w4, step_type w5) {
	x1s = w1; x2s = w2; x3s = w3; x4s = w4; x5s = w5;
    }

    virtual void set_chi_starts(unsigned int w1, unsigned int w2, 
				unsigned int w3, unsigned int w4,
				unsigned int w5, bool count_from_one=true);

    virtual void set_chi_pins(const std::string& w1, const std::string& w2, 
			      const std::string& w3, const std::string& w4,
			      const std::string& w5) {
	l.set_chi_pins(w1, w2, w3, w4, w5);
    }

    void tick() {
	l.tick(z.get_value());
	z.tick();
	q.tick();
	panel.tick();
    }

    void rewind() { z.rewind(); }

    void letter_count() {

	try {
	    while(1) {
		tick();
	    }

	} catch(std::out_of_range& e) {

	}

    }

    void run(unsigned int steps = 0);

};

