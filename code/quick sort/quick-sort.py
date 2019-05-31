def partition(arr, left, right):
  i = left - 1
  pivot = arr[right]

  for j in range(left, right):

    if arr[j] <= pivot:
      
      i = i + 1
      arr[i], arr[j] = arr[j], arr[i]

  arr[i + 1], arr[right] = arr[right], arr[i + 1]

  return i + 1

def quickSort(arr, left, right):
  
  if left < right:

    partitionIndex = partition(arr, left, right)

    quickSort(arr, left, partitionIndex - 1)
    quickSort(arr, partitionIndex + 1, right)

arr = [10, 7, 8, 9, 1, 5]

quickSort(arr, 0, len(arr) - 1)

print(arr)