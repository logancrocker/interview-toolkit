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

def depthFirstSearch(root):
  if (root):
    root.visit()
    root.mark()
    for n in root.neighbors:
      if (not n.marked):
        depthFirstSearch(n)
  else:
    return

if __name__ == "__main__":
  # declare nodes
  n1 = Node('1')
  n2 = Node('2')
  n3 = Node('3')
  n4 = Node('4')
  n5 = Node('5')

  # add neighbors
  n1.add_neighbor(n4)

  n2.add_neighbor(n4)
  n2.add_neighbor(n5)

  n3.add_neighbor(n5)

  n4.add_neighbor(n1)
  n4.add_neighbor(n2)
  n4.add_neighbor(n5)

  n5.add_neighbor(n3)
  n5.add_neighbor(n2)
  n5.add_neighbor(n4)

  # create list of nodes
  nodes = []
  nodes.append(n1)
  nodes.append(n2)
  nodes.append(n3)
  nodes.append(n4)
  nodes.append(n5)

  # init graph
  g = Graph(nodes)
  root = g.nodes[0]

  depthFirstSearch(root)