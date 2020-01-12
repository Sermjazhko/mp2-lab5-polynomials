#include <iostream>
#include "List.h"

using namespace std;
bool List::empty()
{
  return pFirst == nullptr;
}
void List::add_elem(int deg, double number) 
{
  if (deg != 0 || number != 0)
  {
    link *p = new link;
    p->pNext = nullptr;
    p->degree = deg;
    p->constant = number;
    if (empty())
      pFirst = p;
    else
    {
      link *pp = pFirst;
      while (pp->pNext != nullptr)
        pp = pp->pNext;
      pp->pNext = p;
    }
    size++;
  }
}
void List::delete_elem(int pos) 
{
  link *p = pFirst;
  int count = 0;
  if ( empty() || (pos >= size))
    return;
  else
  {
    while (p != nullptr)
    {
      if (pos == count)
      {
        if (pos == 0)
        {
          link *pp = p->pNext; 
          delete p;
          pFirst = pp;
          p = pp;
        }
        else
        {
          link *pp = pFirst; 
          while (pp->pNext != p)
            pp = pp->pNext;
          pp->pNext = p->pNext;
          delete p;
          p = pp;
        }
        size--;
        break;
      }
      p = p->pNext;
      count++;
    }
  }
}
void List::sorting()
{
  if (!empty())
  {
    int position = 0;
    int _size = get_size();
    link *p = pFirst;
    link *pp = pFirst;
    for (int i = 0; i < _size; i++)
    { 
      p = pFirst;
      pp = pFirst;
      for (int k = 0; k < i; k++)
        p = p->pNext;     
      while (pp != p->pNext)
        pp = pp->pNext;
      position = i + 1; 
      while (pp != nullptr)
      {
        if (p->degree == pp->degree)
        {
          p->constant = p->constant + pp->constant;
          pp = pp->pNext;
          delete_elem(position);
          _size = get_size();
        }
        else
        {
          pp = pp->pNext;
          position++;
        }
      }
    }   
    p = pFirst;
    pp = pFirst;
    for (int i = 0; i < _size; i++)
    {
      if (p->constant == 0.0)
      {
        while (pp != p->pNext)
          pp = pp->pNext;
        delete_elem(i);
        _size = get_size();
        i--;
        p = pp;
      }
      else
      {
        p = p->pNext;
      }
    }
  }
}
void List::output()
{
  link *p = pFirst;
  cout << "Список: " << endl;
  while (p != nullptr)
  {
    cout << "Степень: " <<  p->degree << " Константа: " << p->constant << endl; ;
    p = p->pNext;
  }
  cout << endl;
}
int List::get_size()
{
  return size;
}
int List::get_elem_deg(int pos)
{
    link *p = pFirst;
    int count = 0;
    while (p != nullptr)
    {
      if (count == pos)
        return p->degree;
      p = p->pNext;
      count++;
    }
    return -1;
}
double List::get_elem_con(int pos)
{
  link *p = pFirst;
  int count = 0;
  while (p != nullptr)
  {
    if (count == pos)
      return p->constant; 
    p = p->pNext;
    count++;
  }
  return -1;
}
