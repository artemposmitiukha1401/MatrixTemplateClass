#ifndef MATRIX_TEMPLATE_CLASS_POINT_H
#define MATRIX_TEMPLATE_CLASS_POINT_H
class Point {
    int x = 0, y = 0;
    public:
    Point() = default;
    Point(int x, int y) : x(x), y(y) {}
    Point& operator += (int value);
    Point& operator -= (int value);
    Point& operator /= (int value);
    Point& operator *= (int value);
    void SetX(int value) { x = value; }
    void SetY(int value) { y = value; }
    int GetX() const { return x; }
    int GetY() const { return y; }

};

inline Point & Point::operator+=(int value) {
    this->x += value;
    this->y += value;
    return *this;
}

inline Point & Point::operator-=(int value) {
    this->x -= value;
    this->y -= value;
    return *this;
}

inline Point & Point::operator/=(int value) {
    this->x /= value;
    this->y /= value;
    return *this;
}

inline Point & Point::operator*=(int value) {
    this->x *= value;
    this->y *= value;
    return *this;
}

#endif

