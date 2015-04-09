
#include <colossus/colossus.h>

void colossus::run(unsigned int steps)
{
    
    // FIXME
    if (steps == 0) steps = 1000000000;

    for(int i = 0; i < steps; i++) {

	try {
	    tick();
	} catch (std::out_of_range& e) {
	    step();
	    rewind();
	}

    }

}


void colossus::step() 
{

#ifdef DONT_DEBUG
    std::cerr << chi_cur_step[0] << " "
	      << chi_cur_step[1] << " " 
	      << chi_cur_step[2] << " "
	      << chi_cur_step[3] << " "
	      << chi_cur_step[4] << "          ";

    std::cerr << c.c[0].value 
	      << std::endl;

#endif

    bool slow = false;

    // Fast steps.
    if (x1s == fast) 
	try { step_x1(); } catch (std::out_of_range& e) { slow = true; }
    if (x2s == fast) 
	try { step_x1(); } catch (std::out_of_range& e) { slow = true; }
    if (x3s == fast) 
	try { step_x1(); } catch (std::out_of_range& e) { slow = true; }
    if (x4s == fast) 
	try { step_x1(); } catch (std::out_of_range& e) { slow = true; }
    if (x5s == fast) 
	try { step_x1(); } catch (std::out_of_range& e) { slow = true; }

    if (slow) {
	if (x1s == slow) try { step_x1(); } catch (...) {}
	if (x2s == slow) try { step_x2(); } catch (...) {}
	if (x3s == slow) try { step_x3(); } catch (...) {}
	if (x4s == slow) try { step_x4(); } catch (...) {}
	if (x5s == slow) try { step_x5(); } catch (...) {}
    }
    c.reset();

}

void colossus::set_chi_starts(unsigned int w1, unsigned int w2, 
			      unsigned int w3, unsigned int w4,
			      unsigned int w5, bool count_from_one) 
{
    if (count_from_one) {
	w1--; w2--; w3--; w4--; w5--;
    }
    chi_starts[0] = chi_cur_step[0] = w1;
    chi_starts[1] = chi_cur_step[1] = w2;
    chi_starts[2] = chi_cur_step[2] = w3;
    chi_starts[3] = chi_cur_step[3] = w4;
    chi_starts[4] = chi_cur_step[4] = w5;
    l.set_chi_positions(w1, w2, w3, w4, w5, false);
}

void colossus::step_x1() {
    chi_cur_step[0] = ((chi_cur_step[0] + 1) % tunny::num_x1_pins);
    l.set_chi_positions(chi_cur_step[0], chi_cur_step[0], chi_cur_step[2],
			chi_cur_step[3], chi_cur_step[4], false);
    if (chi_cur_step[0] == chi_starts[0])
	throw std::out_of_range("Looped.");
}

void colossus::step_x2() {
    chi_cur_step[1] = ((chi_cur_step[1] + 1) % tunny::num_x2_pins);
    l.set_chi_positions(chi_cur_step[0], chi_cur_step[0], chi_cur_step[2],
			chi_cur_step[3], chi_cur_step[4], false);
    if (chi_cur_step[1] == chi_starts[1])
	throw std::out_of_range("Looped.");
}

void colossus::step_x3() {
    chi_cur_step[2] = ((chi_cur_step[2] + 1) % tunny::num_x3_pins);
    l.set_chi_positions(chi_cur_step[0], chi_cur_step[0], chi_cur_step[2],
			chi_cur_step[3], chi_cur_step[4], false);
    if (chi_cur_step[2] == chi_starts[2])
	throw std::out_of_range("Looped.");
}

void colossus::step_x4() {
    chi_cur_step[3] = ((chi_cur_step[3] + 1) % tunny::num_x4_pins);
    l.set_chi_positions(chi_cur_step[0], chi_cur_step[0], chi_cur_step[2],
			chi_cur_step[3], chi_cur_step[4], false);
    if (chi_cur_step[3] == chi_starts[3])
	throw std::out_of_range("Looped.");
}

void colossus::step_x5() {
    chi_cur_step[4] = ((chi_cur_step[4] + 1) % tunny::num_x5_pins);
    l.set_chi_positions(chi_cur_step[0], chi_cur_step[0], chi_cur_step[2],
			chi_cur_step[3], chi_cur_step[4], false);
    if (chi_cur_step[4] == chi_starts[4])
	throw std::out_of_range("Looped.");
}
