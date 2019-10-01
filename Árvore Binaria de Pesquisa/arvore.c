#include <stdlib.h>
#include "arvore.h"
#include <stdio.h>

/* Inicializa uma �rvore
 * @param entradas n�mero de valores iniciais
 * @param valores vetor com valores a serem inseridos
 * @return raiz da �rvore ou NULL se erro
 */
struct nodo * inicializa_arvore(int entradas, int * valores){
    struct nodo *raiz;
    int contador;
    contador = entradas;
    if(valores == NULL || contador <= 0){
        return NULL;
    }
    raiz = malloc(sizeof(struct nodo));
    if(contador == 1){
        raiz->valor = *valores;
        raiz->dir = NULL;
        raiz->esq = NULL;
    }
    else{
        raiz->valor = valores[0];
        raiz->dir = NULL;
        raiz->esq = NULL;
        for(int i = 1; i < contador; i++){
            insere_nodo(raiz, valores[i]);
        }
    }
        return raiz;

}

/* Insere nodo em uma �rvore se a chave ainda n�o existir, sempre como uma folha
 * @param raiz raiz da �rvore
 * @param valor o que ser� inserido
 * @return raiz da �rvore
 */
struct nodo * insere_nodo(struct nodo * raiz, int valor){
    struct nodo *tp;
    if(raiz == NULL){
        tp = malloc(sizeof(struct nodo));
        tp->valor = valor;
        tp->esq = NULL;
        tp->dir = NULL;
        return tp;
    }
    else{
        if(valor < raiz->valor){
            raiz->esq = insere_nodo(raiz->esq, valor);
            return raiz;
        }
        else{
            if(raiz->valor < valor){
                raiz->dir = insere_nodo(raiz->dir, valor);
                return raiz;
            }
            else{
                return raiz;
            }

        }
    }
}

/* Remove nodo em uma �rvore se existir, dando prioridade � sub�rvore esquerda para novo nodo raiz
 * @param raiz raiz da �rvore
 * @param valor o que ser� removido
 * @return raiz da �rvore
 */
struct nodo * find_min(struct nodo *raiz){
    if(raiz!=NULL){
        if(raiz->esq){
            return find_min(raiz->esq);
        }
        else return raiz;
    }
    return NULL;
}
struct nodo * remove_nodo(struct nodo * raiz, int valor){
    struct nodo *tp; 
    //tp = malloc(sizeof(struct nodo));
    if(raiz == NULL){
        return NULL;
    }
    else{
        if(raiz->valor > valor){
            raiz->esq = remove_nodo(raiz->esq, valor);
        }
        else{
            if(raiz->valor < valor){
            raiz->dir = remove_nodo(raiz->dir, valor);
            }
            else{   //raiz->valor == valor que deseja remover
                if(raiz->dir != NULL && raiz->esq != NULL){
                    tp = find_min(raiz->dir);
                    raiz->valor = tp->valor;
                    raiz->dir = remove_nodo(raiz->dir, raiz->valor);
                }
                else{
                    if(raiz->esq == NULL){
                        tp = raiz->dir;
                    }
                    else{
                        tp = raiz->esq;
                    }
                    free(raiz);
                    return tp;
                }
            }
        }
    }
                    return raiz;
}

/* Altura de uma �rvore
 * @param raiz raiz da �rvore
 * @return altura da �rvore
 */
int altura(struct nodo * raiz){
    int alt_e, alt_d;

    if(raiz == NULL){
        return 0;
    }
    else{
        alt_d = altura(raiz->dir);
        alt_e = altura(raiz->esq);
        if(alt_d >= alt_e){
            return alt_d+1;
        }
        else return alt_e+1;
    }
}

/* Consulta se nodo existe
 * @param raiz raiz da �rvore
 * @param valor chave a ser buscada
 * @return ponteiro para nodo, ou NULL se inexistente
 */
struct nodo * busca(struct nodo * raiz, int valor){
        do{
            if(raiz->valor > valor){
                raiz = raiz->esq;
            }
            if(raiz->valor < valor){
                raiz = raiz->dir;
            }
        }while(raiz != NULL && raiz->valor != valor);
        return raiz;

}

