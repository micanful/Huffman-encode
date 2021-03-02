/**
 * @defgroup frequence_h Frequence
 *
 * @brief A module which analyzes a text file and stores the frequency of all characters in our datatype character
 *
 *
 * @author  Leo Hall
 * @since   2021-02-08
 * @{
 */


#ifndef FREQUENCE_H
#define FREQUENCE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief A structure containing an int value corresponding to a char and
 * another int representing how often that character is found in a given text
 *
 */

typedef struct {
  int chara;
  int frequence;
} character;

/**
 * @brief Traverses a text file and increments a character in our array of characters
 * if it finds the corresponding char in the text
 *
 * @param table frequence_file_p The file to be analyzed
 * @param tree An empty array of characters
 * @return NULL
 */
void frequence_analysis(FILE **frequence_file_p, character *analysis);

#endif
/**
 * @}
 */
