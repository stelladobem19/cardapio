#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include "header.h"

int main() {
    setlocale(LC_ALL, "Portuguese"); /* Definindo o idioma para Portugu�s */

    int menu, porcoes, sobremesas, bebidas, opcao, quantidade, sucesso;
    int decisao = 1;
    int tamanhoLista = 0;
    float total = 0.0;
    char cliente[50], timeString[9];
    time_t currentTime;
    struct tm *timeInfo;

    /* Op��es e pre�os dos itens */
    float batata = 10.99;
    float frango = 15.99;
    float tilapia = 18.99;
    float alcatra = 21.99;
    float bolo = 12.99;
    float pudim = 9.99;
    float brigadeiro = 4.99;
    float petit = 14.99;
    float agua = 2.00;
    float suco = 8.49;
    float coca = 6.99;
    float chopp = 12.99;
    ListaCDE l;

    cria(&l); /*crio minha lista para ent�o come�armos*/

     printf("Ol�! Seja bem vindo(a) nosso Restaurante! Como voc� gostaria de ser chamado(a)?\n");
            scanf("%s", cliente);
            printf("� um prazer lhe servir %s ! Vamos come�ar seu pedido?\n\n", cliente);

       /* inicio do la�o de repeti��o principal */
    do {

        printf("Este � o nosso menu de op��es\n");
        printf("------------- POR��ES & CIA -------------\n\n");
        printf("--------------MENU PRINCIPAL-------------\n");
        printf("| 1- Por��es                            |\n");
        printf("| 2- Sobremesas                         |\n");
        printf("| 3- Bebidas                            |\n");
        printf("|   Qual op��o deseja navegar?          |\n");
        printf("----------------------------------------\n");
        printf("(Digite o n�mero referente ao menu que deseja navegar)\n");
                printf("Desejo abrir o menu n�mero:");
                scanf("%d", &menu);
                system("cls");

                if((menu == 1) || (menu == 2) || (menu == 3)){

        switch (menu) {
            case 1:
                printf("\n");
                printf("--------------MENU DE POR��ES-----------\n");
                printf("|OP��O  COD    PRODUTO           VALOR   |\n");
                printf("| 1     10   Batata Frita      R$%5.2f   |\n",batata);
                printf("| 2     11   Frango Frito      R$%5.2f   |\n",frango);
                printf("| 3     12   Fil� de til�pia   R$%5.2f   |\n",tilapia);
                printf("| 4     13   Alcatra           R$%5.2f   |\n",alcatra);
                printf("| 5     --   retornar ao menu principal  | \n");
                printf("|Qual por��o deseja adicionar ao pedido? |\n");
                printf("----------------------------------------\n");
                printf("*Caso tenha optado por retornar, digite o n�mero 5 no seu pedido*\n\n");
                printf("Para adicionar uma porc�o ao seu pedido digite \no n�mero referente a ela(OP��O)\n\n");
                printf("Adicionar ao pedido op��o n�mero:");
                        scanf("%d", &porcoes);

                        if(porcoes == 5){ // Se o usu�rio quiser voltar ao menu principal, teclar 5
                        getchar();
                        system("cls");
                        break;
                }
                printf("Digite a quantidade que voc� deseja: ");
                        scanf ("%d", &quantidade);
                printf("----------------------------------------\n");

                switch (porcoes) {
                    case 1:
                        sucesso=insereItem(&l, 10, quantidade, "Batata Frita", batata*quantidade, batata);   /* Insere item na lista e checa se deu certo */
                        if(!sucesso)
                        printf("Problemas ao fazer seu pedido...\n");
                        total = total + (batata * quantidade);         /*total recebe seu valor atual + quantidade de pedidos feitos do item*/
                        tamanhoLista= tamanhoLista+ (1*quantidade);    /*Tamanho da lista aumenta conforme quantidade de itens foram requisitados */
                        break;

                    case 2:
                        sucesso=insereItem(&l, 11, quantidade, "Frango", frango*quantidade, frango);
                        if(!sucesso)
                        printf("Problemas ao fazer seu pedido...\n");
                        total = total + (frango * quantidade);
                        tamanhoLista= tamanhoLista+ (1*quantidade);
                        break;

                    case 3:
                        sucesso=insereItem(&l, 12, quantidade, "Til�pia", tilapia*quantidade, tilapia);
                        if(!sucesso)
                        printf("Problemas ao fazer seu pedido...\n");
                        total = total + (tilapia * quantidade);
                        tamanhoLista= tamanhoLista+ (1*quantidade);
                        break;

                    case 4:
                        sucesso=insereItem(&l, 13, quantidade, "Alcatra", alcatra*quantidade, alcatra);
                        if(!sucesso)
                        printf("Problemas ao fazer seu pedido...\n");
                        total = total + (alcatra * quantidade);
                        tamanhoLista= tamanhoLista+ (1*quantidade);
                        break;

                        default:
                        printf("Op��o inv�lida!\n");              /*Caso a op��o seja inv�lida o usu�rio ter� a op��o*/
                }                                                 /*de retornar ao menu principal*/
                break;

            case 2:
                printf("-------------MENU DE SOBREMESAS-------------\n");
                printf("|OP��O  COD    PRODUTO           VALOR     |\n");
                printf("| 1     21    Bolo de Chocolate R$%.2f    |\n", bolo);
                printf("| 2     22    Pudim de Leite    R$%.2f     |\n", pudim);
                printf("| 3     23    Brigadeiro        R$%.2f     |\n", brigadeiro);
                printf("| 4     24    Petit Gateau      R$%.2f    |\n", petit);
                printf("| 5     --    Retornar ao menu principal   | \n");
                printf("|Qual sobremesa deseja adicionar ao pedido?|\n");
                printf("-------------------------------------------\n");
                printf("*Caso tenha optado por retornar, digite o n�mero 5 no seu pedido*\n\n");
                printf("Para adicionar uma sobremesa ao seu pedido digite \no n�mero referente a ela(OP��O)\n");
                printf("Adicionar ao pedido op��o n�mero:");
                        scanf("%d", &sobremesas);

                if(sobremesas == 5){ // Se o usu�rio quiser voltar ao menu principal, teclar 5
                        getchar();
                        system("cls");
                        break;
                }

                printf("Digite a quantidade que voc� deseja: ");
                scanf ("%d", &quantidade);
                printf("----------------------------------------\n");


                switch (sobremesas) {
                    case 1:
                        sucesso=insereItem(&l, 21, quantidade, "Bolo de Chocolate", bolo*quantidade, bolo);    /* Insere item na lista e checa se deu certo*/
                        if(!sucesso)
                        printf("Problemas ao fazer seu pedido...\n");
                        total = total + (bolo*quantidade);             /*total recebe seu valor atual + quantidade de pedidos feitos do item*/
                        tamanhoLista= tamanhoLista+ (1*quantidade);    /*Tamanho da lista aumenta conforme quantidade de itens foram requisitados */
                        break;
                    case 2:
                        sucesso=insereItem(&l, 22, quantidade, "Pudim de Leite", pudim*quantidade, pudim);
                        if(!sucesso)
                        printf("Problemas ao fazer seu pedido...\n");
                        total = total + (pudim*quantidade);
                        tamanhoLista= tamanhoLista+ (1*quantidade);
                        break;
                    case 3:
                        sucesso=insereItem(&l, 23, quantidade, "Brigadeiro", brigadeiro*quantidade, brigadeiro);
                        if(!sucesso)
                        printf("Problemas ao fazer seu pedido...\n");
                        total = total +(brigadeiro*quantidade);
                        tamanhoLista= tamanhoLista+ (1*quantidade);
                        break;
                    case 4:
                        sucesso=insereItem(&l, 24, quantidade, "Petit Gateau", petit*quantidade, petit);
                        if(!sucesso)
                        printf("Problemas ao fazer seu pedido...\n");
                        total = total +(petit*quantidade);
                        tamanhoLista= tamanhoLista+ (1*quantidade);
                        break;

                        default:
                        printf("Op��o inv�lida!\n");             /*Caso a op��o seja inv�lida o usu�rio ter� a op��o*/
                }                                                /*de retornar ao menu principal*/
                break;

            case 3:
                printf("-------------MENU DE BEBIDAS-------------\n");
                printf("|OP��O  COD    PRODUTO           VALOR   |\n");
                printf("| 1     31      �gua             R$%.2f  |\n", agua);
                printf("| 2     32      Suco de Laranja  R$%.2f  |\n", suco);
                printf("| 3     33      Coca-Cola        R$%.2f  |\n", coca);
                printf("| 4     34      Chopp            R$%.2f |\n", chopp);
                printf("| 5     --   retornar ao menu principal  | \n");
                printf("|Qual bebida deseja adicionar ao pedido? |\n");
                printf("-----------------------------------------\n");
                printf("*Caso tenha optado por retornar, digite o n�mero 5 no seu pedido*\n\n");
                printf("Para adicionar uma bebida ao seu pedido digite \no n�mero referente a ela(OP��O)\n");
                printf("Adicionar ao pedido, op��o n�mero:");
                        scanf("%d", &bebidas);

                        if(bebidas == 5){ // Se o usu�rio quiser voltar ao menu principal, teclar 5
                        getchar();
                        system("cls");
                        break;
                }
                printf("Digite a quantidade que voc� deseja: ");
                        scanf ("%d", &quantidade);
                printf("----------------------------------------\n");


                switch (bebidas) {
                    case 1:
                        sucesso=insereItem(&l, 31, quantidade, "�gua", agua*quantidade, agua); /* Insere item na lista e checa se deu certo */
                        if(!sucesso)
                        printf("Problemas ao fazer seu pedido...\n");
                        total = total + (agua*quantidade);                  /*total recebe seu valor atual + quantidade de pedidos feitos do item*/
                        tamanhoLista= tamanhoLista+ (1*quantidade);         /*Tamanho da lista aumenta conforme quantidade de itens foram requisitados */
                        break;
                    case 2:
                        sucesso=insereItem(&l, 32, quantidade, "Suco de Laranja", suco*quantidade, suco);
                        if(!sucesso)
                        printf("Problemas ao fazer seu pedido...\n");
                        total = total +(suco*quantidade);
                        tamanhoLista= tamanhoLista+ (1*quantidade);
                        break;
                    case 3:
                        sucesso=insereItem(&l, 33, quantidade, "Coca-Cola", coca*quantidade, coca);
                        if(!sucesso)
                        printf("Problemas ao fazer seu pedido...\n");
                        total = total +(coca*quantidade);
                        tamanhoLista= tamanhoLista+ (1*quantidade);
                        break;
                    case 4:
                        sucesso=insereItem(&l, 34, quantidade, "Chopp", chopp*quantidade, chopp);
                        if(!sucesso)
                        printf("Problemas ao fazer seu pedido...\n");
                        total = total+(chopp*quantidade);
                        tamanhoLista= tamanhoLista+ (1*quantidade);
                        break;

                        default:
                        printf("Op��o inv�lida!\n");
                }
                break;

            default:
                printf("Op��o inv�lida!\n");    /*Caso a op��o seja inv�lida o usu�rio ter� a op��o*/
            }                                  /*de retornar ao menu principal*/

                }else{
                        printf("Op��o inv�lida. Por favor, tecle ENTER para selecionar novamente!\n\n");
                        /*utiliza a fun��o getchar(); duas vezes para que o software aguarde at� o usu�rio
                         teclar enter para continuar*/
                        getchar();
                        getchar();
                        system("cls");
                    }


            printf("Deseja fazer mais um pedido? \n1 - Sim \n2 - N�o \n");
            scanf("%d", &decisao);
            printf("\n");
            system("cls");

        }while (decisao != 2);  /*Final do meu ciclo de repeti��o principal*/


            printf("---------------COMANDA------------------\n");
            printf("ID..QUANT..PRODUTO...........VALOR......\n");
            displayLista(&l);                                        /* Exibe itens do pedido */
            printf("-------------------------------\n\n");
            printf("Quantidade de itens: %d\n", tamanhoLista);    /*Exibe contador de itens selecionados */
            printf("Total a pagar: R$%.2f\n\n", total);           /*Valor total atualizado */
            printf("-------------------------------\n");
            printf("Deseja remover algum item?\n1- Sim\n2- N�o\n");
            scanf("%d", &opcao);
            printf("-------------------------------\n");


        while(opcao == 1){                                /*removo at� que o usuario n�o queira mais remover*/
        int itemRemover;
        char produtoRemover;
        float valorRemover;
            printf("Ser� removido apenas um (1) item por vez. \n");
            printf("Digite o ID do item que deseja remover: ");
            scanf("%d", &itemRemover);

            sucesso= removeItem(&l, itemRemover, "", 0, 0); /*Removo o item pedido e checo se deu certo*/
            if(!sucesso){
            printf("FALHA EM REMOVER: %d", itemRemover);
            printf("POR FAVOR DIGITE UM N�MERO DE ID V�LIDO!\n\n");
            printf("TECLE ENTER PARA DIGITAR NOVAMENTE\n");
            getchar();
            getchar();
            }
            system("cls");

            tamanhoLista=tamanhoLista - 1;
            No* aux = l.inicio;
            total= total - aux->unidade;
            printf("-----------COMANDA ATUALIZADA-----------\n");
            printf("ID..QUANT..PRODUTO...........VALOR......\n");
            displayLista(&l); // Exibir itens da lista atualizada
            printf("---------------------------------------\n");
            printf("Quantidade de itens: %d\n", tamanhoLista);
            printf("Total a pagar: R$%.2f\n", total);

            printf("Deseja remover mais algum item? \n1- Sim\n2- N�o\n\n");
            scanf("%d", &opcao);

        }
        printf("\nSEU PEDIDO EST� SENDO PREPARADO!\n");
        printf("%s, FAVOR DIRIJA-SE AO BALC�O DE ATENDIMENTO PARA REALIZAR O PAGAMENTO.\n", cliente);
        printf("\nAGRADECEMOS A CONFIAN�A, VOLTE SEMPRE!!!\n");

    time(&currentTime);
    timeInfo = localtime(&currentTime); /*fun��es da biblioteca <time.h> para pegar a hora atual*/
    strftime(timeString, sizeof(timeString), "%H:%M:%S", timeInfo);/*transformando a hora em uma string*/

    printf("Seu pedido foi conclu�do �s: %s\n", timeString);
    tempoPreparo();

    return 0;
}
