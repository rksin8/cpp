#ifndef VECTOR_H
#define VECTOR_H

#include "point.hpp"


class Point;
class Vector
{
private:
    double xComp_, yComp_;
    

public:
    Vector(Point p1, Point p2);
    Vector(double x1, double y1, double x2, double y2);
    double distance(const Point& p1, const Point& p2) const;

    Vector& operator+(const Vector& v2);
    Vector& operator-(const Vector& v2);
    //double dot(const Point& p1, const Point& p2) const;
    double dot(const Vector& v2) const;
    double cross(const Vector& v2) const;
    //double cross(const Point& p1, const Point& p2) const;
    
    double mag() const;
    
    double distFromPoint(const Point& p1, const Point& p2, const Point& p3);

    void print() const;
    virtual ~Vector();
};

#endif /* VECTOR_H */
