#pragma once

#include <iostream>
#include <assert.h>
#include <cstdint>
#include <cstring>
#include <vector>

typedef struct Item {
  char name[30];
  uint32_t time_played; // seconds
  uint16_t offset;
} Item;

class Items {
  public:
    std::vector<Item> items;
    std::string filename;

    Items(std::string filename);
    void UpdateVector(void);
    void UpdateTime(std::string name, uint32_t new_time);
    void AddGame(std::string name, uint32_t time = 0);

    friend std::ostream& operator<<(std::ostream &os, Items const &m){
      for(Item i : m.items){
        std::cout << "Items[" << i.offset << "]: " << i.name
                  << " - " << i.time_played << "s of playtime"
                  << std::endl;
      }
      return os;
    }
};