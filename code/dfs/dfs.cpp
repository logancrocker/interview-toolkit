#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
  private:
    char label;
    bool marked;
    vector<Node*> neighbors;
  public:
    Node(char label) {
      this->label = label;
      this->marked = false;
    }
    vector<Node*> get_neighbors() {
      return this->neighbors;
    }
    void add_neighbor(Node* n) {
      this->neighbors.push_back(n);
    }
    void visit() {
      cout << this->label << endl;
    }
    void mark() {
      this->marked = true;
    }
    bool isMarked() {
      return this->marked;
    }
};

class Graph {
  private:
    vector<Node*> nodes;
  public:
    Graph(vector<Node*> nodes) {
      this->nodes = nodes;
    }
    vector<Node*> get_nodes() {
      return this->nodes;
    }
};

void printVector(vector<Node*> v) {
  for (Node* n : v) {
    n->visit();
  }
}

void depthFirstSearch(Node* root) {
  if (root == NULL) { return; }
  root->visit();
  root->mark();
  for (Node* n : root->get_neighbors()) {
    if (!n->isMarked()) {
      depthFirstSearch(n);
    }
  }
}

int main() {

  // declare nodes
  Node* n1 = new Node('1');
  Node* n2 = new Node('2');
  Node* n3 = new Node('3');
  Node* n4 = new Node('4');
  Node* n5 = new Node('5');

  // add neighbors
  n1->add_neighbor(n4);

  n2->add_neighbor(n4);
  n2->add_neighbor(n5);

  n3->add_neighbor(n5);

  n4->add_neighbor(n1);
  n4->add_neighbor(n2);
  n4->add_neighbor(n5);

  n5->add_neighbor(n3);
  n5->add_neighbor(n2);
  n5->add_neighbor(n4);

  // create list of nodes
  vector<Node*> nodes;
  nodes.push_back(n1);
  nodes.push_back(n2);
  nodes.push_back(n3);
  nodes.push_back(n4);
  nodes.push_back(n5);

  // init graph
  Graph* g = new Graph(nodes);

  Node* root = g->get_nodes()[0];
  depthFirstSearch(root);

  return 0;
}