// Lab 13, The "Geometry Homework" Program
// Programmer: Fernando Ian Patricio
// Editor(s) used: Code:Blocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using std::ios;
using std::ostream;

#include <iomanip>
using std::setprecision; // output::control decimal places

#include "GeometryHomework.h"

const double PI = 3.14159; // global constant

// Print Square data to console
void Square::output( ostream& out ) const
{
  out << reset;
  out << "SQUARE\r\nSide=" << x;
  out << set;
  out << "\r\nArea=" << x * x;
  out << "\r\nPerimeter=" << 4 * x;
} // end function Square::output

// Print Square data to xls file
void Square::xls( ostream& out ) const
{
  out << reset;
  out << "SQUARE" << "\t" << x << "\t\t\t\t\t";
  out << set;
  out <<  x * x << "\t" << 4 * x;
} // end function Square::xls

// Print Rectangle data to console
void comsc::Rectangle::output( ostream& out ) const
{
  out << reset;
  out << "RECTANGLE\r\nLength=" << x << " Width=" << y;
  out << set;
  out << "\r\nArea=" << x * y;
  out << "\r\nPerimeter=" << (2 * y) + (2 * x);
} // end function Rectangle::output

// Print Rectangle data to xls file
void comsc::Rectangle::xls( ostream& out ) const
{
  out << reset;
  out << "RECTANGLE" << "\t\t\t" << x << "\t" << y << "\t\t";
  out << set;
  out << x * y << "\t" << (2 * y) + (2 * x);
} // end function Rectangle::xls

// Print Circle data to console
void Circle::output( ostream& out ) const
{
  out << reset;
  out << "CIRCLE\r\nRadius=" << x;
  out << set;
  out << "\r\nArea=" << PI * x * x;
  out << "\r\nPerimeter=" << 2 * PI * x;
} // end function Circle::output

// Print Circle data to xls file
void Circle::xls( ostream& out ) const
{
  out << reset;
  out << "CIRCLE" << "\t\t" << x << "\t\t\t\t";
  out << set;
  out << PI * x * x << "\t" << 2 * PI * x;
} // end function Circle::xls

// Print Cube data to console
void Cube::output( ostream& out ) const
{
  out << reset;
  out << "CUBE\r\nSide=" << x;
  out << set;
  out << "\r\nSurface Area=" << 6 * x * x;
  out << "\r\nVolume=" << x * x * x;
} // end function Cube::output

// Print Cube data to xls file
void Cube::xls( ostream& out ) const
{
  out << reset;
  out << "CUBE" << "\t" << x << "\t\t\t\t\t\t\t";
  out << set;
  out << 6 * x * x << "\t" << x * x * x;
} // end function Cube::xls

// Print Prism data to console
void Prism::output( ostream& out ) const
{
  out << reset;
  out << "PRISM\r\nLength=" << x << " Width=" << y << " Height=" << z;
  out << set;
  out << "\r\nSurface Area=" << 2 * ((y * x) + (z * x) + (z * y));
  out << "\r\nVolume=" << x * y * z;
} // end function Prism::output

// Print Prism data to xls file
void Prism::xls( ostream& out ) const
{
  out << reset;
  out << "PRISM" << "\t\t\t" << x << "\t" << y << "\t" << z << "\t\t\t";
  out << set;
  out << 2 * ((y * x) + (z * x) + (z * y)) << "\t" << x * y * z;
} // end function Prism::xls

// Print Cylinder data to console
void Cylinder::output( ostream& out ) const
{
  out << reset;
  out << "CYLINDER\r\nRadius=" << x << " Height=" << y;
  out << set;
  out << "\r\nSurface Area=" << (2 * PI * x * y) + (2 * PI * x * x);
  out << "\r\nVolume=" << PI * x * x * y;
} // end Cylinder::output

// Print Cylinder data to xls file
void Cylinder::xls( ostream& out ) const
{
  out << reset;
  out << "CYLINDER" << "\t\t" << x << "\t\t\t" << y << "\t" << "\t\t";
  out << set;
  out << (2 * PI * x * y) + (2 * PI * x * x) << "\t" << PI * x * x * y;
} // end Cylinder::xls

// stand-alone, programmer-defined output stream manipulator
ostream& reset(ostream& out)
{
  out.unsetf(ios::fixed|ios::showpoint);
  out << setprecision(6);
  return out;
} // end function reset

// stand-alone, programmer-defined output stream manipulator
ostream& set(ostream& out)
{
  out.setf(ios::fixed|ios::showpoint);
  out << setprecision(2);
  return out;
} // end function sett

// overloaded stream insertion operator
ostream& operator<< ( ostream& out, const Shape* s )
{
  s->output(out);
  return out;
}  // end overloaded operator <<



