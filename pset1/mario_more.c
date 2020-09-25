// This is Mario more version.

#include <stdio.h>
#include <cs50.h>

int main(void) {
  // Prompt user to decide which height he wants the column to have
  int height;

  do {
      height = get_int("Please choose desired height (1-8): ");
  }
  while (height < 1 || height > 8);
  
  // Design & align the column
  int i;
  int j;
  int length = 2 * (1 + height);
  int mid_0 = height - 1;
  int mid_1 = height + 2;
  int left;
  int right;
  
  for (i = 0; i < height; i++) {
    left = mid_0 - i;
    right = length - height + i;

    for (j = 0; j < length; j++) {
      if ((j >= left && j <= mid_0) || (j >= mid_1 && j <= right) ) {
        printf("#");
      }
      else {
        printf(" ");
      }
    }
    printf("\n");
  }
}