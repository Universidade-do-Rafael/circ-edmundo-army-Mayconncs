#include "TCircList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _no{
  int info;
  struct _no *prox;
}TNo;

struct list_{
  int M;
  TNo *inicio;
};

TCircList *TCircList_create(int M) {
  TCircList *clist = (TCircList *)malloc(sizeof(TCircList));
  if (clist != NULL)
    clist->inicio = NULL;
    clist->M = M;
  return clist;
}

bool TCircList_insert_fim(TCircList *clist, int info) {
  TNo *novo = malloc(sizeof(TNo));
  if (novo == NULL)
    return false;

  novo->info = info;
  if (clist->inicio == NULL)
    clist->inicio = novo;
  else {
    TNo *aux = clist->inicio;
    while (aux->prox != clist->inicio)
      aux = aux->prox;
    aux->prox = novo;
  }
  novo->prox = clist->inicio;
  return true;
}

void TCircList_print(TCircList *clist) {
  if (clist == NULL || clist->inicio == NULL)
    return;
  TNo *aux = clist->inicio;
  do {
    printf("%d\n", aux->info);
    aux = aux->prox;
  } while (aux != clist->inicio);
  putchar('\n');
}
int TCircList_delete(TCircList *clist, int k) {
    if (clist->inicio == NULL || k <= 0) {
      return 0;
    }
    TNo *atual = clist->inicio;
    TNo *anterior = clist->inicio;
    while (atual->prox != atual) {
      for (int i = 1; i <= k; i++) {
        anterior = atual;
        atual = atual->prox;
      }
      anterior->prox = atual->prox;
      atual = anterior->prox;
    }
    clist->inicio = anterior->prox;
    return 1;
}
