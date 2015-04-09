
#include <colossus/elemental.h>

class bus : public clockable, public input {
private:
    input& z;
    cipher_stream& c;
    tpchar_t cur_value;
public:

    typedef enum { value, off, delta } mode;
    mode z_mode;
    mode x_mode;
    mode y_mode;

    tpchar_t old_z, old_x, old_y;

    bus(input& z, cipher_stream& c) : z(z), c(c) {
	z_mode = x_mode = y_mode = off;
	old_z = old_x = old_y = 0;
    }

    virtual void tick();

    virtual tpchar_t get_value() { return cur_value; }

};

