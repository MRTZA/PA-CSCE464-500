#include "Router.hpp"

#include <stdexcept>
#include <cmath>


Router::Router(std::vector<std::shared_ptr<Node>> &_nodes, int _range) : range(_range) {
  throw std::runtime_error("n/a");
}

Router::Router(std::unordered_map<int, std::shared_ptr<Node>> &_nodes, int _range) : range(_range) {
  this->nodes = _nodes;
}

double Router::getDistance(Node &a, Node &b) {
    double dist = sqrt(pow((b.getX() - a.getX()), 2) + pow((b.getY() - a.getY()), 2));
    return fabs(dist);
}

void Router::getNearbyNodes(Node &in, std::vector<std::shared_ptr<Node>> &nearby) {
    for(auto [id, node] : this->nodes) {
        if(in.getId() != node->getId()) {
            if(this->getDistance(in, *node) <= this->range) {
                nearby.push_back(node);
            }
        }
    }
}

int Router::route(Node &start, Node &end, std::vector<int> &path, std::vector<int> &visited, int depth) {
  if(start == end) {
    return 0;
  }

  // nodeID
  path.push_back(start.getId());

  // nearest nodes
  std::vector<std::shared_ptr<Node>> nearby;
  this->getNearbyNodes(start, nearby);

  for(int i = 0; i < depth; i++) { std::cout << ""; }
  std::cout << "Found " << nearby.size() << " nodes near " << start << std::endl;

  if(nearby.empty()) {
    std::cerr << "No nearby nodes to " << start << std::endl;
    return -1;
  } else {

    for(int i = 0; i < depth; i++) { std::cout << ""; }
    std::cout << "Nearby nodes: " << std::endl;

    for(auto node : nearby) {
      auto dist = getDistance(start, *node);

      for(int i = 0; i < depth; i++) { std::cout << ""; }
      std::cout << "" << *node << ", dist = " << dist << std::endl;
    }
  }

  for(auto node : nearby) {
    // check for ending node
    if(node->getId() == end.getId()) {
      for(int i = 0; i < depth; i++) { std::cout << ""; }
      std::cout << "Found destination node " << *node << std::endl;

      path.push_back(node->getId());
      return 0;
    }
  }

  // for each of the nearby nodes, recurse
  for(auto node : nearby) {
    // ignore if visited
    if(std::find(visited.begin(), visited.end(), node->getId()) != visited.end()) {
      break;
    }

    visited.push_back(node->getId());

    for(int i = 0; i < depth; i++) { std::cout << ""; }
    std::cout << "Trying node " << *node << std::endl;

    if(node->getId() == end.getId()) {
      return 0;
    }

    std::vector<int> subPath;
    std::vector<int> subVisited = visited;

    int ret = this->route(*node, end, subPath, subVisited, (depth + 1));

    if(ret != -1) {
      for(int i = 0; i < depth; i++) { std::cout << ""; }
      std::cout << "Discovered route through node " << *node << std::endl;

      for(auto node : subPath) {
        path.push_back(node);
      }

      return 0;
    } else {
      visited.push_back(node->getId());
    }
  }

  return -1;
}
