#include "sttp-format.hpp"

Items::Items(std::string filename){
  this->filename = filename;

  FILE* fp = fopen(filename.c_str(), "rb"); unsigned char* buffer; long int size;
  if(!fp){exit(1);} fseek(fp, 0, SEEK_END); size = ftell(fp); fseek(fp, 0, SEEK_SET);
  buffer = (uint8_t*)malloc(size); if(!buffer) exit(1);
  fread((void*)buffer, size, 1, fp);
  fclose(fp);

  // Every 34 bytes is a new file, so file length should be divisible by 34
  assert((size % 34 == 0));

  for(int i = 0; i < size; i+=34){
    Item i_;
    memcpy(i_.name, buffer+i, 30);
    uint8_t thrr[4] = {0}; memcpy(thrr, buffer+i+30, 4);
    uint32_t tt =  thrr[0] | (thrr[1] << 8) | (thrr[2] << 16) | (thrr[3] << 24);
    
    i_.time_played = tt; i_.offset = (i/34);
    items.push_back(i_);
  }

  free(buffer);
}

void Items::UpdateTime(std::string name, uint32_t new_time){
  // Find offset
  uint16_t offset = 0;
  for(Item i : this->items){
    if(strcmp(i.name, name.c_str()) == 0){
      offset = i.offset;
      break;
    }
  }
  
  FILE* fp = fopen(this->filename.c_str(), "rb+");
  fseek(fp, (offset*34)+30, SEEK_SET);
  fwrite(&new_time, sizeof(uint32_t), 1, fp);

  fclose(fp);
}

void Items::UpdateVector(void){
  // Clear out vector
  this->items.clear();

  FILE* fp = fopen(this->filename.c_str(), "rb"); unsigned char* buffer; long int size;
  if(!fp){exit(1);} fseek(fp, 0, SEEK_END); size = ftell(fp); fseek(fp, 0, SEEK_SET);
  buffer = (uint8_t*)malloc(size); if(!buffer) exit(1);
  fread((void*)buffer, size, 1, fp);
  fclose(fp);


  for(int i = 0; i < size; i+=34){
    Item i_;
    memcpy(i_.name, buffer+i, 30);
    uint8_t thrr[4] = {0}; memcpy(thrr, buffer+i+30, 4);
    uint32_t tt =  thrr[0] | (thrr[1] << 8) | (thrr[2] << 16) | (thrr[3] << 24);
    
    i_.time_played = tt; i_.offset = (i/34);
    this->items.push_back(i_);
  }

  free(buffer);
}

void Items::AddGame(std::string name, uint32_t time){
  FILE* fp = fopen(this->filename.c_str(), "a");
  char pluh[30] = {0}; memcpy(pluh, name.c_str(), strlen(name.c_str()));
  fwrite(pluh, 30, 1, fp); fwrite(&time, sizeof(uint32_t), 1, fp);
  fclose(fp);
}