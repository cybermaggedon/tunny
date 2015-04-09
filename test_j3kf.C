
#include <colossus/tunny.h>

#include <string>
#include <iostream>

const std::string khcipher = " J3KF+LXT/.+YTMLE/RFVC-SE///4GYX3Q.Z3GVWKWDVAPURPYL/.UYAI.EOW3ZBVVAQRTO/PACJ.NLVLZYYNTU.IDCPKTEZOSWCOBNWFJ+UAKE+WU-JMWYWLXRM+M/HV+TVTC-FOGN3QZG4J.VLM/KK+OEC/YIWTSZUDTSY+3LCCHZADQ-3VBXKEOCSO/+ZBFN34-F.+4UVFVLIP4KFGRBFIVFFJX/FKFSHJ.VUJVWXE+LFAICDYX3EZD33U+GSOGXPAXHTJSNUQI+PXS3JRG+-U+YZITF/SM4LIDPSYMVJM/BL/YHDGBG/UI+EM.JEMX.YQNUWTLAUCLUSDMZGXCQ3CPPCCYLTJC4KXB--G4VGQ4J.EYTEVSG33DVLVPDGNOGAJOUWGFY4KGO-4+IRKDPGDHGBQLFSS/YDP/FM-/BANLERZEMT.U3XZA43RGYD+-J4VYRTONRYF/OI4Y+I3LXUFAHGRT.RXCO3HKCQIML.VHVIGHBWBTU3RZFN.J.WGNLSGLYBJT+TPM-RHHMXTNDSVUO3W/4ORZ4UY.LA-XZYVLCZROMPM3RYSLUD-SNQQA+RK/UV4K/GOSSMJRGIZYPO+BEEB+OEWAWKYXW.-NKUQERUM-PA4WFNKU-Q-LNC.D-A3C.FB.RFOGZHUWTEAYB3HNHCEW.N33QEEVUEC3OOR4BRNLH/IF3+DJJ3S3J4XA+Z3SMT/K4L-IDLQWCLMQ3TO3PNYVCGZCXUMSSBH.BWMGGTIYSC/UBX/PE+3IZZ.Z/CCWLSL+4/4+IET/ELBCBDAM4ELKDAGB3O.3J+IEQQJ.U.VSAQSAYZAU+3YOZWPPPV/YOVOE/P/E4UOZYK4PE3A.ETZGFBCZE.4WA3PSDR3XMLJLH+S3UWOA.T-RID-MA.CVZGLNYK4U.HBPSA+3U+BLSGS/FNRXMOMEBBABIPOAGDWA-4T/B.L.HDSAJE.HE-4FZW+SDBAYCNBTEODDALCMIG-QNM+-PEFC+ABNQ-MVT3-GHKAN/ENZLPMJRVRB+4NBCRTFDVNLRTPIGIEZGSPUXMW3WJQTOEV+WA-HJZLX-JQID-X++FFGKCTO.3.F+JIISVTXKC+..YM/SOQUIAS-IAGJJPRYLLT.EJBJAMRP+MS-ZRUVLBBE-UNYQGBBHEB+QCHYYHVN.NHKS-YG3BNZKQJBO-FQ.SZB/JRFILGUZUZVCCVGULEKU4/HRBGYIZVLCM3/ONJ-OBIRSCT+IZCB-TTZMDQWQUCIVTGTTYNEOTTORM-FSKS3WJWL/ZXOCOCYGC.BRIRKXK.FLJUSP/-G.WP.MMVHBYREWQZZAN/BKSEYDBGXAUV+NUKUKIKIGS+VO-4EY/GWI+SGJOJCBYGGMY4+/EMGULCSC-Y+CXLIECYC-+-ZXHSPOTFGFDWIFT-4XXDDLMMKT433WH/BX-OILWDJC/FFE-ZYH3C4GI4T/3KUJQ4YNBQWXWB-RM.Q3GG/4Z-AIGW4GYYEBXRJHXQA..-.G/3W/-LVS+4GS-+FRYIOFYGUK-FEYA4J-ZB-MSPAM/WLLJ3GFMJP/GGF-C+O-KQ.K4PWVL+3O.LX4TUD+Y+QOO3GTJT+.MR-4JSRXD-X4SCIDIVLCDEGSOZOGWXQZOZ.3PPQ4ZYXKL+QETCM/3/--CHG4+W.BNHTB+Z-NZCO+QEB+-/FNJ+NSHTO+CW.CM/VHIM-S.3VAFDJ3MEH.G+NQFDCUSK+MCKDCEC-TFWSYBQSWE4UOQOXY-E.ESE4OLJQOBUQZUSLRWV-AVOYX3CKS3ZFUAQAWESYMXQV/4MOXORAVKOIELRXCSR4EU/KEFDQWQ-BWEXGALS/.JLQ/CEKT-4C+TWDNGST-UQ-ERBP.YZ-ZH/Q3ITMN-O3P/JBEVZUOY4CTNY4PKCB3YIW/+BOKDEZE.VCTROQDTAXI3VKGYQVOKSCXPDDAD4DLTELK.GDDLTRPXORSFTDOGB.-NQJHNM/4/JOTIVGOQF+FC.GDX4DMT.UBRV ";

