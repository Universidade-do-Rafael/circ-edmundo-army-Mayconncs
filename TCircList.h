#ifndef TCIRCULAR_LIST_H
#define TCIRCULAR_LIST_H
#include <stdbool.h>

typedef struct list_ TCircList;

TCircList *TCircList_create(int);

bool TCircList_insert_fim(TCircList *, int);

void TCircList_print(TCircList *);

int TCircList_delete(TCircList *, int);

#endif