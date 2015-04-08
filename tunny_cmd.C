
#include <colossus/teleprinter.h>
#include <colossus/tunny.h>

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <getopt.h>
#include <vector>
#include <fstream>

#include <boost/program_options.hpp>
const std::string khcipher = "/WWVPXA+/XZOEIEANDTLIK3EV-FHEZNFXX.YKCWPYEA.S4COMJJE4LVUIPRWKWSJZB3COXNWVWD4V4V+LG.MD.FAXFJCAHA+WWPM4M.3/VPZZ/KWCGP.JXZYTOHQQFE-JF.RRTHUW.FMVJQ4P-.LQBDYQA+HAQQNBH/ZHPT-SC3HLDVJRPXU/.BXZ.UYL/LV-VLM-RFBKXVS+PRQHN+CYUQBYXX/+3ERDMDNBDDMXHSCBBGHKKFLGA.U+U-+JFK34JNVNG.ZWJABPWVC-HNOIYEKG-IP./QIBAA4VGRC/G/XR.LPYLSB.JDWYCAR/4BT-X4YIEHSIQDDK.4J-FNC-CH.FJKOIDWITCLOZM/K+.+/XNZMLTP/UQ3AAZ/YUTQ4-JMDZSW.UDQFRHJBO+3ID+NMGX-PT-BNNITVSKOQMVHKU-UKKOBEIEBPSZMV3W.YER/M44ZVJ/KEVCW/GFKCU.3IB-RMB-CORPOONF4QEHYXGJ4QRHFA4U.KQDD-PHXDDDQDG+BZVF4HIVMZOH3AG3ANQOS4J/ZGNNWRZSPLHTUGSTYNFS4/ITZRY3RKD.TM/IW34IRHMELGROQM4.Q.GDYWDQAZR3..IAVKF/AP4YR4LS-XL/DK4MSEOQLHMGIUHIH+HKLCKY4DXEHYEXYZ/3PGN/3ZCV.K3AJLKBRADBPWZ3.ZAOWRRV4M-JGDBOQTTVXOQM+AXYYETEZQOTI.CBO-IQYB+ABDKP3SG.LNJ-X+TIDMJGDTD4C-WEOGZ3FMMUPGH4AAYHPXTKBCKTQYKB3FNUMRCHUYQXJIZ+JNR3JQGP-MELWO4+JKMIORCPFATC-D.VVWO.QZ-CMGEQSGDT/DUJHZIUPXWC+PQYCVF4I33BN-+4WDATPFRZMYAKXBK3MNEQS.JZDUEW-RYWFVJDQ+/J3JFGG-ITFERRJ+R+RQIHOPBTT+OUTV3CEIORVVF-K/SJVBHUG-MFPXK-DMD.RYEVJINZJCZW-HJE.4VBWNZWEMZWXCLTYJ+ZGLXWA4/ANJLJ43MODWRZH...LWOR+AB3A4GUC/XZL/NSXTMTDGYXC4WY4D4ADYEKSZF+XVOYXMOQYKHRPAFQ4B-IGO//G3VKLKQGIJNBYU.-3QBB+4PVXSK4GF+JP4XSRLLNPPIIDI3HQ3BKMXAAQRLKDT3ZKI4K/BKZG.PK.EEX/PFIOPQTQCYWVPAXWHHZYAM3OENA4-X3-BOK+-ANEJYVUQWUDD3RQEXM+B3EFYC.IVMXDE+PVTDOE.HHOVBO-B3+ZHCCFQVGZUAB+SSHUVC.4.WPQAORTH+CM.EEN.DCW./MZN.MM.LMPI/OJVIYODYHKFGHY-FE-QUUOP/NYH/XBRQSZM+H4-JWKKUGR3DLFZPHAKBG4YGBD4QLVBHMWG.GMMGPQGRM4CDHB4/FX.-XXDRNSXB./HUMG3BDUK3EUCERS.FPHEKMSWIXRPHBB/YTOBSFRREFQYTMFOSPWEGETENWDEN/GY+IXGSMPNE4CGWTYZVARYUA-4YC+DEO+N-LCXGPE+UWHWEU3MRGPVDZJG.MRKGI-ZBILEY-QC4C/LXSW3TMZSOHKGRTFICOGXPZ/N+H3HJRFDXZVZ-QYZSOG/YTALXEP3OR3U.4P/3SF.-U-JZJDAEZMM3KYDCTL4JJL.3RW+I/WYIX-VIOQIMUGJ/SDVAWFYNZOX4./ZSG3+Z-JUAMGXM/H.PWM+EVHUKZKQKFYO/TNCF/AQ.GO/FTWBJGH/MKM4FO+HNXHZIDRPKJUSMX4JM-F+FEPYTEGY-PR.ILMKMDXATTUDOZMF+SQIQ-SJ.EPQRGODTK+VPFPQL.IH3VPBVUC4HD+UCCQADFVSQ4KMJGTD+OPXKQ3RE4+GZQBWAXP4G.PPQ.3USWOCXPGCJHY.M/-AF3-USDFX.MGU+JUD/FSCQLQQXMJ-O.JQXZEZNVGXSHSB/JWJAUV4HHR3CQ-PDB/U4AEJHKYD.NJFLPFEP/WVL-VBSID3EN4/-EGHMAM+WVHQTLNLNL.I.RJA+JQK/KUR44C-PRCPRDLAY+IDE/IMWKDSUGAF.HA-RJ--ENI..MT.VVNFHFK.HXTD-+3GWR3MFOVLN.WKIJK.K/ZVKYO-OKBSJDRUAUYWXZJMZRNJPVFKVS+-VXR/B33VWAPQAAUMYD3JLFJBFSU/W3RCKPVRSJ-4WTGYEXR3CN.-UC4X/AQMTQCVVRREX.3ODIKRZF+/L-NCHFIZUVTVF+MC+/MHVHY4AXFCMYQFTIG3EFWA.L-JDHN+JAJ4.QAD4HIN+PZZU+-FVAZCKL.NHFDMBEINROIQJIV.ANACETX3UX.CULA43KZSE+JPHPYVVAZUXV3S+DCVJRDEGGJAK+4X-KSIZTIMHVALKPPISOPIXSANZBOUEBEOWEXCQ.MWWISKDYGPMUBAAHO-L+UWJQG-AJAU/OU/LRVEJSYZZY+LI4IUAXGRPHD3OUCZEX.RSERBYQI/JXFKFAMWDMJDVFITHK3MCKWLZHWGAQ3G3LXV4A/RPQKNZG+3IS.Z/CBBV3F/ECQ+XEKKE+A+LBZ/PZKCGQG+MSKQC-P+FYOYQU-.ESUS/SSCWF+U.X/XANUNULLNERMVQF-.WXWKPNNP/N.C3PGJWAJ3ZUSEAYFQG.QOIGD.QU4FHQ-LUDJSKYKGMRA-G4-ODOR-I-AYJHM+Q.+YX./Z+SGNQE+.UOYR.4KNLZ4.IA4SIW4OLTFBJHJTWTJSP3ZGPZFGIBHH-XSMH+WOMV4LDOJ4ZFH/NCCWRNX/L+H/LZPBZN.+EHR4UHU43GTFHSUXOIINYZJUJF/J3TIFXKTMS+TUVUMMKCDPXBVIDZOJRPVMA3JKUQLAH4G.YU3HCLMOCBVWDWQS.B-GYTNR-IBK33YSYPMYAHIGYFG3MRQKCUOWXYJVDLLS.JMZDJVUAHUH-.UHBZEUSI.FUKJTHX4-.XVPRVOJZHBUWSWJYUHQ4RWJFICUI+USKHJEWJVNWZSA+SK.EU3SFFAWE-MXJMD3YRTJKLXRLFWUGNKA-JYYIKE+4E4CB.GH+I/ZJ--QKRDVWTUKLGEHR-3NIHBW-BFWJRA4VWI-BOXGHVPQYMGCFZUVQF4PSY/GM.W-3ANADFB.OQ3KKTBFEEDUAIAY/XSFCFLRYJ+SNK/YJCBLV4MOL+J-G4ZD/ZJSUJ.-UHB/W/CIQ/AGKCPMX3ARA3V/CNJ3ZSJIOPOW.VZ.ZY-E/ZRVAJFU/DNN-LG/MRXPTQNDNFSG-OS-VE.PNQDRJTFBRMBCNBUXUL+UM-ILERYBNIAXTDRIACW.UM/GKJIMFTIPNE+T4JXAPAODBIEWSY3HZXW.VO+3GAOEMR4GUSB.TN-RKMQA-WWTHT/Z+IZBYXXLZ4AYVLR/DMEYZIVZCTGVUBAUFQ3KEVTYCLH.T-DOTS4EB.PO33TPQURS-FS+-+.OQNMIL/WHYWPFHC+YRAYBJTDKHM/THPWRYS/Z.3OAE.PRHMBHUEC.L.J.EK3EPVPN+HVIFXQQZOGIGO4MYWPS+GOVCPAGX3BF3HJEY.B+3-3FRIMF+G3FBMFIL4.BNUYLLZQJC-W3LABWGUWJQFUFLXLOUU4HTNTILM-W3-OQP//3LSPWVOWPUWSJUUSGUUPLUXSFDDYHLJQBRMGZ.NLZQACY44/Z4TMW4SAV33VQZQQE3TTLLMZZIEFSLZPBP3LYX-AWVUW-PB+.NCEFH3STXSGDOFOW-/GPMBHB+GHWLZJ.S+/IC+LH3WXL3B4VHT3USYBAF+4MVCIBR-PLJEGHZ+CWCLWTJ/RUHSSZE3OKNPVGBYCWXSY/BTPQLHS3NKFYN/Q4NHVWOSSITXJO/PC34FGUBA.MK3KGAXYXXIFZV+VLCKH3CSCYR./CHWXSDXFKJMIEWXZ3QUFTZR/WDE.BYC4HAOBH+UWF/HO4OQW-XHQU/DJP.KNJIFAULBTRANT.B4BM3BSMG/BM3FARG.SFODS.FNC.MSGFSK+DMKGFBPVRVGZIJ+BXFLNLFYBE.QHDXCXXLALOUZDCPDIFYRA4BVOHIXTIHGZ4YYFNT4V4UFDL/Q.T3-D+FEBK+3M/CVESEKL/4F/UWZFFRQK-HX+HJIBT+LLJUU-FB3MQZUW-URFT/YXKW4U.D4E4HDRUSVGVQR+SV-H3JUPIEGSZ3GFYHJVRGINPBSV-/WEJDWJ/H/DS.FHCAPHZ.OYXOVYA+-DTFCUENL-D+RBICUPSLRZYZY/NLD44/E.KKXLWLSKPVTOVYEY.TC/UM.JNKCRKHQUKCCXYLEDHDAG3QBKU.P3VY/3HADBFSYTX+ZE-KQCQPET4SGB./-YBNMOUYRPYILTPJDBTDYOD/OJXKI3KHN4NX3RNTBZCPI4/DHN4BJPM/QD-VSRQV-PF-R3PDUVF3/+3US+4JZJXHXX4QQ3BREJUB.WLJ.OALMB-GA/LL+-GCOQHITHEDY+LX./SPIQXKK+.XXTSW4RJ/U+CBUEZUVB4IH4TBWNRL.+DI.V-X4XSAAJSTEVFY/NEUHJI.HGF.NMN3PTSYUSDTE3ZATPGFS4FM+.GU/ZUK+EYQMPQVLPXMCPX3IOS+4VLAW+FT-TYVZNIFOOVHMM3DHOXWTTQWDHFDH..3ZIROMUVWDVOCA+OELILVISZY/RLQIXY4AUEDODOLZBS-+LVLAAPTKF/3RBTIK+NG3CXGKF-.P+YU-A/SGN/TRDHYWFTX+OH+GPUOMJWZME+HIWX3QJGOPSDUMAWRNGT3LVO4-GMWROBO3O3VLZ/PSFISL3/TCMHFVYC-RT//YFPZ+O4RMWZ3QPGC/TKJU.SCOU3P4-SL.D.JZT4ABYKJ-IZX.W4ZNFRTSIVJRDTPYMAJMCAAVPSW/FVHY+FIECZMAYZOLJ3XYLCEB4AY/TH.P/SLUG/LOOMXXBKJTALJ3JISDP-W/T+QJYMDL-AP+-ADB3LUJGOTEMCKE33DI3JEUJ4QWFSFNMYZJHYMP+C+QWDCZMUP4+OCWSRHZSJJMDPTNJVTUOZPMFU-ALBOOZNQKKGDX/UNOCNVL.CXHUVUXWRNXVOUDM4BZW-V3KULNHQXPHP//DNKFI.CVGASJKUF.GCTWJSX3UR-M/PCEDFT-TRI+/K3ZHHADITCBLFFYCAW3SPYT++ZU3BTSD-A4YH/ZMAPVDP-ZE/3WPOF/4UQ-3WNAO3OKFSCWIM.+ZFWQWCLYLS-MVOP--H/IQBN.-J/EAXGY-DPAEG4ESEFZTEIPW+ZQFXXOZJWBVIL.IMY4O/DLPLINYCPJ/PGDYQXMWYUTOMOTMRD-CPHX+H34TZDQSWCPCTK3U./O+S/SDV3GEVFKGUIWJFIHJCHLEFFBB-3SACF4SCMHV4BLJAY3TPCRD-QRLZCEW4NEXOUKSZDSOSDNQI3-3-W.A-WN4TZ3QFALEERLKSQYSKL4+OWACIO3-KSLAUWR3FNWSM4FFFNBMWFY-PFJMFUNML.RTJGYOGASTIFR+.GAQBDBTEZ/AYYCJBNOWJFESCGNNUNLK/4GJH.IVJ-CGOCVPA-WSFDVYB3QQ/GJDV3NHSHZ+MCJEJ+UHYFYVSOJSPERDKTGY/K+E4QUQX3VMC+EXHO3DI+NJT+OPM/3GR-+QU.FD3CZBXUWSBR+GC.ULT3NTSYVZSP.DG-FELM.J3PNGZYWC3MI3+O4WUS33FDBWC-FKLW+KWKAAJYGEEV44TOYXZ/RPNVIKTUJHY/F4/DUXNNJWI-3JCYXXTCJJH/4FEF/MQWDGMHA4H34JNX+.BU-GOCG-VJF4QK-P+HGDMVRVTCYOLM+Q.BYETEHTOYT.-FERLHQ3R-E/ZUG/GZ3-43HUYM.DCXF+TFSVEKLD/OT+XZDSXQJLMWRFD/U.3V3B4RTJZ3LW-****";

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
	("chi.settings", po::value< std::vector<unsigned int> >()->multitoken(),
	 "Chi wheel settings")
	("psi.settings", po::value< std::vector<unsigned int> >()->multitoken(),
	 "Psi wheel settings")
	("mu.settings", po::value< std::vector<unsigned int> >()->multitoken(),
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

    std::vector<unsigned int> chi_settings, psi_settings, mu_settings;

    if (vm.count("chi.settings"))
	chi_settings = vm["chi.settings"].as<std::vector<unsigned int> >();

    if (vm.count("psi.settings"))
	psi_settings = vm["psi.settings"].as<std::vector<unsigned int> >();

    if (vm.count("mu.settings"))
	mu_settings = vm["mu.settings"].as<std::vector<unsigned int> >();

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
	std::ostream_iterator<unsigned int> out_it(std::cerr," ");
	std::copy(chi_settings.begin(), chi_settings.end(), out_it);
	std::cerr << std::endl;

	std::cerr << "Psi settings: ";
	std::copy(psi_settings.begin(), psi_settings.end(), out_it);
	std::cerr << std::endl;

	std::cerr << "Mu settings: ";
	std::copy(mu_settings.begin(), mu_settings.end(), out_it);
	std::cerr << std::endl;

    }

    tunny t;

    t.set_chi_pins(chi1, chi2, chi3, chi4, chi5);
    t.set_psi_pins(psi1, psi2, psi3, psi4, psi5);
    t.set_mu_pins(mu1, mu2);

    t.set_chi_positions(chi_settings);
    t.set_psi_positions(psi_settings);
    t.set_mu_positions(mu_settings);

    t.limitation = tunny::x2lim;

    std::vector<tpchar_t> plain;

    std::vector<tpchar_t> cipher;

    teleprinter::from_string(khcipher, cipher);
    tpchar_t prev = 0;

	for(int i = 0; i < cipher.size(); i++) {

	tpchar_t v;

	std::vector<unsigned int> chi_pos, psi_pos, mu_pos;
	t.get_chi_positions(chi_pos);
	t.get_psi_positions(psi_pos);
	t.get_mu_positions(mu_pos);

	t.tick(prev);
	prev = cipher[i];

	v = cipher[i];

	tpchar_t w = v;
	tpchar_t chi = t.get_chi();
	tpchar_t psi = t.get_psi();
	tpchar_t mu = t.get_mu();
	w ^= chi;
	w ^= psi;

	bool bm = t.get_bm();
	bool tm = t.get_tm();

	std::cout << std::setfill(' ') << std::setw(7) << i << ": "
		  << teleprinter::to_char(v) << " "
		  << (int) ((v & 16) ? 1 : 0)
		  << (int) ((v & 8) ? 1 : 0)
		  << (int) ((v & 4) ? 1 : 0)
		  << (int) ((v & 2) ? 1 : 0)
		  << (int) ((v & 1) ? 1 : 0) << "  "
		  << teleprinter::to_char(w) << " "
		  << (int) ((w & 16) ? 1 : 0)
		  << (int) ((w & 8) ? 1 : 0)
		  << (int) ((w & 4) ? 1 : 0)
		  << (int) ((w & 2) ? 1 : 0)
		  << (int) ((w & 1) ? 1 : 0) << "  "
		  << std::setw(2) << (chi_pos[0] + 1) << " "
		  << std::setw(2) << (chi_pos[1] + 1) << " "
		  << std::setw(2) << (chi_pos[2] + 1) << " "
		  << std::setw(2) << (chi_pos[3] + 1) << " "
		  << std::setw(2) << (chi_pos[4] + 1) << "  "
		  << std::setw(2) << (mu_pos[0] + 1) << " "
		  << std::setw(2) << (mu_pos[1] + 1) << "  "
		  << std::setw(2) << (psi_pos[0] + 1) << " "
		  << std::setw(2) << (psi_pos[1] + 1) << " "
		  << std::setw(2) << (psi_pos[2] + 1) << " "
		  << std::setw(2) << (psi_pos[3] + 1) << " "
		  << std::setw(2) << (psi_pos[4] + 1) << "  "
		  << (int) ((chi & 16) ? 1 : 0)
		  << (int) ((chi & 8) ? 1 : 0)
		  << (int) ((chi & 4) ? 1 : 0)
		  << (int) ((chi & 2) ? 1 : 0)
		  << (int) ((chi & 1) ? 1 : 0) << " "
		  << (int) ((psi & 16) ? 1 : 0)
		  << (int) ((psi & 8) ? 1 : 0)
		  << (int) ((psi & 4) ? 1 : 0)
		  << (int) ((psi & 2) ? 1 : 0)
		  << (int) ((psi & 1) ? 1 : 0) << " "
		  << (int) ((mu & 2) ? 1 : 0)
		  << (int) ((mu & 1) ? 1 : 0) << " "
		  << (int) (bm) << " "
		  << (int) (tm)
		  << std::endl;

	plain.push_back(w);

//	show("crypt: ", v, chi_pos, psi_pos, mu_pos);

//	std::cout << teleprinter::to_char(v);
    }

    std::string tout;
    teleprinter::to_string(plain, tout);

    std::cout << tout << std::endl;

    exit(0);

}

