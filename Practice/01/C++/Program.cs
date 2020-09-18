#include <iostream>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int a;
    a = 2 + 2 * 2;
    std::cout << "Результат выражения 2+2*2 = " << a << endl;
 }