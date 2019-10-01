#include "fila.h"
#include <stdlib.h>

struct fila * create(){
    struct fila *fila;
    struct llist *enc;

    enc = create_l();
    fila = malloc(sizeof(struct fila));
    if(fila == NULL){
        return NULL;
    }
    else{
        fila->le = enc;
        fila->le->fim = NULL;
        fila->le->cabeca = NULL;
        return fila;
    }
    return NULL;
}

int makenull(struct fila * f){    
    if(f->le->tam == 0){  
        return 0;
    }

    else{  
        struct elem *delete; 
        while(f->le->cabeca != NULL){
            delete = f->le->cabeca->next;
            free(f->le->cabeca);
            f->le->cabeca = delete;
            f->le->tam--;
        }
        return 1;
    }
    return 0;  
}

int dequeue(struct fila * f){
    if(f->le->cabeca == NULL){
        return 0;
    }
    
    else{
        struct elem *delete;
        int valor = f->le->cabeca->val;
        delete = f->le->cabeca->next;
        free(f->le->cabeca);
        f->le->cabeca = delete;
        f->le->tam--;
        return valor;
    }
    return 0;
}

int enqueue(struct fila * f, int val){
    if(f->le->cabeca == NULL){ 
        f->le->cabeca = create_node(val);
        insert_l(f->le, NULL, f->le->cabeca);
        f->le->fim = f->le->cabeca;
        f->le->fim->next = NULL;
        return 1;
    }
    else{
        struct elem *a;
        a = create_node(val);
        insert_l(f->le, f->le->fim, a);
        f->le->fim = a;
        return 1;
    }
    return 0;
}

 int vazia(struct fila * f){
    if(f->le->tam == 0){
        return 1;
    }
    else return 0;
}

void destroy(struct fila * f){
    destroy_l(f->le);
    free(f);
}
