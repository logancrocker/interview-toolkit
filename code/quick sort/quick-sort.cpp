#include <iostream>

using namespace std;

void swap(int* a, int* b) { 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition(int arr[], int left, int right) {
  int pivot = arr[right];
  int i = left - 1;

  for (int j = left; j <= right - 1; ++j) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[right]);
  return (i + 1);
}

void quickSort(int arr[], int left, int right) {
  if (left < right) {
    int partitionIndex = partition(arr, left, right);

    quickSort(arr, left, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, right);
  }
}

int main() {

  int arr[10] = { 3, 8, 4, 1, 9, 10, 5, 2, 7, 6 };
  const int size = sizeof(arr) / sizeof(arr[0]);

  quickSort(arr, 0, size - 1);

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}