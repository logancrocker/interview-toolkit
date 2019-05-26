#include <iostream>

using namespace std;

class Vector {
  private:
    int* items = new int[5];
    int capacity = 5;
    int length = 0;

  public:
    bool empty() {
      return this->length == 0;
    }

    int size() {
      return this->length;
    }

    void push_back(int item) {
      if (this->length < this->capacity) {
        this->items[this->length] = item;
        this->length++;
      }
      else {
        int newCapacity = this->capacity * 2;
        int* newItems = new int[newCapacity];
        for (int i = 0; i < this->capacity; ++i) {
          newItems[i] = this->items[i];
        }
        newItems[this->length] = item;
        this->length++;
        delete[] this->items;
        this->items = newItems;
        this->capacity = newCapacity;
      }
    }

    int at(int index) {
      if (this->length == 0) {
        cout << "Empty vector!" << endl;
        return -1;
      }
      else {
        return this->items[index];
      }
    }

};