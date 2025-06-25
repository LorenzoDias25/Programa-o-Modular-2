#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int matri;
  char nome[50];
  int cod;
  float nota1, nota2, nota3;
} aluno;

main() {
  setlocale(LC_ALL, "Portuguese");

  int cont, tamanho, aux, pos;
  char opcao;
  aluno *bd, *auxb;
  printf("Tamanho inicial de alunos que seram cadastrados: ");
  scanf("%d", &tamanho);
  bd = malloc(tamanho * sizeof(aluno));
  for (cont = 0; cont < tamanho; cont++) {
    printf("Matricula: ");
    scanf("%d", &bd[cont].matri);
    getchar();
    printf("Nome: ");
    gets(bd[cont].nome);
    printf("Código da disciplina: ");
    scanf("%d", &bd[cont].cod);
    getchar();
    bd[cont].nota1 = 0;
    bd[cont].nota2 = 0;
    bd[cont].nota3 = 0;
    system("clear");
  }
  do {
    printf("Menu");
    printf("\n(I) Inserir");
    printf("\n(E) Excluir");
    printf("\n(L) Listar");
    printf("\n(N) Notas");
    printf("\n(S) Sair");
    scanf("%c", &opcao);
    getchar();
    switch (opcao) {
    case 'I':
    case 'i':
      tamanho++;
      bd = realloc(bd, tamanho * sizeof(aluno));
      cont = tamanho - 1;
      printf("Matricula: ");
      scanf("%d", &bd[cont].matri);
      getchar();
      printf("Nome: ");
      gets(bd[cont].nome);
      printf("Código da disciplina: ");
      scanf("%d", &bd[cont].cod);
      getchar();
      bd[cont].nota1 = 0;
      bd[cont].nota2 = 0;
      bd[cont].nota3 = 0;
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
        auxb = malloc(tamanho * sizeof(aluno));
        for (cont = 0; cont < tamanho + 1; cont++) {
          if (cont != pos) {
            auxb[aux].matri = bd[cont].matri;
            strcpy(auxb[aux].nome, bd[cont].nome);
            auxb[aux].cod = bd[cont].cod;
            auxb[aux].nota1 = bd[cont].nota1;
            auxb[aux].nota2 = bd[cont].nota2;
            auxb[aux].nota3 = bd[cont].nota3;
            aux++;
          }
        }
        free(bd);
        bd = auxb;
        system("clear");
      } else {
        printf("Posição inválida !!!\n");
      }
      break;
    case 'L':
    case 'l':
      aux = 0;
      for (cont = 0; cont < tamanho; cont++) {
        printf("\n--------------------------------------");
        printf("\nMatricula: %d", bd[cont].matri);
        printf("\nNome: %s", bd[cont].nome);
        printf("\nCódigo da disciplina: %d", bd[cont].cod);
        printf("\nNota 1: %.2f", bd[cont].nota1);
        printf("\nNota 2: %.2f", bd[cont].nota2);
        printf("\nNota 3: %.2f", bd[cont].nota3);
        printf("\nMédia: %.2f",
               (bd[cont].nota1 + bd[cont].nota2 + bd[cont].nota3) / 3);
        printf("\n--------------------------------------\n");
        aux++;
      }
      if (aux == 0){
        printf("Nenhum aluno cadastrado \n");
      }
      break;
      case 'N': 
      case 'n':
        printf("Matricula do aluno: ");
        scanf("%d", &pos);
        getchar();
        aux = 0; 
        for (cont = 0; cont < tamanho; cont++){
          if (pos == bd[cont].matri){
            printf("Nota 1: ");
            scanf("%f", &bd[cont].nota1);
            printf("\nNota 2: ");
            scanf("%f", &bd[cont].nota2);
            printf("\nnota 3: ");
            scanf("%f", &bd[cont].nota3);
            getchar();
            aux++;
          }
        }
        if (aux == 0){
          printf("Matricula não encontrada \n");
        } else {
          system("clear");
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
