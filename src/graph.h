#pragma once

#include <unordered_map>
#include <unordered_set>

namespace sgl {

template <class NodeKey>
class Graph {
  typedef std::unordered_set<NodeKey> NodeSet;

  void AddEdge(const NodeKey &source, const NodeKey &dest) {
    edges_[source] = dest;
    nodes_.insert(source);
    nodes_.insert(dest);
  }

 private:
  NodeSet nodes_;
  std::unordered_map<NodeKey, NodeSet> edges_;
};

}
