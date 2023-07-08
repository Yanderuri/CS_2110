/**
 * @file my_string.c
 * @author Vy Mai
 * @collaborators Me, myself and I
 * @brief Your implementation of these famous 3 string.h library functions!
 *
 * NOTE: NO ARRAY NOTATION IS ALLOWED IN THIS FILE
 *
 * @date 2023-03-xx
 */

#include <stddef.h>
#include "my_string.h"
#define CHAR_INC(a) ((a) += (sizeof(char)));
/**
 * @brief Calculate the length of a string
 *
 * @param s a constant C string
 * @return size_t the number of characters in the passed in string
 */
size_t my_strlen(const char *s)
{
    int ans = 0;
    while (*s != 0){
        s += sizeof(char);
        ans++;
    }
    return ans; 
}

/**
 * @brief Compare two strings
 *
 * @param s1 First string to be compared
 * @param s2 Second string to be compared
 * @param n First (at most) n bytes to be compared
 * @return int "less than, equal to, or greater than zero if s1 (or the first n
 * bytes thereof) is found, respectively, to be less than, to match, or be
 * greater than s2"
 */
int my_strncmp(const char *s1, const char *s2, size_t n)
{
    if (s1 == s2){
        return 0;
    }
    while (n > 0){
        if (*s1 == *s2 && *s1 == 0){
            return 0;
        }
        else if (*s1 < *s2){
           return -1; 
        }
        else if (*s1 > *s2){
            return 1;
        }
        s1 += sizeof(char);
        s2 += sizeof(char);
        n--;
    }
    return 0;
}

/**
 * @brief Copy a string
 *
 * @param dest The destination buffer
 * @param src The source to copy from
 * @param n maximum number of bytes to copy
 * @return char* a pointer same as dest
 */
char *my_strncpy(char *dest, const char *src, size_t n)
{
    char* result = dest;
    while(n > 0){
        *dest = *src;
        if (*src == 0){
            return result;
        }
        src += sizeof(char);
        dest += sizeof(char);
        n--;
    }
    return result;
}

/**
 * @brief Concatenates two strings and stores the result
 * in the destination string
 *
 * @param dest The destination string
 * @param src The source string
 * @param n The maximum number of bytes from src to concatenate
 * @return char* a pointer same as dest
 */
char *my_strncat(char *dest, const char *src, size_t n)
{
    char* result = dest;
    dest += my_strlen(dest);
    while(n > 0){        
        *dest = *src;
        if (*src == 0){
            return result;
        }
        dest += sizeof(char);
        src += sizeof(char);
        n--;
    }
    return result;
}

/**
 * @brief Copies the character c into the first n
 * bytes of memory starting at *str
 *
 * @param str The pointer to the block of memory to fill
 * @param c The character to fill in memory
 * @param n The number of bytes of memory to fill
 * @return char* a pointer same as str
 */
void *my_memset(void *str, int c, size_t n)
{
    char *pstr = str;
    while (n > 0){
        *pstr = c;
        pstr += sizeof(char);
        n--;
    }
    return NULL;
}

/**
 * @brief Finds the first instance of c in str
 * and removes it from str in place
 *
 * @param str The pointer to the string
 * @param c The character we are looking to delete
 */
void remove_first_instance(char *str, char c){
    char* curr = &*str;
    short i = 1;
    while (*str != 0){
        if (i > 0 && *str == c){
            str += sizeof(char);
            i--;
        }
        *curr = *str;
        str += sizeof(char);
        curr += sizeof(char);
    }
    *curr = 0;
    return;
}

/**
 * @brief Finds the last instance of c in str
 * and removes it from str in place
 *
 * @param str The pointer to the string
 * @param c The character we are looking to delete
 */
void remove_last_instance(char *str, char c){
    char *last = NULL;
    while (*str != 0){
        if (*str == c){
            last = str;
        }
        str += sizeof(char);
    }
    while (last != NULL && *last != 0){
        *last = *(last + sizeof(char));
        last += sizeof(char);
    }
    return;
}

/**
 * @brief Finds the last instance of c in str
 * and replaces it with the contents of replaceStr
 *
 * @param str The pointer to the string
 * @param c The character we are looking to delete
 * @param replaceStr The pointer to the string we are replacing c with
 */
void replace_character_with_string(char *str, char c, char *replaceStr) {
    char * last = NULL;
    int replacement_size = my_strlen(replaceStr);
    if (*replaceStr == 0 || replacement_size == 0){
        return;
    }
    while(*str != 0){
        if (*str == c){
            last = str;
        }
        CHAR_INC(str);
    }
    // after this loop terminates, str should be at the null-terminator.
    // last should point to the last ocurrence of character.
    if (last == NULL){
        return;
    }
    if (replacement_size == 1){
        *last = *replaceStr;
        *str = 0;
        return;
    }
    // int leftover_size = my_strlen(last + sizeof(char));
    
    while(str > last){  // while the address of str is bigger than the address of last_occurence
        *((str) + ((replacement_size-1) * sizeof(char))) = *str;
        str -= sizeof(char);
    }
    while(replacement_size > 0){
        *last = *replaceStr;
        CHAR_INC(last);
        CHAR_INC(replaceStr);
        replacement_size--;
    }
    return;
}

/**
 * @brief Remove the first character of str (ie. str[0]) IN ONE LINE OF CODE.
 * No loops allowed. Assume non-empty string
 * @param str A pointer to a pointer of the string
 */
void remove_first_character(char **str) {
    *str += sizeof(char);
    return;
}