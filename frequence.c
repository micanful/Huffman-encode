#include "frequence.h"

void frequence_analysis(FILE **frequence_file_p, character *analysis)
{
  //fills the frequence table with all characters
  for (int i = 0; i <= 255; i++){
    analysis[i].chara = i;
  }


  //stegar igenom textfilen och adderar 1 till korresponderande tecken för varje gång det dyker upp
int current = fgetc(*frequence_file_p);

  while(current != EOF){
    int i = 0;
    while(analysis[i].chara != current){
      i++;
    }
    analysis[i].frequence++;

    current = fgetc(*frequence_file_p);
  }
}
