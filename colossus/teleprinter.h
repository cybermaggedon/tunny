
#ifndef TELEPRINTER_H
#define TELEPRINTER_H

#include <vector>
#include <string>

typedef unsigned char tpchar_t;

class teleprinter {

public:

    static tpchar_t from_char(unsigned char);
    static unsigned char to_char(tpchar_t);

    static void from_string(const std::string& s, std::vector<tpchar_t>& v) {
	v.clear();
	for(std::string::const_iterator it = s.begin();
	    it != s.end();
	    it++)
	    v.push_back(from_char(*it));
    }

    static void to_string(const std::vector<tpchar_t>& v, std::string& s) {
	s.clear();
	for(std::vector<tpchar_t>::const_iterator it = v.begin();
	    it != v.end();
	    it++)
	    s.push_back(to_char(*it));
    }

};

#endif

