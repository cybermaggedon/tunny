
#include <colossus/tunny.h>

#include <string>
#include <iostream>

const std::string khcipher = "J3KTIKK4PUDUFI3OV-3+JGJKXJ.KQOK.FFCQSENTACBEXPFKEIAHQCOGTL/JTDQY3AQRKFYAF/GFS+UQ-++4ENHD4SRWWXFIBKWV+BYQJHQW-F+ENHZBPYLMW.O.DY-MBLLYJL4Q4AUD3VIKE+LM-DH.UVW4Q+WLUQEDTQUOKYFL4D+E-DVPNPI3SN3YZVHM3DTM4G3HF3TGDT.PXTFFKM3G...QDHH./V+JZOVLUET+EBUQLA/PVUCHQFY+UIU4CIAPQXB4ZGT/HDBCS3BOG+VJQQCBK-LQ4J+UKTACFKPZFWOSPDTA.AYWLE+IQOLDSMAV-HXQY/.FTSBCIJO-KX4O++AOA3.H/BMCREHFKWAZ+WGDX.NISP+G+SDSYZFJL3ZBHT./YFTXU4RQCVR/LZ4ZNXVT4XYAX3LLYODOU-/BC/LOCXZSW4XLA43XHTJBUWPG/XUE3NISQKSA+UGA.JZI3-CF4BO3+-M//EM/G/F434GXF/JHXZEAOWAJI+NNUQ/-4SDFAO.43J-VVQJI-SDLHL4LZW.YZ4UY.LACWDFIR3VEP-Y-BCZ+X3WC/DE+KQIVZPC.AS-YQ3ZGIZFSFCQEACRLTDWEZEYGL+LTA/FWVYU-MELWVNZLBZBSNQ-YTZ../VQAVTNI.TELPGAELALPZDRMSLGVV-DPVZQRNZJBI3AE/RV.KRYBOCLK4E3QPXCD-IRGGRGOKSVRCPFOW3JSY+NY.H/CZF3NKKORMU4ASSJXXUGHE3NTZIMKEPHEUHCCHHFVQZMVPWT3QPSZXRNQQYPEMUFX+J+YB.QRTEEXA/AOMGJKH4QXBBRQSNIMR-YAQURKFNGHLZMMYWYRVPGZPW4MQ-HVEZMT.HAFVPR3DYEOPCEMVFD4EIF4GG3I/YFYG34RETRJBCVTOJFMF4RE+ITZFVVTU.XB4EE+LNMHPKQPIG3+JFTIO3L.WLZHHQDP4VMOIKSLXDHE3XBCGOQYUZASFPKPS--A/Y4OLYZW-U-3JMBYG.QGMAXQ/E4PSSAFOTTUS-3OLRTJEKANSJHTS.SRZHYDMJLBKK-L3QUWMVPKVKBKPPME3XM4IZE.LGRXXVY/FITBIBYM/SOQUCEOGAIVYZVMPZMVROJBJ+.LTMJLBQQGOAIIV/FCQGXV+Y/OKUIABBG.QMA+XNINOPULKMJYM4-FDG+-RJTR.KEQRCOC-KT4Y3KMFWP.MSPRW/+VLFOSKQTQA.SYB.LM+IZYIMDG+I4MOE/W.C/3JYTD.XGGEMY+DUILVBED3MFEBGN/SRVASN/NDUYEXGAZWQPD3QWWP--JGQXDLH+IIH+Q.4HKJQKNPQW.PGZAJAYUNAAXOTMESZ.ARLDOY.XP3-/SRN3-KY3HSOA-O.Y-Z.LXUH+/XMUOPA+RXN.GAJKG/JPWE--JBY+HXT4D+Q/HF4/E/ONBQLV/VL4O3J/IHNKG+/LYMU+OHEH/C/LZQF/OJROO4TAFRLQEFK/YM.A+GE.COEQNO4OLBURXZ.MSJUSSW4LFB4/KLSYUVXJYCHGPU.+3ZCLG.B/AZ4N+JTDDELAKZP-OYVKF-LXIOMKIPDPE.Z-PK/3USK+VYQRMDJMLIZS+BEYYLXGB./Y4BIOZDP/C+/D/3G.3EH-+3CNKAYPIPTICZPZOVOCEDHEINJDABY3RU+QU-4VESQT/UJGEYPXLGPMVWG3TNHW4RQBX+4BDAWFJG/-FRANU+AG+XQOSH/IUZEF/F4UR4XGYT3-SWC-IT34+USAXAOB+NY+WATFJIZ.4C+USZYZOBD+-AQPKYQYJIMG3VIQ/S4Z3YI4LGB/3UDYZ+4DVBWEXJ/ZWXNKKAMDEKQMEUXAYKWSST/GW+SCLJJSTVTAQO-KB4FM+HV3AZDECZD+AKZTPBLF+VM/WIO/HCDKMWAIMNSLQRTDG.+F+NITD-BCOCXMRR/XBRZW4CZ4NGGZEN4DDCQCFH.G.B-WHDRRGI.IELL.KSU3B/L344ZFLB+EYBW/-/PINTSXAFQWQEEXYONHEJVL3WFAH3NENYECIWKLRH.A+B-NZ3.RS//MYH.HNOAWR.4+Q";

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

// ----------------------------------------------------------------------------

    tpchar_t prev = 0;

    for(int i = 0; i < cipher.size(); i++) {
	tpchar_t v;

	t.tick(prev);

	prev = cipher[i];

	v = cipher[i];
	v ^= t.get_chi();
	v ^= t.get_psi();

	std::vector<unsigned int> chi_pos, psi_pos, mu_pos;
	t.get_chi_positions(chi_pos);
	t.get_psi_positions(psi_pos);
	t.get_mu_positions(mu_pos);

//	show("crypt: ", v, chi_pos, psi_pos, mu_pos);

	std::cout << teleprinter::to_char(v);
    }

/*
    std::vector<tpchar_t> plain;
    std::string out;

    t.decrypt(cipher, plain);
    teleprinter::to_string(plain, out);

    std::cout << out << std::endl;
*/

    return 0;

}

