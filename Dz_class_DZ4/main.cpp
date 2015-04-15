#include <iostream>

using namespace std;

class Shape {
public:
virtual void show()=0; // виртуальный метод, будет определен в производных классах от этого
// "для корректного вызова через указатели базового класса".

virtual double perimetr()=0; // виртуальный метод; периметр

double area(){return 0;} // будем считать, у не определенной фигуры площадь 0,
// если мы будем обращаться к методу area через указатель фигура,то он вернет 0 "всегда".
};


class Square : public Shape {
protected:
double side;
public:
Square(double s) {side=s;}
void show() {cout << "я квадрат" << endl;}
double perimetr() {return side*4;}
//double area(){return side*side;}
 };

class Rectangle : public Shape {
protected:
double height, widht;
public:
Rectangle(double h,double w) {height=h ;widht=w ;}
void show() {cout << "я прямоугольник" << endl;}
double perimetr() {return height*2+widht*2;}
double area(){return height*widht;}
};




int main()
{
Shape* s[] {
new Square(50),
new Rectangle(2,3),
new Square(15)
};

for (int i=0;i<3;i++)
{
s[i]->show();cout << "мой периметр="  <<s[i]->perimetr() << endl;
cout << "площадь ="  << s[i]->area() << endl; // если работаем через указатель базового класса, он использует его метод
// у всех фигур площади 0
}
Rectangle *s2 = new Rectangle(5,3);
cout << "площадь прямоугольника (5,3) ="  << s2->area() << endl;//тут работает правильно
Square *s3 = new Square(3);
cout << "площадь квадрата 3 ="  << s3->area() << endl; // допустим для квадрата это метод не определен, тогда используем метод базового класса = 0


// удалять обязательно или ОС все сделает за нас?
for (int i=0;i<3;i++)
{
delete s[i];
}
delete s2;
delete s3;



return 0;
}
