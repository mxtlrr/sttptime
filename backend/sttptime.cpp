#include <iostream>

#include "sttp-format.hpp"

int main(void){
  Items i("test.log");
  i.AddGame("CrazyCattle3D.exe", 1200);
  std::cout << i;
}