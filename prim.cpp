#include "prim.hpp"
#include <fstream>
#include <limits.h>
#include <map>


std::vector<std::vector<int>> Prim::generateMatrix(std::string file) {
    std::ifstream data;
    std::string line, source_vertex, destination_vertex;
    std::map<std::string, int> index;
    int weight; 
    vertex_count = 0;
    
    data.open(file);
    
    while (std::getline(data, line)) {
        if (line.length() == 1)
            break;
        line = line.substr(0,line.size()-1);
        index[line] = vertex_count;
        vertexes.push_back(line);
        vertex_count++;
    }
    
    std::vector<std::vector<int>> adjacency_matrix(vertex_count, 
                                  std::vector<int>(vertex_count, INT_MAX));

    while (data >> source_vertex >> destination_vertex >> weight) {
        adjacency_matrix[index[source_vertex]][index[destination_vertex]] = weight;
        adjacency_matrix[index[destination_vertex]][index[source_vertex]] = weight;
    }
        
    data.close();
    return adjacency_matrix;
}



bool validEdge(int i, int j, std::vector<bool> visited) { 
   if (i == j) 
       return false; 
   if (visited[i] == false && visited[j] == false) 
        return false; 
   else if (visited[i] == true && visited[j] == true) 
        return false; 
   return true; 
}


void Prim::prim(std::vector<std::vector<int>>& matrix) {   

    std::vector<bool> visited(vertex_count, false); 
    visited[0] = true; 
  
    int visited_count = 1;
    std::ofstream answer;
    answer.open("Answers.txt");

    for (std::string x : vertexes)
        answer << x << "\n";
    answer << "\n";

    while (visited_count < vertex_count) { 
        int cheapest = INT_MAX, x = -1, y = -1; 
        for (int i = 0; i < vertex_count; i++) { 
 	          for (int j = 0; j < vertex_count; j++) {                
                if (matrix[i][j] < cheapest && validEdge(i,j, visited)) { 
                    cheapest = matrix[i][j]; 
                    x = i; 
                    y = j; 
                } 
            } 
        } 

        if (x != -1 && y != -1) {
            answer << vertexes[x] << "\t" << vertexes[y] << "\t" << cheapest << "\n";
            visited_count++;
            visited[x] = visited[y] = true; 
        } 
    } 
}
