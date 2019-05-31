#include <iostream>

using namespace std;

void merge(int arr[], int left, int mid, int right) {
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int* leftHelper = new int[n1];
  int* rightHelper = new int[n2];

  for (i = 0; i < n1; ++i) {
    leftHelper[i] = arr[left + i];
  } 
  for (j = 0; j < n1; ++j) {
    rightHelper[j] = arr[mid + 1 + j];
  } 

  i = 0;
  j = 0;
  k = left;
  while (i < n1 && j < n2) {
    if (leftHelper[i] <= rightHelper[j]) {
      arr[k] = leftHelper[i];
      i++;
    }
    else {
      arr[k] = rightHelper[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = leftHelper[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = rightHelper[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int left, int right) {

  if (left < right) {
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
  }
}

int main() {

  int arr[10] = { 3, 8, 4, 1, 9, 10, 5, 2, 7, 6 };
  const int size = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, size - 1);

  for (int i = 0; i < size; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}