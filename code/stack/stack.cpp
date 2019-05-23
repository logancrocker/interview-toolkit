#include <iostream>

using namespace std;

class Stack {
  private:
	  int stack[100];
	  int size = 0;
	  int top = this->stack[size];

  public:
    void pop() {
      if (this->size >= 1) {
        this->top = this->stack[size - 2];
        this->size -= 1;
      }
      else {
        cout << "Empty stack!" << endl;
      }
    }

    void push(int item) {
      if (this->size < 100) {
        this->stack[size] = item;
        this->size += 1;
        this->top = item;
      }
      else {
        cout << "Stack overflow!" << endl;
      }
    }

    bool isEmpty() {
      return this->size == 0;
    }

    int peek() {
      if (!this->isEmpty()) {
        return this->top;
      }
      else {
        return -1;
      }
    }
};