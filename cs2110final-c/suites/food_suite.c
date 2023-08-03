/**
 * @file food_suite.c
 * @author Sameer
 * @brief Testing Suites to Final-C - Summer 2023
 * @date 2023-29-07
 */

// Check Docs
// Tutorial : https://libcheck.github.io/check/doc/check_html/check_3.html
// Check API: https://libcheck.github.io/check/doc/doxygen/html/check_8h.html

// System Headers
#include <string.h>
#include <check.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <sys/wait.h> // For grabbing return value of system call

// TA Headers
#include "test_utils.h"

int mallocs_until_fail = -1;


// allow infinite mallocs by default
static void reset_mallocs_until_fail_and_malloclist(void) {
   // malloclist = NULL;
    mallocs_until_fail = -1;
}

/* Tests */

START_TEST(test_create_pear_empty_list) {
    head = NULL;
    // Unlimited Malloc
    mallocs_until_fail = -1;

    foodType foodType = PEAR;
    int damage = 5;
    char *pearVariety = "Anjou";
    int health = 99;

    int retVal = makeWrapper(foodType, damage, pearVariety, health);
    ck_assert_msg(retVal == SUCCESS,                                           "Error with makeWrapper() when used on empty list! Expected return value: SUCCESS");
    ck_assert_msg(head->data.foodType == PEAR, "Error with makeWrapper() when used on empty list! Expected foodType: PEAR");
    ck_assert_msg(strcmp(head->data.food.pear.pearVariety, "Anjou") == 0, "Error with makeWrapper() when used on empty list! Expected pearVariety: %s but was: %s", pearVariety, head->data.food.pear.pearVariety);
    ck_assert_msg(head->data.food.pear.damage == 5,                           "Error with makeWrapper() when used on empty list! Expected pear damage: %d but was: %d", damage, head->data.food.pear.damage);
    ck_assert_msg(head->next == NULL,                                          "Error with makeWrapper() when used on empty list! Remember to set head->next to NULL!");
    
    free(head->data.food.pear.pearVariety);
    free(head);
}
END_TEST

START_TEST(test_create_potato_empty_list) {
    head = NULL;
    // Unlimited Malloc
    mallocs_until_fail = -1;

    foodType foodType = POTATO;
    int damage = 5;
    char *pearVariety = "Scrumptious";
    int health = 99;

    int retVal = makeWrapper(foodType, damage, pearVariety, health);
    ck_assert_msg(retVal == SUCCESS,                       "Error with makeWrapper()! Expected return value on empty list: SUCCESS");
    ck_assert_msg(head->data.foodType == POTATO, "Error with makeWrapper() when used on empty list! Expected foodType: POTATO");
    ck_assert_msg(head->data.food.potato.health == 99,     "Error with makeWrapper()! Expected potato health: %d but was: %d", health, head->data.food.potato.health);
    ck_assert_msg(head->next == NULL,                      "Error with makeWrapper()! Remember to set head->next to NULL if the list is empty!");
    
    free(head);
}
END_TEST

START_TEST(test_create_potato_malloc_failure) {
    head = NULL;
    // No Malloc Usages
    mallocs_until_fail = 0;

    foodType foodType = POTATO;
    int damage = 5;
    char *pearVariety = "BigPotato";
    int health = 99;

    int retVal = makeWrapper(foodType, damage, pearVariety, health);
    ck_assert_msg(retVal == FAILURE, "Error with makeWrapper()! Should return FAILURE on malloc failure");
    ck_assert_msg(head == NULL,      "Error with makeWrapper()! Wrapper should not be added to list upon malloc failure");
}
END_TEST

START_TEST(test_create_pear_malloc_failure) {
    head = NULL;
    // No Malloc Usages
    mallocs_until_fail = 0;

    foodType foodType = POTATO;
    int damage = 5;
    char *pearVariety = "ThisIsAPotatoItDoesntHaveAName";
    int health = 99;

    int retVal = makeWrapper(foodType, damage, pearVariety, health);
    ck_assert_msg(retVal == FAILURE, "Error with makeWrapper()! Should return FAILURE on malloc failure");
    ck_assert_msg(head == NULL,      "Error with makeWrapper()! Wrapper should not be added to list upon malloc failure");
}
END_TEST

