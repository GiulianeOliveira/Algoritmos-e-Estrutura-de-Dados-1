#include "le.h"
#include <stdlib.h>

/** Cria uma lista.
 * @return descritor de lista ou NULL
 */

struct llist * create_l(){ //ALOQUEI LLIST
    struct llist *desc;    //Para saber o inicio da lista
    desc = malloc(sizeof(struct llist));
    desc->tam = 0;  //INICIALIZA EM 0 E VAI INCREMENTANDO NO create_node
    if(desc == NULL){
        return NULL;
    }
    else{
        desc->cabeca = NULL;
    }
        return desc;

}
/** Cria um nodo de lista inicializado.
 * @param val valor a ser armazenado
 * @return ponteiro para nodo criado ou NULL
 */
 elem * create_node(struct nodo *valor){ //ALOCA A CABEÇA
    struct elem *cab;
    cab = malloc(sizeof(struct elem));  
    if(cab == NULL){
        return NULL;
    }
    else
    cab->valor = valor;
    cab->next = NULL;

    return cab;
}
 /** Insere um elemento na lista após um elemento
  * @param desc descritor da lista
  * @param prev nodo anterior, NULL se início da lista
  * @param ponteiro para o item o que será inserido
  * @return 1 se OK, 0 se erro
  */
 int insert_l(struct llist *desc, elem * prev, elem * item){
    struct elem *tp;
    if(desc == NULL){   //VERIFICA SE TEM LISTA
        return 0;
    }
    if(prev == NULL){   //Se o anterior é NULL, então é o primeiro nodo
        item->next = desc->cabeca;
        desc->cabeca = item;
        desc->tam = desc->tam +1;
        return 1;
    }
    else{
        tp = prev->next;
        prev->next = item;
        item->next = tp;
        desc->tam = desc->tam +1;
        return 1;
    }
        return 0;

 }

/** Remove um elemento de uma posição
* @param desc descritor da lista
* @param prev nodo anterior, NULL se início da lista
* @return 1 se OK, 0 se erro
*/
int delete_l(struct llist *desc, elem * prev){
    if(prev == NULL){ 
        if(desc->cabeca == NULL){
            return 0;
        }
        else{
            if(desc->cabeca->next == NULL){ //Ou seja, se nao tem mais nada na lista
                free(desc->cabeca);
                desc->tam = 0;
                return 1;
            }
            else{
                prev = desc->cabeca->next;
                free(desc->cabeca);
                desc->cabeca = prev;
                desc->tam = desc->tam -1;
                return 1;
            }
        }
    }
    else{
        if(prev->next == NULL){ 
            return 0;
        }
        else{
            struct elem *tp;
            tp = prev->next->next;  //salva o proximo endereço da lista
            free(prev->next);   //Apaga o elemento desejado
            prev->next = tp;
            desc->tam = desc->tam -1;
            return 1;
        }
    }

}
/** Retorna ponteiro para elemento.
 * @param desc descritor da lista
 * @param pos posição para elemento
 * @return ponteiro para elemento
 */
elem * get_l(struct llist *desc, int pos){
    struct  elem *tp;

    if(desc->cabeca == NULL){
        return NULL;
    }
     tp = desc->cabeca;
    for(int i = 1; tp != NULL; i++, tp = tp->next){ 
        if(pos == i){
            return tp;  //retorna o nodo da lista
        }
    }
    return NULL;
}
/** Muda o valor do elemento.
 * @param desc descritor da lista
 * @param pos posição para elemento
 * @param item novo valor para item
 * @return 1 se OK, 0 se erro
 */
int set_l(struct llist *desc, int pos, int val){
    struct  elem *tp;

    if(desc->cabeca == NULL){
        return 0;
    }
    tp = desc->cabeca;
    for(int i = 1; tp != NULL; i++, tp= tp->next){
        if(pos == i){
            tp->valor->valor = val;  //troca o valor
            return 1;
        }
    }
    return 0;
}

/** Encontra um elemento com um determinado valor
* @param desc descritor da lista
* @param prev ponteiro para posição em que começa a busca pelo elemento
* @param val  valor buscado
* @return ponteiro caso encontre, NULL se não encontrar
*/
elem * locate_l(struct llist *desc, elem * prev, int val){

        if(prev==NULL){
           if(desc->cabeca->valor->valor == val){
              return desc->cabeca;  //retorna o endereço buscado
            }
            prev = desc->cabeca;
        }
    for(int i = 0; prev->next != NULL ; i++){ 
        if(prev->next->valor->valor == val){
            return prev->next;  //retorna o endereço buscado
        }
        prev = prev->next;
    }
    return NULL;

}

/** Retorna o comprimento da lista
* @param desc descritor da lista
* @return comprimento da lista atual
*/
int length_l(struct llist *desc){
    return desc->tam;
}

/** Destrói a lista, liberando a memória e eliminando todos os elementos.
 * @param desc descritor da lista
 */
void destroy_l(struct llist *desc){
    free(desc->cabeca);
    free(desc);
}
