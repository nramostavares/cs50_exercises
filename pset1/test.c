// This is credit version.

#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>


int main(void) {
  // Declare all my variables.
  long credit_card;
  int digits;
  int counter = 0;
  int nr_digits;
  int num_multiplication;
  int sum_even_pos = 0;
  int sum_odd_pos = 0;
  string entity = "";

  // Ask the user for a credit card number.
  do {
    credit_card = get_long("Number: ");
  }
  while(credit_card < 0);

  while(credit_card>0) {
    // This counter will allow me to consider which position I am at (which will be
    // starting at last digit due to next function).
    counter += 1;

    // Parse credit_card last digit as the rest from modulo function.
    nr_digits = credit_card % 10;

    if (counter % 2 == 0){
      // For even numbers, I will multiply my digit by 2.
      num_multiplication = 2 * nr_digits;

      // In case it is a 2 digit result, and since the maximum value will be 18 (2 * 9),
      // I will split these digits by also applying the modulo function and adding 1 (from the 'tens' 'operation' - lack of better word).
      if(num_multiplication >= 10) {
        num_multiplication = num_multiplication % 10 + 1;
      }

      // Store this multiplication in a sum of sum even numbers variable.
      sum_even_pos += num_multiplication;
    }
    else {
      // As for odd numbers, I will just store and sum these values to a variable of sum odd position.
      sum_odd_pos += nr_digits;
    }

    // Once the number of credit_card gets parsed until 2 or 1 digits, describe which entity it belongs to.
    if (counter == 14 && (credit_card == 34 || credit_card == 37)) {
      entity = "AMEX";
    }
    else if ((credit_card == 51 || credit_card == 52 || credit_card == 53 || credit_card == 54 || credit_card == 55) && counter == 15) {
      entity = "MASTERCARD";
    }
    else if (credit_card == 4 && (counter >= 13 && counter <= 16) ) {
      entity = "VISA";
    }

    // Parse credit_card number by one digit.
    credit_card = credit_card/10;
  }

  // In case we can't find an entity it belongs to in this previous loop and if the resulting
  // sum (calculated in the next line) turns out not to be zero, then we're looking at an Invalid
  // credit card number.
  int final_sum = sum_even_pos + sum_odd_pos;

  if (final_sum % 10 != 0 || entity[0] == '\0' ) {
    printf("INVALID\n");
  }
  else {
    printf("%s\n", entity);
  }
}

