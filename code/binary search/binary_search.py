def recursive(arr, left, right, value):
  if (left <= right):
    mid = left + (right - left) / 2

    if (arr[mid] == value):
      return mid

    elif (value < arr[mid]):
      return recursive(arr, left, mid - 1, value)

    else:
      return recursive(arr, mid + 1, right, value)
  
  return -1

def iterative(arr, left, right, value):
  while (left <= right):
    mid = left + (right - left) / 2

    if (arr[mid] == value):
      return mid

    elif (value < arr[mid]):
      right = mid - 1

    else:
      left = mid + 1

  return -1