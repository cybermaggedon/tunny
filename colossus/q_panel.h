
#include <colossus/elemental.h>

#include <map>

class comparison_unit : public clockable {
private:
    counters* cntrs;
    input* in;
public:
    comparison_unit(input& in, counters& c) : in(&in), cntrs(&c) { 
	counting.resize(cntrs->num_counters);
    }
    virtual void tick();

    std::vector<bool> counting;

    tpchar_t selector;
    tpchar_t mask;

    bool negate;

};

class addition_unit : public clockable {
private:
    counters* cntrs;
    input* in;
public:
    addition_unit(input& in, counters& c) : in(&in), cntrs(&c) { }

    virtual void tick();

    std::map<bool, unsigned int> counting;

    tpchar_t mask;
    bool check;

    bool negate;

};

class q_panel : public clockable {
private:
    input& in;
    counters& cntrs;
public:
    static const int num_simples = 10;
    static const int num_adders = 5;

    std::vector<comparison_unit> simples;
    std::vector<addition_unit> adders;

    q_panel(input& i, counters& c) : in(i), cntrs(c) {
	for(int i = 0; i < num_simples; i++) {
	    simples.push_back(comparison_unit(in, c));
	}
	for(int i = 0; i < num_adders; i++)
	    adders.push_back(addition_unit(in, c));
    }


    virtual void tick() {
	for(int i = 0; i < num_simples; i++)
	    simples[i].tick();
	for(int i = 0; i < num_adders; i++)
	    adders[i].tick();
    }
};
