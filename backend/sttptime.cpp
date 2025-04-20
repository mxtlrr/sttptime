#include <iostream>

#include "sttp-format.hpp"
#include "monitor-games.hpp"

int main(void){
  printf("STTPTime backend starting!\n");
  Items i("test.log");

  while(true){
    for(Item i_ : i.items){
      if(IsAppRunning(std::string(i_.name))){
        i_.time_played++;
        i.UpdateTime(i_.name, i_.time_played);
        break;
      }
    }
    i.UpdateVector();
    Sleep(1000);
  }
}