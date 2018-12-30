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
