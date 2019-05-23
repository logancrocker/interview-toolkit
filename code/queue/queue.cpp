#include <iostream>

using namespace std;

class Queue {
  private:
    int queue[10];
    int size = 0;
    int first = 0;
    int last = 0;

  public:
    void add(int item) {
      if (last == 10) {
        cout << "Full queue!" << endl;
      }
      else {
        this->queue[last] = item;
        this->last += 1;
        this->size += 1;
      }
    }

    void remove() {
      if (first == last) {
        cout << "Empty queue!" << endl;
      }
      else {
        for (int i = 0; i < last - 1; i++) {
          this->queue[i] = queue[i + 1];
        }
        this->last -= 1;
        this->size -= 1;
      }
    }

    bool isEmpty() {
      return this->size == 0;
    }

    int peek() {
      if (this->size == 0) {
        cout << "Empty queue!" << endl;
        return -1;
      }
      else {
        return this->queue[first];
      }
    }
};