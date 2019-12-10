#pragma once
#ifndef __LIST_H__
#define __LIST_H__

struct link
{
  int degree;
  double constant;
  link *pNext;
};

class List
{
  link *pFirst;
  int size;
public:
  List()
  {
    pFirst = nullptr;
    size = 0;
  }
  bool empty();
  void add_elem(int deg, double number); 
  void delete_elem(int pos); 
  void sorting(); 
  void output();
  int get_size();
  int get_elem_deg(int pos); 
  double get_elem_con(int pos);
  ~List()
  {
    while (pFirst != nullptr)
    {
      link *p = pFirst;
      pFirst = p->pNext;
      delete p;
    }
  }
};

#endif
