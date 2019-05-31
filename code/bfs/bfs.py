from queue import Queue

class Node:
  def __init__(self, label):
    self.label = label
    self.marked = False
    self.neighbors = []

  def add_neighbor(self, node):
    self.neighbors.append(node)

  def visit(self):
    print(self.label)

  def mark(self):
    self.marked = True

class Graph:
  def __init__(self, nodes):
    self.nodes = nodes

def breadthFirstSearch(root):
  q = Queue() 
  root.mark()
  q.put(root)

  while (not q.empty()):
    r = q.get()
    r.visit()
    for n in r.neighbors:
      if (not n.marked):
        n.mark()
        q.put(n)

if __name__ == "__main__":
  # declare nodes
  a = Node('a')
  b = Node('b')
  c = Node('c')
  d = Node('d')
  e = Node('e')
  f = Node('f')

  # add neighbors
  a.add_neighbor(b)

  b.add_neighbor(c)

  c.add_neighbor(e)

  d.add_neighbor(b)

  e.add_neighbor(d)
  e.add_neighbor(f)

  # create list of nodes
  nodes = []
  nodes.append(a)
  nodes.append(b)
  nodes.append(c)
  nodes.append(d)
  nodes.append(e)
  nodes.append(f)

  # init graph
  g = Graph(nodes)
  root = g.nodes[0]

  breadthFirstSearch(root)