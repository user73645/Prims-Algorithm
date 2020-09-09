#ifndef PRIM_HPP
#define PRIM_HPP 

#include <vector>
#include <string> 

class Prim {
    private:
        int vertex_count;
        std::vector<std::string> vertexes;
    public:
        std::vector<std::vector<int>> generateMatrix(std::string file);
        void prim(std::vector<std::vector<int>>& matrix);
};

#endif
