#include "classic_mode.h"


classic_mode::classic_mode() //constructor
{
}
classic_mode::~classic_mode() //destructor
{
}

int classic_mode::classic_neighbor_number // classic_neighbor_number() return an integer based on neighboor 
(char **grid, //creates the grid
int row, int column, // row and column = dimensions
int neighbor_count1, int neighbor_count2)  //neighbor_count1 and neighbor_count2 each square's neighbor


{
  int count = 0;
  char** newGrid = new char*[row];

  for (int i = 0; i < row; ++i)
  {
    newGrid[i] = new char[column];
  }

//makes a copy of the original grid to newGrid for to count neighbors
  for (int i = 0; i < row; ++i)
  {
    for (int p = 0; p < column; ++p)
    {
      newGrid[i][p] = grid[i][p];
    }
  }


//TOP LEFT CORNER
  if (neighbor_count1 == 0)
  {
    if (neighbor_count2 == 0)
    {
      if (newGrid[neighbor_count1 + 1][neighbor_count2] == 'X')
      {
        count += 1;
      }
      if (newGrid[neighbor_count1 + 1][neighbor_count2 + 1] == 'X')
      {
        count += 1;
      }
      if (newGrid[neighbor_count1][neighbor_count2 + 1] == 'X')
      {
        count += 1;
      }
    }



//TOP RIGHT CORNER
    else if (neighbor_count2 == column - 1)
    {
      if (newGrid[neighbor_count1][neighbor_count2 - 1] == 'X')
      {
        count += 1;
      }
      if (newGrid[neighbor_count1 + 1][neighbor_count2 - 1] == 'X')
      {
        count += 1;
      }
      if (newGrid[neighbor_count1 + 1][neighbor_count2] == 'X')
      {
        count += 1;
      }
    }


//TOP ROW
    else
    {
      if (newGrid[neighbor_count1][neighbor_count2 - 1] == 'X')
      {
        count += 1;
      }
      if (newGrid[neighbor_count1 + 1][neighbor_count2 - 1] == 'X')
      {
        count += 1;
      }
      if (newGrid[neighbor_count1 + 1][neighbor_count2] == 'X')
      {
        count += 1;
      }
      if (newGrid[neighbor_count1 + 1][neighbor_count2 + 1] == 'X')
      {
        count += 1;
      }
      if (newGrid[neighbor_count1][neighbor_count2 + 1] == 'X')
      {
        count += 1;
      }
    }
  }
  
  
  //BOTTOM LEFT CORNER -- SON SOL ROW
  else if (neighbor_count1 == row - 1)
  {
    if (neighbor_count2 == 0)
    {
      if (newGrid[neighbor_count1 - 1][neighbor_count2] == 'X')
      {
        count += 1;
      }
      if (newGrid[neighbor_count1 - 1][neighbor_count2 + 1] == 'X')
      {
        count += 1;
      }
      if (newGrid[neighbor_count1][neighbor_count2 + 1] == 'X')
      {
        count += 1;
      }
    }


//BOTTOM RIGHT CORNER -- SON SOL ROW
    else if (neighbor_count2 == column - 1)
    {
      if (newGrid[neighbor_count1 - 1][neighbor_count2] == 'X')
      {
        count += 1;
      }
      if (newGrid[neighbor_count1 - 1][neighbor_count2 - 1] == 'X')
      {
        count += 1;
      }
      if (newGrid[neighbor_count1][neighbor_count2 - 1] == 'X')
      {
        count += 1;
      }
    }
    
//BOTTOM ROW
    else
    {
      if (newGrid[neighbor_count1][neighbor_count2 - 1] == 'X')
      {
        count += 1;
      }
      if (newGrid[neighbor_count1 - 1][neighbor_count2 - 1] == 'X')
      {
        count += 1;
      }
      if (newGrid[neighbor_count1 - 1][neighbor_count2] == 'X')
      {
        count += 1;
      }
      if (newGrid[neighbor_count1 - 1][ neighbor_count2 + 1] == 'X')
      {
        count += 1;
      }
      if (newGrid[neighbor_count1][neighbor_count2 + 1] == 'X')
      {
        count += 1;
      }
    }
  }
  
  
  
//LEFT COLUMN
  else if (neighbor_count2 == 0)
  {
    if (newGrid[neighbor_count1 - 1][neighbor_count2] == 'X')
    {
      count += 1;
    }
    if (newGrid[neighbor_count1 - 1][neighbor_count2 + 1] == 'X')
    {
      count += 1;
    }
    if (newGrid[neighbor_count1][neighbor_count2 + 1] == 'X')
    {
      count += 1;
    }
    if (newGrid[neighbor_count1 + 1][neighbor_count2 + 1] == 'X')
    {
      count += 1;
    }
    if (newGrid[neighbor_count1 + 1][neighbor_count2] == 'X')
    {
      count += 1;
    }
  }
  
  
//RIGHT COLUMN
  else if (neighbor_count2 == column - 1)
  {
    if (newGrid[neighbor_count1 - 1][neighbor_count2] == 'X')
    {
      count += 1;
    }
    if (newGrid[neighbor_count1 - 1][neighbor_count2 - 1] == 'X')
    {
      count += 1;
    }
    if (newGrid[neighbor_count1][neighbor_count2 - 1] == 'X')
    {
      count += 1;
    }
    if (newGrid[neighbor_count1 + 1][neighbor_count2 - 1] == 'X')
    {
      count += 1;
    }
    if (newGrid[neighbor_count1 + 1][neighbor_count2] == 'X')
    {
      count += 1;
    }
  }


// OTHER ITEMS -- DISARIDA KALANLAR
  else
  {
    if (newGrid[neighbor_count1 - 1][neighbor_count2] == 'X')
    {
      count += 1;
    }
    if (newGrid[neighbor_count1 - 1][neighbor_count2 + 1] == 'X')
    {
      count += 1;
    }
    if (newGrid[neighbor_count1][neighbor_count2 + 1] == 'X')
    {
      count += 1;
    }
    if (newGrid[neighbor_count1 + 1][neighbor_count2 + 1] == 'X')
    {
      count += 1;
    }
    if (newGrid[neighbor_count1 + 1][neighbor_count2] == 'X')
    {
      count += 1;
    }
    if (newGrid[neighbor_count1 + 1][neighbor_count2 - 1] == 'X')
    {
      count += 1;
    }
    if (newGrid[neighbor_count1][neighbor_count2 - 1] == 'X')
    {
      count += 1;
    }
    if (newGrid[neighbor_count1 - 1][neighbor_count2 - 1] == 'X')
    {
      count += 1;
    }
  }
  
// return number of neighbors
  return count;
}
