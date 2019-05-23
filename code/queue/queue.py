class Queue:

  def __init__(self):
    self.queue = []

  def isEmpty(self):
    return len(self.queue) == 0

  def add(self, data):
    self.queue.append(data)

  def remove(self):
    if (not len(self.queue) == 0):
      self.queue.pop(0)
    else:
      print("Empty queue!")
  
  def peek(self):
    if (not len(self.queue) == 0):
      return self.queue[0]
    else:
      print("Empty queue!")