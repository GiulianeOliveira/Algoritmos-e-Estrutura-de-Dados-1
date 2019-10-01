#ifndef _ARVORE_H_
#define _ARVORE_H_
#include "fila.h"
/* IMPLEMENTA��O DE �RVORE BIN�RIA DE PESQUISA */

/* Inicializa uma �rvore
 * @param entradas n�mero de valores iniciais
 * @param valores vetor com valores a serem inseridos
 * @return raiz da �rvore ou NULL se erro
 */
struct nodo * inicializa_arvore(int entradas, int * valores);

/* Insere nodo em uma �rvore se a chave ainda n�o existir, sempre como uma folha
 * @param raiz raiz da �rvore
 * @param valor o que ser� inserido
 * @return raiz da �rvore
 */
struct nodo * insere_nodo(struct nodo * raiz, int valor);

/* Remove nodo em uma �rvore se existir, dando prioridade � sub�rvore esquerda para novo nodo raiz
 * @param raiz raiz da �rvore
 * @param valor o que ser� removido
 * @return raiz da �rvore
 *
 */
struct nodo * find_min(struct nodo *raiz);
struct nodo * remove_nodo(struct nodo * raiz, int valor);

/* Altura de uma �rvore
 * @param raiz raiz da �rvore
 * @return altura da �rvore
 */
int altura(struct nodo * raiz);

/* Consulta se nodo existe
 * @param raiz raiz da �rvore
 * @param valor chave a ser buscada
 * @return ponteiro para nodo, ou NULL se inexistente
 */
struct nodo * busca(struct nodo * raiz, int valor);

/* Descobre se uma �rvore est� balanceada
 * @param raiz da �rvore
 * @return diferen�a das alturas das sub�rvores
 */
int balanceada(struct nodo * raiz);


/* N�mero de elementos em uma �rvore
 * @param raiz raiz da �rvore
 * @return n�mero de elementos da �rvore
 */
int numero_elementos(struct nodo * raiz);

/* Percorre a �rvore em abrang�ncia
 * @param raiz raiz da �rvore
 * @param resultado vetor onde ser� armazenado o percurso (j� deve estar alocado)
 * @return n�mero atual de elementos no vetor
 */
int abrangencia(struct nodo * raiz, int * resultado);

/* Percorre a �rvore de forma pr�-fixada
 * @param raiz raiz da �rvore
 * @param resultado vetor onde ser� armazenado o percurso (j� deve estar alocado)
 * @return n�mero atual de elementos no vetor
 */
int prefix(struct nodo * raiz, int * resultado);

/* Percorre a �rvore de forma p�s-fixada
 * @param raiz raiz da �rvore
 * @param resultado vetor onde ser� armazenado o percurso (j� deve estar alocado)
 * @return n�mero atual de elementos no vetor
 */
int postfix(struct nodo * raiz, int * resultado);

/* Percorre a �rvore de forma infix
 * @param raiz raiz da �rvore
 * @param resultado vetor onde ser� armazenado o percurso (j� deve estar alocado)
 * @return n�mero atual de elementos no vetor
 */
int infix(struct nodo * raiz, int * resultado);

/* Imprime na stdio os valores de um caminhamento com um espa�o entre cada valor,
 * m�ximo de 10 valores por linha
 * @param valores vetor com valores a serem impressos
 * @param tamanho n�mero de entradas no vetor de valores
 */
void imprime(int * valores, int tamanho);

/* Remove todos os nodos
 * @param raiz da �rvore
 */
void remove_todos(struct nodo * raiz);



#endif
