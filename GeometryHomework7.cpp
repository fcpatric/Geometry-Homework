// Lab 12, The "Geometry Homework" Program
// Programmer: Fernando Ian Patricio
// Editor(s) used: Code:Blocks
// Compiler(s) used: GNU GCC Compiler

#include <cstring> // strcmp

#include <fstream>
using std::ifstream; // read in file
using std::ofstream; // write in file

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector; // store shapes

#include "GeometryHomework.h"

// Global constants
const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 4;
const char* const DELIMITER = " ";

int main()
{
  // print my name and this assignment's title
  cout << "Lab 11, The \"Geometry Homework\" Program \n";
  cout << "Programmer: Fernando Ian Patricio\n";
  cout << "Editor(s) used: Code:Blocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // create a file-reading object
  ifstream fin;
  fin.open("geo.txt"); // open a txt file
  if (!fin.good()) // check if the file opened successfully
    return 1;

  // create an vector of generic, variable mutating pointers
  vector< const Shape* > shapes;

  // Loop to read each line of the file
  while (!fin.eof())
  {
    int n = 0; // parse the line into blank-delimited tokens

    // read an entire line into memory
    char buf[MAX_CHARS_PER_LINE];
    fin.getline(buf, MAX_CHARS_PER_LINE);

    // array to store memory addresses of the tokens in buf
    const char* token[MAX_TOKENS_PER_LINE] = {}; // initialize to 0

    // parse the line
    token[0] = strtok(buf, DELIMITER); // first token

    if (token[0]) // zero if line is blank
    {
      for (n = 1; n < MAX_TOKENS_PER_LINE; n++)
      {
        token[n] = strtok(0, DELIMITER); // subsequent tokens
        if (!token[n]) break; // no more tokens
      } // end for loop for reading one line
    } // exit if file not found

    // Loop to store data
    for ( int i = 0; i < n; i++ ) // n = #of tokens
    {
      if ( strcmp(*token, "SQUARE") == 0 )
      {
        const Square* const s = new Square(token); // Dynamically allocate Square object
        shapes.push_back(s); // store s in the vector
        break;
      } // end if square

      if ( strcmp(*token, "RECTANGLE") == 0 )
      {
        const Rectangle* const r = new Rectangle(token); // Dynamically allocate Rectangle object
        shapes.push_back(r); // store r in the vector
        break;
      } // end if rectangle

      if ( strcmp(*token, "CIRCLE") == 0 )
      {
        const Circle* const cir = new Circle(token); // Dynamically allocate Circle object
        shapes.push_back(cir); // store cir in the vector
        break;
      } // end if circle

      if ( strcmp(*token, "CUBE") == 0 )
      {
        const Cube* const cub = new Cube(token); // Dynamically allocate Cube object
        shapes.push_back(cub); // store cub in the vector
        break;
      } // end if cube

      if ( strcmp(*token, "PRISM") == 0 )
      {
        const Prism* const p = new Prism(token); // Dynamically allocate Prism object
        shapes.push_back(p); // store p in the vector
        break;
      } // end if prism

      if ( strcmp(*token, "CYLINDER") == 0 )
      {
        const Cylinder* const cyl = new Cylinder(token); // Dynamically allocate Cylinder object
        shapes.push_back(cyl); // store cyl in the vector
        break;
      } // end if prism

      // invalid objects
      else
      {
        cout << *token << " invalid object\n";
        break;
      } // end if invalid object
    } // end for loop for storing
  } // end while looe for reading

  // Close txt file
  fin.close();

  // For loop to output data on console
  for( unsigned int j = 0; j < shapes.size(); j++ )
  {
     cout << shapes[j];
     cout << endl;
  } // end for loop for output to console

  // create a file-writing object
  ofstream fout;
  fout.open("geo.xls"); // open xls file
  if (!fout.good()) // check to see if the file opened successfully
    return 1;

  // For xls file output
  fout << "Shape \tside \tradius \tlength \twidth \theight \tarea \tperimeter \tsurface area \tvolume\n";

  // For loop  to output data to the xls file
  for( unsigned int k = 0; k < shapes.size(); k++ )
  {
    shapes[k]->xls(fout);
    fout << endl;
  } // end for loop for output to xls file

  // Close xls file
  fout.close();

  // deallocate all dynamically-allocated memory in a loop
  for( unsigned int l = 0; l < shapes.size(); l++ )
  {
    delete shapes[l];
  } // end for loop for deletion
} // end int main






