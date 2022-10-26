#include <stdio.h>

int binarySearch(int n, int arr[], int target, int *cnt) {
  int l = 0, r = n - 1;

  while (l <= r) {
    int mid = (l + r) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] > target) {
      r = mid;
    } else {
      l = mid;
    }
    (*cnt)++;
  }

  return -1;

}

int main() {
  int cnt = 0, index;
  int arr[] = {7, 9, 15, 21, 32, 40, 53, 60, 84, 96};
  int arr2[] = {1, 5, 7, 9, 10, 45, 56, 88, 99, 111};
  index = binarySearch(10, arr, 15, &cnt);
  // index = binarySearch(10, arr2, 9, &cnt);


  printf("%d\n", index);
  printf("found in %d tries", cnt);
}