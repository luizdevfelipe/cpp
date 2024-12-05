#include <stdio.h>
#include <stdlib.h>

/*
* LISTA ENCADEADA
* Através de ponteiros, chamados nós, que guardam um valor e o endereço de memória de seu próximo valor
* é possível implementar o conceito de lista encadeada, onde os valores são armazenados na memória de maneira
* não linear, ao contrário de arrays, possibilitando armazenar grandes quantidades de dados dinamicamente, mas
* com maior custo de memória e um tempo maior de busca sobre os dados, visto que não é possível aplicar o conceito
* de busca binária nessa estrutura
*/

typedef struct node {
  int number;
  struct node *next;
} node;

int main(int argc, char *argv[]) {
  node *list = NULL;

  for (int i = 1; i < argc; i++) {
    int number = atoi(argv[i]);

    node *n = malloc(sizeof(node));

    if (n == NULL) {
        return 1;
    }

    n->number = number;
    n->next = list;
    list = n;
  }

  // exibindo a toda a lista
  node *ptr = list;
  while (ptr != NULL) {
    printf("%i\n", ptr->number);
    ptr = ptr->next;
  }
}