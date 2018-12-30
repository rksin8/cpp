#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>
class Point
{
private:
    double x_, y_;

public:
    Point(double x=0, double y=0):x_{x},y_{y}{}

    Point(const Point& p){
        x_ = p.x_;
        y_ = p.y_;
    }

    Point& operator+(const Point& p) 
    {
        x_ = x_ + p.x_;
        y_ = y_ + p.y_;

        return *this;
    }
    Point& operator-(const Point& p) 
    {
        x_ = p.x_ - x_;
        y_ = p.y_ - y_;

        return *this;
    }

    Point rotate(const double angle, const Point& center = Point{0,0}) const
    {
        auto theta = angle * M_PI / 180; // degree to radian
        using std::cos;
        using std::sin;

        auto x = x_ * cos(theta) - y_ * sin(theta);
        auto y = x_ * sin(theta) + y_ * cos(theta);

        return Point(x,y);

    }

    double getX() const{
        return x_;
    }
    
    double getY() const{
        return y_;
    }

    double distance(const Point& p){
        auto dx = p.x_ - x_;
        auto dy = p.y_ - y_;
    
        return std::sqrt(dx*dx + dy*dy);
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& p);

    virtual ~Point(){};
};

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    return os << "(" << p.x_ << "," << p.y_ << ") ";
}

#endif /* POINT_H */
