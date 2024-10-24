#include <iostream>

int main()
{
  //  std::cout << "\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb" << std::endl;
    for (unsigned char c = 0xB3; c < 0xE0; ++c) {
        std::cout << (char)c << " ";
    }
    
}
