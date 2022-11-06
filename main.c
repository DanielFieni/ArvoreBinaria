#include "lista.h"

int main(int argc, char *argv[]){
    
    int op, argumento;

    raiz = inicializaArvore();

   do{
		op = menu();
		switch (op)
		{
            case 0:
                //sair
                break;
            case 1:
                //inserir
                inserir(&raiz);
                break;

            case 2:
                // Caminhamento em ordem
                printf("\n\t=====| Caminhamento EM ORDEM |=====\n\n");
                caminhamento_em_ordem(raiz);
                printf("\n\n");
                break;

            case 3:
                // Caminhamento Pre Ordem
                printf("\n\t=====| Caminhamento PRE ORDEM |=====\n\n");
                caminhamento_pre_ordem(raiz);
                printf("\n\n");
                break;

            case 4: 
                // Caminhamento Pos Ordem
                printf("\n\t=====| Caminhamento POS ORDEM |=====\n\n");
                caminhamento_pos_ordem(raiz);
                printf("\n\n");
                break;

            case 5:
                // Buscando um valor na arvore
                printf("\n\t=====| BUSCANDO UM VALOR |=====\n\n");
                printf("Insira o valor a procurado: ");
                scanf("%d", &argumento);
                buscarArvore(raiz, &argumento);
                printf("\n\n");
                break;

            case 6: 
                //Remover valor da arvore
                printf("\n\t|============= EXCLUIR ELEMENTO =============|\n");
                printf("Insira o valor a ser removido: ");
                scanf("%d" , &argumento);
                removerArvore(&raiz, &argumento);
                break;
            
            default:
                // Caso a opcao digitada nao exista
                printf("\n\n\n\tOpcao invalida! Tente novamente!\n\n\n");
                break;
        }   

        system("PAUSE");

	} while(op != 0);

    return 0;
}
