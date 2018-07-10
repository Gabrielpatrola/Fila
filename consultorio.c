#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>



typedef struct dado
{int codigo;
 char nome[80];
 float valor;
 int qt;
}dados;
typedef struct Item 
{   dados numero; 
    struct Item *proximo;    
}Itens;
typedef struct Filas 
{ 
    Itens *inicio; 
    Itens *fim; 
}Fila;

void Inicializar(Fila **fila) 
{ 
    // -> Recebe a fila por referencia 
    //    para inicializ?-la 
    *fila = (Fila *) malloc(sizeof(Fila)); 
    (*fila)->inicio = NULL; 
    (*fila)->fim = NULL; 
}

int EstaVazia(Fila *fila) 
{ 
    return fila->inicio == NULL; 
}

void Inserir(Fila *fila, int numero, char nome[],int qt,float valor) 
{ 
    Itens *novo; 
    novo = (Itens *)malloc(sizeof(Itens));  

    // -> Verifica se a mem?ria foi alocada com sucesso 
    if (novo != NULL) 
    { 
        novo->numero.codigo = numero; 
        novo->numero.qt = qt; 
        novo->numero.valor= valor; 
        strcpy(novo->numero.nome,nome); 
        novo->proximo = NULL;

        if(EstaVazia(fila)) 
        { 
            // -> Primeiro Item da Fila. 
            fila->inicio = novo; 
            fila->fim = novo; 
        } 
        else 
        { 
            // -> Ultimo item da Fila 
            fila->fim->proximo = novo; 
            fila->fim=novo; 
        } 
    } 
}

void Retirar(Fila *fila) 
{ 
    Itens *item;

    if(!EstaVazia(fila)) 
    { 
        item = fila->inicio; 
        fila->inicio = item->proximo; 
        free(item);

        // -> Se a fila acabou devemos atualizar o final 
        if (fila->inicio == NULL) 
            fila->fim = NULL; 
    } 
}

void MostrarFila(Fila *fila) 
{ 
    int i = 0; 
    Itens *item; 
    printf("\n\n Listando...\n\n"); 
    printf("---------------------------------\n");

    if (EstaVazia(fila)) 
    { 
        printf ("A Fila esta vazia!\n"); 
    } 
    else 
    {       
        item = fila->inicio;
              while(item != NULL) 
        { 
            i++; 
            printf("Item [%i]\n",i); 
            printf("Codigo-> %d\t", item->numero.codigo); 
            printf("Nome-> %s\t", item->numero.nome); 
            printf("Qt-> %d\t", item->numero.qt); 
            printf("Valor-> %.2f\n", item->numero.valor); 
            item = item->proximo; 
        } 
    }

    printf("---------------------------------\n"); 
}
Itens Mostrar(Fila *fila,int cod) 
{ 
    int i = 0; 
    Itens *item; 
    printf("\n\n Listando...\n\n"); 
    printf("---------------------------------\n");

  /*  if (EstaVazia(fila)) 
    { 
        printf ("A Fila esta vazia!\n"); 
    } 
    else 
    {    */   
        item = fila->inicio;
        if (item == NULL)
        {printf("nao cadastrado");
		}
        system("pause"); 
        while(item != NULL && item->numero.codigo==cod ) 
        { 
            i++; 
            printf("Item [%i]\n",i); 
            printf("Codigo-> %d\t", item->numero.codigo); 
            printf("Nome-> %s\t", item->numero.nome); 
            printf("Qt-> %d\t", item->numero.qt); 
            printf("Valor-> %.2f\n", item->numero.valor); 
            item = item->proximo; 
        } 
  //  }

    printf("---------------------------------\n"); 
    return *item;
}

void Menu() 
{   system("cls");
    printf("Digite a sua escolha: \n" );
    printf("1 Inserir fila \n" );
    printf("2 retirar da fila \n" );
    printf("3 tamanho da fila \n");
    printf("4 Sair \n" );
    printf("Opcao : " );
    
}


int tamanho (Fila *fila)
{ /*Retorna o tamanho da fila*/ 
 Itens *p;
 int cont = 0; 
 p = fila->inicio;
 while (p != NULL)
   { cont ++; 
     p = p->proximo; 
   }
    return cont;
 }
int main() 
{    int cod;
    Fila *fila = NULL; 
    int opcao,qt,tam; 
    int numero;
    char nome[80];
    float valor;

    Inicializar(&fila); 
   do{
   
    Menu(); 
    scanf("%i", &opcao);

   

        switch (opcao) 
        { 
            case 1: 
                printf( "Digite um numero: "); 
                scanf("\n%i", &numero);
                printf( "Digite produto: "); 
                scanf("\n%s", &nome);
                printf( "Digite a quantidade: "); 
                scanf("\n%i", &qt);
                printf( "Digite o valor unitario: "); 
                scanf("\n%f", &valor);  
                Inserir(fila, numero,nome,qt,valor); 
                MostrarFila(fila);
                system("pause");

                break; 
            case 2: 
                Retirar(fila); 
                MostrarFila(fila);
                system("pause");

                break;
                
            case 3: 
                tam= tamanho(fila); 
                printf( "Tamanho Fila=%d\n",tam);
                system("pause");

                break;

                                
            case 4: 
                   exit;
                   break;
            default: 
                
                printf( "Escolha invalida.\n\n"); 
                system("pause");
                break; 
        }

      
    }while (opcao!=5);

    system("pause"); 
    return 0;
}
