
#include <colossus/elemental.h>

#include <map>

class simple_logic : public clockable {
private:
    counters* cntrs;
    input* in;
public:
    simple_logic(input& in, counters& c) : in(&in), cntrs(&c) { 
	counting.resize(cntrs->num_counters);
    }
    virtual void tick();

    std::vector<bool> counting;

    tpchar_t selector;
    tpchar_t mask;

    bool negate;

};

class adder_logic : public clockable {
private:
    counters* cntrs;
    input* in;
public:
    adder_logic(input& in, counters& c) : in(&in), cntrs(&c) { }

    virtual void tick();

    std::map<bool, unsigned int> counting;

    tpchar_t mask;
    bool check;

    bool negate;

};

class logic_unit : public clockable {
private:
    input& in;
    counters& cntrs;
public:
    static const int num_simples = 10;
    static const int num_adders = 5;

    std::vector<simple_logic> simples;
    std::vector<adder_logic> adders;

    logic_unit(input& i, counters& c) : in(i), cntrs(c) {
	for(int i = 0; i < num_simples; i++) {
	    simples.push_back(simple_logic(in, c));
	}
	for(int i = 0; i < num_adders; i++)
	    adders.push_back(adder_logic(in, c));
    }


    virtual void tick() {
	for(int i = 0; i < num_simples; i++)
	    simples[i].tick();
	for(int i = 0; i < num_adders; i++)
	    adders[i].tick();
    }
};
