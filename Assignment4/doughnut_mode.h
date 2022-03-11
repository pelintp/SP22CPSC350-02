#ifndef DOUGHNUT_MODE_H
#define DOUGHNUT_MODE_H

#include <iostream>

using namespace std;

class doughnut_mode
{
  public:
    doughnut_mode();
    ~doughnut_mode();
    int doughnut_neighbor_number(char **grid, int row, int column, int neighbor_count1, int neighbor_count2);
};

#endif
