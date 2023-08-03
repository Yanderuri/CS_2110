/**
 * CS 2110 - Spring 2023
 * Final Exam - Kirby Food Queue
 *
 * Name: Vy Mai
 */

/**
 *
 * IMPORTANT: string.h has been included so you are encouraged to use any string functions (strlen, strncpy, etc.) that you may need.
 */

// DO NOT MODIFY THE INCLUDE(s) LIST
#include "food.h"

// Global variables
struct wrapper *head = NULL; // Head of the food list (a linked list)

/** makeWrapper
 *
 * Creates a new wrapper at the head which will hold either a pear or potato.
 * If the wrapper is created properly, set its foodType to the provided foodType.
 * If the provided type is a pear, the new wrapper should hold given info on the pear.
 * If the provided type is a potato, the new wrapper should hold given info on the potato.
 * If everything was allocated and copied without problems, then push this wrapper to the front of the food linked list.
 * The head of the food linked list is stored in the global variable 'head' (listed on top).
 *
 * NOTE: Check out the 'food.h' file for more info on the structs
 * ------------------------------------------------
 * Here is the struct definition of a wrapper.
 * struct wrapper {
 *  struct data data;
 *  struct wrapper *next;
 * };
 * ------------------------------------------------
 *
 *
 * NOTE: You should create deep copies of the elements if needed.
 *
 * NOTE: If this function succeeds, it should return SUCCESS and add the newly created
 *       wrapper to the front of the list. If it fails, it should return FAILURE.
 *
 * @param foodType An enum that specifies the type of food contained in the wrapper
 * @param damage The amount of damage done if the food in the wrapper is a pear
 * @param pearVariety The type of pear if the food in the wrapper is a pear
 * @param health The amount of health restored if the food in the wrapper is a potato
 * @return FAILURE if any of the following are true:
 *         (1) pearVariety is NULL if foodType is PEAR
 *         (2) dynamic memory allocation failure occurs
 *         Otherwise, return SUCCESS
 */
int makeWrapper(foodType foodType, int damage, const char *pearVariety, int health)
{

  if (foodType == PEAR && pearVariety == NULL)
  {
    return FAILURE;
  }
  struct wrapper * curr = malloc(sizeof(struct wrapper));
  if (curr == NULL)
  {
    return FAILURE;
  }
  curr->data.foodType = foodType;
  if (foodType == PEAR)
  {
    curr->data.food.pear.damage = damage;
    if ((curr->data.food.pear.pearVariety = malloc(strlen(pearVariety) + 1)) == NULL)
    {
      free(curr);
      return FAILURE;
    }
    strcpy(curr->data.food.pear.pearVariety, pearVariety);
  }
  else if (foodType == POTATO)
  {
    curr->data.food.potato.health = health;
  }
  if (head == NULL)
  {
    head = curr;
    curr->next = NULL;
    return SUCCESS;
  }
  else
  {
    curr->next = head;
    head = curr;
    return SUCCESS;
  }
  return FAILURE;
}

/** replacePearVariety
 *
 * Iterate through the list of food and find the first wrapper with a pear that
 * has a pearVariety in it that is the same as the targetVariety. For that pear,
 * replace its pearVariety with the replacementVariety. Only reassign the pearVariety
 * given that dynamic memory allocation succeeds.
 *
 * Leave any other struct fields unchanged. If dynamic memory allocation fails at any
 * point, leave any previously existing fields unchanged.
 *
 * Remember that you have access to the head global variable.
 *
 * You should make deep copies anytime you change a pearVariety.
 *
 * IMPORTANT: 'replacementVariety' is the given parameter
 * IMPORTANT: 'pearVariety' is the function name
 *
 * @param replacementVariety a string containing the new pearVariety
 * @param targetVariety a string containing the old pearVariety to find in the list
 * @return FAILURE if any of the following are true:
 *         (1) replacementVariety is NULL
 *         (2) targetVariety is NULL
 *         (3) targetVariety was not found in the list
 *         (4) dynamic memory allocation failure occurs
 *         Otherwise, return SUCCESS
 */
int replacePearVariety(const char *replacementVariety, const char *targetVariety)
{
  if (replacementVariety == NULL || targetVariety == NULL)
  {
    return FAILURE;
  }
  struct wrapper * curr = head;
  char * old = NULL;
  while (curr != NULL)
  {
    if (curr->data.foodType == PEAR && strcmp(curr->data.food.pear.pearVariety, targetVariety) == 0)
    {
      old = curr->data.food.pear.pearVariety;
      if ((curr->data.food.pear.pearVariety = malloc(strlen(replacementVariety) + 1)) == NULL)
      {
        curr->data.food.pear.pearVariety = old;
        return FAILURE;
      }
      free(old);
      strcpy(curr->data.food.pear.pearVariety, replacementVariety);
      return SUCCESS;
    }
    curr = curr->next;
  }
  return FAILURE;
}
