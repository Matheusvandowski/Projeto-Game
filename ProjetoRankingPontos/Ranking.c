#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct {
    int Codigo;
    float Pontos;
    char Sexo;}
Jogador;
typedef Jogador Jogo[25];

void PrintMenu(int Principal, int Argumento){
    system("cls");
        printf("CASTLELVANIA");

    switch(Principal){
        case 1:

printf(" \n\n+--------------------------------Menu-------------------------------+\n\
|                                                                   |\n\
|  1 Jogar                                                          |\n\
|  2 Jogador ranqueado com a maior pontuacao                        |\n\
|  3 Jogador ranqueado com menos pontuacao                          |\n\
|  4 Mostrar os dados de um jogador, se ranqueado, usando seu codigo|\n\
|  5 Mostrar o numero de jogadores ranqueados                       |\n\
|  6 Mostrar o ranking dos jogadores (TOP20)                        |\n\
|  7 Remover um jogador desse ranking, usando codigo e senha admin  |\n\
|  8 Fim                                                            |\n\
|                                                                   |\n\
+-------------------------------------------------------------------+\n");

        if(Argumento == 1){
            printf("\n   +-------------------!! AVISO !! ----------------+\n\
   |                                               |\n\
   |                 OPCAO INVALIDA                |\n\
   |                 TENTA OUTRA VEZ               |\n\
   |                                               |\n\
   +-----------------------------------------------+\n");
                            system("pause");
                            }
                            break;
        }

    }

void Jogar( Jogo Pessoa, int *Fim){

    Jogador NovaPessoa;
    int IndicePessoa, i;
    PrintMenu( 0,0);
    printf("\n NOVO PLAYER\t\t\t \n +-------------------------------------+");
        if (*Fim == 26){
            printf("\n Nao ha espaco para um novo player \n +-------------------------------------+");
            system("pause");
            return;
        }
        printf("\n|\n| Codigo: ");
        scanf("%d",&NovaPessoa.Codigo);
        printf("|\n| Pontos: ");
        scanf("%f", &NovaPessoa.Pontos);
        printf("|\n| Sexo: ");
        fflush(stdin);
        NovaPessoa.Sexo=getchar();

        IndicePessoa = *Fim + 1;
        for(i = 0; i <= *Fim; i++){
            if(Pessoa[i].Pontos <=NovaPessoa.Pontos){
                IndicePessoa = i;
                i = *Fim;
            }
        }
        for (i=*Fim; i >= IndicePessoa; i--){
            Pessoa[i+1].Codigo = Pessoa[i].Codigo;
            Pessoa[i+1].Pontos = Pessoa[i].Pontos;
            Pessoa[i+1].Sexo = Pessoa[i].Sexo;
        }
        Pessoa[IndicePessoa]=NovaPessoa;
        (*Fim)++;
        PrintMenu(0,0);
        printf("\n NOVO PARTICIPANTE \n");
        printf("\n +----------+ \n Pessoa cadastrada com Sucesso \n +----------+ \n");
        system("pause");
        return;

}

void MaisPontos( Jogo Pessoa, int *Fim){

    PrintMenu(0,0);
    printf("\n MELHOR CLASSIFICADO - RANKING: \n");

    if(*Fim == -1){
        printf("\n\n +------------------+ \n\n Ninguem Cadastrado \n\n +------------------+ \n\n");
        }
    else{
        printf("\n|Codigo      |Pontos        |Sexo\t\t|\n\n");
        printf("|%d\t\t%.2f\t\t%c\t\t|\n", Pessoa[0].Codigo, Pessoa[0].Pontos, Pessoa[0].Sexo);
        printf("+-----------------------------------------------+\n\n");
        }

        system("pause");
        return;
}

void MenosPontos( Jogo Pessoa, int *Fim){

    PrintMenu(0,0);
    printf("\n PIOR CLASSIFICADO - RANKING: \n");

    if(*Fim == -1){
        printf("\n\n +------------------+ \n\n Ninguem Cadastrado \n\n +------------------+ \n\n");
        }
    else{
        printf("\n|Codigo      |Pontos        |Sexo\t\t|\n\n");
        printf("|%d\t\t%.2f\t\t%c\t\t|\n", Pessoa[*Fim].Codigo, Pessoa[*Fim].Pontos, Pessoa[*Fim].Sexo);
        printf("+-----------------------------------------------+\n\n");
        }

        system("pause");
        return;
}

void NumJogadores(int *Fim){
    PrintMenu(0,0);
    printf("\n+----------------------------+\n| Numero de Participantes\t\t    |\n+----------------------------+\n");
        if(*Fim  == -1){
            printf("\n\n +------------------+ \n\n Ninguem Cadastrado \n\n +------------------+ \n\n");
        }
        else {
            printf("\n Numero de Jogadores: %d", (*Fim)+1);
            printf("\n+----------------------------+\n\n");
        }
        system("pause");
        return;
}

void MostrarRanking(Jogo Pessoa, int *Fim){

    int i;
    PrintMenu(0,0);
    printf("\n+--------------------------------+\n| RANKING 20 MELHORES PLAYERS\t\t\t      |\n+--------------------------------+");
    if (*Fim==-1){
        printf("\n\n +------------------+ \n\n Ninguem Cadastrado \n\n +------------------+ \n\n");
    }
    else{
       printf("\n|Codigo      |Pontos        |Sexo\t\t|\n\n");
       for(i=0; i<=19; i++){
             printf("|%d\t\t%.2f\t\t%c\t\t|\n", Pessoa[i].Codigo, Pessoa[i].Pontos, Pessoa[i].Sexo);
             printf("+-----------------------------------------------+\n\n");
        }
    }

    system("pause");
    return;

}


int main (){

char Opcao;
int i, Fim;
Fim = -1;
Jogo Pessoa;

do{PrintMenu(1,0);
    Opcao = getch();
    switch(Opcao)
        {

    case 49: // 1 - Jogar
            Jogar(Pessoa, &Fim);
            break;

    case 50://2 - Mais Pontos
            MaisPontos(Pessoa, &Fim);
            break;

    case 51://3 0 Menos Pontos
            MenosPontos(Pessoa, &Fim);
            break;

    case 53://5 Numero de Jogadores no Raking
            NumJogadores(&Fim);
            break;

    case 54://6 Ranking(TOP 20)
            MostrarRanking(Pessoa, &Fim);
            break;

    case 56://8
        PrintMenu(0,0);
        printf("\n\n PROGRAMA ENCERRADO\n\n");
        printf("Matheus Alves \t\n\n");
        break;

    default:
        PrintMenu(1,1);
        }
    }while(Opcao!= 56);
    system("pause");

return 0;
}






