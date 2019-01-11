// Lab 12, The "Geometry Homework" Program
// Programmer: Fernando Ian Patricio
// Editor(s) used: Code:Blocks
// Compiler(s) used: GNU GCC Compiler

#ifndef GeoemetryHomework_h
#define GeoemetryHomework_h

#include <cstdlib> // atof

#include <iostream>
using std::ostream;

// abstract class Shape
class Shape
{
  protected:
    const double x, y, z; // 3 generic dimensions

  public:
    Shape( const char* const t[] ) : x( t[1] ? atof(t[1]) : 0 ), y ( t[2] ? atof(t[2]) : 0 ), z ( t[3] ? atof(t[3]) : 0 ) {}; // initialize the generic dimensions
    virtual void output( ostream& ) const = 0; // pure virtual function console output
    virtual void xls( ostream& ) const = 0; // pure virtual function file output
    virtual ~Shape() {}; // empty virtual destructors->output(out)
}; // end class Shape

struct Square : public Shape
{
  Square( const char* const t[] ) : Shape( t ) {}; // Constructor to initialize
  void output( ostream& ) const; // Accessor to ouput to  console
  void xls( ostream& ) const; // Accessor to output to xls file
}; // end struct Square

struct Rectangle : public Shape
{
  Rectangle( const char* const t[] ) : Shape( t ) {}; // Constructor to initialize
  void output( ostream& ) const; // Accessor to output to console
  void xls( ostream& ) const; // Accessor to output to xls
}; // end struct Rectangle

struct Circle : public Shape
{
  Circle( const char* const t[] ) : Shape( t ) {}; // Constructor to initialize
  void output( ostream& ) const; // Accessor to output to console
  void xls( ostream& ) const; // Accessor to output to xls
}; // end struct Circle

struct Cube : public Square
{
  Cube( const char* const t[] ) : Square( t )  {}; // Constructor to initialize
  void output( ostream& ) const; // Accessor to output to console
  void xls( ostream& ) const; // Accessor to output to xls
}; // end struct Cube

struct Prism : public Rectangle
{
  Prism( const char* const t[] ) : Rectangle ( t ) {}; // Constructor to initialize
  void output( ostream& ) const; // Accessor to output to console
  void xls( ostream& ) const; // Accessor to output to xls
}; // end struct Prism

struct Cylinder : public Circle
{
  Cylinder( const char* const t[] ) : Circle ( t ) {}; // Constructor to initialize
  void output( ostream& ) const; // Accessor to output to console
  void xls( ostream& ) const; // Accessor to output to xls
}; // end struct Cylinder

// stand-alone prototypes
ostream& reset( ostream& );
ostream& set( ostream& );

// overloaded stream insertion operator
ostream& operator<< ( ostream&, const Shape* );

#endif


