struct nodo {
	int valor;
	struct nodo * dir, * esq;
};

typedef struct elem{
  struct nodo *valor;
  /* aqui vai o ponteiro para o pr�ximo elemento */
  struct elem * next;
} elem;

/** Descritor de lista encadeada.
  * O acesso � lista come�a na posi��o 1.
  * Manter a capacidade atual e o ponteiro para o �ltimo elemento da lista
  * s�o opcionais.
  */

struct llist{
  /* your code here! */
  elem * cabeca; //Cabeca retira
  elem * fim; //Fim insere
  int tam;
};


/** Cria uma lista.
 * @return descritor de lista ou NULL
 */
struct llist * create_l();

/** Cria um nodo de lista inicializado.
 * @param val valor a ser armazenado
 * @return ponteiro para nodo criado ou NULL
 */
 elem * create_node(struct nodo *valor);


 /** Insere um elemento na lista ap�s um elemento
  * @param desc descritor da lista
  * @param prev nodo anterior, NULL se in�cio da lista
  * @param ponteiro para o item o que ser� inserido
  * @return 1 se OK, 0 se erro
  */
 int insert_l(struct llist *desc, elem * prev, elem * item);

/** Remove um elemento de uma posi��o
* @param desc descritor da lista
* @param prev nodo anterior, NULL se in�cio da lista
* @return 1 se OK, 0 se erro
*/
int delete_l(struct llist *desc, elem * prev);

/** Retorna ponteiro para elemento.
 * @param desc descritor da lista
 * @param pos posi��o para elemento
 * @return ponteiro para elemento
 */
elem * get_l(struct llist *desc, int pos);

/** Muda o valor do elemento.
 * @param desc descritor da lista
 * @param pos posi��o para elemento
 * @param item novo valor para item
 * @return 1 se OK, 0 se erro
 */
int set_l(struct llist *desc, int pos, int val);

/** Encontra um elemento com um determinado valor
* @param desc descritor da lista
* @param prev ponteiro para posi��o em que come�a a busca pelo elemento
* @param val  valor buscado
* @return ponteiro caso encontre, NULL se n�o encontrar
*/
elem * locate_l(struct llist *desc, elem * prev, int val);

/** Retorna o comprimento da lista
* @param desc descritor da lista
* @return comprimento da lista atual
*/
int length_l(struct llist *desc);

/** Destr�i a lista, liberando a mem�ria e eliminando todos os elementos.
 * @param desc descritor da lista
 */
void destroy_l(struct llist *desc);

