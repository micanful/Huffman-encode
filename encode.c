#include "encode.h"

//Local function which adds a given char's encoded bit value to a bitbuffer
void add_char(bit_buffer *buffer, int value, Table *table)
{
  for(int i = 0; i < bit_buffer_size(table[value].array); i++){
    bit_buffer_insert_bit(buffer, bit_buffer_inspect_bit(table[value].array, i));
  }
}

//Local function which adds EOT to a given bitbuffer to avoid trash-bits during decoding
void add_eot(bit_buffer *buffer, Table table)
{
  bit_buffer *copy = bit_buffer_copy(table.array);

  while(bit_buffer_size(copy) > 0){
    bit_buffer_insert_bit(buffer, bit_buffer_remove_bit(copy));
  }

  bit_buffer_free(copy);
}


void encode(FILE **text_file_p, FILE **out_file_p, Table *table)
{
  int current = fgetc(*text_file_p);

  bit_buffer *complete_bit_sequence = bit_buffer_empty();

  while(current != EOF){
    add_char(complete_bit_sequence, current, table);

    current = fgetc(*text_file_p);
  }

  add_eot(complete_bit_sequence, table[4]);

  printf("%d bytes used in encoded form.", bit_buffer_size(complete_bit_sequence) / 8);

  char *string = bit_buffer_to_byte_array(complete_bit_sequence);

  fwrite(string, 1, bit_buffer_size(complete_bit_sequence) / 8, *out_file_p);

  free(string);

  bit_buffer_free(complete_bit_sequence);
}


void decode(FILE **text_file_p, FILE **out_file_p, Node *tree)
{
  int current = fgetc(*text_file_p);

  bit_buffer *complete_bit_sequence = bit_buffer_empty();

  while(current != EOF){
    bit_buffer_insert_byte(complete_bit_sequence, current);

    current = fgetc(*text_file_p);
  }

  Node *node_pointer = tree;

  while(bit_buffer_size(complete_bit_sequence) > 0){

    if(is_leaf(node_pointer)){
      fputc(node_pointer->value, *out_file_p);

      node_pointer = tree;
    }

    if(bit_buffer_remove_bit(complete_bit_sequence) == 0){
      node_pointer = node_pointer->left;
    } else{
      node_pointer = node_pointer->right;
    }
  }

  printf("File decoded succesfully.");
}
