#include <stdio.h>
#include <stdlib.h>

/*
* Esse código cria um ponteiro que aponta para um pedaço de memória com 3 bytes,
* O conteúdo desses bytes é transportado para um novo pedaço de memória com 4 bytes através de um novo ponteiro
* Um novo valor é colocado no byte adiocional
* O endereço de memória do ponteiro temporário é vinculado ao original
*/

int main(void) {
  int *list = malloc(3 * sizeof(int));

  if (list == NULL) {
    return 1;
  }

  list[0] = 1;
  list[1] = 2;
  list[2] = 3;

  int *tmp = malloc(4 * sizeof(int));
  if (tmp == NULL){
    free(list);
    return 1;
  }

  for (int i = 0; i < 3; i++) {
    tmp[i] = list[i];
  }

  tmp[3] = 4;

  free(list);
  list = tmp;

  for (int i = 0; i < 3; i++) {
    printf("%i\n", list[i]);
  }

}