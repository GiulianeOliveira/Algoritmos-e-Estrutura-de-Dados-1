#include "ls.h"
#include <stdlib.h>

struct list * create(int max){
    struct list *lista_sequencial;
        if(max>0){
            lista_sequencial = malloc(sizeof(struct list)); //ALOCA A LISTA
            lista_sequencial->capacidade = max;     //TAMANHO DO VETOR
            lista_sequencial->ultimo = 0;
            lista_sequencial->arm = malloc(max * sizeof(elem));   //ALOCA UM VETOR DE TAMANHO MAX DO TIPO ELEM
            return lista_sequencial;    //RETORNA A LISTA ALOCADA, SE TAMANHO MAX MAIOR QUE ZERO, DESCRITOR DA LISTA
        }
        else return NULL;
}

int insert(struct list *desc, int pos, elem item){
    if(desc->ultimo >= desc->capacidade){
        return 0;
    }
    if(pos > desc->ultimo+1 || pos < 1){
        return 0;
    }
    else{
        for(int q = desc->ultimo; q >= pos; q++){
            desc->arm[q+1] = desc->arm[q];
        }
    desc->arm[pos] = item;
    desc->ultimo = desc->ultimo+1;
    return 1;
    }
}

int removel(struct list *desc, int pos){
    if(pos > desc->ultimo){
        return 0;
    }
    else{
         desc->ultimo = desc->ultimo -1;
        for(int q = pos; q <= desc->ultimo; q++){
            desc->arm[q] = desc->arm[q+1];
        }
        return 1;
    }
    
}

elem get(struct list *desc, int pos){
    if(pos > desc->ultimo || pos < 0){      
        return 0;
    }
    else return desc->arm[pos];
}

int set(struct list *desc, int pos, elem item){
    if(pos > desc->ultimo || pos < 0){
        return 0;
    }
    else desc->arm[pos] = item;
    return 1;
}

int locate(struct list *desc, int pos, elem item){
    for(int i = pos; i <= desc->ultimo; i++){
        if(desc->arm[i] == item){
            return i;
        }
    }
     return 0;
}

int length(struct list *desc){
    return desc->ultimo;      
}

int max(struct list *desc){
    return desc->capacidade;
}

int full(struct list *desc){
    int resp1, resp2;

    if((resp1 = max(desc)) == (resp2 = length(desc))){
        return 1;
    }
    else return 0;
}

void destroy(struct list *desc){
    free(desc);
}
