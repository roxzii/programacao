#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void limpatela()
{
    for (int i = 0; i < 150; i++)
    {
        printf("\n");
    }   
}

//Aber, imprime e conta o número de linhas do ficheiro "bin.txt":
int OpenTXT()
{
    int ch, linha = 0;
    FILE *f;
    
    //Abrir o ficheiro em modo leitura:
    f = fopen("bin.txt", "r");

    //Verificar se o ficheiro foi aberto com sucesso:
    if (f == NULL)
    {
        fprintf(stderr, "Erro na abretura do ficheiro %s.\n", "bin.txt");
        exit(EXIT_FAILURE);
    }

    //Imprimir no ecrã o conteúdo do ficheiro: 
    while ((ch = fgetc(f)) != EOF)
    {
        putchar(ch); //igual ao printf("%d", ch);
        if (ch == '\n')
        {
            linha++;
        }
    }

    return linha;
}

//Aber e imprime o conteúdo do ficheiro "bin.bin":
void OpenBIN()
{

}

//Premete ao utilizador adicionar uma questão nova ao jogo:
int AddQuest()
{
    char quest[150];

    //Abertura do ficheiro:
    //*********************************************************************************
    FILE *f;
    
    //Abrir o ficheiro em modo leitura:
    f = fopen("bin.txt", "w");

    //Verificar se o ficheiro foi aberto com sucesso:
    if (f == NULL)
    {
        fprintf(stderr, "Erro na abertura do ficheiro %s.\n", "bin.txt");
        exit(EXIT_FAILURE);
    }
    //*********************************************************************************

    printf("Questão-> ");
    fgets(quest,150,stdin);

    fprintf(f, "\n\nString: %s\n", quest);

    return 0;
}

int jogar()
{
    int a, aux = 0, aux1 = 0;
    char letra[150];
    limpatela();

    srand(time(NULL)); //Define como semente para a função rand() a hora atual do sistema
    a = rand()%3;
    
    printf("a = %i\n\n", a);
    if (a > 0)
    {
        aux1 = 5 * a + a;
    }
    else
    {
        aux1 = 5 * a;
    }

    //************************************************************************************************
    //Abertura do ficheiro:
    FILE *f;
    
    //Abrir o ficheiro em modo leitura:
    f = fopen("bin.txt", "r");

    //Verificar se o ficheiro foi aberto com sucesso:
    if (f == NULL)
    {
        fprintf(stderr, "Erro na abretura do ficheiro %s.\n", "bin.txt");
        exit(EXIT_FAILURE);
    }
    //************************************************************************************************
    

    for (int i = 0; i < aux1 + 7;i++)
    {
        aux++;
        fgets(letra,150,f);
        if (aux > aux1 && aux <= aux1 + 5)
        {
            printf("%s", letra);
        }
    }

    return 0;
}

//Mostra ao utilizador as questões armazenadas:
void Listar()
{
    int linha = OpenTXT(), aux = 0;
    char letra[150], continuar;

    //************************************************************************************************
    //Abertura do ficheiro:
    FILE *f;
    
    //Abrir o ficheiro em modo leitura:
    f = fopen("bin.txt", "r");

    //Verificar se o ficheiro foi aberto com sucesso:
    if (f == NULL)
    {
        fprintf(stderr, "Erro na abretura do ficheiro %s.\n", "bin.txt");
        exit(EXIT_FAILURE);
    }
    //************************************************************************************************
    
    limpatela();
    for (int i = 0; i < linha - 4;i++)
    {
        aux++;
        fgets(letra,150,f);
        printf("%s", letra);
        if (aux == 11)
        {
            printf("\nPor favor clique no ENTER para continuar....");
            scanf("%cd", &continuar);
            limpatela();
            aux = -1;
        }
    }

    //Teste:
    //fgets(letra,89,f);
    //printf("%s", letra);
}

