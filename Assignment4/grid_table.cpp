#include "grid_table.h"

// constructor
grid_table::grid_table()
{
  row = 0;
  column = 0;
  population_density = 0.0;
}

//destructor
grid_table::~grid_table()
{
  delete grid;
}

void grid_table::start() //starts the program
{
  while(true)
  {
    cout << endl;
    cout << "Do you wish to provide a MAP-FILE or RANDOM assignment? Type= RANDOM OR FILE"<< endl;

    cin >> random_file_selection;
    if ((random_file_selection == "RANDOM") || (random_file_selection == "Random") || (random_file_selection == "random") || (random_file_selection == "FILE") || (random_file_selection == "File") || (random_file_selection == "file"))
    {
        if ((random_file_selection == "RANDOM") || (random_file_selection == "Random") || (random_file_selection == "random"))
        {
          random_grid();
        }
        else if ((random_file_selection == "FILE") || (random_file_selection == "File") || (random_file_selection == "file"))
        {
          cout << "Enter a file name: " << endl;
          cin >> fileName;

          ifstream fileStream;

          fileStream.open(fileName);
          if (!fileStream.is_open())
          {
//exit the file
            cout << "Cannot open file. Exiting." << endl;
            exit(EXIT_FAILURE);
          }
          fileStream.close();
          file_grid(fileName); 
        }
    }
    else
    {
      continue;
    }

    cout << "Select a game mode between (classic, doughnut, or mirror)" << endl;
    cin >> game_mode;

    if ((game_mode == "CLASSIC")||(game_mode == "Classic")|| (game_mode == "classic") 
    || (game_mode == "DOUGHNUT")||(game_mode == "Doughnut") || (game_mode == "doughnut")
    || (game_mode == "MIRROR")||(game_mode == "Mirror") || (game_mode == "mirror"))
    {
    }
    else
    {
        // ADD ERROR STOP THE CODE
      continue;
    }

    cout << "Do you want to pause between generations? if yes type pause. Do you want to output to a file? if yes press any key" << endl;
    cin >> pause;

    if ((pause == "PAUSE") || (pause == "Pause") || (pause == "pause"))
    {
    }

    break;
  }
}

// WILL ALLOW USER TO SELECT THE GAME MODE
void grid_table::start_game()
{
  if (game_mode == "CLASSIC" || game_mode == "Classic" || game_mode == "classic")
  {
    start_classic_mode(pause, grid);
  }
  else if (game_mode == "DOUGHNUT" ||game_mode == "Doughnut" || game_mode == "doughnut")
  {
    start_doughnut_mode(pause, grid);
  }
  else if (game_mode == "MIRROR" ||game_mode == "Mirror" || game_mode == "mirror")
  {
    start_mirror_mode(pause, grid);
  }
}

//creates a random grid with the input
void grid_table::random_grid()
{
  cout << "Enter the height of the grid." << endl;
  cin >> row;

  cout << "Enter the width of the grid." << endl;
  cin >> column;

  invalid_population_density = false;

  while (!invalid_population_density)
  {
    cout << "Enter the population density between 0.0 and 1.0. (HAS TO  BE IN DECIMAL FORMAT)" << endl;
    cin >> population_density;

    if ((population_density <= 0.0) || (population_density >= 1.0 ))
    {
      invalid_population_density = false;
    }
    else
    {
      invalid_population_density = true;
    }
  }

  grid = new char*[row];

  for (int i = 0; i < row; ++i)
  {
    grid[i] = new char[column];
  }

  for (int i = 0; i < row; ++i)
  {
    for (int p = 0; p < column; ++p)
    {
      generate_num = rand() % 100;
      generate_num /= 100;

      if (population_density <= generate_num)
      {
        grid[i][p] = 'X';
      }
      else
      {
        grid[i][p] = '-';
      }
    }
  }
}

