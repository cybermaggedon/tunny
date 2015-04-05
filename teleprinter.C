
#include <vector>
#include <colossus/teleprinter.h>

tpchar_t teleprinter::from_char(unsigned char f)
{

    static unsigned char chrs[256];

    static bool init = false;

    if (!init) {
	for(int i = 0; i < 256; i++) chrs[i] = 0;
	chrs['/'] = 0x00;
	chrs['T'] = 0x01;
	chrs['3'] = 0x02;
	chrs['O'] = 0x03;
	chrs['9'] = 0x04;
	chrs['.'] = 0x04;
	chrs['H'] = 0x05;
	chrs['N'] = 0x06;
	chrs['M'] = 0x07;
	chrs['4'] = 0x08;
	chrs['L'] = 0x09;
	chrs['R'] = 0x0a;
	chrs['G'] = 0x0b;
	chrs['I'] = 0x0c;
	chrs['P'] = 0x0d;
	chrs['C'] = 0x0e;
	chrs['V'] = 0x0f;
	chrs['E'] = 0x10;
	chrs['Z'] = 0x11;
	chrs['D'] = 0x12;
	chrs['B'] = 0x13;
	chrs['Y'] = 0x15;
	chrs['S'] = 0x14;
	chrs['F'] = 0x16;
	chrs['X'] = 0x17;
	chrs['A'] = 0x18;
	chrs['W'] = 0x19;
	chrs['J'] = 0x1a;
	chrs['5'] = 0x1b;
	chrs['+'] = 0x1b;
	chrs['U'] = 0x1c;
	chrs['Q'] = 0x1d;
	chrs['K'] = 0x1e;
	chrs['8'] = 0x1f;
	chrs['-'] = 0x1f;
	init = true;
    }

    return chrs[f];

}
 
unsigned char teleprinter::to_char(tpchar_t f)
{

    static unsigned char chrs[32];

    static bool init = false;

    if (!init) {
	chrs[0x00] = '/';
	chrs[0x01] = 'T';
	chrs[0x02] = '3';
	chrs[0x03] = 'O';
	chrs[0x04] = '.';
	chrs[0x05] = 'H';
	chrs[0x06] = 'N';
	chrs[0x07] = 'M';
	chrs[0x08] = '4';
	chrs[0x09] = 'L';
	chrs[0x0a] = 'R';
	chrs[0x0b] = 'G';
	chrs[0x0c] = 'I';
	chrs[0x0d] = 'P';
	chrs[0x0e] = 'C';
	chrs[0x0f] = 'V';
	chrs[0x10] = 'E';
	chrs[0x11] = 'Z';
	chrs[0x12] = 'D';
	chrs[0x13] = 'B';
	chrs[0x14] = 'S';
	chrs[0x15] = 'Y';
	chrs[0x16] = 'F';
	chrs[0x17] = 'X';
	chrs[0x18] = 'A';
	chrs[0x19] = 'W';
	chrs[0x1a] = 'J';
	chrs[0x1b] = '+';
	chrs[0x1c] = 'U';
	chrs[0x1d] = 'Q';
	chrs[0x1e] = 'K';
	chrs[0x1f] = '-';
	init = true;
    }

    return chrs[f];

}

