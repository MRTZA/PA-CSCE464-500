#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

#include "Router.hpp"

int main(int argc, char const *argv[]) {
  int err;

  // validate command
  if(argc != 5) {
    return -1;
  }

  std::unordered_map<int, std::shared_ptr<Node>> nodes;
  Reader::ReadInput(std::string(argv[1]), nodes);

  if(nodes.empty()) {
    std::cerr << "no nodes in config file" << std::endl;
    return -1;
  } else {
    // do nothin
  }

  int reach = std::stoi(std::string(argv[2]));

  if(reach <= 0) {
    std::cerr << "invalid signal reach arguments '" << argv[2] << "'" << std::endl;
  }

  // check source and destination node
  int srcId = std::stoi(std::string(argv[3]));
  auto src = *nodes[srcId];

  int dstId = std::stoi(std::string(argv[4]));
  auto dst = *nodes[dstId];

  Router router(nodes, reach);

  std::vector<int> path;
  std::vector<int> visited;

  err = router.route(src, dst, path, visited);

  if(err != 0) {
    std::cout << "Could not complete route:";
  } else {
    std::cout << "Found complete route: ";
  }

  // print result
  for(auto id : path) {
    std::cout << id << " -> ";
  }

  // reset output
  std::cout << "Stop" << std::endl;

  return 0;
}