//char** grid -- height & width
void grid_table::file_grid(string inputFile)
{
  ifstream filestream;
  string currentSentence = "";
  int lineCounter = 0;
  int z = 0;

  filestream.open(inputFile);

  if (!filestream.is_open())
  {
//exit it error
    exit(EXIT_FAILURE);
  }

  while ((!filestream.eof()) && (!filestream.fail()))
  {
    string temp = "";

    if (lineCounter == 0)
    {
      getline(filestream, temp);
      row = stoi(temp);
    }

    else if (lineCounter == 1)
    {
      getline(filestream, temp);
      column = stoi(temp);

      grid = new char*[row];

      for (int i = 0; i < row; ++i)
      {
        grid[i] = new char[column];
      }
    }

    else
    {
      getline(filestream, temp);

      for (int i = 0; i < temp.size(); ++i)
      {
        if (temp[i] == '-')
        {
          grid[z][i] = '-';
        }
        else if (temp[i] == 'X')
        {
          grid[z][i] = 'X';
        }
      }
      z++;
    }
    ++lineCounter;
  }
  filestream.close();
}

//file has to be in the same folder
//asks the user for an output file
string grid_table::getFileName()
{
    cout << "START OF FILE CODE" << endl;
  string fileName;
  cout << "Enter a textfile name to output." << endl;
  cin >> fileName;

    cout << "right before ifstream" << endl;
  ifstream fileStream;
    cout << "right after ifstream" << endl;

  fileStream.open(fileName);
    cout << "right after file open" << endl;

  if (!fileStream.is_open())
  {
//exit error
    cout << "FAILURE IN FILE OPENING" << endl;
    exit(EXIT_FAILURE);
  }
  cout << "END OF FILE CODE" << endl;
  fileStream.close();
    cout << "END OF FILE CLOSED!!!" << endl;

  return fileName;
}

