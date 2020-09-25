// This is Mario less version.

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
    int k;
    int dots;
    int card;

    for (i = 0; i < height; i++) {
        card = i ;
        dots = height - card - 1;

        for (j = 0; j < dots ; j++) {
            printf(" ");
        }

        for (k = 0; k <= card; k++) {
            printf("#");
        }
        printf("\n");

    }
}
