/** реализация перегрузки операторов для класса рациональная дробь */


#include <iostream>
#include <math.h>
typedef long long ll;

using namespace std;

// поиск НОД - Наибольший общий делитель
ll GCD(ll a, ll b) {
  return (b == 0) ? a : GCD(b, a % b);
}



class RationalFraction {
 private:
 ll numerator;// числитель дроби
 ll denominator;// знаменатель дроби
 public:
 // функция показать дробь
 void showFraction() {
 if (denominator != 1)  //если делитель в дроби единица, показываем как простое число
    cout << numerator << "/" << denominator <<endl;
 else  cout << numerator << endl;
 }


 void normalize(RationalFraction &temp){  // нормализация дроби
 ll maxmul = GCD(temp.numerator,temp.denominator); // поиск наибольшего общего целого для числителя и знаменателя
 temp.numerator   = temp.numerator/maxmul;
 temp.denominator = temp.denominator/maxmul;
 return;
 }

 RationalFraction operator+ (RationalFraction add) {  // реализация сложения для дроби
    RationalFraction temp (numerator*add.denominator + add.numerator*denominator,denominator*add.denominator);
    normalize(temp);
 return temp;
 }


 RationalFraction operator- (RationalFraction sub) {  // реализация вычитания для дроби
    RationalFraction temp (numerator*sub.denominator - sub.numerator*denominator,denominator*sub.denominator);
    normalize(temp);
 return temp;
 }

 RationalFraction operator* (RationalFraction mul) {  // реализация умножения для дроби
    RationalFraction temp (numerator*mul.numerator,denominator*mul.denominator);
    normalize(temp);
 return temp;
 }

 RationalFraction operator/ (RationalFraction div) {  // реализация умножения для дроби
    RationalFraction temp (numerator*div.denominator,denominator*div.numerator);
    normalize(temp);
 return temp;
 }

 RationalFraction operator+ (int integer){
   RationalFraction temp  (numerator + ((ll)integer)*denominator, denominator);
  return temp;
 }
 RationalFraction operator- (int integer){
   RationalFraction temp  (numerator -((ll)integer)*denominator, denominator);
  return temp;
 }



 // конструктор
 RationalFraction(ll n, ll d = 1 ) {numerator = n; denominator =d;} // (int d = 1) можно задавать дробь одним целым числом
// RationalFraction(int n, int d ) : n(numerator), (denominator) {} // со списком инициализации

// конструктор копирования
 RationalFraction(RationalFraction const& copyr): numerator(copyr.numerator),denominator(copyr.denominator) {};

  friend ostream& operator << (ostream& os, RationalFraction& temp) {
    os << temp.numerator << "/" << temp.denominator << " ";
    return os;
  }


 };




int main()
{
RationalFraction drob1 (1,2);
RationalFraction drob2 (3,2);
RationalFraction drob3=drob1+drob2;
cout << "1/2 + 3/2 ="; cout << drob3 << endl;
drob3=drob1-drob2;
cout << "1/2 - 3/2 ="; cout << drob3 << endl;
drob3=drob1*drob2;
cout << "1/2 * 3/2 ="; cout << drob3 << endl;
drob3=drob1/drob2;
cout << "(1/2)/(3/2)=";cout << drob3 << endl;
cout << endl;

RationalFraction drob4 (10,7);
RationalFraction drob5 (10,5);
RationalFraction drob6=drob4+drob5;
cout << "10/7 + 10/5 ="; cout << drob6 << endl;
drob6=drob4-drob5;
cout << "10/7 - 10/5 ="; cout << drob6 << endl;
drob6=drob4*drob5;
cout << "10/7 * 10/5 ="; cout << drob6 << endl;
drob6=drob4/drob5;
cout << "10/7 / 10/5 ="; cout << drob6 << endl;

RationalFraction drob7 (-7,4);
RationalFraction drob8 (8,3);
RationalFraction drob9=drob7+drob8;
cout << "-7/4 + 8/3 =";drob9.showFraction();
drob9=drob7-drob8;
cout << "-7/4 - 8/3 =";drob9.showFraction();
drob9=drob7*drob8;
cout << "-7/4 * 8/3 =";drob9.showFraction();
drob9=drob7/drob8;
cout << "-7/4 / 8/3 =";drob9.showFraction();

int a=5,b=3,c=4;
cout << "1/2 - 5 =";(drob1-a).showFraction();
cout << "-7/4 + 3 =";(drob7+b).showFraction();
cout << "8/3 + 4 =";(drob8+c).showFraction();





return 0;
}
