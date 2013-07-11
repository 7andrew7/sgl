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
std::ostream& operator<<(std::ostream &out, const Graph<NodeKey> &graph){

  for (const auto &node_key : graph.GetNodes()) {
    out << node_key << ": ";

    typename Graph<NodeKey>::NodeSet neighbors = graph.GetNeighbors(node_key);
    for (const auto &neighbor : neighbors)
      out << neighbor << " ";

    out << std::endl;
  }

  return out;
}

}
