/**
 * @defgroup huffman_h Huffman
 *
 * @brief The main file
 *
 * Checks that the given parameters are correct and then
 * utilizes every other module to encode or decode a textfile with huffman encoding
 *
 * @author  Leo Hall
 * @since   2021-02-08
 * @{
 */

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "hufftable.h"
#include "hufftrie.h"
#include "frequence.h"
#include "encode.h"

/**
 * @brief Checks if parameters are correctyl formatted and if files are opened correctly
 *
 * @return 0 if everything is ok, otherwise 1
 */
int check_prog_params(int argc, const char *argv[],
                FILE **frequence_file_p, FILE **text_file_p, FILE **out_file_p);


#endif
/**
 * @}
 */
