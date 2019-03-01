#include <iostream>
#include <vector>

#include "print.h"





int main(int argc, char *argv[])
{

    using Matrix = std::vector<std::vector<double>>;
    Matrix v{ {1,5,7},{8,9,4},{2,3,6}};
    Matrix w  = v;

    print(v);
    Matrix result{{0,0,0},{0,0,0},{0,0,0}};
    Matrix result2{{0,0,0},{0,0,0},{0,0,0}};


    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[0].size(); ++j) {
            result[i][j] = v[v[0].size()-j-1][i];
        }
    }

    std::cout << "Matrix after rotation:" << std::endl;
    print(result);

    for (int i = 0; i < w.size(); ++i) {
        for (int j = 0; j < w[0].size(); ++j) {
            result2[i][j] = w[j][w[0].size()-i-1];
        }
    }
    std::cout << "Matrix after rotation by -90:" << std::endl;
    print(result2);

    
    return 0;
}
