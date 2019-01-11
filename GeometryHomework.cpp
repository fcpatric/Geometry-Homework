// Lab 12, The "Geometry Homework" Program
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
  out << "SQUARE side=" << x;
  out << set;
  out << " area=" << x * x;
  out << " perimeter=" << 4 * x;
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
void Rectangle::output( ostream& out ) const
{
  out << reset;
  out << "RECTANGLE length=" << x << " width=" << y;
  out << set;
  out << " area=" << x * y;
  out << " perimeter=" << (2 * y) + (2 * x);
} // end function Rectangle::output

// Print Rectangle data to xls file
void Rectangle::xls( ostream& out ) const
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
  out << "CIRCLE radius=" << x;
  out << set;
  out << " area=" << PI * x * x;
  out << " perimeter=" << 2 * PI * x;
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
  out << "CUBE side=" << x;
  out << set;
  out << " surface area=" << 6 * x * x;
  out << " volume=" << x * x * x;
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
  out << "PRISM length=" << x << " width=" << y << " height=" << z;
  out << set;
  out << " surface area=" << 2 * ((y * x) + (z * x) + (z * y));
  out << " volume=" << x * y * z;
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
  out << "CYLINDER radius=" << x << " height=" << y;
  out << set;
  out << " surface area=" << (2 * PI * x * y) + (2 * PI * x * x);
  out << " volume=" << PI * x * x * y;
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