START_TEST(test_create_pear_null_string) {
    head = NULL;
    // Unlimited Malloc
    mallocs_until_fail = -1;

    foodType foodType = PEAR;
    int damage = 5;
    char *pearVariety = NULL;
    int health = 99;

    int retVal = makeWrapper(foodType, damage, pearVariety, health);

    ck_assert_msg(retVal == FAILURE, "Error with makeWrapper()! Should return FAILURE on NULL string input");
    ck_assert_msg(head == NULL,      "Error with makeWrapper()! Wrapper should not be added to list upon failure");
}
END_TEST

START_TEST(test_create_pear_malloc_string_failure) {
    head = NULL;
    // 1 Malloc Usage
    mallocs_until_fail = 1;

    foodType foodType = PEAR;
    int damage = 5;
    char *pearVariety = "BadName";
    int health = 99;

    int retVal = makeWrapper(foodType, damage, pearVariety, health);

    ck_assert_msg(retVal == FAILURE, "Error with makeWrapper()! Should return FAILURE on malloc failure");
    ck_assert_msg(head == NULL,      "Error with makeWrapper()! Wrapper should not be added to list upon failure");
}
END_TEST

START_TEST(test_create_pear_big_list) {
    head = NULL;
    // Unlimited Malloc
    mallocs_until_fail = -1;

    foodType foodType1 = PEAR;
    int damage1 = 10;
    char *pearVariety1 = "Bartlett";
    int health1 = -5;
    _makeWrapper(foodType1, damage1, pearVariety1, health1);

    foodType foodType2 = POTATO;
    int damage2 = -5;
    char *pearVariety2 = "NoThanks!";
    int health2 = 5;
    _makeWrapper(foodType2, damage2, pearVariety2, health2);

    foodType foodType3 = PEAR;
    int damage3 = 20;
    char *pearVariety3 = "Comice";
    int health3 = -10;
    _makeWrapper(foodType3, damage3, pearVariety3, health3);

    // New Wrapper info to add:
    foodType foodType4 = PEAR;
    int damage4 = 30;
    char *pearVariety4 = "Bosc";
    int health4 = -50;
    int retVal = makeWrapper(foodType4, damage4, pearVariety4, health4);

    ck_assert_msg(retVal == SUCCESS, "Error with makeWrapper()! should return SUCCESS when wrapper added successfully");
    
    ck_assert_msg(head->next->next->next->data.foodType == PEAR,                    "Error with makeWrapper()! Incorrect foodType");
    ck_assert_msg(strcmp(head->next->next->next->data.food.pear.pearVariety, "Bartlett") == 0,  "Error with makeWrapper()! Pear name not set properly!");
    ck_assert_msg(head->next->next->next->data.food.pear.damage == 10,                    "Error with makeWrapper()! Incorrect damage/health");
    ck_assert_msg(head->next->next->next->next == NULL,                                    "Error with makeWrapper()! NULL pointer on tail not set");

    ck_assert_msg(head->next->next->data.foodType == POTATO,    "Error with makeWrapper()! Incorrect foodType");
    ck_assert_msg(head->next->next->data.food.potato.health == 5,    "Error with makeWrapper()! Incorrect damage/health");

    ck_assert_msg(head->next->data.foodType == PEAR,                          "Error with makeWrapper()! Incorrect foodType");
    ck_assert_msg(strcmp(head->next->data.food.pear.pearVariety, "Comice") == 0,  "Error with makeWrapper()! Pear name not set properly!");
    ck_assert_msg(head->next->data.food.pear.damage == 20,                          "Error with makeWrapper()! Incorrect damage/health");

    ck_assert_msg(head->data.foodType == PEAR, "Error with makeWrapper()! Incorrect foodType");
    ck_assert_msg(strcmp(head->data.food.pear.pearVariety, "Bosc") == 0,    "Error with makeWrapper()! Pear name not set properly!");
    ck_assert_msg(head->data.food.pear.damage == 30,                          "Error with makeWrapper()! Incorrect damage/health");

    free(head->next->next->next->data.food.pear.pearVariety);
    free(head->next->next->next);
    free(head->next->next);
    free(head->next->data.food.pear.pearVariety);
    free(head->next);
    free(head->data.food.pear.pearVariety);
    free(head);
}
END_TEST

