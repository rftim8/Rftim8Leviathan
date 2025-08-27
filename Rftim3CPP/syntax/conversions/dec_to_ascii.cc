#include "dec_to_ascii.hh"

void DecToASCII() {
	for (int i = 0; i <= 255; i++)
	{
		std::cout << (char)i << ' ' << i << std::endl;
	}
}