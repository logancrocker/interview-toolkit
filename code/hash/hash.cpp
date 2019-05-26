#include <iostream>
#include <string>

using namespace std;

class Hash {
  private:
    string* keys = new string[100];
  public:
    int hash(string key) {
      int sum = 0;
      for (char c : key) {
        sum += c;
      }
      return sum % 100;
    }
    void insert(string key) {
      int index = this->hash(key);
      this->keys[index] = key;
      return;
    }
    string retrieve(string key) {
      int index = this->hash(key);
      return this->keys[index];
    }
};