// starts mirror mode 
//asks if the user want pause
void grid_table::start_mirror_mode(string pause, char** grid)
{
    cout << "TESTING, START OF MIRROR" << endl;
  grid_table *use_it = new grid_table();

// creates copy_of_grid  to count cell neighbors
  char **copy_of_grid = new char*[row];

  for (int i = 0; i < row; ++i)
  {
    copy_of_grid[i] = new char[column];
  }

// grid holds values --sondan bir onceki valueleri tutuyor
  char **same_grids = new char*[row];

  for (int i = 0; i < row; ++i)
  {
    same_grids[i] = new char[column];
  }

  for (int i = 0; i < row; ++i)
  {
    for (int p = 0; p < column; ++p)
    {
      copy_of_grid[i][p] = grid[i][p];
      same_grids[i][p] = grid[i][p];
    }
  }

//OUTPUT FILE
  string fileName = use_it->getFileName();
  cout << "MOOOO" << endl;

  ofstream outFS;
  outFS.open(fileName);
    cout << "1" << endl;

  
  mirror_mode m;
//WHILE LOOP FOR IF THE GRID IS EMPTY OR STABILEZED
  while ((empty_world == false) || (stabilzed_world == false))
  {
      cout << "INSIDE LOOP 1" << endl;
    for (int i = 0; i < row; ++i)
    {
        cout << "INSIDE LOOP 2" << endl;
      for (int p = 0; p < column; ++p)
      {
          cout << "INSIDE LOOP 3" << endl;
        int number_of_neigh = 0;
// MIRROR TO CHECKING CELL NEIGHBORS
//COUNTING THE EMPTY CELLS
            cout << "loop3 bTESTTESTTEST" << endl;

        number_of_neigh = m.mirror_neighbor_number(copy_of_grid, row-1, column-1, i, p);
                    cout << "loop3 BEFORE " << endl;

        if (number_of_neigh <= 1)
        {
            cout << "loop3 if1" << endl;
          grid[i][p] = '-';
          zero_count++;
          
        }
        else if (number_of_neigh == 2)
        {
                        cout << "loop3 if2" << endl;

          if (copy_of_grid[i][p] == '-')
          {
            grid[i][p] = '-';
            zero_count++;
          }
          else if (copy_of_grid[i][p] == 'X')
          {
            grid[i][p] = 'X';
          }
        }
        else if (number_of_neigh == 3)
        {
            cout << "loop3 if3" << endl;

          if (copy_of_grid[i][p] == '-')
          {
            grid[i][p] = 'X';
          }
          else if (copy_of_grid[i][p] == 'X')
          {
            grid[i][p] = 'X';
          }
        }
        else if (number_of_neigh >= 4)
        {
            cout << "loop3 if4" << endl;

          grid[i][p] = '-';
          zero_count++;
        }
      }
    }
    cout << "after LOOP 3" << endl;

//looks at the back and forth movement -- sondan iki oncekini check ediyor 
    if (generation_number % 2 == 0)
    {
      for (int i = 0; i < row; ++i)
      {
        for (int p = 0; p < column; ++p)
        {
          same_grids[i][p] = copy_of_grid[i][p];
        }
      }
    }
    cout << "DEEPER LOOP 3" << endl;

    generation_number++;

//outputing the file
    outFS << endl;
    cout << endl;
    outFS << "Generation Number: " << generation_number << endl;
    cout << "Generation Number: " << generation_number << endl;
    outFS << endl;
    cout << endl;

    for (int i = 0; i < row; ++i)
    {
      for (int p = 0; p < column; ++p)
      {
        cout << copy_of_grid[i][p] << " ";
        outFS << copy_of_grid[i][p] << " ";
      }
      cout << endl;
      outFS << endl;
    }

// if it selected as pause it will pause between generations
    if (pause == "PAUSE" || pause == "Pause" || pause == "pause")
    {
      string pauseStr = "";
      cout << "Press a key to continue." << endl;
      cin >> pauseStr;
    }

    int cells_on_grid = 0;
    int totalNumCells = row * column;



// counts the number of cells equal between grid and copy_of_grid
    for (int i = 0; i < row; ++i)
    {
      for (int p = 0; p < column; ++p)
      {
        if (grid[i][p] == copy_of_grid[i][p])
        {
          cells_on_grid++;
        }
      }
    }

// counts the number of cells equal between on going generation and second the last -- iki oncekini
    int count_cells = 0;
    for (int i = 0; i < row; ++i)
    {
      for (int p = 0; p < column; ++p)
      {
        if (grid[i][p] == same_grids[i][p])
        {
          count_cells++;
        }
      }
    }
    cout << "MIDWAY" << endl;

// exits when all cells are equal

    if (count_cells == totalNumCells)
    {
      stabilzed_world = true;
      outFS << "World is stabilzed." << endl;
      cout << "World is stabilzed. Press any key to EXIT." << endl;
      cin >> exit_program;
      break;
    }

// exits when all cells are equal continuously --ardisik
    if (cells_on_grid == totalNumCells)
    {
      stabilzed_world = true;
      outFS << "World is stabilzed." << endl;
      cout << "World is stabilzed. Press any key to EXIT." << endl;
      cin >> exit_program;
      break;
    }

// exit when cells are empty
    if (zero_count == totalNumCells)
    {
      empty_world = true;
      outFS << "World is empty." << endl;
      cout << "World is empty. Press any key to EXIT." << endl;
      cin >> exit_program;
      break;
    }

// make changes from grid to copy_of_grid 
    for (int i = 0; i < row; ++i)
    {
      for (int p = 0; p < column; ++p)
      {
        copy_of_grid[i][p] = grid[i][p];
      }
    }
  }
  cout << "TEST, END OF MIRROR" << endl;

  outFS.close();
}

