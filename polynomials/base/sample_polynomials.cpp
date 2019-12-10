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
  cout << "Введите полином без пробелов и других непонятных символов" << endl << "Точность - 2 знака после запятой (можно до 6 поменять). Дробные константы можно вводить через . или , " << endl << "Степени полинома до 49, сделайте скидочку на тупость проги, это не проверяется" << endl << "Например: xyz+5,05x2-0.1z10:" << endl;
  cin >> poly;
  Polynomials exper(poly);
  cout << endl << "Введите полином, с которым складываем:" << endl;
  cin >> help;
  cout << "Результат: " << exper.add(help) << endl;
  cout << endl <<  "Константу, на которую умножаем исходный полином:" << endl;
  cin >> constan;
  cout << "Результат: " << exper.mult_const(constan) << endl;
  cout <<  endl << "Введите полином, на который умножаем:" << endl;
  cin >> help;
  cout << "Результат: " << exper.mult(help) << endl;
  double x, y, z;
  cout << endl << "Введите подряд x, y, z:" << endl;
  cin >> x >> y >> z;
  cout << "Результат: " << exper.point_calcul(x, y, z);
	return 0;
}