START_TEST(test_create_potato_big_list) {
    head = NULL;
    // Unlimited Malloc
    mallocs_until_fail = -1;

    foodType foodType1 = PEAR;
    int damage1 = 10;
    char *pearVariety1 = "Bartlett";
    int health1 = -5;
    _makeWrapper(foodType1, damage1, pearVariety1, health1);

    foodType foodType2 = POTATO;
    int damage2 = -5;
    char *pearVariety2 = "NoThanks!";
    int health2 = 5;
    _makeWrapper(foodType2, damage2, pearVariety2, health2);

    foodType foodType3 = PEAR;
    int damage3 = 20;
    char *pearVariety3 = "Comice";
    int health3 = -10;
    _makeWrapper(foodType3, damage3, pearVariety3, health3);

    // New Wrapper info to add:
    foodType foodType4 = POTATO;
    int damage4 = -50;
    char *pearVariety4 = "Bosc";
    int health4 = 50;
    int retVal = makeWrapper(foodType4, damage4, pearVariety4, health4);

    ck_assert_msg(retVal == SUCCESS, "Error with makeWrapper()! Should return SUCCESS when wrapper added successfully");
    
    ck_assert_msg(head->next->next->next->data.foodType == PEAR,                    "Error with makeWrapper()! Incorrect foodType");
    ck_assert_msg(strcmp(head->next->next->next->data.food.pear.pearVariety, "Bartlett") == 0,  "Error with makeWrapper()! Pear name not set properly!");
    ck_assert_msg(head->next->next->next->data.food.pear.damage == 10,                    "Error with makeWrapper()! Incorrect damage/health");
    ck_assert_msg(head->next->next->next->next == NULL,                                    "Error with makeWrapper()! NULL pointer on tail not set");

    ck_assert_msg(head->next->next->data.foodType == POTATO,        "Error with makeWrapper()! Incorrect foodType");
    ck_assert_msg(head->next->next->data.food.potato.health == 5,       "Error with makeWrapper()! Incorrect damage/health");

    ck_assert_msg(head->next->data.foodType == PEAR,                         "Error with makeWrapper()! Incorrect damage/health");
    ck_assert_msg(strcmp(head->next->data.food.pear.pearVariety, "Comice") == 0,  "Error with makeWrapper()! Pear name not set properly!");
    ck_assert_msg(head->next->data.food.pear.damage == 20,                          "Error with makeWrapper()! Incorrect damage/health");

    ck_assert_msg(head->data.foodType == POTATO,                          "Error with makeWrapper()! Incorrect foodType");
    ck_assert_msg(head->data.food.potato.health == 50,                         "Error with makeWrapper()! Incorrect damage/health");

    free(head->next->next->next->data.food.pear.pearVariety);
    free(head->next->next->next);
    free(head->next->next);
    free(head->next->data.food.pear.pearVariety);
    free(head->next);
    free(head);
}
END_TEST

