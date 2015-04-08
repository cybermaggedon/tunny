
#include <iostream>
#include <stdlib.h>
#include <getopt.h>
#include <vector>
#include <fstream>

#include <boost/program_options.hpp>

namespace po = boost::program_options;
int main(int argc, char** argv)
{

    int c;
    int digit_optind = 0;

    // Declare the supported options.
    po::options_description desc("Options");
    desc.add_options()
	("help,h", "produce help message")
	("verbose,v", "enable verbose output")
	("in,i", po::value<std::string>()->default_value("-"), "input file")
	("out,o", po::value<std::string>()->default_value("-"), "output file")
	("decrypt,d", "enable decryption")
	("encrypt,e", "enable encryption")
	("chi.1", po::value<std::string>(), "Chi 1 wheel pins")
	("chi.2", po::value<std::string>(), "Chi 2 wheel pins")
	("chi.3", po::value<std::string>(), "Chi 3 wheel pins")
	("chi.4", po::value<std::string>(), "Chi 4 wheel pins")
	("chi.5", po::value<std::string>(), "Chi 5 wheel pins")
	("psi.1", po::value<std::string>(), "Psi 1 wheel pins")
	("psi.2", po::value<std::string>(), "Psi 2 wheel pins")
	("psi.3", po::value<std::string>(), "Psi 3 wheel pins")
	("psi.4", po::value<std::string>(), "Psi 4 wheel pins")
	("psi.5", po::value<std::string>(), "Psi 5 wheel pins")
	("mu.1", po::value<std::string>(), "Mu 1 wheel pins")
	("mu.2", po::value<std::string>(), "Mu 2 wheel pins")
	("chi.settings", po::value< std::vector<int> >()->multitoken(),
	 "Chi wheel settings")
	("psi.settings", po::value< std::vector<int> >()->multitoken(),
	 "Psi wheel settings")
	("mu.settings", po::value< std::vector<int> >()->multitoken(),
	 "My wheel settings")
	("config,c", po::value<std::string>(), "set configuration file")
	;

    po::variables_map vm;

    try {

	po::store(po::parse_command_line(argc, argv, desc), vm);

	if (vm.count("config")) {
	    std::string config = vm["config"].as<std::string>();

	    std::ifstream config_file(config.c_str());
	    po::store(po::parse_config_file(config_file, desc), vm);

	}

	po::notify(vm);    
    
    } catch (std::exception& e) {
	
	std::cerr << e.what() << std::endl;
	exit(1);

    }

    if (vm.count("help")) {
	std::cout << desc << "\n";
	return 1;
    }
    
    bool encrypt = true;
    bool verbose = false;

    if (vm.count("verbose"))
	verbose = true;

    if (vm.count("encrypt"))
	encrypt = true;

    if (vm.count("decrypt"))
	encrypt = false;

    std::istream* in;
    std::ostream* out;

    if (vm.count("in")) {
	std::string fname = vm["in"].as<std::string>();

	if (fname == "-")
	    in = &std::cin;
	else
	    in = new std::ifstream(fname.c_str());

	if (verbose)
	    std::cerr << "Input from \"" << fname << "\"" << std::endl;

    } else {
	in = &std::cin;
    }

    if (vm.count("out")) {
	std::string fname = vm["out"].as<std::string>();

	if (fname == "-")
	    out = &std::cout;
	else
	    out = new std::ofstream(fname.c_str());

	if (verbose)
	    std::cerr << "Output to \"" << fname << "\"" << std::endl;

    } else {
	out = &std::cout;
    }

    std::string chi1, chi2, chi3, chi4, chi5;
    std::string psi1, psi2, psi3, psi4, psi5;
    std::string mu1, mu2;

    if (vm.count("chi.1"))
	chi1 = vm["chi.1"].as<std::string>();
    if (vm.count("chi.2"))
	chi2 = vm["chi.2"].as<std::string>();
    if (vm.count("chi.3"))
	chi3 = vm["chi.3"].as<std::string>();
    if (vm.count("chi.4"))
	chi4 = vm["chi.4"].as<std::string>();
    if (vm.count("chi.5"))
	chi5 = vm["chi.5"].as<std::string>();

    if (vm.count("psi.1"))
	psi1 = vm["psi.1"].as<std::string>();
    if (vm.count("psi.2"))
	psi2 = vm["psi.2"].as<std::string>();
    if (vm.count("psi.3"))
	psi3 = vm["psi.3"].as<std::string>();
    if (vm.count("psi.4"))
	psi4 = vm["psi.4"].as<std::string>();
    if (vm.count("psi.5"))
	psi5 = vm["psi.5"].as<std::string>();

    if (vm.count("mu.1"))
	mu1 = vm["mu.1"].as<std::string>();
    if (vm.count("mu.2"))
	mu2 = vm["mu.2"].as<std::string>();

    std::vector<int> chi_settings, psi_settings, mu_settings;

    if (vm.count("chi.settings"))
	chi_settings = vm["chi.settings"].as<std::vector<int> >();

    if (vm.count("psi.settings"))
	psi_settings = vm["psi.settings"].as<std::vector<int> >();

    if (vm.count("mu.settings"))
	mu_settings = vm["mu.settings"].as<std::vector<int> >();

    if (verbose) {

	std::cerr << "Chi 1: " << chi1 << std::endl;
	std::cerr << "Chi 2: " << chi2 << std::endl;
	std::cerr << "Chi 3: " << chi3 << std::endl;
	std::cerr << "Chi 4: " << chi4 << std::endl;
	std::cerr << "Chi 5: " << chi5 << std::endl;

	std::cerr << "Psi 1: " << psi1 << std::endl;
	std::cerr << "Psi 2: " << psi2 << std::endl;
	std::cerr << "Psi 3: " << psi3 << std::endl;
	std::cerr << "Psi 4: " << psi4 << std::endl;
	std::cerr << "Psi 5: " << psi5 << std::endl;

	std::cerr << "Mu 1: " << mu1 << std::endl;
	std::cerr << "Mu 2: " << mu2 << std::endl;

	std::cerr << "Chi settings: ";
	std::ostream_iterator<int> out_it(std::cerr," ");
	std::copy(chi_settings.begin(), chi_settings.end(), out_it);
	std::cerr << std::endl;

	std::cerr << "Psi settings: ";
	std::copy(psi_settings.begin(), psi_settings.end(), out_it);
	std::cerr << std::endl;

	std::cerr << "Mu settings: ";
	std::copy(mu_settings.begin(), mu_settings.end(), out_it);
	std::cerr << std::endl;

    }

    exit(0);

}

