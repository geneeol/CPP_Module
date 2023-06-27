#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (char *p = argv[i]; *p; p++)
				std::cout << (char)std::toupper(*p);
		}
	}
	std::cout << std::endl;
	return (0);
}