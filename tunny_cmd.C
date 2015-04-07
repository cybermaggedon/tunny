
#include <iostream>
#include <stdlib.h>
#include <getopt.h>
#include <vector>

#include <boost/program_options.hpp>

namespace po = boost::program_options;
int main(int argc, char** argv)
{

    int c;
    int digit_optind = 0;

    // Declare the supported options.
    po::options_description desc("Allowed options");
    desc.add_options()
	("help,h", "produce help message")
	("verbose,v", "enable verbose output")
	("in,i", po::value<std::string>()->default_value("-"), "input file")
	("out,o", po::value<std::string>()->default_value("-"), "output file")
	("decrypt,d", "enable decryption")
	("encrypt,e", "enable encryption")
	("set",  po::value<std::vector<std::string> >()->multitoken(),
	 "set configuration parameter (key=value)")
	("config,c", "set configuration file")
	;

    po::variables_map vm;

    try {

	po::store(po::parse_command_line(argc, argv, desc), vm);


	po::notify(vm);    
    
    } catch (std::exception& e) {
	
	std::cerr << e.what() << std::endl;
	exit(1);

    }

    if (vm.count("help")) {
	std::cout << desc << "\n";
	return 1;
    }
    
    if (vm.count("in")) {
	std::cout << "In was set to " 
		  << vm["in"].as<std::string>() << ".\n";
    } else {
	std::cout << "In was not set.\n";
    }

    if (vm.count("set")) {
	const std::vector<std::string>& val = 
	    vm["set"].as<std::vector< std::string > >();

	for(std::vector<std::string>::const_iterator it = val.begin();
	    it != val.end();
	    it++) {
	    std::cout << "set:" << *it << std::endl;
	}
    }

    exit(0);

}

