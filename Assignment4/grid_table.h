#ifndef GRID_TABLE_H
#define GRID_TABLE_H

#include <iostream>
#include <string>
#include <fstream>
#include "classic_mode.h"
#include "doughnut_mode.h"
#include "mirror_mode.h"

using namespace std;

class grid_table : public classic_mode, public doughnut_mode, public mirror_mode
{
  public:
    grid_table();
    ~grid_table();
    string getFileName();
    char** grid;
    int row;
    int column;
    void file_grid(string inputFile);
    void random_grid();
    void start();
    void start_game();
    void start_classic_mode(string pause, char** rid);
    void start_doughnut_mode(string pause, char** grid);
    void start_mirror_mode(string pause, char** grid);
  private:
    float population_density;
    float generate_num;
    bool invalid_population_density;
    bool empty_world = false;
    bool stabilzed_world = false;
    int generation_number = 0;
    int zero_count = 0;
    string game_mode;
    string random_file_selection;
    string pause;
    string fileName;
    string exit_program = "";
};

#endif