#include "frontend-add-game.hpp"

void AddGame(std::string filename, std::string game_name){
  FILE* fp = fopen(filename.c_str(), "a");
  char pluh[30] = {0};
  memcpy(pluh, game_name.c_str(), strlen(game_name.c_str()));
  uint32_t always_0 = 0;

  fwrite(pluh, 30, 1, fp);
  fwrite(&always_0, sizeof(uint32_t), 1, fp);
  fclose(fp);
}

Item GetGameData(std::string filename, std::string name){
  FILE* fp = fopen(filename.c_str(), "rb");
  unsigned char* buffer; long int size;
  if(!fp){exit(1);} fseek(fp, 0, SEEK_END); size = ftell(fp); fseek(fp, 0, SEEK_SET);
  buffer = (uint8_t*)malloc(size); if(!buffer) exit(1);
  fread((void*)buffer, size, 1, fp);
  fclose(fp);

  Item i_;
  for(int i = 0; i < size; i+=34){
    char c_name[30] = {0}; memcpy(c_name, buffer+i, 30);
    if(strcmp(c_name, (name.c_str())) == 0){
      memcpy(i_.name, buffer+i, 30);
      uint8_t thrr[4] = {0}; memcpy(thrr, buffer+i+30, 4);
      uint32_t tt =  thrr[0] | (thrr[1] << 8) | (thrr[2] << 16) | (thrr[3] << 24);
      i_.time_played = tt;

      break;
    }
  }
  free(buffer);
  return i_;
}


std::vector<Item> get_all_games(std::string filename){
  std::vector<Item> thebruh;

  // more boilerplate garbage
  FILE* fp = fopen(filename.c_str(), "rb");
  unsigned char* buffer; long int size;
  if(!fp){exit(1);} fseek(fp, 0, SEEK_END); size = ftell(fp); fseek(fp, 0, SEEK_SET);
  buffer = (uint8_t*)malloc(size); if(!buffer) exit(1);
  fread((void*)buffer, size, 1, fp);
  fclose(fp);

  for(int i = 0; i < size; i+=34){
    Item i_2;
    uint8_t temp_time[4];

    memcpy(i_2.name, buffer+i, 30);
    memcpy(temp_time, buffer+i+30, 4);
    
    i_2.time_played = temp_time[0] | (temp_time[1] << 8) | (temp_time[2] << 16) | (temp_time[3] << 24);
    thebruh.push_back(i_2);
  }
  
  return thebruh;
}