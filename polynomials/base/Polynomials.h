#pragma once
#ifndef __POLYNOMIALS_H__
#define __POLYNOMIALS_H__
#include <iostream>
#include <string>

#include <cmath>
#include "List.h"

using namespace std;
class Polynomials
{
  List polynomial;
public:
  Polynomials(string pol = "")  //разбор строки, который убил во мне человека
  {
    int point = 100; // для степени
    int symbol = 0, symbol_x = 0, symbol_y = 0, symbol_z = 0; //для буковок
    double constant = 0; //константа
    int degree = 0; //степень
    int sign = 1;//знак
    int comma = 0;
    char B[2] = { '+', '-' };
    char C[3] = { 'x','y','z' };
    unsigned int i = 0;
    while (i < pol.length())
    {
      if (pol[i] == B[0] || pol[i] == B[1]) //если знак
      {
        if (pol[i] == B[0])
          sign = 1;
        else
          sign = -1;
        if ((degree / (point*point) == 0) && (symbol_x != 0)) //для ленивой попы, которая не может поставить 1 после степени и написать x, y, z в правильном порядке
          degree = degree + point * point;
        if ((((degree % (point*point)) / point) == 0) && (symbol_y != 0))//шикарные формулы, потому что могу
          degree = degree + point;
        if ((degree % (point) == 0) && (symbol_z != 0))
          degree = degree + 1;
        if (constant != 0 || degree != 0) //запись, если не первый элемент и не 0
        {
          if (comma != 0)
          {
            int index = 0;
            int a = (int)constant;
            while (a != 0)
            {
              a = a / 10;
              index++;
            }
            if ((index - comma) != 0)
            {
              if (comma == -1)
                comma = 0;
              //cout << comma << endl;
              constant = constant / pow(10, (index - comma));
              comma = 0;
            }
          }
          polynomial.add_elem(degree, constant);
          degree = 0;
          constant = 0;
        }
        symbol = 0;
        symbol_x = 0;
        symbol_y = 0;
        symbol_z = 0;
      }
      else //число или буковка
      {
        int number = check_number(pol[i]);
        if (number != -1) //число  или точка/запятая
        {
          if (symbol != 0) //степень
          {
            int help = degree / (point*point);
            if (symbol_x != 0)
              degree = degree + (9 * help + number)*point*point; //ещё немного крутых формул
            help = (degree % (point*point)) / point;
            if (symbol_y != 0)
              degree = degree + (9 * help + number)*point;
            help = degree % point;
            if (symbol_z != 0)
              degree = degree + 9 * help + number;
          }
          else //константа
          {
            if (number != -2)
            {
              constant = constant * 10 + sign * number;
            }
            else //точка
            {
              if (comma == 0)//учитывается только первая точка
              {
                int a = (int)constant;
                int index = 0;
                while (a != 0)
                {
                  a = a / 10;
                  index++;
                }
                if (index == 0)
                  index = -1;
                comma = index;
              }
            }
          }
        }
        else //буковка
        {
          if (constant == 0 && sign == 1)
            constant = 1;
          if (constant == 0 && sign == -1)
            constant = -1;
          symbol++;
          if ((degree / (point*point) == 0) && (symbol_x != 0)) //вновь для ленивой попы, тут, если идут по порядку, например, xy2
            degree = degree + point * point;
          if ((((degree % (point*point)) / point) == 0) && (symbol_y != 0))
            degree = degree + point;
          if ((degree % (point) == 0) && (symbol_z != 0))
            degree = degree + 1;
          if (pol[i] == C[0]) //если х
          {
            symbol_x++;
            symbol_y = 0;
            symbol_z = 0;
          }
          if (pol[i] == C[1]) //если y
          {
            symbol_y++;
            symbol_x = 0;
            symbol_z = 0;
          }
          if (pol[i] == C[2]) //если z
          {
            symbol_z++;
            symbol_x = 0;
            symbol_y = 0;
          }
        }
      }
      i++;
    }
    if ((degree / (point*point) == 0) && (symbol_x != 0)) //для последнего элемента
      degree = degree + point * point;
    if ((((degree % (point*point)) / point) == 0) && (symbol_y != 0))
      degree = degree + point;
    if ((degree % (point) == 0) && (symbol_z != 0))
      degree = degree + 1;
    if (constant != 0 || degree != 0)
    {
      if (comma != 0)
      {
        int index = 0;
        int a = (int)constant;
        while (a != 0)
        {
          a = a / 10;
          index++;
        }
        if ((index - comma) != 0)
        {
        // cout << comma << endl;
          if (comma == -1)
            comma = 0;
          constant = constant / pow(10, (index - comma));
          comma = 0;
        }
      }
      polynomial.add_elem(degree, constant);
      degree = 0;
      constant = 0;
    }
  }
  string add(string help);
  string mult(string help);
  string mult_const(double constant);
  string transformation(List &obj);
  int get_size();
  double point_calcul(double x, double y, double z);
  int get_monom_deg(int pos);
  double get_monom_con(int pos);
  int check_number(char str);
  ~Polynomials()
  {}
};
#endif
