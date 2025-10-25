#include "Point.h"

Point & Point::operator+=(int value) {
    this->x += value;
    this->y += value;
    return *this;
}

Point & Point::operator-=(int value) {
    this->x -= value;
    this->y -= value;
    return *this;
}

Point & Point::operator/=(int value) {
    this->x /= value;
    this->y /= value;
    return *this;
}

Point & Point::operator*=(int value) {
    this->x *= value;
    this->y *= value;
    return *this;
}

