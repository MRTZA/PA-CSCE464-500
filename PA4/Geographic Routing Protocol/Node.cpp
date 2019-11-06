#include "Node.hpp"

// print node
std::ostream & operator <<(std::ostream &out, const Node &n) {
  out << "Node[id=" << n.id << ", pos=(" << n.x << ", " << n.y << ")]";

  return out;
}

void Reader::ReadInput(const std::string &path, std::unordered_map<int, std::shared_ptr<Node>> &outNodes) {
    // open file
    std::ifstream config(path);

    // iterate through
    std::string line;
    while(std::getline(config, line)) {
        // get ints
        std::istringstream iss(line);

        int id, x, y;

        if(!(iss >> id >> x >> y)) {
            std::cerr << "ignoring invalid config line '" << line << "'" << std::endl;
            break;
        }

        outNodes[id] = std::make_shared<Node>(id, x, y);
    }
}