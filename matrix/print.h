#include <iostream>
#include <vector>
template <typename T>
void print(std::vector<std::vector<T>>& matrix){

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout  << std::endl;
    }
}



