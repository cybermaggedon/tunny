
#ifndef COLOSSUS_ELEMENTAL_H
#define COLOSSUS_ELEMENTAL_H

#include <colossus/teleprinter.h>

class clockable {
public:
    virtual void tick() = 0;
};

class input {
public:
    virtual tpchar_t get_value() = 0;
};

class incrementable {
public:
    virtual void increment() = 0;
};

class counters {
public:
    static const int num_counters = 5;
    virtual void increment(unsigned int counter) = 0;
    virtual void get_counts(std::vector<unsigned int>& counts) = 0;
};

class cipher_stream {
public:
    virtual tpchar_t get_chi() = 0;
    virtual tpchar_t get_psi() = 0;
    virtual void get_chi_positions(std::vector<unsigned int>& pos) = 0;
    virtual void get_psi_positions(std::vector<unsigned int>& pos) = 0;
    virtual void get_mu_positions(std::vector<unsigned int>& pos) = 0;
};

#endif

