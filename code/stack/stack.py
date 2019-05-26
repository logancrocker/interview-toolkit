class Stack:
  def __init__(self):
    self.stack = []

  def push(self, item):
    self.stack.append(item)

  def pop(self):
    if (not self.isEmpty()):
      self.stack.pop()
    else:
      print("Empty stack!")

  def peek(self):
    if (not self.isEmpty()):
      return self.stack[len(self.stack) - 1]
    else:
      print("Empty stack!")

  def isEmpty(self):
    return len(self.stack) == 0

