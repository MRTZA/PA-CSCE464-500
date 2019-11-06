#include <memory>
#include <vector>
#include <unordered_map>

#include "Node.hpp"

class Router {
private:
    static double getDistance(Node &a, Node &b);
    void getNearbyNodes(Node &in, std::vector<std::shared_ptr<Node>> &nearby);

    // max distance between nodes
    int range = 0;

    std::unordered_map<int, std::shared_ptr<Node>> nodes;

  public:
    Router() {}
    Router(std::vector<std::shared_ptr<Node>> &nodes, int range);
    Router(std::unordered_map<int, std::shared_ptr<Node>> &nodes, int range);

    int route(Node &start, Node &end, std::vector<int> &path, std::vector<int> &visited, int depth = 0);
};
