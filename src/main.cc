
#include <iostream>
#include <fstream>

#include "graph.h"

int main(int argc, const char* argv[]) {
  std::string file_name = "../data/tiny.al";

  if (argc >= 2)
    file_name = argv[1];

  sgl::Graph<std::string> graph;

  std::ifstream phile;
  phile.open(file_name);
  phile >> graph;

  std::cout << graph << std::endl;
}