// starts doughnut and asks if they want pause
// copy_of_grid counts neighbors then  makes changes on the original grid 1
void grid_table::start_doughnut_mode(string pause, char** grid)
{
  grid_table *use_it = new grid_table();

//changes 1
  char **copy_of_grid = new char*[row];

  for (int i = 0; i < row; ++i)
  {
    copy_of_grid[i] = new char[column];
  }

//checks for stab
  char **same_grids = new char*[row];

  for (int i = 0; i < row; ++i)
  {
    same_grids[i] = new char[column];
  }

  for (int i = 0; i < row; ++i)
  {
    for (int p = 0; p < column; ++p)
    {
      copy_of_grid[i][p] = grid[i][p];
      same_grids[i][p] = grid[i][p];
    }
  }

//OUTPUT FILE
  string fileName = use_it->getFileName();

  ofstream outFS;
  outFS.open(fileName);

//counts neigboors
//checks stabilization

  while ((empty_world == false) || (stabilzed_world == false))
  {
    for (int i = 0; i < row; ++i)
    {
      for (int p = 0; p < column; ++p)
      {
        int number_of_neigh = 0;
        
// sends from copy to the original grid 
// count all empty cells
        number_of_neigh = use_it->doughnut_neighbor_number(copy_of_grid, row, column, i, p);
        if (number_of_neigh <= 1)
        {
          grid[i][p] = '-';
          zero_count++;
        }
        else if (number_of_neigh == 2)
        {
          if (copy_of_grid[i][p] == '-')
          {
            grid[i][p] = '-';
            zero_count++;
          }
          else if (copy_of_grid[i][p] == 'X')
          {
            grid[i][p] = 'X';
          }
        }
        else if (number_of_neigh == 3)
        {
          if (copy_of_grid[i][p] == '-')
          {
            grid[i][p] = 'X';
          }
          else if (copy_of_grid[i][p] == 'X')
          {
            grid[i][p] = 'X';
          }
        }
        else if (number_of_neigh >= 4)
        {
          grid[i][p] = '-';
          zero_count++;
        }
      }
    }

//checks stab
    if (generation_number % 2 == 0)
    {
      for (int i = 0; i < row; ++i)
      {
        for (int p = 0; p < column; ++p)
        {
          same_grids[i][p] = copy_of_grid[i][p];
        }
      }
    }

    generation_number++;

//OUTPUT FILE
    outFS << endl;
    cout << endl;
    outFS << "Generation Number: " << generation_number << endl;
    cout << "Generation Number: " << generation_number << endl;
    outFS << endl;
    cout << endl;

    for (int i = 0; i < row; ++i)
    {
      for (int p = 0; p < column; ++p)
      {
        cout << copy_of_grid[i][p] << " ";
        outFS << copy_of_grid[i][p] << " ";
      }
      cout << endl;
      outFS << endl;
    }

//PAUSES WILL BE ASKED AS  OTHERS
    if (pause == "PAUSE" || pause == "pause" || pause == "Pause")
    {
      string pauseStr = "";
      cout << "Press a key to continue" << endl;
      cin >> pauseStr;
    }

    int cells_on_grid = 0;
    int totalNumCells = row * column;

// counts board and copy_of_grid  equal nums
    for (int i = 0; i < row; ++i)
    {
      for (int p = 0; p < column; ++p)
      {
        if (grid[i][p] == copy_of_grid[i][p])
        {
          cells_on_grid++;
        }
      }
    }

// checks the grid and same_grids same cells holding second the last generation --sondan iki onceki
    int count_cells = 0;
    for (int i = 0; i < row; ++i)
    {
      for (int p = 0; p < column; ++p)
      {
        if (grid[i][p] == same_grids[i][p])
        {
          count_cells++;
        }
      }
    }

//checks stab
    if (count_cells == totalNumCells)
    {
      stabilzed_world = true;
      outFS << "World is stabilzed" << endl;
      cout << "World is stabilzed. Press any key to EXIT." << endl;
      cin >> exit_program;
      break;
    }

// exits when all cells are equal continuously --ardisik
    if (cells_on_grid == totalNumCells)
    {
      stabilzed_world = true;
      outFS << "World is stabilzed" << endl;
      cout << "World is stabilzed. Press any key to EXIT." << endl;
      cin >> exit_program;
      break;
    }

// exit when cells are empty
    if (zero_count == totalNumCells)
    {
      empty_world = true;
      outFS << "World is empty." << endl;
      cout << "World is empty. Press any key to EXIT." << endl;
      cin >> exit_program;
      break;
    }

// tput changes grom grid to copy_of_grid
    for (int i = 0; i < row; ++i)
    {
      for (int p = 0; p < column; ++p)
      {
        copy_of_grid[i][p] = grid[i][p];
      }
    }
  }

  outFS.close();
}

