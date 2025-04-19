#pragma once

#include <iostream>
#include <assert.h>
#include <cstdint>
#include <cstring>
#include <vector>

typedef struct Item {
  char name[30];
  uint32_t time_played;
} Item;

void AddGame(std::string filename, std::string game_name);
Item GetGameData(std::string filename, std::string name);