#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

void instrucao();

void menu ()
{
    int op=0;
    printf("\n================================================================================");
    printf("\n         Seja bem vindo ao Jogo Blackjack — 21.");
    printf("\n         1 — Ler tutorial");
    printf("\n         2 — Começar a jogar.");
    printf("\n         Selecione uma das opçoes acima: ");
    scanf("%i", &op);
    printf("================================================================================");



    while (op >2|| op<1)
    {
        system("cls");
        printf("\n================================================================================");
        printf("\n         Seja bem vindo ao Jogo Blackjack — 21.");
        printf("\n         1 — Ler tutorial");
        printf("\n         2 — Começar a jogar.");
        printf("\n         Selecione uma das opçoes acima: ");
        scanf("%i", &op);
        printf("================================================================================");
    }

    if (op==1)
    {
        instrucao();
        Sleep(300);
        system("cls");
    }
    else if (op==2)
    {
        int main();
        Sleep(300);
        system("cls");
    }
}

void instrucao()
{
 printf("\n\n     se vira ai");
 getch();
        system("cls");
}

int gera_carta() //função onde vai gerar o valor da carta 1-10
{
    int i;
    srand(time(NULL));
    i=rand()%51; // 0 até 51 13*4 possibilidades

    // conversão dos valores de i:
    if (i==0||i==13||i==26||i==39)
        return 1;

    if (i==1||i==14||i==27||i==40)
        return 2;

    if (i==2||i==15||i==28||i==41)
        return 3;

    if (i==3||i==16||i==29||i==42)
        return 4;

    if (i==4||i==17||i==30||i==43)
        return 5;

    if (i==5||i==18||i==31||i==44)
        return 6;

    if (i==6||i==19||i==32||i==45)
        return 7;

    if (i==7||i==20||i==33||i==46)
        return 8;

    if (i==8||i==21||i==34||i==47)
        return 9;

    if (i==9||i==22||i==35||i==48)
        return 10;

    if (i==10||i==23||i==36||i==49)
        return 11;

    if (i==11||i==24||i==37||i==50)
        return 12;

    if (i==12||i==25||i==38||i==51)
        return 13;
}

void mostra_carta(int *carta, int n)
{
    if (carta[n]==1)
        printf("        ======\n        |A   |\n        |    |\n        |   A|\n        ======", carta[n], carta[n]); //ÁS
    if (carta[n]==11)
        printf("        ======\n        |J   |\n        |    |\n        |   J|\n        ======", carta[n], carta[n]); //valete
    if (carta[n]==12)
        printf("        ======\n        |Q   |\n        |    |\n        |   Q|\n        ======", carta[n],carta[n]);//dama
    if (carta[n]==13)
        printf("        ======\n        |K   |\n        |    |\n        |   K|\n        ======", carta[n],carta[n]);//rainha
    if (carta[n]<10&&carta[n]>1)
        printf("        ======\n        |%i   |\n        |    |\n        |   %i|\n        ======", carta[n],carta[n]); //1-9
    if(carta[n]==10)
        printf("        ======\n        |%i  |\n        |    |\n        |  %i|\n        ======", carta[n],carta[n]);//10
}

