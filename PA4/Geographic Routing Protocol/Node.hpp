#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <string>

class Node {
  friend std::ostream & operator <<(std::ostream &out, const Node &n);

private:
    int id = -1;

    int x = 0, y = 0;

  public:
    Node() = delete;
    Node(int id, int x, int y) : id(id), x(x), y(y) {}

    virtual ~Node() {}

  public:
    int getId() const {
      return this->id;
    }
    void setId(int newId) {
        this->id = newId;
    }

    int getX() const {
      return this->x;
    }
    void setX(int newX) {
        this->x = newX;
    }

    int getY() const {
      return this->y;
    }
    void setY(int newY) {
      this->y = newY;
    }

    void setPos(int newX, int newY) {
      this->setX(newX);
      this->setY(newY);
    }
};

#pragma mark - Comparison
inline bool operator==(const Node& lhs, const Node& rhs) {
  return (lhs.getId() == rhs.getId());
}

inline bool operator!=(const Node& lhs, const Node& rhs) {
  return !(lhs == rhs);
}

class Reader {
public:
    static void ReadInput(const std::string &path, std::unordered_map<int, std::shared_ptr<Node>> &outNodes);

private:
};
