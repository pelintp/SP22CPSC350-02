#include "mirror_mode.h"


mirror_mode::mirror_mode() //constructor
{
}
mirror_mode::~mirror_mode() //destructor
{
}


int mirror_mode::mirror_neighbor_number // classic_neighbor_number() return an integer based on neighboor 
(char **grid, //creates the grid
int neighbor_count1, int neighbor_count2, //neighbor_count1 and neighbor_count2 each square's neighbor
int row, int column) // row and column = dimensions
{
  int count = 0;
  cout << "inside mirror func" << endl;

  char** newGrid = new char*[row];

  for (int i = 0; i < row; ++i)
  {
    newGrid[i] = new char[column];
  }


  for (int i = 0; i < row; ++i) // copies org grid to the newGrid
  {
    for (int p = 0; p < column; ++p)
    {
      newGrid[i][p] = grid[i][p];
    }
  }
  cout << "111" << endl;

  if (neighbor_count1 == 0)
  {
        cout << "222" << endl;

    if (neighbor_count2 == 0)
    {
          cout << "333" << endl;

//LEFT TOP CORNER

      if (newGrid[neighbor_count1][neighbor_count2] == 'X')
      {
        count += 3;
      }
      if (newGrid[neighbor_count1][neighbor_count2 + 1] == 'X')
      {
        count += 2;
      }
      if (newGrid[neighbor_count1 + 1][neighbor_count2 + 1] == 'X')
      {
        count++;
      }
      if (newGrid[neighbor_count1 + 1][neighbor_count2] == 'X')
      {
        count += 2;
      }
    }
    else if (neighbor_count2 == column - 1)
    {
          cout << "444" << endl;

//RIGHT TOP  CORNER
      if (newGrid[neighbor_count1][neighbor_count2] == 'X')
      {
        count += 3;
      }
      if (newGrid[neighbor_count1 + 1][neighbor_count2] == 'X')
      {
        count += 2;
      }
      if (newGrid[neighbor_count1 + 1][neighbor_count2 - 1] == 'X')
      {
        count++;
      }
      if (newGrid[neighbor_count1][neighbor_count2 - 1] == 'X')
      {
        count += 2;
      }
    }
    else
    {
          cout << "555" << endl;

//ELSE ITEMS
      if (newGrid[neighbor_count1][neighbor_count2 + 1] == 'X')
      {
        count += 2;
      }
      if (newGrid[neighbor_count1 + 1][neighbor_count2 + 1] == 'X')
      {
        count++;
      }
      if (newGrid[neighbor_count1 + 1][neighbor_count2] == 'X')
      {
        count++;
      }
      if (newGrid[neighbor_count1 + 1][neighbor_count2 - 1] == 'X')
      {
        count++;
      }
      if (newGrid[neighbor_count1][neighbor_count2 - 1] == 'X')
      {
        count += 2;
      }
      if (newGrid[neighbor_count1][neighbor_count2] == 'X')
      {
        count++;
      }
    }
  }
  else if (neighbor_count1 == row - 1)
  {
        cout << "666" << endl;

    if (neighbor_count2 == 0)
    {
//BOTTOM LEFT  CORNER
      if (newGrid[neighbor_count1][neighbor_count2] == 'X')
      {
        count += 3;
      }
      if (newGrid[neighbor_count1 - 1][neighbor_count2] == 'X')
      {
        count += 2;
      }
      if (newGrid[neighbor_count1 - 1][neighbor_count2 + 1] == 'X')
      {
        count++;
      }
      if (newGrid[neighbor_count1][neighbor_count2 + 1] == 'X')
      {
        count += 2;
      }
    }
    else if (neighbor_count2 == column - 1)
    {
//BOTTOM RIGHTT  CORNER
      if (newGrid[neighbor_count1][neighbor_count2] == 'X')
      {
        count += 3;
      }
      if (newGrid[neighbor_count1 - 1][neighbor_count2] == 'X')
      {
        count += 2;
      }
      if (newGrid[neighbor_count1 - 1][neighbor_count2 - 1] == 'X')
      {
        count++;
      }
      if (newGrid[neighbor_count1][neighbor_count2 - 1] == 'X')
      {
        count += 2;
      }
    }
    else
    {
          cout << "777" << endl;

//OTHER ITEMS IN THE ROW
      if (newGrid[neighbor_count1][neighbor_count2] == 'X')
      {
        count++;
      }
      if (newGrid[neighbor_count1][neighbor_count2 + 1] == 'X')
      {
        count += 2;
      }
      if (newGrid[neighbor_count1 - 1][neighbor_count2 + 1] == 'X')
      {
        count++;
      }
      if (newGrid[neighbor_count1 - 1][neighbor_count2] == 'X')
      {
        count++;
      }
      if (newGrid[neighbor_count1 - 1][neighbor_count2 - 1] == 'X')
      {
        count++;
      }
      if (newGrid[neighbor_count1][neighbor_count2 - 1] == 'X')
      {
        count += 2;
      }
    }
  }
  else if (neighbor_count2 == column - 1)
  {
        cout << "888" << endl;

// RIGHT COLUMN
    if (newGrid[neighbor_count1][neighbor_count2] == 'X')
    {
      count++;
    }
    if (newGrid[neighbor_count1 + 1][neighbor_count2] == 'X')
    {
      count += 2;
    }
    if (newGrid[neighbor_count1 + 1][neighbor_count2 - 1] == 'X')
    {
      count++;
    }
    if (newGrid[neighbor_count1][neighbor_count2 - 1] == 'X')
    {
      count++;
    }
    if (newGrid[neighbor_count1 - 1][neighbor_count2 - 1] == 'X')
    {
      count++;
    }
    if (newGrid[neighbor_count1 - 1][neighbor_count2] == 'X')
    {
      count += 2;
    }
  }
  else if (neighbor_count2 == 0)
  {
        cout << "999" << endl;

// LEFT COLUMN
    if (newGrid[neighbor_count1][neighbor_count2] == 'X')
    {
      count++;
    }
    if (newGrid[neighbor_count1 + 1][neighbor_count2] == 'X')
    {
      count += 2;
    }
    if (newGrid[neighbor_count1 + 1][neighbor_count2 + 1] == 'X')
    {
      count++;
    }
    if (newGrid[neighbor_count1][neighbor_count2 + 1] == 'X')
    {
      count++;
    }
    if (newGrid[neighbor_count1 - 1][neighbor_count2 + 1] == 'X')
    {
      count++;
    }
    if (newGrid[neighbor_count1 - 1][neighbor_count2] == 'X')
    {
      count +=2;
    }
  }
  else
  {
        cout << "1000" << endl;
        cout << neighbor_count1 << endl;
        cout << neighbor_count2 << endl;
        cout << newGrid[neighbor_count1 - 1][neighbor_count2] << endl;
        cout << newGrid[neighbor_count1 - 1][neighbor_count2 + 1] << endl;
        cout << newGrid[neighbor_count1][neighbor_count2 + 1] << endl;

//Error happens here
    if (newGrid[neighbor_count1 - 1][neighbor_count2] == 'X')
    {
                cout << "aaa" << endl;

      count += 1;
    }
    if (newGrid[neighbor_count1 - 1][neighbor_count2 + 1] == 'X')
    {
        cout << "bb" << endl;

      count += 1;
    }
    if (newGrid[neighbor_count1][neighbor_count2 + 1] == 'X')
    {
        cout << "cc" << endl;
      count += 1;
    }
    if (newGrid[neighbor_count1 + 1][neighbor_count2 ] == 'X')
    {
        cout << "d" << endl;
      count += 1;
    }
    if (newGrid[neighbor_count1 + 1][neighbor_count2- 1] == 'X')
    {
        cout << "ee" << endl;
      count += 1;
    }
    if (newGrid[neighbor_count1 + 1][neighbor_count2 + 1] == 'X')
    {
        cout << "ff" << endl;
      count += 1;
    }
    if (newGrid[neighbor_count1][neighbor_count2 + 1] == 'X')
    {
        cout << "gg" << endl;
      count += 1;
    }
    if (newGrid[neighbor_count1 + 1][neighbor_count2 + 1] == 'X')
    {
        cout << "hh" << endl;
      count += 1;
    }
    cout << "none" << endl;
  }
  cout << "after mirror func" << endl;
//RETUNS NEIGHBORS
  return count;
}