const std::string hx1 = "..xxxx.xx....xxx..x.x...x.xxxx.x.xxx...x.";
const std::string hx2 = "..xx.xx..x..xx..xxxx.x...xxx..x";
const std::string hx3 = ".xx.xx..xx...xx...xxx.x..xx..";
const std::string hx4 = "..x....xxx.xx..xxxx..x..xx";
const std::string hx5 = "..x.x..x.xxxx....xx..xx";

const std::string hm1 = "...xxxx.xxx.xxxx.xxxx.xxxx.xxxx.xxx....xx.xxxx.xxx.xxxx.xxxx.";
const std::string hm2 = "....x.x...x.x.x...x.x.x...x.x.x.x.x.x";

const std::string hs1 = "x.xx.x..x.x.x.x.x.xxxx.x.x.xxx..x.x.xx...x.";
const std::string hs2 = "x..x.x.x.xx.x....x.xxx.x.xx.x..x.x.x..xxx.x.xx.";
const std::string hs3 = "x.x.x..xx.x.x..x.x.xxx..x.x.x.xx.x.x....xxx..x.x.x.";
//FIXME: Added a dit.
const std::string hs4 = ".x.x.x.x.x.x..x.xx.x.x..x.x.xx.x...xx.x.x.xxxx...xx..";
const std::string hs5 = ".x..x.xx...x.x.xxxx..xx.x.x.x.x.x.x.x.x...x.xx.x..x.xx...xx";

void show(const std::string& pref, tpchar_t v,
	  const std::vector<unsigned int>& chi_pos,
	  const std::vector<unsigned int>& psi_pos,
	  const std::vector<unsigned int>& mu_pos)
{

    std::cout << pref
	      << "'" << teleprinter::to_char(v) << "' "
	      << (int) ((v & 16) ? 1 : 0)
	      << (int) ((v & 8) ? 1 : 0)
	      << (int) ((v & 4) ? 1 : 0)
	      << (int) ((v & 2) ? 1 : 0)
	      << (int) ((v & 1) ? 1 : 0)
	      << "     " << (int) v
	      << "          c" 
	      << chi_pos[0] + 1 << ","
	      << chi_pos[1] + 1 << ","
	      << chi_pos[2] + 1 << ","
	      << chi_pos[3] + 1 << ","
	      << chi_pos[4] + 1 << " s"

	      << psi_pos[0] + 1 << ","
	      << psi_pos[1] + 1 << ","
	      << psi_pos[2] + 1 << ","
	      << psi_pos[3] + 1 << ","
	      << psi_pos[4] + 1 << " m"
	
	      << mu_pos[0] + 1 << ","
	      << mu_pos[1] + 1
	
	      << std::endl;
	}

int main()
{

    tunny t;

    std::vector<tpchar_t> cipher;
    teleprinter::from_string(khcipher, cipher);

    t.set_chi_pins(hx1, hx2, hx3, hx4, hx5);
    t.set_mu_pins(hm1, hm2);
    t.set_psi_pins(hs1, hs2, hs3, hs4, hs5);

    t.set_chi_positions(31, 1, 1, 15, 1);
    t.set_mu_positions(59, 26);
    t.set_psi_positions(32, 36, 11, 9, 43);
    
    t.set_limitation(tunny::x2lim);

// ----------------------------------------------------------------------------

    tpchar_t prev_in = 0;
    tpchar_t prev_out = 0;

    for(int i = 0; i < cipher.size(); i++) {
	tpchar_t v;

	t.step(prev_in, prev_out);

	prev_in = cipher[i];

	v = cipher[i];
	v ^= t.get_chi();
	v ^= t.get_psi();

	prev_out = v;

	std::vector<unsigned int> chi_pos, psi_pos, mu_pos;
	t.get_chi_positions(chi_pos);
	t.get_psi_positions(psi_pos);
	t.get_mu_positions(mu_pos);

//	show("crypt: ", v, chi_pos, psi_pos, mu_pos);

	std::cout << teleprinter::to_char(v);
    }

    std::cout << std::endl;

/*
    std::vector<tpchar_t> plain;
    std::string out;

    t.decrypt(cipher, plain);
    teleprinter::to_string(plain, out);

    std::cout << out << std::endl;
*/

    return 0;

}