int main ()
{
    setlocale(LC_ALL,"Portuguese_Brazil");
    menu();
    int opi=1;

    ///DECLARAÇÕES DAS VARIÁVEIS ======================================================================

    do
    {
        int player=0; //vai receber a quantidade de jogadores que irão jogar
    printf("\n\n Insira quantos jogadores irão participar da mesa: ");
    scanf("%i", &player);

    while (player<0)
    {system("cls");
    printf("\n\n Insira quantos jogadores irão participar da mesa: ");
    scanf("%i", &player);
    }

    char nome_jogador[player][50];
    int carta[player][5];
    int somatoria[player];
    int aux;
    int qt=0,op;
    for (aux=1; aux<=player; aux++) //zera a somatória dos player
        somatoria[aux]=0;

///Insert nos nomes dos players ======================================================================
    for (aux=1; aux<=player; aux++)
    {
        printf("\n          Insira o Nome do %iº  jogador: ", aux);
        fflush(stdin);
        gets(nome_jogador[aux]);
    }

    system("cls");

    /// mão dos players/ inicio do programa ===========================================================

    for (aux=1; aux<=player; aux++)
    {
        printf("\33[1m"); /// para deixar em negrito.
        printf("\n================================================================================");
        printf("\n  ¤ Vez do jogador: %s ¤", nome_jogador[aux]);
        printf("\n================================================================================");
        printf("\33[0m");
        printf("\n             CARTAS SOB A MESA:       \n\n");

        carta[aux][0]=gera_carta(); //chamada da função p/gerar carta, com retorno de um numero da carta 1-13

        if (carta[aux][0]>10) //aqui faz a somatória do numero recebido pela função. as cartas J/Q/K tem o valor de 10 no jogo
            somatoria[aux]= somatoria[aux]+10; // por isso os numeros recebidos acima de 10 (11,12,13) são somados com 10, pela regra
        else
            somatoria[aux] += carta[aux][0]; // se não for maior q 10, o numero recebido, é somado com o próprio numero. Sem regras.
        printf("\33[1m");
        mostra_carta(carta[aux], 0); //chamada da função p/mostrar as carta
        printf("\33[0m");

        /// inicio do Laço após a primeira carta lançada

        do  //     vai rodar enquanto a quantidade de cartas forem menores que 5, ou a opção dor igual a dois (parar de pedir cartas)
        {
            printf("\n\n     Deseja descer mais uma carta? ");
            printf("\n     1 - Sim.\n     2 - Não.");
            printf("\n     Selecione uma das opções acima: ");
            scanf("%d", &op);
            printf("\n\n");
            printf("\n\n");

            while (op >2|| op<1)
            {
                system("cls");
                printf("\n\n     O número inserido é inválido. Insira-o novamente:");
                printf("\n\n     Deseja descer mais uma carta? ");
                printf("\n    1 - Sim.\n     2 - Não.");
                printf("\n  Selecione uma das opções acima: ");
                scanf("%d", &op);
                printf("\n\n\33[0m");
            }

            switch (op)
            {
            case 1:
            {
                carta[aux][qt]=gera_carta();

                if (carta[aux][qt]>10)
                    somatoria[aux]= somatoria[aux]+10;
                else
                    somatoria[aux]+= carta[aux][qt];
                    printf("\33[1m");
                mostra_carta(carta[aux], qt);
                    printf("\33[0m");
                printf("\n                          Pontuação do Jogador é de:\33[1m %i \33[0m \n\n", somatoria[aux]);

                if (somatoria[aux]>21)
                {
                    printf("\n\n  O Jogador %s Estourou 21!\n\n", nome_jogador[aux]);
                    break;
                }

                break;
            }

            case 2:
            {
                system("cls");
                printf("\n================================================================================");
                printf("\n        O Jogador %s encerra suas jogadas!",nome_jogador[aux]);
                printf("\n        Pontuação de %s foi de: %i\n", nome_jogador[aux],somatoria[aux]);
                printf("================================================================================\n\n");
                break;
            }
        }
    qt++; //incrementa a quantidade de cartas

        }
        while (op!=2 && qt<aux*5&& somatoria[aux]<=21);

        system("pause");
        system("cls");
      //  printf("\n diferença %i", res[aux]);
    } /// fim do laço de players.

    /// mostra dos resultados ===================================================

        int i=0, flag=0;


    for(aux=1; aux<=player; aux++)
    {
        printf("\n O jogador %s Atingiu %i pontos.", nome_jogador[aux], somatoria[aux]);
        if (somatoria[aux] == 21)
            printf("O jogador %s ganhou, fazendo os gloriosos 21 pontos ...\n", nome_jogador[aux]);
    }

      for(aux=1; aux<=player; aux++)
            {
        if (somatoria[aux] == 21)
            printf("\n\nO jogador %s ganhou, fazendo os gloriosos 21 pontos ...\n", nome_jogador[aux]);
            }

    int winner = somatoria[0];

         for (aux=1; aux<player*5; aux++)
        {
            if (somatoria[aux] <=21)
                somatoria[aux]= (somatoria[aux] - 21) * (-1);
            if (somatoria[aux] < winner)
            {
                winner = somatoria[aux]; //achar a menor diferença entre a somatória e 21
                i=aux;
                flag=1;
            }
        }

         if (flag==1)
    printf("\n\n O jogador = %s = Ganhou a partida por ter tido o ponto mais próximo de 21.\n\n", nome_jogador[i]);



getch();
system("cls");
printf("================================================================================");
printf("\n\n Deseja jogar novamente?");
printf("\n\n 1 - Sim.");
printf("\n\n 2 - Não");
printf("\n  Selecione uma opção:");
scanf("%i", &opi);
printf("================================================================================");

    if (opi==2)
        exit(1);


    }while (opi!=2);

}













