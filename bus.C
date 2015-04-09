
#include <iostream>

#include <colossus/bus.h>

void bus::tick() {

    tpchar_t v = 0;

    if (z_mode == value)
	v ^= z.get_value();

    if (x_mode == value)
	v ^= c.get_chi();

    if (y_mode == value)
	v ^= c.get_psi();

    if (z_mode == delta) {
	v ^= (z.get_value() ^ old_z);
	old_z = z.get_value();
    }

    if (x_mode == delta) {
	v ^= (c.get_chi() ^ old_x);
	old_x = c.get_chi();
    }

    if (y_mode == delta) {
	v ^= (c.get_psi() ^ old_y);
	old_y = c.get_psi();
    }

    cur_value = v;

    std::vector<unsigned int> pos;
    c.get_chi_positions(pos);

#ifdef DONT_DEBUG
    std::cerr << teleprinter::to_char(v) << " ";
    std::cerr << (int) ((v & 16) ? 1 : 0)
	      << (int) ((v & 8) ? 1 : 0)
	      << (int) ((v & 4) ? 1 : 0)
	      << (int) ((v & 2) ? 1 : 0)
	      << (int) ((v & 1) ? 1 : 0)
	      << "     " << (int) v << "          " 
	      << pos.at(0) + 1 << " "
	      << pos.at(1) + 1 << " "
	      << pos.at(2) + 1 << " "
	      << pos.at(3) + 1 << " "
	      << pos.at(4) + 1 << " "
	      << std::endl;
#endif

}
