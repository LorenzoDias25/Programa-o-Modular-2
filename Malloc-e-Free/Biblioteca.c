#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char titulo[50];
  char autor[50];
  char editora[50];
  int ano;
  char ass[100];
} bd;

main() {
  setlocale(LC_ALL, "Portuguese");

  bd *library, *auxl;
  int cont, aux, pos, tamanho;
  char opcao, busca, auxb[50];
  printf("Tamanho inicial de livros a serem cadastrados: ");
  scanf("%d", &tamanho);
  getchar();
  library = malloc(tamanho * sizeof(bd));
  for (cont = 0; cont < tamanho; cont++) {
    printf("Titulo: ");
    gets(library[cont].titulo);
    printf("Autor: ");
    gets(library[cont].autor);
    printf("Editora: ");
    gets(library[cont].editora);
    printf("Ano de lançamento: ");
    scanf("%d", &library[cont].ano);
    getchar();
    printf("Assunto do livro: ");
    gets(library[cont].ass);
    system("clear");
  }
  do {
    printf("Menu ");
    printf("\n(I) Inserir");
    printf("\n(E) Excluir");
    printf("\n(B) Busca");
    printf("\n(L) Listar");
    printf("\n(S) Sair");
    scanf("%c", &opcao);
    getchar();
    switch (opcao) {
    case 'I':
    case 'i':
      tamanho++;
      library = realloc(library, tamanho * sizeof(bd));
      cont = tamanho - 1;
      printf("Titulo: ");
      gets(library[cont].titulo);
      printf("Autor: ");
      gets(library[cont].autor);
      printf("Editora: ");
      gets(library[cont].editora);
      printf("Ano de lançamento: ");
      scanf("%d", &library[cont].ano);
      getchar();
      printf("Assunto do livro: ");
      gets(library[cont].ass);
      system("clear");
      break;
    case 'E':
    case 'e':
      printf("Posição absoluta que deseja excluir: ");
      scanf("%d", &pos);
      getchar();
      if (pos < tamanho) {
        tamanho--;
        aux = 0;
        auxl = malloc(tamanho * sizeof(bd));
        for (cont = 0; cont < tamanho + 1; cont++) {
          if (cont != pos) {
            strcpy(auxl[aux].titulo, library[cont].titulo);
            strcpy(auxl[aux].autor, library[cont].autor);
            strcpy(auxl[aux].editora, library[cont].editora);
            auxl[aux].ano = library[cont].ano;
            strcpy(auxl[aux].ass, library[cont].ass);
            aux++;
          }
        }
        free(library);
        library = auxl;
        system("clear");
      } else {
        printf("Posição inválida !!!\n");
      }
      break;
    case 'B':
    case 'b':
      printf("Busca por: ");
      printf("\n(T) Titulo ");
      printf("\n(A) Autor");
      printf("\n(E) Editora");
      printf("\n(V) Voltar");
      scanf("%c", &busca);
      getchar();
      switch (busca) {
      case 'T':
      case 't':
        printf("Titulo: ");
        gets(auxb);
        aux = 0;
        for (cont = 0; cont < tamanho; cont++) {
          if ((strcmp(auxb, library[cont].titulo)) == 0) {
            printf("\n--------------------------------");
            printf("\nTitulo: %s", library[cont].titulo);
            printf("\nAutor: %s", library[cont].autor);
            printf("\nEditora: %s", library[cont].editora);
            printf("\nAno: %d", library[cont].ano);
            printf("\nAssunto do livro: %s", library[cont].ass);
            printf("\n--------------------------------\n");
            aux++;
          }
        }
        if (aux == 0) {
          printf("Titulo não encontrado \n");
        }
        break;
      case 'A':
      case 'a':
        printf("Autor: ");
        gets(auxb);
        aux = 0;
        for (cont = 0; cont < tamanho; cont++) {
          if ((strcmp(auxb, library[cont].autor)) == 0) {
            printf("\n--------------------------------");
            printf("\nTitulo: %s", library[cont].titulo);
            printf("\nAutor: %s", library[cont].autor);
            printf("\nEditora: %s", library[cont].editora);
            printf("\nAno: %d", library[cont].ano);
            printf("\nAssunto do livro: %s", library[cont].ass);
            printf("\n--------------------------------\n");
            aux++;
          }
        }
        if (aux == 0) {
          printf("Autor não encontrado\n");
        }
        break;
      case 'E':
      case 'e':
        printf("Editora: ");
        gets(auxb);
        aux = 0;
        for (cont = 0; cont < tamanho; cont++) {
          if ((strcmp(auxb, library[cont].autor)) == 0) {
            printf("\n--------------------------------");
            printf("\nTitulo: %s", library[cont].titulo);
            printf("\nAutor: %s", library[cont].autor);
            printf("\nEditora: %s", library[cont].editora);
            printf("\nAno: %d", library[cont].ano);
            printf("\nAssunto do livro: %s", library[cont].ass);
            printf("\n--------------------------------\n");
          }
        }
        if (aux == 0) {
          printf("Editora não encontrada \n");
        }
        break;
      case 'V':
      case 'v':
        break;
      default:
        printf("Opção inválida !!!\n");
      }
      break;
    case 'L':
    case 'l':
      aux = 0;
      for (cont = 0; cont < tamanho; cont++) {
        printf("\n--------------------------------");
        printf("\nTitulo: %s", library[cont].titulo);
        printf("\nAutor: %s", library[cont].autor);
        printf("\nEditora: %s", library[cont].editora);
        printf("\nAno: %d", library[cont].ano);
        printf("\nAssunto do livro: %s", library[cont].ass);
        printf("\n--------------------------------\n");
        aux++;
      }
      if (aux == 0) {
        printf("Titulo não encontrado \n");
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
