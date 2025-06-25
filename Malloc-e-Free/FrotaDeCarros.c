#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char modelo[25];
  char marca[25];
  char placa[25];
  int ano;
  char cor[25];
} bd;

main() {
  setlocale(LC_ALL, "Portuguese");
  bd *frota, *auxf;
  char opcao;
  int cont, aux, posaux, tamanho;

  printf("Número inicial de automóveis a serem cadastrados: ");
  scanf("%d", &tamanho);
  getchar();
  frota = malloc(tamanho * sizeof(bd));
  for (cont = 0; cont < tamanho; cont++) {
    printf("Modelo: ");
    gets(frota[cont].modelo);
    printf("Marca: ");
    gets(frota[cont].marca);
    printf("Placa: ");
    gets(frota[cont].placa);
    printf("Ano: ");
    scanf("%d", &frota[cont].ano);
    getchar();
    printf("Cor: ");
    gets(frota[cont].cor);
  }
  system("clear");
  do {
    printf("Menu ");
    printf("\n(I) Inserir");
    printf("\n(E) Excluir");
    printf("\n(L) Listar ");
    printf("\n(S) Sair");
    scanf("%c", &opcao);
    getchar();
    switch (opcao) {
    case 'I':
    case 'i':
      tamanho++;
      frota = realloc(frota, tamanho * sizeof(bd));
      cont = tamanho - 1;
      printf("Modelo: ");
      gets(frota[cont].modelo);
      printf("Marca: ");
      gets(frota[cont].marca);
      printf("Placa: ");
      gets(frota[cont].placa);
      printf("Ano: ");
      scanf("%d", &frota[cont].ano);
      getchar();
      printf("Cor: ");
      gets(frota[cont].cor);
      system("clear");
      break;
    case 'E':
    case 'e':
      printf("Posição absoluta que deseja excluir: ");
      scanf("%d", &posaux);
      getchar();
      if (posaux < tamanho){
      aux = 0;
      tamanho--;
      auxf = malloc(tamanho * sizeof(bd));
      for (cont = 0; cont < tamanho +1; cont++) {
        if (cont != posaux) {
          strcpy(auxf[aux].modelo, frota[cont].modelo);
          strcpy(auxf[aux].marca, frota[cont].marca);
          strcpy(auxf[aux].placa, frota[cont].placa);
          auxf[cont].ano = frota[cont].ano;
          strcpy(auxf[cont].cor, frota[cont].cor);
          aux++;
        }
      }
      free (frota);
      frota = auxf;
        system("clear");
      } else {
        printf("Posição inválida \n");
      }
      break;
    case 'L':
    case 'l':
      aux = 0;
      for (cont = 0; cont < tamanho; cont++) {
        printf("\n--------------------------");
        printf("\nModelo: %s", frota[cont].modelo);
        printf("\nMarca: %s", frota[cont].marca);
        printf("\nPlaca: %s", frota[cont].placa);
        printf("\nAno: %d", frota[cont].ano);
        printf("\nCor: %s", frota[cont].cor);
        printf("\n--------------------------");
        aux++;
      }
      if (aux == 0) {
        printf("Nenhuma automóvel cadastrado\n");
      } else {
        printf("\n");
      }
      break;
      case 'S':
      case 's':
      printf("Bye");
      break;
    default:
      printf("Opção inválida !!!\n");
    }
  } while (opcao != 'S' && opcao != 's');
}
