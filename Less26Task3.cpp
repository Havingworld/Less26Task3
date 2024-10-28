#include <iostream>

int main()
{
	int nDspLgt{ 0 }, nDspHgt{ 0 };

	std::cout << "Enter display lenght: ";
	std::cin >> nDspLgt;
	std::cout << "Enter display haight: ";
	std::cin >> nDspHgt;

	std::cout << (char)0xC9;
	for (int i = 0; i < nDspLgt; i++) {
		std::cout << (char)0xCD;
	}
	std::cout << (char)0xBB << std::endl;

	for (int i = 0; i < nDspHgt; i++) {
		std::cout << (char)0xBA;
		for (int j = 0; j < nDspLgt; j++) {
			std::cout << " ";
		}
		std::cout << (char)0xBA << std::endl;
	}

	std::cout << (char)0xC8;
	for (int i = 0; i < nDspLgt; i++) {
		std::cout << (char)0xCD;
	}
	std::cout << (char)0xBC << std::endl;
}
