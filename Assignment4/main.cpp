#include <iostream>
#include "grid_table.h"

using namespace std;

int main(int argc, char** argv)
{
  grid_table *test = new grid_table();
  test->start();
  test->start_game();
  test->~grid_table();
  return 0;
}