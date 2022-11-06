#include "lista.h"

//Funcao do MENU
int menu(){
	int opcao;
	system("@cls||clear");
	printf("\n\t|=========== MENU ===========|\n\n");
	printf("0 - sair (Sair da aplicacao)\n");
	printf("1 - Inserir Valor\n");
	printf("2 - Listar valores com caminhamento EM ORDEM.\n");
	printf("3 - Listar valores com caminhamento PRE ORDEM.\n");
	printf("4 - Listar valores com caminhamento POS ORDEM.\n");
	printf("5 - Consultar Valor.\n");
	printf("6 - Remover Valor.\n");
	printf("Escolha uma opcao: ");
	scanf("%d" ,&opcao);
	
	return opcao;
}

// ===============================================

TElem *inserir(TNo **raiz){
	TElem *novo = (TElem *)malloc(sizeof(TElem)); // Aloca espaco para um novo elemento
	
	// Solicita um valor para ser inserido na arvore
	printf("\n\n\n");
	printf("\t=====| INSERIR USUARIO |=====\n\n");
	printf("Insira um VALOR: ");
	scanf("%d", &novo->valor);

	novo->prox = NULL;

	if ((*raiz) == NULL){ // Conferi se a arvore ja possue uma raiz

		// Se a arvore estiver vazia, insere o valor na raiz da arvore
		(*raiz) = insereArvore(&(*raiz), novo);

	} else {

		// Insere o valor na sua respectiva posicao na arvore
		insereArvore(&(*raiz), novo);

	}
	
	return novo;
	
}

// ===============================================

TNo *inicializaArvore(){

	//Inicializa a arvore retornado apenas null para a raiz
	return NULL;
}

// ===============================================

TNo *criarNo(TElem *atual){
	
	// Sera inserido as informacoes do Nodo (NO)
	TNo *novo = (TNo *)malloc(sizeof(TNo)); // Alocar um novo espaco na memoria para o valor ser inserido na arvore
	novo->valor = atual->valor;
	novo->esq = NULL; // Criar uma nova bifurcacao para a esquerda
	novo->dir = NULL; // Criar uma nova bifurcacao para a direita
	return novo; // Retorna o elemento com suas informacoes atualizadas

}

// ===============================================

TNo *insereArvore(TNo **nodo, TElem *atual){
	if ((*nodo) == NULL){

		// Quando encontrar NULL significa que encontrou a posicao aonde o elemento sera inserido
		(*nodo) = criarNo(atual);

	} else if (atual->valor < (*nodo)->valor){

		// Se o valor for menor que o do Nodo atual da arvore chama a funcao novamente passando o Nodo da esquerda
		// como parametro. Ou seja, a arvore ira percorrer a esquerda da arvore
		(*nodo)->esq = insereArvore(&(*nodo)->esq, atual);

	} else {

		// Se o valor for maior que o Nodo atual da arvore chama a funcao novamente passando o Nodo da direita
		// como parametro. Ou seja, ira percorrer a direita na arvore
		(*nodo)->dir = insereArvore(&(*nodo)->dir, atual);

	}

	// Retorna o Nodo, ou seja, o NO da arvore, contendo o novo valor inserido
	return (*nodo);

}

// ===============================================

