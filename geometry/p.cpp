#include <iostream>
#include <cmath>

double squareRoot(const double a){
    double b = std::sqrt(a);

    if(b != b){
        return -1.0;
    }else{
        return std::sqrt(a);
    }

}
