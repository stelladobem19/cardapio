#include "header.h"

int insereItem(ListaCDE *l, int item, int quantidade, char nome[], float valor, float unidade) {
  No* novoNo = (No*)malloc(sizeof(No)); /*Inserindo novo nó na memoria e checando se deu certo*/
    if(novoNo == NULL)
    return 0;

        novoNo->id = item;               /*Faço a passagem de todos parametros enviados na chamada de função do main para o novo nó*/
        novoNo->quantidade= quantidade;
        strcpy(novoNo->produto, nome);
        novoNo->valor = valor;
        novoNo->unidade= unidade;
        novoNo->ant = NULL;
        novoNo->prox = NULL;

                 /*Caso minha lista esteja vazia, o novo nó se torna o inicio dela*/
    if (l->inicio == NULL) {
        l->inicio = novoNo;    /*Tanto o inicio quanto o fim da lista apontam para o novo nó*/
        l->fim = novoNo;

                /*Caso a lista não esteja vazia eu faço a inserção do nó, ao final na lista*/
    } else {
        No* aux = l->inicio;        /*Encontra o último nó da lista*/
        while (aux->prox != NULL) {
            aux = aux-> prox;
        }
            aux->prox = novoNo;     /* Insere o novo nó após o último nó */
            novoNo->ant = aux;
            }
}

}

int removeItem(ListaCDE *l, int itemRemover, char nome[], float valor, float unidade) {
    No* aux = l->inicio;                 /*Faço o aux apontar para o primeiro item da lista e percorrer*/
                                        /*a lista em busca do nó a ser removido*/
    while (aux != NULL) {
        if (aux->id == itemRemover) {
            /*Reduz a quantidade do item em 1*/
            aux->quantidade -= 1;
            aux->valor = aux->valor - aux->unidade ; /* Atualiza o valor do item no nó peganto o valor total */
                                                     /*e diminuindo o valor de apenas uma unidade*/
                                                     /* Se a quantidade chegar a zero, o nó será removido da lista*/
            if (aux->quantidade == 0) {
                if (aux->ant != NULL) {
                        aux->ant->prox = aux->prox; /*o proximo do nó anterior passará a apontar para o mesmo proximo que o  nó em que*/
                }                                   /*o prox do aux aponta, assim será feita a "costura" da lista */
                    else {
                        l->inicio = aux->prox;     /*Caso seja o primeiro da lista o inicio da lista passar a apontar para o então segundo*/
                    }                              /*nó da lista para que o atual inicio seja removido*/

                if (aux->prox != NULL) {
                        aux->prox->ant = aux->ant;
                    }

                free(aux); /*Libero memoria*/
            }

            break; /* Sai do loop após encontrar o nó desejado*/
        }
        aux = aux->prox;  /*andando pela lista até encontrar o nó desejado*/
    }
}

void displayLista(ListaCDE *l) {
      No* aux = l->inicio;

    while (aux != NULL) {
        printf("%d   %d     %s        %.2f\n", aux->id, aux->quantidade, aux->produto, aux->valor);
        aux = aux->prox;
    }

    printf("\n");
}

void cria(ListaCDE *l) {
    l->inicio = NULL;
    l->fim = NULL;
}

void tempoPreparo() {
  time_t t = time(NULL);  /*obtendo horario atual*/
    struct tm* horario = localtime(&t);
    horario->tm_min = horario->tm_min + 40; /*Adciono 40 minutos estimados de tempo para preparo do pedido*/
    mktime(horario);
    printf("Seu pedio está previsto para ficar pronto ás: %02d:%02d\n", horario->tm_hour, horario->tm_min);
}
