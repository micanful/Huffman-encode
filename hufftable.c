#include "hufftable.h"

Table *create_table()
{
  Table *new = calloc(256, sizeof(Table));

  return new;
}

void free_table(Table *table)
{
  for(int i = 0; i <= 255; i++){
    bit_buffer_free(table[i].array);
  }
  free(table);
}

void tree_to_table(Table *table, Node *tree, bit_buffer *buffer)
{
  if(is_leaf(tree) == 0){
    bit_buffer *right_buffer = bit_buffer_copy(buffer);
    bit_buffer_insert_bit(right_buffer, 1);
    bit_buffer_insert_bit(buffer, 0);

    tree_to_table(table, tree->left, buffer);
    tree_to_table(table, tree->right, right_buffer);
  }

  if(is_leaf(tree) == 1){
    table[tree->value].array = buffer;
    table[tree->value].value = tree->value;
  }
}
