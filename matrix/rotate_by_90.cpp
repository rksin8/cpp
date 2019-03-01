#include <iostream>
#include <vector>

#include "print.h"

int main(int argc, char *argv[])
{

    using Matrix = std::vector<std::vector<double>>;
    Matrix v{ {1,5,7},{8,9,4},{2,3,6}};

    print(v);
    Matrix result{{0,0,0},{0,0,0},{0,0,0}};


    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[0].size(); ++j) {
            result[i][j] = v[v[0].size()-j-1][i];
        }
    }

    std::cout << "Matrix after rotation:" << std::endl;
    print(result);
    
    return 0;
}