//Premite ao utilizar Gerir o concurso:
void GerirConcurso()
{
    //A variável "tank" serve para caso o utilizador digita uma letra ou um simbolo o programa não quebrar:
    int tank;
    char opc[0];

    limpatela();
    printf("Olá! Por favor escolha uma das seguintes opções:\n");
    printf("1 -> Listar Questões;\n");
    printf("2 -> Procurar Questões;\n");
    printf("3 -> Adicionar Questões;\n");
    printf("4 -> Remover Questões;\n");
    printf("5 -> Sair\n");
    printf("->");
    scanf("%s", opc);
    tank = atof(opc);

    //Vereficar a opção escolhida pelo utilizador:
    while (tank != 1 && tank != 2 && tank != 3 && tank != 4 && tank != 5)
    {
        limpatela();
        printf(" <(*-*)>   <(*-*)>   <(*-*)>\n");
        printf("\nO valor introduzido é inválido.\nPor favor digite um número entre 1 e 5 seguido de um ENTER.\n");
        printf("1 -> Listar Questões;\n");
        printf("2 -> Procurar Questões;\n");
        printf("3 -> Adicionar Questões;\n");
        printf("4 -> Remover Questões;\n");
        printf("5 -> Sair\n");
        printf("-> ");
        scanf("%s", opc);
        tank = atoi(opc);
    } 

    //Escolha da opção a Realizar:
    switch (tank)
    {
    case 1:
        limpatela();
        Listar();
        break;
    case 2:
        limpatela();
        break;
    case 3:
        limpatela();
        AddQuest();
        break;
    case 4:

        break;
    case 5:
        break;
    default:
        break;
    }
}

//Mostra ao utilizador o menu do jogo:
void menujogo()
{   
    //A variável "tank" serve para caso o utilizador digita uma letra ou um simbolo o programa não quebrar:
    int tank;
    char opc[0];  
    
    printf("********************************************************************************\n");
    printf("*                                                                              *\n");
    printf("*                  Quem quer ser Milionário                                    *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n");
    printf("\n");
    printf("Bem-vindo ao jogo Quem quer ser Milinário.\n");
    printf("Por favor indique umas das seguintes opções:\n");
    printf("\n1 -> Gerir concurso.\n");
    printf("2 -> Iniciar Concurso.\n");
    printf("-> ");

    //Escolha da opção e verificar o valor introduzido:
    scanf("%s", opc);
    tank = atoi(opc);

    while (tank != 1 && tank != 2)
    {
        limpatela();
        printf(" <(*-*)>   <(*-*)>   <(*-*)>\n");
        printf("\n");
        printf("O valor introduzido é inválido.\nPor favor digite o número 1 ou 2 seguido de um ENTER.");
        printf("\n1 -> Gerir concurso.\n");
        printf("2 -> Iniciar Concurso.\n");
        printf("-> ");
        scanf("%s", opc);
        tank = atoi(opc);
    } 

    if (tank == 1)
    {
        GerirConcurso();
    }
    else
    {
        jogar();
    }
    
    
}

//Mostrar ao utilizador a opção de ver um modo texto ou modo binário:
void menu()
{
    //A variável "tank" serve para caso o utilizador digita uma letra ou um simbolo o programa não quebrar:
    int tank;
    char con, opc[0];

    printf("Por favor indique como pretende ver o conteúdo sobre as questões:\n");
    printf("1 -> Ver em modo Texto.\n");
    printf("2 -> Ver em modo Binário.\n");
    scanf("%s", opc);

    tank = atoi(opc);

    //Vereficar se o valor introduzido é válido:
    while (tank != 1 && tank != 2)
    {
        printf(" <(*-*)>   <(*-*)>   <(*-*)>\n");
        printf("\n");
        printf("O valor introduzido é inválido.\nPor favor digite o número 1 ou 2 seguido de um ENTER.");
        printf("\n1 -> Ver em modo Texto.\n");
        printf("2 -> Ver em modo Binário.\n");
        printf("-> ");
        scanf("%s", opc);
        tank = atoi(opc);
    }

    //Abrir os ficheiros:
    if (tank == 1)
    {
        limpatela();
        OpenTXT();
        scanf("%cd", &con);
        limpatela();
        menujogo();
    }
    else
    {
        
    }
}

int main(void)
{    
    limpatela();
    menu();
    /*srand(time(NULL));

    a = (rand()%8);
    
    printf("a = %i\n\n", a);*/
    
    return 0;
}