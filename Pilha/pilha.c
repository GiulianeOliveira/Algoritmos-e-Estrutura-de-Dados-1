#include "pilha.h"
#include <stdlib.h>
#define max 5

/** Cria uma pilha
 * @return  um descritor ou NULL
 */
struct pilha * create(){
    struct pilha *pl;  
    struct list *seq;

    seq = create_sequencial(max);

    pl = malloc(sizeof(struct pilha));
    if(pl == NULL){
        return NULL;
    }
    else{
        pl->sequencial = seq;
        return pl;  //RETURN DESCRITOR 
    }
    return NULL;
}
/* Insere um elemento no topo da pilha
 * @param p descritor de pilha
 * @param val elemento a ser inserido
 * @return 1 se OK, 0 se erro
 */
int push(struct pilha * p, int val){
    if(p->sequencial == NULL || p->sequencial->ultimo == max){  
        return 0;
    }
    else{
        int pos = length(p->sequencial);
        insert(p->sequencial, pos+1, val); 
        return 1;
    }
}  
/* Descarta o topo da pilha
 * @param p descritor de pilha
 * @return 1 se OK, 0 se erro
 */
int pop(struct pilha * p){
    if(p->sequencial == NULL || p->sequencial->ultimo == 0){  
        return 0;
    }
    else{
        removel(p->sequencial, p->sequencial->ultimo);
        return 1;
    }
}
/** Apaga todos elementos da pilha
 * @param p descritor da pilha
 * @return 1 se OK, 0 se erro
 */
int makenull(struct pilha * p){ //VER SE TÁ CERTO
    if(p->sequencial == NULL || p->sequencial->ultimo == 0){  
        return 0;
    }
    else{
        struct pilha *aux;
        for(aux = p; aux != NULL; aux++){
            free(aux->sequencial->arm);
        }
        if(p->sequencial == NULL){
            return 1;
        }
    return 0;
       
    }
}
/* Retorna o elemento no topo da pilha, ou zero se não existir
 * @param p descritor da pilha
 * @return o elemento ou 0
 */
int top(struct pilha * p){
    if(p->sequencial == NULL || p->sequencial->ultimo == 0){  
        return 0;
    }
    else{
        get(p->sequencial, p->sequencial->ultimo);
        return p->sequencial->ultimo;
    }
}
/* Retorna se a pilha está vazia ou não
 * @param p descritor de pilha
 * @return 1 se vazia, 0 se não
 */
 int vazia(struct pilha *p){
    if(p->sequencial->ultimo == 0){
        return 1;
    }
    else return 0;
 }
 /** Desaloca toda a pilha
  * @param p descritor da pilha
  */
void destroy(struct pilha * p){ 
    destroy_s(p->sequencial);
    free(p);
}
