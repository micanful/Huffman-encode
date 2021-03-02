/**
 * @defgroup hufftrie_h Hufftrie
 *
 * @brief Defines the datatype for a node and its functions
 *
 * Defines the datatype for a node and its functions. With these functions multiple nodes are
 * maniplulated into a huffman trie. Uses a pre-defined implementation of a bitbuffer and a priorityqueue.
 *
 * Credits for bitbuffer: Jonny Pettersson
 *
 * Credits for priorityqueue: Sebastian Sandberg, Jonny Pettersson
 * @author  Leo Hall
 * @since   2021-02-08
 * @{
 */

#ifndef HUFFTRIE_H
#define HUFFTRIE_H
#include "pqueue.h"
#include "list.h"
#include "frequence.h"
#include "bit_buffer.h"

/**
 * @brief A node in a tree
 *
 * A node in a tree containing a weight, a value and two child nodes.
 *
 */

typedef struct node {
  int weight;
  int value;
  struct node *left, *right;
} Node;

/**
 * @brief Creates an empty node
 *
 * @return The new allocated node.
 */
Node *create_new(int weight, int value);


/**
 * @brief Creates a priority queue with all elements of our huffman analysis in it
 *
 * @param analysis Our huffman analysis
 * @return pqueue Our new priority queue
 */
pqueue *create_pq(character *analysis);

/**
 * @brief Creates a huffman trie based on the given priority queue
 *
 * @param pq Our priority queue
 * @return Node our huffman trie
 */
Node *pq_to_tree(pqueue *pq);

/**
 * @brief Recursively frees the given tree by using BFS
 *
 * @param tree our tree
 * @return NULL
 */
void kill_tree(Node *tree);

/**
 * @brief Checks if a given node in a tree is a leaf
 *
 * @param tree our tree
 * @return 1 if it is a leaf, otherwise 0
 */
int is_leaf(Node *tree);

#endif
/**
 * @}
 */