START_TEST(test_change_pear_variety_null_replacement) {
    
    head = NULL;
    // Unlimited Malloc
    mallocs_until_fail = -1;

    makeWrapper(PEAR, 10, "Bartlett", 50);
    makeWrapper(PEAR, 20, "Bosc", 60);
    makeWrapper(PEAR, 30, "Bosc", 70);
    makeWrapper(POTATO, 40, "Comice", 80);

    char *replacementVariety = NULL;
    char *targetVariety = "Bosc";

    // The actual tests
    int retVal = replacePearVariety(replacementVariety, targetVariety);

    ck_assert_msg(retVal == FAILURE, "Error with replacePearVariety()! should return FAILURE on NULL string input");

    ck_assert_msg(strcmp(head->next->next->next->data.food.pear.pearVariety, "Bartlett") == 0,  "Error with replacePearVariety()! Pear name not set properly!");
    ck_assert_msg(head->next->next->next->data.food.pear.damage == 10,                    "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->next->next->next->data.food.potato.health == 10,                   "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->next->next->next->next == NULL,                                    "Error with replacePearVariety()! Error with makeWrapper()! NULL pointer on tail not set");

    ck_assert_msg(strcmp(head->next->next->data.food.pear.pearVariety, "Bosc") == 0,    "Error with replacePearVariety()! Pear name not set properly!");
    ck_assert_msg(head->next->next->data.food.pear.damage == 20,                          "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->next->next->data.food.potato.health == 20,                         "Error with replacePearVariety()! Incorrect damage/health");

    ck_assert_msg(strcmp(head->next->data.food.pear.pearVariety, "Bosc") == 0,          "Error with replacePearVariety()! Pear name not set properly!");
    ck_assert_msg(head->next->data.food.pear.damage == 30,                                "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->next->data.food.potato.health == 30,                               "Error with replacePearVariety()! Incorrect damage/health");

    ck_assert_msg(head->data.food.pear.damage == 80,                                      "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->data.food.potato.health == 80,                                     "Error with replacePearVariety()! Incorrect damage/health");
    
    free(head->next->next->next->data.food.pear.pearVariety);
    free(head->next->next->next);
    free(head->next->next->data.food.pear.pearVariety);
    free(head->next->next);
    free(head->next->data.food.pear.pearVariety);
    free(head->next);
    free(head);

}
END_TEST

START_TEST(test_change_pear_variety_null_target) {
    
    head = NULL;
    // Unlimited Malloc
    mallocs_until_fail = -1;

    _makeWrapper(PEAR, 10, "Bartlett", 50);
    _makeWrapper(PEAR, 20, "Bosc", 60);
    _makeWrapper(PEAR, 30, "Bosc", 70);
    _makeWrapper(POTATO, 40, "Comice", 80);

    char *replacementVariety = "PearCat";
    char *targetVariety = NULL;

    // The actual tests
    int retVal = replacePearVariety(replacementVariety, targetVariety);

    ck_assert_msg(retVal == FAILURE, "Error with replacePearVariety()! should return FAILURE on NULL string input %d %d", retVal, FAILURE);

    ck_assert_msg(strcmp(head->next->next->next->data.food.pear.pearVariety, "Bartlett") == 0,  "Error with replacePearVariety()! Pear name not set properly!");
    ck_assert_msg(head->next->next->next->data.food.pear.damage == 10,                    "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->next->next->next->data.food.potato.health == 10,                   "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->next->next->next->next == NULL,                                    "Error with replacePearVariety()! Error with makeWrapper()! NULL pointer on tail not set");

    ck_assert_msg(strcmp(head->next->next->data.food.pear.pearVariety, "Bosc") == 0,    "Error with replacePearVariety()! Pear name not set properly!");
    ck_assert_msg(head->next->next->data.food.pear.damage == 20,                          "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->next->next->data.food.potato.health == 20,                         "Error with replacePearVariety()! Incorrect damage/health");

    ck_assert_msg(strcmp(head->next->data.food.pear.pearVariety, "Bosc") == 0,          "Error with replacePearVariety()! Pear name not set properly!");
    ck_assert_msg(head->next->data.food.pear.damage == 30,                                "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->next->data.food.potato.health == 30,                               "Error with replacePearVariety()! Incorrect damage/health");

    ck_assert_msg(head->data.food.pear.damage == 80,                                      "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->data.food.potato.health == 80,                                     "Error with replacePearVariety()! Incorrect damage/health");

    free(head->next->next->next->data.food.pear.pearVariety);
    free(head->next->next->next);
    free(head->next->next->data.food.pear.pearVariety);
    free(head->next->next);
    free(head->next->data.food.pear.pearVariety);
    free(head->next);
    free(head);
}
END_TEST


START_TEST(test_change_pear_variety) {
    
    head = NULL;
    // Unlimited Malloc
    mallocs_until_fail = -1;

    _makeWrapper(PEAR, 10, "Bartlett", 50);
    _makeWrapper(PEAR, 20, "Bosc", 60);
    _makeWrapper(PEAR, 30, "Bosc", 70);
    _makeWrapper(POTATO, 40, "Comice", 80);

    char *replacementVariety = "PearCat";
    char *targetVariety = "Bosc";

    // The actual tests
    int retVal = replacePearVariety(replacementVariety, targetVariety);

    ck_assert_msg(retVal == SUCCESS, "Error with replacePearVariety()!");

    ck_assert_msg(strcmp(head->next->next->next->data.food.pear.pearVariety, "Bartlett") == 0,  "Error with replacePearVariety()! Pear name not set properly!");
    ck_assert_msg(head->next->next->next->data.food.pear.damage == 10,                    "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->next->next->next->data.food.potato.health == 10,                   "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->next->next->next->next == NULL,                                    "Error with replacePearVariety()! NULL pointer on tail not set");

    ck_assert_msg(strcmp(head->next->next->data.food.pear.pearVariety, "Bosc") == 0,    "Error with replacePearVariety()! Pear name not set properly!");
    ck_assert_msg(head->next->next->data.food.pear.damage == 20,                          "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->next->next->data.food.potato.health == 20,                         "Error with replacePearVariety()! Incorrect damage/health");

    ck_assert_msg(strcmp(head->next->data.food.pear.pearVariety, "PearCat") == 0,          "Error with replacePearVariety()! Pear name not set properly!");
    ck_assert_msg(head->next->data.food.pear.damage == 30,                                "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->next->data.food.potato.health == 30,                               "Error with replacePearVariety()! Incorrect damage/health");

    ck_assert_msg(head->data.food.pear.damage == 80,                                      "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->data.food.potato.health == 80,                                     "Error with replacePearVariety()! Incorrect damage/health");

    free(head->next->next->next->data.food.pear.pearVariety);
    free(head->next->next->next);
    free(head->next->next->data.food.pear.pearVariety);
    free(head->next->next);
    free(head->next->data.food.pear.pearVariety);
    free(head->next);
    free(head);
}
END_TEST


START_TEST(test_change_pear_variety_empty_list) {
    
    head = NULL;
    // Unlimited Malloc
    mallocs_until_fail = -1;

    char *replacementVariety = "PearCat";
    char *targetVariety = "Bosc";

    // The actual tests
    int retVal = replacePearVariety(replacementVariety, targetVariety);

    ck_assert_msg(retVal == FAILURE, "Error with replacePearVariety() on empty list!");
    ck_assert_msg(head == NULL,      "Error with replacePearVariety() on empty list!");
}
END_TEST


START_TEST(test_change_pear_variety_malloc_failure) {
    head = NULL;

    _makeWrapper(PEAR, 10, "Bartlett", 50);
    _makeWrapper(PEAR, 20, "Bosc", 60);
    _makeWrapper(PEAR, 30, "Bosc", 70);
    _makeWrapper(POTATO, 40, "Comice", 80);

    char *replacementVariety = "PearCat";
    char *targetVariety = "Bosc";

    // No Malloc
    mallocs_until_fail = 0;
    int retVal = replacePearVariety(replacementVariety, targetVariety);

    ck_assert_msg(retVal == FAILURE, "Error with replacePearVariety()!");

    ck_assert_msg(strcmp(head->next->next->next->data.food.pear.pearVariety, "Bartlett") == 0,  "Error with replacePearVariety()! Pear name not set properly!");
    ck_assert_msg(head->next->next->next->data.food.pear.damage == 10,                    "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->next->next->next->data.food.potato.health == 10,                   "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->next->next->next->next == NULL,                                    "Error with replacePearVariety()! NULL pointer on tail not set");

    ck_assert_msg(strcmp(head->next->next->data.food.pear.pearVariety, "Bosc") == 0,    "Error with replacePearVariety()! Pear name not set properly!");
    ck_assert_msg(head->next->next->data.food.pear.damage == 20,                          "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->next->next->data.food.potato.health == 20,                         "Error with replacePearVariety()! Incorrect damage/health");

    ck_assert_msg(strcmp(head->next->data.food.pear.pearVariety, "Bosc") == 0,          "Error with replacePearVariety()! Pear name not set properly!");
    ck_assert_msg(head->next->data.food.pear.damage == 30,                                "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->next->data.food.potato.health == 30,                               "Error with replacePearVariety()! Incorrect damage/health");

    ck_assert_msg(head->data.food.pear.damage == 80,                                      "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->data.food.potato.health == 80,                                     "Error with replacePearVariety()! Incorrect damage/health");
    
    free(head->next->next->next->data.food.pear.pearVariety);
    free(head->next->next->next);
    free(head->next->next->data.food.pear.pearVariety);
    free(head->next->next);
    free(head->next->data.food.pear.pearVariety);
    free(head->next);
    free(head);
}
END_TEST

START_TEST(test_change_pear_variety_no_match) {
    head = NULL;

    _makeWrapper(POTATO, 10, "Bartlett", 50);
    _makeWrapper(PEAR, 20, "Bosc", 60);
    _makeWrapper(POTATO, 30, "Bosc", 70);
    _makeWrapper(POTATO, 40, "Comice", 80);

    char *replacementVariety = "PearCat";
    char *targetVariety = "Bartlett";

    // Unlimited Malloc
    mallocs_until_fail = -1;
    int retVal = replacePearVariety(replacementVariety, targetVariety);

    ck_assert_msg(retVal == FAILURE, "Error with replacePearVariety()!");
    
    ck_assert_msg(head->next->next->next->data.food.pear.damage == 50,                    "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->next->next->next->data.food.potato.health == 50,                   "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->next->next->next->next == NULL,                                    "Error with replacePearVariety()! NULL pointer on tail not set");

    ck_assert_msg(strcmp(head->next->next->data.food.pear.pearVariety, "Bosc") == 0,    "Error with replacePearVariety()! Pear name not set properly!");
    ck_assert_msg(head->next->next->data.food.pear.damage == 20,                          "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->next->next->data.food.potato.health == 20,                         "Error with replacePearVariety()! Incorrect damage/health");

    ck_assert_msg(head->next->data.food.pear.damage == 70,                                "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->next->data.food.potato.health == 70,                               "Error with replacePearVariety()! Incorrect damage/health");

    ck_assert_msg(head->data.food.pear.damage == 80,                                      "Error with replacePearVariety()! Incorrect damage/health");
    ck_assert_msg(head->data.food.potato.health == 80,                                     "Error with replacePearVariety()! Incorrect damage/health");

    free(head->next->next->next);
    free(head->next->next->data.food.pear.pearVariety);
    free(head->next->next);
    free(head->next);
    free(head);
}
END_TEST


Suite *food_suite(void)
{
    Suite *s = suite_create("food_suite");

    // push tests
    tcase_singleton(s, reset_mallocs_until_fail_and_malloclist, NULL, test_create_pear_empty_list);
    tcase_singleton(s, reset_mallocs_until_fail_and_malloclist, NULL, test_create_potato_empty_list);
    tcase_singleton(s, reset_mallocs_until_fail_and_malloclist, NULL, test_create_potato_malloc_failure);
    tcase_singleton(s, reset_mallocs_until_fail_and_malloclist, NULL, test_create_pear_malloc_failure);
    tcase_singleton(s, reset_mallocs_until_fail_and_malloclist, NULL, test_create_pear_malloc_string_failure);
    tcase_singleton(s, reset_mallocs_until_fail_and_malloclist, NULL, test_create_pear_null_string);
    tcase_singleton(s, reset_mallocs_until_fail_and_malloclist, NULL, test_create_pear_big_list);
    tcase_singleton(s, reset_mallocs_until_fail_and_malloclist, NULL, test_create_potato_big_list);
    tcase_singleton(s, reset_mallocs_until_fail_and_malloclist, NULL, test_change_pear_variety);
    tcase_singleton(s, reset_mallocs_until_fail_and_malloclist, NULL, test_change_pear_variety_null_target);
    tcase_singleton(s, reset_mallocs_until_fail_and_malloclist, NULL, test_change_pear_variety_null_replacement);
    tcase_singleton(s, reset_mallocs_until_fail_and_malloclist, NULL, test_change_pear_variety_malloc_failure);
    tcase_singleton(s, reset_mallocs_until_fail_and_malloclist, NULL, test_change_pear_variety_empty_list);
    tcase_singleton(s, reset_mallocs_until_fail_and_malloclist, NULL, test_change_pear_variety_no_match);

    return s;
}
