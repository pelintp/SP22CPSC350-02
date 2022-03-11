#ifndef MIRROR_MODE_H
#define MIRROR_MODE_H

#include <iostream>

using namespace std;

class mirror_mode
{
  public:
    mirror_mode();
    ~mirror_mode();
    int mirror_neighbor_number(char **grid, int row, int column , int neighbor_count1, int neighbor_count2);
};

#endif