/* Descobre se uma �rvore est� balanceada
 * @param raiz da �rvore
 * @return diferen�a das alturas das sub�rvores
 */
int balanceada(struct nodo * raiz){
    if(raiz){
    unsigned int tp1, tp2, resul;

    tp1 = altura(raiz->dir);
    tp2 = altura(raiz->esq);
    return (resul = tp1 - tp2);
    }
    return 0;
}


/* N�mero de elementos em uma �rvore
 * @param raiz raiz da �rvore
 * @return n�mero de elementos da �rvore
 */
int numero_elementos(struct nodo * raiz){   
    int tp1, tp2, resultado; 
    if(raiz == NULL){
        return 0;
    }
    tp1 = numero_elementos(raiz->esq) + 1;
    tp2 = numero_elementos(raiz->dir) + 1;
    return resultado = tp1 + tp2;
}

/* Percorre a �rvore em abrang�ncia
 * @param raiz raiz da �rvore
 * @param resultado vetor onde ser� armazenado o percurso (j� deve estar alocado)
 * @return n�mero atual de elementos no vetor
 */

int abrangencia(struct nodo * raiz, int * resultado){
    struct fila *f;
    struct nodo *n;
    n = raiz;
    int i=0;
    f = create();
    if(raiz != NULL){
        enqueue(f,n);

        while(vazia(f) != 1){
            n = dequeue(f);
            resultado[i] = n->valor;
            i++;
            if(n->esq != NULL){
                enqueue(f, n->esq);
            }
            if(n->dir != NULL){
                enqueue(f, n->dir);
            }
        }
    }
    return i;
}


/* Percorre a �rvore de forma pr�-fixada
 * @param raiz raiz da �rvore
 * @param resultado vetor onde ser� armazenado o percurso (j� deve estar alocado)
 * @return n�mero atual de elementos no vetor
 */
int l=0;
int prefix(struct nodo * raiz, int * resultado){
    if(raiz == NULL){   //ARRUMAR!!!!!
        return l;
    }
    resultado[l] = raiz->valor;
    l++;
    prefix(raiz->esq, resultado);
    prefix(raiz->dir, resultado);
    return l;
}
/* Percorre a �rvore de forma p�s-fixada
 * @param raiz raiz da �rvore
 * @param resultado vetor onde ser� armazenado o percurso (j� deve estar alocado)
 * @return n�mero atual de elementos no vetor
 */
int i =0;
int postfix(struct nodo * raiz, int * resultado){
    if(raiz == NULL){
        return i;
    }
    postfix(raiz->esq, resultado);
    postfix(raiz->dir, resultado);
    resultado[i] = raiz->valor;
    i++;

    return i;
}

/* Percorre a �rvore de forma infix
 * @param raiz raiz da �rvore
 * @param resultado vetor onde ser� armazenado o percurso (j� deve estar alocado)
 * @return n�mero atual de elementos no vetor
 */

int infix(struct nodo * raiz, int * resultado){
    static int i=0;

    if(raiz != NULL){
        infix(raiz->esq, resultado);    //visita subarvore a esquerda
        resultado[i] = raiz->valor;     //raiz
        infix(raiz->dir, resultado);    //visita subarvore a direita
        return i;
    }
    
    return i;
    
}

/* Imprime na stdio os valores de um caminhamento com um espa�o entre cada valor,
 * m�ximo de 10 valores por linha
 * @param valores vetor com valores a serem impressos
 * @param tamanho n�mero de entradas no vetor de valores
 */
void imprime(int * valores, int tamanho){
    printf("        ");
    for(int i = 0; i < tamanho; i++){
        printf("%d ", valores[i]);
        if(i == 9){
             printf("\n");
             printf("        ");
        }
    }

}

/* Remove todos os nodos
 * @param raiz da �rvore
 */
void remove_todos(struct nodo * raiz){
    if(raiz){   //Verifica se tem raiz
        remove_todos(raiz->dir);
        remove_todos(raiz->esq);
        free(raiz);
    } 
}

