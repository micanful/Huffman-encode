/**
 * @defgroup encode_h Encode
 *
 * @brief Encodes and decodes a text file
 *
 *
 * @{
 */

#ifndef ENCODE_H
#define ENCODE_H

#include <stdio.h>
#include "hufftable.h"
#include "hufftrie.h"

/**
 * @brief Encodes a text file to an empty out file with the help of a huffman table
 *
 * Analyzes every char in the text file, encodes it through the huffman table
 * and writes the encoded characters to the out file
 *
 * @param text_file_p Text file to be encoded
 * @param out_file_p File to write encoded text to
 * @param table A huffman table
 * @return NULL
 */
void encode(FILE **text_file_p, FILE **out_file_p, Table *table);


/**
 * @brief Decodes a text file to an out file with the help of a huffman-trie
 *
 * Reads an encoded text, traverses the huffman trie bit by bit and prints a leaf's
 * character to the out file when a leaf is encountered
 *
 * @param text_file_p Text file to be decoded
 * @param out_file_p File to write decoded text to
 * @param tree The trie to be traversed for decoding
 * @return NULL
 */
void decode(FILE **text_file_p, FILE **out_file_p, Node *tree);

#endif
/**
 * @}
 */