// starts classic game
void grid_table::start_classic_mode(string pause, char** grid)
{
    grid_table *file = new grid_table();

// changes
    char **newGridCopy = new char*[row];

    for (int i = 0; i < row; ++i)
    {
      newGridCopy[i] = new char[column];
    }

//for stab
    char **same_grids = new char*[row];

    for (int i = 0; i < row; ++i)
    {
      same_grids[i] = new char[column];
    }

//makes a copy of the original grid
    for (int i = 0; i < row; ++i)
    {
      for (int p = 0; p < column; ++p)
      {
        newGridCopy[i][p] = grid[i][p];
        same_grids[i][p] = grid[i][p];
      }
    }

// OUTPUT FILE
    string fileName = file->getFileName();

    ofstream outFS;
    outFS.open(fileName);

//counts neighbor  and updates grid
    while ((empty_world == false) || (stabilzed_world == false))
    {
      for (int i = 0; i < row; ++i)
      {
        for (int p = 0; p < column; ++p)
        {
          int number_of_neigh = 0;
// counts neighboor - uses classic mode
          number_of_neigh = file->classic_neighbor_number(newGridCopy, row, column, i, p);

// add one to  zero count if the cell is empty
          if (number_of_neigh <= 1)
          {
            grid[i][p] = '-';
            zero_count++;
          }
          else if (number_of_neigh == 2)
          {
            if (newGridCopy[i][p] == '-')
            {
              grid[i][p] = '-';
              zero_count++;
            }
            else if (newGridCopy[i][p] == 'X')
            {
              grid[i][p] = 'X';
            }
          }
          else if (number_of_neigh == 3)
          {
            if (newGridCopy[i][p] == '-')
            {
              grid[i][p] = 'X';
            }
            else if (newGridCopy[i][p] == 'X')
            {
              grid[i][p] = 'X';
            }
          }
          else if (number_of_neigh >= 4)
          {
            grid[i][p] = '-';
            zero_count++;
          }
        }
      }

// updates same_grids() 
//checks stab

      if (generation_number % 2 == 0)
      {
        for (int i = 0; i < row; ++i)
        {
          for (int p = 0; p < column; ++p)
          {
            same_grids[i][p] = newGridCopy[i][p];
          }
        }
      }

      generation_number++;

// ouputting to file
      outFS << endl;
      cout << endl;
      outFS << "Generation Number: " << generation_number << endl;
      cout << "Generation Number: " << generation_number << endl;
      outFS << endl;
      cout << endl;

      for (int i = 0; i < row; ++i)
      {
        for (int p = 0; p < column; ++p)
        {
          cout << newGridCopy[i][p] << " ";
          outFS << newGridCopy[i][p] << " ";
        }
        cout << endl;
        outFS << endl;
      }
//makes pauses
      if (pause == "PAUSE" ||pause == "Pause" || pause == "pause")
      {
        string pauseStr = "";
        cout << "Press a key to continue." << endl;
        cin >> pauseStr;
      }

      int cells_on_grid = 0;
      int totalNumCells = row * column;

//if grid and new grid copy are same both stabs
      for (int i = 0; i < row; ++i)
      {
        for (int p = 0; p < column; ++p)
        {
          if (grid[i][p] == newGridCopy[i][p])
          {
            cells_on_grid++;
          }
        }
      }

//if on the same  location increment
      int count_cells = 0;
      for (int i = 0; i < row; ++i)
      {
        for (int p = 0; p < column; ++p)
        {
          if (grid[i][p] == same_grids[i][p])
          {
            count_cells++;
          }
        }
      }

// if same stab
      if (count_cells == totalNumCells)
      {
        stabilzed_world = true;
        outFS << "World is stabilzed." << endl;
        cout << "World is stabilzed. Press any key to EXIT." << endl;
        cin >> exit_program;
        break;
      }

// exits when all cells are equal continuously --ardisik
      if (cells_on_grid == totalNumCells)
      {
        stabilzed_world = true;
        outFS << "World is stabilzed_world." << endl;
        cout << "World is stabilzed. Press any key to EXIT." << endl;
        cin >> exit_program;
        break;
      }

//if empty exit
      if (zero_count == totalNumCells)
      {
        empty_world = true;
        outFS << "World is empty." << endl;
        cout << "World is empty. Press any key to EXIT." << endl;
        cin >> exit_program;
        break;
      }

// put changes from newGridCopy to grid
      for (int i = 0; i < row; ++i)
      {
        for (int p = 0; p < column; ++p)
        {
          newGridCopy[i][p] = grid[i][p];
        }
      }
    }
    

    outFS.close();
}
