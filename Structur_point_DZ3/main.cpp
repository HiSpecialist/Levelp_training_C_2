/** Домашнее задание - структуры данных
---------------------------------------
определить структуру данных "точка"
(на плоскости, с 2 -мя координатами x и y)

Реализовать функции сложения и вычитания как для векторов
*/


#include <iostream>
#include <math.h>
#include <assert.h>
using namespace std;

struct Point {
double corX;
double corY;
}; //point1,point2,point3; часто задают тут


// операция сложения векторов, вектора складываются по координатам соответсвенно x=x1+x2, y= y1+y2
Point addition(Point point1,Point point2){
Point retPoint;
retPoint.corX=point1.corX+point2.corX;
retPoint.corY=point1.corY+point2.corY;
return retPoint;
}

// операция вычитания векторов, вектора вычитаются по координатам соответсвенно x=x1-x2, y= y1-y2
Point subtraction(Point point1,Point point2){
Point retPoint;
retPoint.corX=point1.corX-point2.corX;
retPoint.corY=point1.corY-point2.corY;
return retPoint;
}

// длина вектора
double lenght(Point point){
return sqrt(point.corX*point.corX+point.corY*point.corY);
}


int main()
{

    Point point1={2.3, 4.9};
    Point point2={7.6,-2.4};
    Point point3;

    point3=addition(point1,point2);

    assert(point3.corX < 9.91 && point3.corX > 9.89 && point3.corY > 2.49 && point3.corY < 2.51);

    point1={6, 7};
    point2={-6,-2};

    point3=addition(point1,point2);

    assert( point3.corX < 10E-10 && point3.corX > -10E-10 && point3.corY > 4.99 && point3.corY < 5.01 );

    cout << "Struct Point" << endl;
    cout << "Точка 1 X=";
    cin >> point1.corX;
    cout << "Y=";
    cin >> point1.corY;
    cout << "Точка 2 X=";
    cin >> point2.corX;
    cout << "Y=";
    cin >> point2.corY; cout << endl;

    point3=addition(point1,point2);

    double l=lenght(point3);


    cout << "x3=" << point3.corX  << " y3=" << point3.corY << endl;
    cout << l ;

    return 0;
}
