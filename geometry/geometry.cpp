#include <iostream>
#include <cmath>

#include "point.hpp"
#include  "line.hpp"
#include "vector.hpp"

#include <vector>



double polygonArea(std::vector<Point> polygon)
{
    double area = 0.0;
    int N = polygon.size();

    // triangulate the polygon
    auto p0 = polygon[0];
    
    for (int i = 1; i+1 < N; ++i) {
        auto p1 = polygon[i];
        Vector v1{p0, p1};
       auto p2 = polygon[i+1];
        Vector v2{p0, p2};

       double cross = v1.cross(v2);
      area += cross; 
    }

    return std::abs(area/2);
}

void circleFrom3Points(const Point& p1, const Point& p2, const Point& p3)
{
    Line l1{p1, p2};
    Line l2{p2, p3};

    Line l1Per = l1.perPendicular();
    Line l2Per = l2.perPendicular();

    Point center = l1Per.intersection(l2);

    double radius = center.distance(p1);

    std::cout << "center = " << center << std::endl;

    std::cout << "radius = " << radius << std::endl;

}




int main(int argc, char *argv[])
{
    Point p1{1,3};
    Point p2{5,1};

    Vector v1{p1, p2};
    v1.print();

    auto dist= p1.distance(p2);

    std::cout << dist << std::endl;
    return 0;
}
