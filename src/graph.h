#pragma once

#include <iostream>
#include <unordered_map>
#include <unordered_set>

namespace sgl {

template <class NodeKey>
class Graph {
 public:

  typedef std::unordered_set<NodeKey> NodeSet;

  void AddEdge(const NodeKey &source, const NodeKey &dest) {
    edges_[source].insert(dest);
    nodes_.insert(source);
    nodes_.insert(dest);
  }

  const NodeSet &GetNodes() const {
    return nodes_;
  }

  const NodeSet &GetNeighbors(const NodeKey &node) const {
    static const NodeSet empty_node_set_ = {};

    auto it = edges_.find(node);
    if (it == edges_.end())
      return empty_node_set_;
    else
      return it->second;
  }

 private:
  NodeSet nodes_;
  std::unordered_map<NodeKey, NodeSet> edges_;
};

template<class NodeKey>
std::ostream& operator<<(std::ostream &os, const Graph<NodeKey> &graph){

  for (const auto &node_key : graph.GetNodes()) {
    os << node_key << ": ";

    for (const auto &neighbor : graph.GetNeighbors(node_key))
      os << neighbor << " ";

    os << std::endl;
  }

  return os;
}

template<class NodeKey>
std::istream& operator>>(std::istream &is, Graph<NodeKey> &graph)
{
  while(true) {
    std::string source, dest;
    is >> source >> dest;

    if (!is)
      return is;

    graph.AddEdge(source, dest);
  }
}

}
