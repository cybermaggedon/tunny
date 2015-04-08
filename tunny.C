
#include <iostream>
#include <stdexcept>
#include <vector>

#include <colossus/tunny.h>

void tunny::tick(tpchar_t plain) 
{

    tpchar_t x;

    // Basic motor is mu37 cam.
    cur_bm = *mp2;

    // FIXME: no
    // Total motor adds limitation.
    //cur_tm = cur_bm ^ lim;

    // Deal with limitations.
    if (limitation == nolim)

	// No limitation: TM = BM
	cur_tm = cur_bm;
    
    else { 

	// Other limitations.
	bool lim = false;
    
	if (limitation == x2lim) {
	    lim ^= ((cur_chi & (1 << 3)) != 0);
	}

	if ((cur_bm == false) && lim)
	    cur_tm = false;
	else
	    cur_tm = true;

    }

    prev2_input = prev_input;
    prev_input = plain;

    // Chi seems to be delayed by 1 character.

    // From Newmanry: this deals with the LZ40 machine: No chi wheel
    // contribution to first letter.  FIXME: Need to be able to disable for
    // LZ42?

    x = 0;
    if (*xp1) x |= 16;
    if (*xp2) x |= 8;
    if (*xp3) x |= 4;
    if (*xp4) x |= 2;
    if (*xp5) x |= 1;
    prev_chi = cur_chi;
    cur_chi = x;

/*
    prev_chi = cur_chi;
    cur_chi = next_chi;
    next_chi = x;
*/
    
    x = 0;
    if (*sp1) x |= 16;
    if (*sp2) x |= 8;
    if (*sp3) x |= 4;
    if (*sp4) x |= 2;
    if (*sp5) x |= 1;
    prev_psi = cur_psi;
    cur_psi = x;
    
    x = 0;
    if (*mp1) x |= 2;
    if (*mp2) x |= 1;
    cur_mu = x;

    // Chi wheels always move.
    if (++xp1 == x1.end()) xp1 = x1.begin();
    if (++xp2 == x2.end()) xp2 = x2.begin();
    if (++xp3 == x3.end()) xp3 = x3.begin();
    if (++xp4 == x4.end()) xp4 = x4.begin();
    if (++xp5 == x5.end()) xp5 = x5.begin();

    // Psi wheels move if total motor is active.
    if (cur_tm) {
	if (++sp1 == s1.end()) sp1 = s1.begin();
	if (++sp2 == s2.end()) sp2 = s2.begin();
	if (++sp3 == s3.end()) sp3 = s3.begin();
	if (++sp4 == s4.end()) sp4 = s4.begin();
	if (++sp5 == s5.end()) sp5 = s5.begin();
    }
    
    // Move mu37 wheel if mu61 cam is active.
    if (*mp1)
	if (++mp2 == m2.end()) mp2 = m2.begin();

    // Always move mu61 cam.
    if (++mp1 == m1.end()) mp1 = m1.begin();

}

void tunny::text2pins(const std::string& text, std::vector<bool>& pins, 
		       int num) 
{
    
    pins.clear();
    for(std::string::const_iterator it = text.begin(); it != text.end();
	it++) {
	pins.push_back(*it == 'x');
    }

    if (pins.size() != num)
	throw std::out_of_range("Pin configuration incorrect size.");
}

void tunny::set_chi_positions(unsigned int w1, unsigned int w2, 
			      unsigned int w3, unsigned int w4,
			      unsigned int w5, bool count_from_one) 
{

    if (count_from_one) {
	w1--; w2--; w3--; w4--; w5--;
    }

}

void tunny::set_psi_positions(unsigned int w1, unsigned int w2, 
			      unsigned int w3, unsigned int w4,
			      unsigned int w5, bool count_from_one) 
{

    if (count_from_one) {
	w1--; w2--; w3--; w4--; w5--;
    }

}

void tunny::set_mu_positions(unsigned int w1, unsigned int w2, 
			     bool count_from_one) 
{

    if (count_from_one) {
	w1--; w2--;
    }
    
    mp1 = m1.begin() + w1;
    mp2 = m2.begin() + w2;

}
