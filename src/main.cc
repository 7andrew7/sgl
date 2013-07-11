
#include <iostream>

#include "graph.h"

int main() {
  sgl::Graph<std::string> graph;

  graph.AddEdge("1", "2");
  graph.AddEdge("2", "3");
  graph.AddEdge("3", "1");
  graph.AddEdge("3", "2");

  std::cout << graph << std::endl;
}
