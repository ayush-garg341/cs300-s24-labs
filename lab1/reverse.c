#include <stdio.h>
#include <stdlib.h>

/**
 * TODO:
 * In this file, you will write two functions:
 *
 * 1. reverse_arr: will take in two inputs a char* array and the number of
 * elements in the array. It's responsible for reversing the input array. You
 * should be modifying this array in place. Meaning that you shouldn't returning
 * anything from this function.
 *
 * 2. swap: will take in two elements from the array and swap them. Returns
 * nothing.
 *
 * Example:
 * Given an array ["hello", "my", "name", "is"], after calling reverse_arr
 * will result in ["is", "name", "my", "hello"]
 */

void swap(char **array, int start_idx, int end_idx) {
  char *temp = array[start_idx];
  array[start_idx] = array[end_idx];
  array[end_idx] = temp;
}

void reverse_arr(char **array, int num) {
  if (num >= 2) {
    for (int idx = 0; idx < num / 2; idx++) {
      int end_idx = num - idx - 1;
      swap(array, idx, end_idx);
    }
  }
}
