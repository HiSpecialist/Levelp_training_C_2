// Домашнее задание - рекурсия
// ---------------------------
//  ЗАДАНИЕ:
// Пользователь вводит натуральное число N. Нужно вывести все способы разложить его на слагаемые.
// Способы отличающиеся только порядком слагаемых считаются одинаковыми.
// -----------------------
// Например N = 4:
// 4 = 4
// 4 = 3 + 1
// 4 = 2 + 2
// 4 = 2 + 1 + 1
// 4 = 1 + 1 + 1 + 1
#include <iostream>
//#include <cmath>

using namespace std;
int arr[1000];
int N;


void summa(int Ncur,int minimum = 0, int i = 0) {
    if ( Ncur < 0 || minimum == N) { /* <-условие выхода" ;*/ return;}
    arr[i] = minimum;
    if (minimum != 0) {summa(Ncur-minimum,minimum,i+1); /*cout << "requr1";*/}
    summa(Ncur - 1, minimum + 1, i);

    if (Ncur == 0) {       // вывод строки
       for (int j=0; j<=i; ++j){
        cout << arr[j] << (j != i ? '+' : '\n' );
       }
    }
}





int main()
{
      // Вводим число N

  cout << "N = ";
  cin >> N;

     // Вывод разложения на слагаемые
  summa(N);

  return 0;
}


