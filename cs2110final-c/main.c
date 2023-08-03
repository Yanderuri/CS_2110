/**
 * CS 2110 - Fall 2021
 * Final Exam - Kirby Food Queue
 *
 * You may use this file to test your functions from food.c
 */

#include "food.h"

/**
 * @brief A main function that you can use for testing.
 * 
 * Implementing this function is NOT necessary for the final.
 * You can use this if you want to create custom tests.
 * We have included a basic test as an example.
 * 
 */
int main(void) {

    makeWrapper(PEAR, 50, "Anjou", 3475784); // health doesn't matter since its a pear
    printf("head data (pear damage: %d, pear variety: %s)", head->data.food.pear.damage, head->data.food.pear.pearVariety);

    replacePearVariety("Anjou", "Bartlett");
    printf("head data (pear variety: %s)", head->data.food.pear.pearVariety);
    return 0;
}
