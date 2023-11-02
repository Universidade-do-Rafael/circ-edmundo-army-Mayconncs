#include "TCircList.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N, i = 1, j = 1, M;
    scanf("%d %d", &N, &M);
    TCircList *clist = TCircList_create(M);
    while(i <= N) {
        if (!TCircList_insert_fim(clist, i))
            printf("Erro ao tentar inserir %i\n", i);
        i++;
    }
    TCircList_delete(clist, M);
    TCircList_print(clist);
    free(clist);
    return 0;
}