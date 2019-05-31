def mergeSort(arr):
  if len(arr) > 1:
    mid = len(arr) // 2

    leftHelper = arr[:mid]
    rightHelper = arr[mid:]

    mergeSort(leftHelper)
    mergeSort(rightHelper)

    i = j = k = 0

    while i < len(leftHelper) and j < len(rightHelper):
      if leftHelper[i] < rightHelper[j]:
        arr[k] = leftHelper[i]
        i += 1

      else:
        arr[k] = rightHelper[j]
        j += 1

      k += 1

    while i < len(leftHelper):
      arr[k] = leftHelper[i]
      i += 1
      k += 1

    while j < len(rightHelper):
      arr[k] = rightHelper[j]
      j += 1
      k += 1

if __name__ == '__main__':
  arr = [ 3, 8, 4, 1, 9, 10, 5, 2, 7, 6 ]

  mergeSort(arr)

  print(arr)
  