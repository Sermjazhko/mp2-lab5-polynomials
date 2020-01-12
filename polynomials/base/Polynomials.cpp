#include <iostream>
#include <string>
#include <cmath>
#include "Polynomials.h"
#include "List.h"

using namespace std;
string Polynomials::add(string help)
{
  Polynomials obj(help);
  List result_pol;
  int _size = polynomial.get_size();
  for (int i = 0; i < _size; i++)
    result_pol.add_elem(polynomial.get_elem_deg(i), polynomial.get_elem_con(i));
  _size = obj.get_size();
  for (int i = 0; i < _size; i++)
    result_pol.add_elem(obj.get_monom_deg(i), obj.get_monom_con(i));
  result_pol.sorting();

  string object = transformation(result_pol);
  return object;
}
string Polynomials::mult(string help)
{
  Polynomials obj(help);
  List result_pol;
  int _size = polynomial.get_size();
  int _size_obj = obj.get_size();
  for (int i = 0; i < _size; i++)
    for (int k = 0; k < _size_obj; k++)
      result_pol.add_elem((polynomial.get_elem_deg(i) + obj.get_monom_deg(k)), (polynomial.get_elem_con(i) * obj.get_monom_con(k)));
  result_pol.sorting();
  string object = transformation(result_pol);
  return object;
}
string Polynomials::mult_const(double constant)
{
  List result_pol;
  if (constant != 0)
  {
    int _size = polynomial.get_size();
    for (int i = 0; i < _size; i++)
      result_pol.add_elem(polynomial.get_elem_deg(i), constant * polynomial.get_elem_con(i));
  }
  result_pol.sorting();
  string object = transformation(result_pol);
  return object;
}
double Polynomials::point_calcul(double x, double y, double z)
{
  polynomial.sorting();
  int _size = polynomial.get_size();
  double result = 0;
  int deg_x = 0;
  int deg_y = 0;
  int deg_z = 0;
  int point = 100;
  for (int i = 0; i < _size; i++)
  {
    deg_x = polynomial.get_elem_deg(i) / (point*point);
    deg_y = (polynomial.get_elem_deg(i) % (point*point)) / point;
    deg_z = polynomial.get_elem_deg(i) % point;
    result = result + polynomial.get_elem_con(i) * pow(x, deg_x)* pow(y, deg_y) * pow(z, deg_z);
  }
  return result;
}
string Polynomials::transformation(List &obj)                                                   
{
  //obj.output();
  string result = "0";
  if (!obj.empty())
  {
    int _size = obj.get_size();
    int point = 100;
    int deg = 0;
    double con = 0;
    int help = 0;
    result = "";
    for (int i = 0; i < _size; i++)
    {
      con = obj.get_elem_con(i);
      if (con != 1 && con != -1)
      {
        if (con > 0 && i != 0)
        {
          result = result + '+' + to_string(con);
          int _size_ = result.length();
          result.erase(_size_ - 4, _size_);
        }
        else
        {
          result = result + to_string(con);
          int _size_ = result.length();
          result.erase(_size_ - 4, _size_);
        }
      }
      else
        if (con > 0 && i != 0)
          result = result + '+';
        else
        {
          if (con > 0)
            result = result;
          else
            result = result + '-';
        }
      deg = obj.get_elem_deg(i) / (point*point);
      if (deg != 0)
        if (deg == 1)
          result = result + 'x';
        else
          result = result + 'x' + to_string(deg);
      help = obj.get_elem_deg(i);
      help = (help - deg * point*point) / point;
      if (help != 0)
        if (help == 1)
          result = result + 'y';
        else
          result = result + 'y' + to_string(help);
      deg = obj.get_elem_deg(i) % point;
      if (deg != 0)
        if (deg == 1)
          result = result + 'z';
        else
          result = result + 'z' + to_string(deg);
    }
  }
  return result;
}
int Polynomials::get_size()
{
  return polynomial.get_size();
}
int Polynomials::get_monom_deg(int pos)
{
  return polynomial.get_elem_deg(pos);
}
double Polynomials::get_monom_con(int pos)
{
  return polynomial.get_elem_con(pos);
}
int Polynomials::check_number(char str)
{
  char A[10] = { '0','1','2','3','4','5','6','7','8','9' };  
  char B[2] = { '.',',' };
  for (int i = 0; i < 10; i++)
    if (str == A[i])
      return i;
  if (str == B[0] || str == B[1])
    return -2;
  return -1;  
}
