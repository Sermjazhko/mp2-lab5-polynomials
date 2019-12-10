#include <cstdlib>
#include <iostream>
#include "Polynomials.h"
#include "List.h"

using namespace std; 

int main()
{
  setlocale(LC_ALL, "Russian");
  string poly;
  string help;
  int constan = 0;
  cout << "������� ������� ��� �������� � ������ ���������� ��������" << endl << "�������� - 2 ����� ����� ������� (����� �� 6 ��������). ������� ��������� ����� ������� ����� . ��� , " << endl << "������� �������� �� 49, �������� �������� �� ������� �����, ��� �� �����������" << endl << "��������: xyz+5,05x2-0.1z10:" << endl;
  cin >> poly;
  Polynomials exper(poly);
  cout << endl << "������� �������, � ������� ����������:" << endl;
  cin >> help;
  cout << "���������: " << exper.add(help) << endl;
  cout << endl <<  "���������, �� ������� �������� �������� �������:" << endl;
  cin >> constan;
  cout << "���������: " << exper.mult_const(constan) << endl;
  cout <<  endl << "������� �������, �� ������� ��������:" << endl;
  cin >> help;
  cout << "���������: " << exper.mult(help) << endl;
  double x, y, z;
  cout << endl << "������� ������ x, y, z:" << endl;
  cin >> x >> y >> z;
  cout << "���������: " << exper.point_calcul(x, y, z);
	return 0;
}