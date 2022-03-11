#include "doughnut_mode.h"

doughnut_mode::doughnut_mode()//constructor
{
}
doughnut_mode::~doughnut_mode()//destructor
{
}


int doughnut_mode::doughnut_neighbor_number // doughnut_neighbor_number() return an integer based on neighboor 
(char **grid, //creates the grid
int row, int column, // row and column = dimensions
int neighbor_count1, int neighbor_count2) //neighbor_count1 and neighbor_count2 each square's neighbor



{
  int count = 0;
  char** newGridCopy = new char*[row];

  for (int i = 0; i < row; ++i)
  {
    newGridCopy[i] = new char[column];
  }



//makes a copy of the original grid to newGridCopy for to count neighbors
  for (int i = 0; i < row; ++i)
  {
    for (int p = 0; p < column; ++p)
    {
      newGridCopy[i][p] = grid[i][p];
    }
  }
  if (neighbor_count1 == 0)
  {
    if (neighbor_count2 == 0)
    {
        
        
        
//LEFT CORNER GRID
      if (newGridCopy[row - 1][neighbor_count2] == 'X')
      {
        count++;
      }
      if (newGridCopy[row - 1][neighbor_count2 + 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1][column - 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1 + 1][column - 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1 + 1][neighbor_count2] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1 + 1][neighbor_count2 + 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1][neighbor_count2 + 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[row - 1][column - 1] == 'X')
      {
        count++;
      }
    }
    else if (neighbor_count2 == column - 1)
    {
        
        
//RIGHT CORNER GRID
      if (newGridCopy[row - 1][neighbor_count2] == 'X')
      {
        count++;
      }
      if (newGridCopy[row - 1][neighbor_count2 - 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1][0] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1 + 1][0] == 'X')
      {
        count++;
      }
      if (newGridCopy[row - 1][0] == 'X')
      {
        count++;
      }
      if(newGridCopy[neighbor_count1][neighbor_count2 - 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1 + 1][neighbor_count2 - 1] == 'X')
      {
        count++;
      }
      if(newGridCopy[neighbor_count1 + 1][neighbor_count2] == 'X')
      {
        count++;
      }
    }
    
//ELSE CELLS FROM TOP OF THE GRID
    else
    {
      if (newGridCopy[neighbor_count1][neighbor_count2 - 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1 + 1][neighbor_count2 - 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1 + 1][neighbor_count2] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1 + 1][neighbor_count2 + 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1][neighbor_count2 + 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[row - 1][neighbor_count2 - 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[row - 1][neighbor_count2] == 'X')
      {
        count++;
      }
      if (newGridCopy[row - 1][neighbor_count2 + 1] == 'X')
      {
        count++;
      }
    }
  }
  
//LAST ROW LEFT CORNER GRID
  else if (neighbor_count1 == row - 1)
  {
    if (neighbor_count2 == 0)
    {
      if (newGridCopy[neighbor_count1][neighbor_count2 + 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1 - 1][neighbor_count2] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1 - 1][neighbor_count2 + 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1 - 1][column - 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1][column - 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[0][neighbor_count2] == 'X')
      {
        count++;
      }
      if (newGridCopy[0][neighbor_count2 + 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[0][column - 1] == 'X')
      {
        count++;
      }
    }
//LAST ROW RIGHT CORNER GRID
    else if (neighbor_count2 == column - 1)
    {
      if (newGridCopy[neighbor_count1][neighbor_count2 - 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1 - 1][neighbor_count2 - 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1 - 1][neighbor_count2] == 'X')
      {
        count++;
      }
      if (newGridCopy[0][neighbor_count2] == 'X')
      {
        count++;
      }
      if (newGridCopy[0][neighbor_count2 - 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[0][0] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1 - 1][0] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1][0] == 'X')
      {
        count++;
      }
    }

//ELSE CELLS FROM BOTTOM OF THE GRID
    else
    {
      if (newGridCopy[neighbor_count1][neighbor_count2 + 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1 - 1][ neighbor_count2 + 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1 - 1][neighbor_count2] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1 - 1][neighbor_count2 - 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[neighbor_count1][neighbor_count2 - 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[0][neighbor_count2 - 1] == 'X')
      {
        count++;
      }
      if (newGridCopy[0][neighbor_count2] == 'X')
      {
        count++;
      }
      if (newGridCopy[0][neighbor_count2 + 1] == 'X')
      {
        count++;
      }
    }
  }
  
  //RIGHT COLUMN GRID
  else if (neighbor_count2 == column - 1)
  {
    if (newGridCopy[neighbor_count1 + 1][neighbor_count2] == 'X')
    {
      count++;
    }
    if (newGridCopy[neighbor_count1 + 1][neighbor_count2 - 1] == 'X')
    {
      count++;
    }
    if (newGridCopy[neighbor_count1][neighbor_count2 - 1] == 'X')
    {
      count++;
    }
    if (newGridCopy[neighbor_count1 - 1][neighbor_count2 - 1] == 'X')
    {
      count++;
    }
    if (newGridCopy[neighbor_count1 - 1][neighbor_count2] == 'X')
    {
      count++;
    }
    if (newGridCopy[neighbor_count1][0] == 'X')
    {
      count++;
    }
    if (newGridCopy[neighbor_count1 + 1][0] == 'X')
    {
      count++;
    }
    if (newGridCopy[neighbor_count1 - 1][0] == 'X')
    {
      count++;
    }
  }
  
  //LEFT COLUMN GRID
  else if (neighbor_count2 == 0)
  {
    if (newGridCopy[neighbor_count1 - 1][neighbor_count2] == 'X')
    {
      count++;
    }
    if (newGridCopy[neighbor_count1 - 1][neighbor_count2 + 1] == 'X')
    {
      count++;
    }
    if (newGridCopy[neighbor_count1][neighbor_count2 + 1] == 'X')
    {
      count++;
    }
    if (newGridCopy[neighbor_count1 + 1][neighbor_count2 + 1] == 'X')
    {
      count++;
    }
    if (newGridCopy[neighbor_count1 + 1][neighbor_count2] == 'X')
    {
      count++;
    }
    if (newGridCopy[neighbor_count1][column - 1] == 'X')
    {
      count++;
    }
    if (newGridCopy[neighbor_count1 + 1][column - 1] == 'X')
    {
      count++;
    }
    if (newGridCopy[neighbor_count1 - 1][column - 1] == 'X')
    {
      count++;
    }
  }
  else
  {
      
//OTHER ITEMS -- (DISARIDA KALANLAR)
    if (newGridCopy[neighbor_count1 - 1][neighbor_count2] == 'X')
    {
      count++;
    }
    if (newGridCopy[neighbor_count1 - 1][neighbor_count2 + 1] == 'X')
    {
      count++;
    }
    if (newGridCopy[neighbor_count1][neighbor_count2 + 1] == 'X')
    {
      count++;
    }
    if (newGridCopy[neighbor_count1 + 1][neighbor_count2 + 1] == 'X')
    {
      count++;
    }
    if (newGridCopy[neighbor_count1 + 1][neighbor_count2] == 'X')
    {
      count++;
    }
    if (newGridCopy[neighbor_count1 + 1][neighbor_count2 - 1] == 'X')
    {
      count++;
    }
    if (newGridCopy[neighbor_count1][neighbor_count2 - 1] == 'X')
    {
      count++;
    }
    if (newGridCopy[neighbor_count1 - 1][neighbor_count2 - 1] == 'X')
    {
      count++;
    }
  }
// return number of neighbors
  return count;
}