#include "huffman.h"


int main(int argc, const char *argv[])
{
  FILE *frequence_file_p, *text_file_p, *out_file_p;

  if ((check_prog_params(argc, argv,
    &frequence_file_p, &text_file_p, &out_file_p)) != 0){

      return 0;
    }

    character *analysis = calloc(256, sizeof(character));

    frequence_analysis(&frequence_file_p, analysis);

    pqueue *pq;

    pq = create_pq(analysis);

    Node *tree = pq_to_tree(pq);

    Table *table = create_table();

    bit_buffer *buffer = bit_buffer_empty();

    tree_to_table(table, tree, buffer);

    if(strcmp(argv[1], "-encode") == 0){
      fseek(text_file_p, 0, SEEK_END);
      printf("%ld bytes read from %s.\n", ftell(text_file_p), argv[3]);
      rewind(text_file_p);

      encode(&text_file_p, &out_file_p, table);

    } else
    {
      decode(&text_file_p, &out_file_p, tree);
    }

    free(analysis);

    pqueue_kill(pq);

    kill_tree(tree);

    free_table(table);

    fclose(frequence_file_p);
    fclose(text_file_p);
    fclose(out_file_p);

    return 0;
}


int check_prog_params(int argc, const char *argv[],
                FILE **frequence_file_p, FILE **text_file_p, FILE **out_file_p)
{
  //verifierar in-data, avrbyter program och ger felmeddelande vid fel
  if((strcmp(argv[1], "-encode") != 0 && strcmp(argv[1], "-decode") != 0) ||
            argv[2] == NULL || argv[3] == NULL || argv[4] == NULL || (argc != 5)){
    printf("USAGE:\n %s [OPTION] [FILE0] [FILE1] [FILE2]\nOptions:", argv[0]);
    printf("\n-encode encodes FILE1 according to frequence analysis done on FILE0. ");
    printf("Stores the result in FILE2\n");
    printf("-decode decodes FILE1 according to frequence analysis done on FILE0. Stores the result in FILE2");
    return 1;
  }

  //öppnar de filer som används, vid fel stängs program och filer
  *frequence_file_p = fopen(argv[2], "r");
  if (*frequence_file_p == NULL){
     fprintf(stderr, "Could not open the file: %s", argv[2]);

     return 1;
   }

   if(strcmp(argv[1], "-encode") == 0){

     *text_file_p = fopen(argv[3], "r");
     if (*text_file_p == NULL){
       fprintf(stderr, "Could not open the file: %s", argv[3]);
       fclose(*frequence_file_p);

       return 1;
     }

     *out_file_p = fopen(argv[4], "wb");
     if (*out_file_p == NULL){
       fprintf(stderr, "Could not open the file: %s", argv[4]);
       fclose(*frequence_file_p);
       fclose(*text_file_p);
       return 1;
     }
   }else

   {
     *text_file_p = fopen(argv[3], "rb");
     if (*text_file_p == NULL){
       fprintf(stderr, "Could not open the file: %s", argv[3]);
       fclose(*frequence_file_p);
       
       return 1;
     }

     *out_file_p = fopen(argv[4], "w");
     if (*out_file_p == NULL){
       fprintf(stderr, "Could not open the file: %s", argv[4]);
       fclose(*frequence_file_p);
       fclose(*text_file_p);
       return 1;
     }
   }

   return 0;
}
