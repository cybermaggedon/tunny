
#include <colossus/q_panel.h>

void comparison_unit::tick()
{
	
    tpchar_t v = in->get_value();

//	std::cerr << (int) v << std::endl;

    bool result = ((v & mask) == selector);

    if (negate) result = !result;

    if (result) {
	for(int i = 0; i < cntrs->num_counters; i++)
	    if (counting[i]) {
		cntrs->increment(i);
	    }
    }

}

void addition_unit::tick()
{
	
    if (mask == 0) return;

    tpchar_t v = in->get_value();

    bool result;

    for(unsigned int i = 0; i < 5; i++) {
	if (mask & (1 << i))
	    result ^= ((v & (1 << i)) != 0);
    }


    if (negate) result = !result;

    if (result == check) {
	for(int i = 0; i < cntrs->num_counters; i++)
	    if (counting[i]) {
		cntrs->increment(i);
	    }
    }

}

