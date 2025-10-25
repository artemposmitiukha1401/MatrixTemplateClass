#include <iostream>
#include "Matrix.h"
#include "Point.h"

std::ostream& operator<<(std::ostream &os,const Point& p) {
    os << "[" << p.GetX() << " : " << p.GetY() << " ]";
    return os;

}
int main() {
    srand(time(nullptr));

    Matrix<Point> matrix = Matrix<Point>(3, 3);
    matrix.Print();
    matrix += 5;
    matrix.Print();

    matrix -= 5;
    matrix.Print();

    matrix *= 5;
    matrix.Print();

    matrix /= 5;
    matrix.Print();

}