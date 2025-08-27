#include "file_operations.hh"

static void ReadCharFormFile();
static void ReadFile();
static void WriteToFile();

void FileOperations()
{
	// ReadCharFormFile();
	ReadFile();
	// WriteToFile();
}

static void ReadCharFormFile()
{
	std::ifstream f1;
	f1.open("Dummy.txt");

	char c;
	f1.get(c);

	std::cout << c << std::endl;
	f1.close();
}

static void ReadFile()
{
	std::ifstream f1;
	f1.open("Dummy.txt");

	char c;
	while (!f1.eof())
	{
		f1.get(c);
		std::cout << c;
	}
	f1.close();
}

static void WriteToFile()
{
	std::ofstream f1;
	f1.open("Dummy.txt");

	f1 << "This is a new text!";
	f1.close();
}