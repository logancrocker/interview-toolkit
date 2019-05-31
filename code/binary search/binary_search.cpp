#include <iostream>

using namespace std;

int recursive(int arr[], int left, int right, int value) {
  if (right >= left) {
    int mid = left + (right - left) / 2;

    if(arr[mid] == value) {
      return mid;
    }
    else if (arr[mid] > value) {
      return recursive(arr, left, mid - 1, value);
    }
    else {
      return recursive(arr, mid + 1, right, value);
    }
  }
  return -1;
}

int iterative(int arr[], int left, int right, int value) {
  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == value) {
      return mid;
    }
    else if (arr[mid] < value) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }
  return -1;
}

int main() {

  int arr[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

  return 0;
}