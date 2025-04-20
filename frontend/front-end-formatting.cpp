#include "front-end-formatting.hpp"

std::string format(unsigned int seconds){
  char the_variable[256];
  if(seconds < 3600 && seconds >= 60){
    // Seconds
    float idk = ((float)seconds/60.0f - (seconds/60))*60;
    sprintf(the_variable, "%d minutes %d seconds",
      seconds/60, (int)idk);
  } else {
    // TODO: handle hours
    sprintf(the_variable, "%d seconds", seconds);
  }
  return std::string(the_variable);
}