#ifndef LINE_H
#define LINE_H


#include <iostream>
#include <vector>

#include "point.hpp"
class Line
{
public:
    Line(double a, double b, double c)
        : a_{a},b_{b},c_{c}{}
    Line(const Point& p1, const Point& p2)
        : a_{p1.getY() - p1.getY()},
          b_{p1.getX() - p2.getX()},
          c_{a_ * p1.getX() + b_ * p1.getY()}, p1_{p1}, p2_{p2}{}

    virtual ~Line();
    std::vector<double> coeff() const
    {
       return std::vector<double>{a_, b_, c_};
    }

    double a() const
    {
        return a_;
    }
    double b() const
    {
        return b_;
    }
    double c() const
    {
        return c_;
    }

    // getPoints() const
    // getP1() const
    // getP2() const

    double slope() const
    {
        return 0.0;
    }

    Line perPendicular() const
    {
        // a line perpendicular to ax + by = c 
        // is -bx + ay =d.
        // as point of line lies on perpendicular this gives d.
        
        auto xMidPoint = (p1_.getX() + p2_.getX()) / 2.0;
        auto yMidPoint = (p1_.getX() + p2_.getX()) / 2.0;

        double d = -b_ * xMidPoint + a_ * yMidPoint;

        Line l{-b_, a_, d};
        return l;
    
    
    }

    bool isPointOnLine(const Point& p) const
    {
        auto minX = std::min(p1_.getX(), p2_.getX());
        auto minY = std::min(p1_.getY(), p2_.getY());
        auto maxX = std::max(p1_.getX(), p2_.getX());
        auto maxY = std::max(p1_.getY(), p2_.getY());
        auto x = p.getX();
        auto y = p.getY();
        return (minX <= x + eps_ && x <= maxX - eps_)
            &&(minY <= y + eps_ && y <= maxY - eps_);
    }

    Point intersection(const Line& l2) const
    {
        auto a1 = a_;
        auto b1 = b_;
        auto a2 = l2.a();
        auto b2 = l2.b();
        auto c1 = c_;
        auto c2 = l2.c();

        auto det  = a1*b2 - a2*b1;
        auto x =  (b2*c1 - b1*c2)/det;
        auto y = (a1*c2 - a2*c1)/det;

        // Check wether point (x,y) lies on the line 1 and line 2
        Point p{x,y};

        if( this->isPointOnLine(p) && l2.isPointOnLine(p))
            return p;
        else
            // Throw error 
    
        return Point{0,0};
    }

private:
   double a_, b_, c_;
   Point p1_, p2_;

   const double eps_ = 1e-5;

};

#endif /* LINE_H */
