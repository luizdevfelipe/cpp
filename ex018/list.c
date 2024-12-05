#include <stdio.h>
#include <stdlib.h>

/*
 * LISTA ENCADEADA ORDENADA
 * Através nós, que guardam um valor e o endereço de
 * memória de seu próximo nó é possível implementar o conceito de lista
 * encadeada, onde os valores são armazenados na memória de maneira não linear,
 * ao contrário de arrays, possibilitando armazenar grandes quantidades de dados
 * dinamicamente. A lista ordenada tem como característica organizar seus
 * elementos, que nesse caso, são valores inteiros de maneira crescente
 */

// Definindo um nó
typedef struct node {
  int number;
  struct node *next;
} node;

int main(int argc, char *argv[]) {
  // criando o primeiro nó que será o inicio da lista
  node *list = NULL;

  // iterando sobre os argumentos inseridos na linha do comando
  for (int i = 1; i < argc; i++) {
    // converte o argumento atual para um número, e não valor ASCII
    int number = atoi(argv[i]);
    // cria um ponteiro de memória "n" com um bloco do tamanho de uma estrutura
    // nó
    node *n = malloc(sizeof(node));
    // caso a operação falhe ele encerra a execução
    if (n == NULL) {
      return 1;
    }
    // define o número lido em um nó que não aponta para nada ainda
    n->number = number;
    n->next = NULL;
    // se alista estiver fazia, ela deve apontar para o primeiro nó definido
    if (list == NULL) {
      list = n;
    }
    // caso a lista tenha elementos e o número do nó seja menor que o início
    // dela ele é adicionado no início
    else if (n->number < list->number) {
      n->next = list;
      list = n;
    }
    // para casos onde o valor se encaixe no meio da lista ou no final deve ser
    // feita a leitura da lista
    else {
      // através de um ponteiro temporário que irá conter os endereços dos nós,
      // verificamos cada um deles
      for (node *ptr = list; ptr != NULL; ptr = ptr->next) {
        // se estiver no fim da lista o nó não aponta a nada, e o valor deve ser
        // adicionado na última posição
        if (ptr->next == NULL) {
          ptr->next = n;
          break;
        }
        // caso o valor do nó seja menor que o valor do próximo nó lido no
        // momento ele é adicionado entre eles
        if (n->number < ptr->next->number) {
          n->next = ptr->next;
          ptr->next = n;
          break;
        }
      }
    }
  }

  // exibindo a toda a lista
  node *ptr = list;
  while (ptr != NULL) {
    printf("%i\n", ptr->number);
    ptr = ptr->next;
  }
}