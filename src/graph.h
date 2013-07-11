#pragma once

#include <unordered_map>
#include <unordered_set>

namespace sgl {

template <class NodeKey>
class Graph {
  typedef std::unordered_set<NodeKey> NodeSet;

 private:
  NodeSet nodes_;
  std::unordered_map<NodeKey, NodeSet> edges_;
};

}
