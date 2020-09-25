// This is Greedy version.

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
  float change;

  // Prompt user for how much he is owed. It will only consider: positive
  //decimal numbers (not negatives nor words).
  do {
    change = get_float("How much change are you owed: ");
  }
  while (change <= 0);

  // Convert the floating number into integer after converting dolars to pennies.
  int change_int = round(change * 100);

  int quar_int = 25;
  int dime_int = 10;
  int nick_int = 5;
  int penn_int = 1;

  int change_int_result = change_int;
  int nr_quar = 0;
  int nr_dime = 0;
  int nr_nick = 0;
  int nr_penn = 0;

  // Start the change analysis by the largest possible coin: quarters.
  for (nr_quar = 0; change_int_result > 0; nr_quar++) {

    change_int_result -= quar_int;

    if (change_int_result < 0) {
      change_int_result += quar_int;
      break;
    }
  }

  // Continue the analysis by the second largest possible coin: dimes.
  for (nr_dime = 0; change_int_result > 0; nr_dime++) {

    change_int_result -= dime_int;

    if (change_int_result < 0) {
      change_int_result += dime_int;
      break;
    }
  }

  // Follows up by the second smallest coin: nickels.
  for (nr_nick = 0; change_int_result > 0; nr_nick++) {

    change_int_result -= nick_int;

    if (change_int_result < 0) {
      change_int_result += nick_int;
      break;
    }
  }

  // Ends the analysis with the lowest possible coin: pennies.
  for (nr_penn = 0; change_int_result > 0; nr_penn++) {

    change_int_result -= penn_int;

    if (change_int_result < 0) {
      change_int_result += penn_int;
      break;
    }
  }

  // Prints the number of coins needed to do the change.
  int nr_coins = nr_quar + nr_penn + nr_nick + nr_dime;

  printf("%i\n", nr_coins);
  // This code could turn into something more neat, but I am finding some trouble in
  // creating a function that would call a "coin" and calculate the change from there.
}