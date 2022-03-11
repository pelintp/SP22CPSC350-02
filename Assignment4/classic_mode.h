#ifndef CLASSIC_MODE_H
#define CLASSIC_MODE_H
#include <iostream>

using namespace std;
class classic_mode
{
  public:
    classic_mode();
    ~classic_mode();
    int classic_neighbor_number(char **grid, int neighbor_count1, int neighbor_count2, int row, int column);
};

#endif
