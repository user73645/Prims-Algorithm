#include "prim.hpp"
#include <iostream>


int main(int argc, char** argv) {
   
    if (argc < 2) {
        std::cout << "Please pass testdata as argument" << std::endl;
        return 0;
    }

    Prim mst;
    std::vector<std::vector<int>> matrix = mst.generateMatrix(argv[1]);
    mst.prim(*&matrix);
}  
