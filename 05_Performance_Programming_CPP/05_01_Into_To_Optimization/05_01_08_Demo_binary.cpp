#include <iostream>
#include <bitset>
#include <cstring>

int main()
{
  std::cout << "Representations of the number 97\n";

  // Character 'a' represented in binary
  std::cout << "char: " << std::bitset<8>('a') << "\n";

  // Float 97.0 represented with 32 bits
  float example = 97.0;
  char binary[sizeof(float)];

  memcpy(binary, &example, sizeof(float));
  std::cout << "32-bit float 97.0:  " << "\n"; 
  for(int i = 0; i < sizeof(float); i++)
  {
    std::cout << std::bitset<sizeof(char)*8>(binary[i]);
  }
  std::cout << std::endl;
  
  return 0;
}