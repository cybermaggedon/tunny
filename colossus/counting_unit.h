
#ifndef COLOSSUS_COUNTING_UNIT_H
#define COLOSSUS_COUNTING_UNIT_H

class counter : public incrementable {
private:
    static const int max_value = 10000;
public:
    uint16_t value;
    counter() { value = 0; }
    uint16_t get() { return value; }
    virtual void increment() {
	value++;
	if (value == max_value) value = 0;
    }
};

class counting_unit : public counters {
public:
    typedef unsigned int counter_mask;
    std::vector<counter> c;
    counting_unit() { c.resize(num_counters); }
    void reset() {
	c.clear();
	c.resize(num_counters);
    }
    virtual void increment(unsigned int i) { c[i].increment(); }
    virtual void get_counts(std::vector<unsigned int>& counts) {
	counts.clear();
	for(int i = 0; i < num_counters; i++)
	    counts.push_back(c[i].get());
    }
};

#endif

