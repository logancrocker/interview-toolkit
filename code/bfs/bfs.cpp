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

void breadthFirstSearch(Node* root) {
  queue<Node*> q;
  root->mark();
  q.push(root);

  while (!q.empty()) {
    Node* r = q.front();
    q.pop();
    r->visit();
    for (Node* n : r->get_neighbors()) {
      if (!n->isMarked()) {
        n->mark();
        q.push(n);
      }
    }
  }

}

int main() {

  // declare nodes
  Node* a = new Node('a');
  Node* b = new Node('b');
  Node* c = new Node('c');
  Node* d = new Node('d');
  Node* e = new Node('e');
  Node* f = new Node('f');

  // add neighbors
  a->add_neighbor(b);

  b->add_neighbor(c);

  c->add_neighbor(e);

  d->add_neighbor(b);

  e->add_neighbor(d);
  e->add_neighbor(f);

  // create list of nodes
  vector<Node*> nodes;
  nodes.push_back(a);
  nodes.push_back(b);
  nodes.push_back(c);
  nodes.push_back(d);
  nodes.push_back(e);
  nodes.push_back(f);

  // init graph
  Graph* g = new Graph(nodes);

  Node* root = g->get_nodes()[0];
  breadthFirstSearch(root);

  return 0;
}