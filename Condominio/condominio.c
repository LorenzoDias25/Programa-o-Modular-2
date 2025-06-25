#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *file;
char *name = "Condominio.dat";
int IDG;

typedef struct {
  int id;             // Identificação
  char propname[100]; // Nome do proprietario
  char resname[100];  // Nome do residente
  char bloco;         // Bloco
  int na;             // Numero do apartamento
  int qq;             // Quantidade de quartos no apartamento
  float ma;           // Metragem do apartamento
  int floor;          // Andar
  int nrap;           // Numero de residentes no apartamento
} bd;

main() {
  setlocale(LC_ALL, "Portuguese");

  char opcao;
  int reg = 0, cont, verify, ida, conta, veriaux;
  bd *cond, *aux, *temp;
  file = fopen(name, "ab+ ");
  do {
    fread(&temp, sizeof(bd), 1, file);
    if (feof(file)) {
      break;
    }
    reg++;
  } while (!feof(file));
  // printf("Teste Reg: %d\n", reg);
  fclose(file);
  IDG = reg + 1;
  if (reg) {
    cond = malloc(reg * sizeof(bd));
    file = fopen(name, "ab+");
    for (cont = 0; cont < reg; cont++) {
      fread(&cond[cont], sizeof(bd), 1, file);
    }
    fclose(file);
  }
  do {
    printf("Menu");
    printf("\n(I) Inserir registro");
    printf("\n(L) Listar registros");
    printf("\n(D) Deletar registro");
    printf("\n(E) Editar registro");
    printf("\n(S) Sair");
    scanf("%c", &opcao);
    getchar();
    switch (opcao) {
    case 'I':
    case 'i':
      if (!reg) {
        cond = malloc(sizeof(bd));
        cond[reg].id = IDG;
        IDG++;
        cont = reg;
        system("clear");
        printf("Digite os dados do apartamento\n");
        printf("Nome do proprietário: ");
        gets(cond[cont].propname);
        printf("Nome do residente: ");
        gets(cond[cont].resname);
        verify = 1;
        do {
          printf("Bloco: ");
          scanf("%c", &cond[cont].bloco);
          getchar();
          switch (cond[cont].bloco) {
          case 'A':
          case 'a':
            verify--;
            break;
          case 'B':
          case 'b':
            verify--;
            break;
          case 'C':
          case 'c':
            verify--;
            break;
          case 'D':
          case 'd':
            verify--;
            break;
          default:
            printf("Bloco inválido !!!");
          }
        } while (verify);
        printf("Número do apartamento: ");
        scanf("%d", &cond[cont].na);
        printf("Quantidade de quartos no apartamento: ");
        scanf("%d", &cond[cont].qq);
        printf("Metragem(Metros quadrados): ");
        scanf("%f", &cond[cont].ma);
        printf("Andar: ");
        scanf("%d", &cond[cont].floor);
        printf("Número de residentes: ");
        scanf("%d", &cond[cont].nrap);
        getchar();
        reg++;
      } else {
        reg++;
        cond = realloc(cond, reg * sizeof(bd));
        cont = reg - 1;
        system("clear");
        cond[cont].id = IDG;
        IDG++;
        printf("Digite os dados do apartamento \n");
        printf("Nome do proprietário: ");
        gets(cond[cont].propname);
        printf("Nome do residente: ");
        gets(cond[cont].resname);
        verify = 1;
        do {
          printf("Bloco: ");
          scanf("%c", &cond[cont].bloco);
          getchar();
          switch (cond[cont].bloco) {
          case 'A':
          case 'a':
            verify--;
            break;
          case 'B':
          case 'b':
            verify--;
            break;
          case 'C':
          case 'c':
            verify--;
            break;
          case 'D':
          case 'd':
            verify--;
            break;
          default:
            printf("Bloco inválido !!!\n");
          }
        } while (verify);
        printf("Número do apartamento: ");
        scanf("%d", &cond[cont].na);
        printf("Quantidade de quartos no apartamento: ");
        scanf("%d", &cond[cont].qq);
        printf("Metragem(Metros quadrados): ");
        scanf("%f", &cond[cont].ma);
        printf("Andar: ");
        scanf("%d", &cond[cont].floor);
        printf("Número de residentes: ");
        scanf("%d", &cond[cont].nrap);
        getchar();
      }
      break;
    case 'L':
    case 'l':
      system("clear");
      if (reg) {
        for (cont = 0; cont < reg; cont++) {
          printf("\nID: %d", cond[cont].id);
          printf("\nProprietário: %s", cond[cont].propname);
          printf("\nResidente: %s", cond[cont].resname);
          printf("\nBloco: %c", cond[cont].bloco);
          printf("\nNúmero do apartamento: %d", cond[cont].na);
          printf("\nQuantidade de quartos: %d", cond[cont].qq);
          printf("\nMetragem: %.2f metros quadrados", cond[cont].ma);
          printf("\nAndar: %d", cond[cont].floor);
          printf("\nNúmero de residentes: %d", cond[cont].nrap);
          printf("\n--------------------------------------\n");
        }
      } else {
        printf("Nenhum registro cadastrado !!!\n");
      }
      break;
    case 'D':
    case 'd':
      printf("ID do registro que deseja excluir: ");
      scanf("%d", &ida);
      getchar();
      verify = 0;
      veriaux = 1;
      for (cont = 0; cont < reg; cont++) {
        if (ida == cond[cont].id)
          verify++;
      }
      if (verify) {
        conta = 0;
        aux = malloc(reg * sizeof(bd));
        for (cont = 0; cont < reg; cont++) {
          if (cond[cont].id != ida) {
            if (veriaux) {
              aux[conta].id = cond[cont].id;
              strcpy(aux[conta].propname, cond[cont].propname);
              strcpy(aux[conta].resname, cond[cont].resname);
              aux[conta].bloco = cond[cont].bloco;
              aux[conta].na = cond[cont].na;
              aux[conta].qq = cond[cont].qq;
              aux[conta].ma = cond[cont].ma;
              aux[conta].floor = cond[cont].floor;
              aux[conta].nrap = cond[cont].nrap;
              conta++;
            } else {
              aux[conta].id = cond[cont].id - 1;
              strcpy(aux[conta].propname, cond[cont].propname);
              strcpy(aux[conta].resname, cond[cont].resname);
              aux[conta].bloco = cond[cont].bloco;
              aux[conta].na = cond[cont].na;
              aux[conta].qq = cond[cont].qq;
              aux[conta].ma = cond[cont].ma;
              aux[conta].floor = cond[cont].floor;
              aux[conta].nrap = cond[cont].nrap;
              conta++;
            }
          } else {
            veriaux = 0;
          }
        }
        reg--;
        free(cond);
        cond = aux;
        system("clear");
        printf("Registro deletado com sucesso\n");
      } else {
        printf("ID não encontrado");
      }
      break;
    case 'E':
    case 'e':
      system("clear");
      printf("ID: ");
      scanf("%d", &ida);
      getchar();
      for (cont = 0; cont < reg; cont++) {
        if (cond[cont].id == ida) {
          printf("Nome do proprietario atual: %s\n", cond[cont].propname);
          printf("Novo nome: ");
          gets(cond[cont].propname);
          system("clear");
          printf("Nome do residente atual: %s\n", cond[cont].resname);
          printf("Novo nome: ");
          gets(cond[cont].resname);
          system("clear");
          printf("Bloco atual: %c\n", cond[cont].bloco);
          verify = 1;
          do {
            printf("Novo bloco: ");
            scanf("%c", &cond[cont].bloco);
            getchar();
            switch (cond[cont].bloco) {
            case 'A':
            case 'a':
              verify--;
              break;
            case 'B':
            case 'b':
              verify--;
              break;
            case 'C':
            case 'c':
              verify--;
              break;
            case 'D':
            case 'd':
              verify--;
              break;
            default:
              printf("Bloco inválido !!!\n");
            }
          } while (verify);
          system("clear");
          printf("Número do apartamento atual: %d\n", cond[cont].na);
          printf("Novo número: ");
          scanf("%d", &cond[cont].na);
          system("clear");
          printf("Número de quartos atual: %d\n", cond[cont].qq);
          printf("Novo número de quartos: ");
          scanf("%d", &cond[cont].qq);
          system("clear");
          printf("Metragem atual: %.2f\n", cond[cont].ma);
          printf("Nova metragem: ");
          scanf("%f", &cond[cont].ma);
          system("clear");
          printf("Andar atual: %d\n", cond[cont].floor);
          printf("Novo andar: ");
          scanf("%d", &cond[cont].floor);
          system("clear");
          printf("Número de residentes atuais: %d\n", cond[cont].nrap);
          printf("Novo número: ");
          scanf("%d", &cond[cont].nrap);
          getchar();
          system("clear");
          printf("Registro editado com sucesso\n");
          cont = reg + 1;
          verify = 0;
        }
      }
      if (verify) {
        printf("Id não encontrado !!!\n");
      }
      break;
    case 'S':
    case 's':
      remove(name);
      file = fopen(name, "ab+");
      for (cont = 0; cont < reg; cont++) {
        fseek(file, 0, SEEK_END);
        fwrite(&cond[cont], sizeof(bd), 1, file);
      }
      fclose(file);
      printf("Registros salvos com sucesso \n");
      printf("BYE BYE");
      break;
    default:
      printf("Opção inválida !!!\n");
    }
  } while (opcao != 'S' && opcao != 's');
}
