#include "base_change.hh"

static void conv0(int, int);

void BaseChange()
{
	int n, b;
	std::cout << "n = ";
	std::cin >> n;
	std::cout << "b = ";
	std::cin >> b;

	conv0(n, b);
}

static void conv0(int x, int b)
{
	if (x)
	{
		conv0(x / b, b);
		std::cout << x % b;
	}
}