/**
 * @defgroup hufftable_h Hufftable
 *
 * @brief A data type representing a table which holds a value and a corresponding bitbuffer.
 *
 * Contains the datatype table which contains a value and a bitbuffer constructed from
 * a huffman trie.
 *
 * @author  Leo Hall
 * @since   2021-02-08
 * @{
 */

#ifndef HUFFTABLE_H
#define HUFFTABLE_H
#include "hufftrie.h"
#include "bit_buffer.h"
#include <stdlib.h>
#include <string.h>
/**
 * @brief A structure containing an int value and a bit_buffer.
 *
 */
typedef struct table {
  int value;
  bit_buffer *array;
} Table;


/**
 * @brief Creates an empty table, caller is responsible
 * for deallocating the table
 *
 * @return The new allocated table.
 */
Table *create_table();


/**
 * @brief Traverses a huffman trie and converts it into a table
 *
 * Traverses a huffman trie and converts it into an array of tables, one for each utf8 char.
 *
 * @param table An empty table
 * @param tree A huffman trie which is to be converted into the Table
 * @param buffer A bitbuffer which assigns an entry in the table its bit sequence
 * @return NULL
 */
void tree_to_table(Table *table, Node *tree, bit_buffer *buffer);

/**
 * @brief Frees the memory for the given table and its contents
 *
 * @param table A table
 * @return NULL
 */
void free_table(Table *table);

#endif
/**
 * @}
 */
