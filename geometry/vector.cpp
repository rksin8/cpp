#include <iostream>

#include "vector.hpp"


Vector::Vector(Point p1, Point p2):
    xComp_{p2.getX()-p1.getX()},
    yComp_{p2.getY() - p1.getY() }
{}


Vector::Vector(double x1, double y1, double x2, double y2):
    xComp_{x2 - x1},
    yComp_{y2 - y1 }
{}


double Vector::distance(const Point& p1, const Point& p2) const
{
    auto dx = p2.getX() - p1.getX();
    auto dy = p2.getY() - p1.getY();
    return std::sqrt( dx*dx + dy*dy);

}

Vector& Vector::operator+(const Vector& v2)
{
    xComp_ = v2.xComp_ + xComp_;
    yComp_ = v2.yComp_ + yComp_;
    return *this;
}
Vector& Vector::operator-(const Vector& v2)
{
    xComp_ = v2.xComp_ - xComp_;
    yComp_ = v2.yComp_ - yComp_;
    return *this;
}
double Vector::dot(const Vector& v2) const
{
    return (xComp_*v2.xComp_ + yComp_ * v2.yComp_);

}
double Vector::cross(const Vector& v2) const
{
    return (xComp_ * v2.yComp_ - yComp_ * v2.xComp_);

}

double Vector::mag() const
{
    return std::sqrt( xComp_*xComp_ + yComp_*yComp_);
}
double Vector::distFromPoint(const Point& A, const Point& B, const Point& C)
{
    Vector AB{A, B};
    Vector BC{B, C};
    auto magAB = AB.mag();
    
    return AB.cross(BC)/magAB;
}
void Vector::print() const
{
    std::cout << "("<< xComp_ << "," << yComp_ << ")" << std::endl;

}

Vector::~Vector(){}