TNo *removerArvore(TNo **nodo, int *argumento)
{
	// Se encontrar NULL, significa que o elemento nao consta na arvore ou que a arvore esta vazia
	if ((*nodo) == NULL){ 
		printf("\n\n\tELEMENTO NAO ENCONTRADO\n\n");
		return NULL;

	} else if ((*nodo)->valor > *argumento){

		// Se o valor procurado for menor que o valor do Nodo atual, desce pela ESQUERDA
		(*nodo)->esq = removerArvore(&(*nodo)->esq, argumento);

	} else if ((*nodo)->valor < *argumento){

		// Se o valor procurado for maior que o valor do Nodo atual, desce pela DIREITA
		(*nodo)->dir = removerArvore(&(*nodo)->dir, argumento);

	} else {

		// Encontrou o Nodo que sera removido
		if ((*nodo)->dir == NULL && (*nodo)->esq == NULL){

			// NO que sera removido nao tem filhos
			free((*nodo)); // Linera o espaco que o elemento estava ocupando na memoria
			(*nodo) = NULL; // Atribui NULL ao NO 

		} else if ((*nodo)->esq == NULL){

			// No que sera removido tem apenas filho a direita
			TNo *temporario = (*nodo);
			(*nodo) = (*nodo)->dir; // O NO da direita volta atras uma posicao
			free(temporario); // O NO achado eh excluido e seu espaco na memoria liberado

		} else if ((*nodo)->dir == NULL){

			// No que sera removido tem apenas filho a esquerda
			TNo *temporario = (*nodo);
			(*nodo) = (*nodo)->esq; // O NO da esquerda volta atras uma posicao 
			free(temporario); // O NO achado eh excluido e seu espao na memoria liberado

		} else {

			// NO possui dois filhos
			TNo *prov = (*nodo)->esq; // Criacao de um provisorio que recebe o NO da esquerda
			while (prov->dir != NULL){ // Percorre os NO da direita ate for igual a NULL
				prov = prov->dir;
			}

			// Trocando os valores entre os NO
			(*nodo)->valor = prov->valor; // O NO que sera excluido recebe o valor provisorio
			prov->valor = *argumento; // O valor do NO e atualizado
			(*nodo)->esq = removerArvore(&(*nodo)->esq, argumento);

		}
	}

	return (*nodo);

}

// ===============================================

void caminhamento_em_ordem(TNo *nodo){

	if (nodo != NULL){
		// Percorre a arvore pela esquerda de forma simetrica, ou seja, do menor valor para o maior
		caminhamento_em_ordem(nodo->esq);
		// Mostrar no prompt o valor do NO da arvore
		printf("\n\t%d\n",nodo->valor);
		// Percorre a arvore pela direita de forma simetrica, ou seja, do menor valor para o maior
		caminhamento_em_ordem(nodo->dir);
	}
}

// ===============================================

void caminhamento_pre_ordem(TNo *nodo){
	if (nodo != NULL)
	{
		// Mostrar no prompt o valor do NO da arvore
		printf("\n\t%d\n",nodo->valor);
		// Percorre a arvore pela esquerda de forma simetrica, ou seja, do menor valor para o maior
		caminhamento_pre_ordem(nodo->esq);
		// Percorre a arvore pela direita de forma simetrica, ou seja, do menor valor para o maior
		caminhamento_pre_ordem(nodo->dir);
	}
}

// ===============================================

void caminhamento_pos_ordem(TNo *nodo){
	if (nodo != NULL)
	{	
		// Percorre a arvore pela esquerda de forma simetrica, ou seja, do menor valor para o maior
		caminhamento_pos_ordem(nodo->esq);
		// Percorre a arvore pela direita de forma simetrica, ou seja, do menor valor para o maior
		caminhamento_pos_ordem(nodo->dir);
		// Mostrar no prompt o valor do NO da arvore
		printf("\n\t%d\n",nodo->valor);
	}
}

// ===============================================

void buscarArvore(TNo *nodo, int *argumento){

	// Se o NO encontrado for NULL significa o valor nao foi encontrado
	if (nodo == NULL){
		printf("\n\n\n\tVALOR NAO ENCONTRADO\n\n");

	} else if (nodo->valor == *argumento) {
		// Quando encontrar e valor, mostrar ele no prompt
		printf("\n\t%d\n", *argumento);

	} else if (nodo->valor > *argumento){
		// Se o valor do NO atual for maior que o valor buscado, desce o NO pela esquerda e chama a funcao de 
		// busca novamente
		buscarArvore(nodo->esq, argumento);

	} else {
		// Se o valor do NO atual for menor que o valor buscado, desce o NO pela direira e chama a funcao de busca
		// novamente
		buscarArvore(nodo->dir, argumento);

	}
}

