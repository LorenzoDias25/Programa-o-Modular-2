#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main() {
  setlocale(LC_ALL, "portuguese");
  int a, pil, pic;
  int b, pfl, pfc;
  int aux, aux2, auxl, auxc;
  int nl, nc;
  int l, c, lb, cb;
  printf("Menu matriz\n");
  printf("Regras da matriz: \n");
  printf("Tamanho minimo: 3 x 3\n");
  printf("Tamanho máximo: use com sabedoria \n");
  do {
    printf("Linha: ");
    scanf("%d", &nl);
    if (nl < 3) {
      printf("Tamanho inválido, digite novamente \n");
    }
  } while (nl < 3);
  do {
    printf("Coluna: ");
    scanf("%d", &nc);
    if (nc < 3) {
      printf("Tamanho inválido, digite novamente \n");
    }
  } while (nc < 3);
  lb = nl / 2;
  cb = nc / 2;
  char matriz[nl][nc];
  for (l = 0; l < nl; l++) {
    for (c = 0; c < nc; c++) {
      matriz[l][c] = '#';
    }
  }
  system("clear");
  printf("Menu posição inicial \n");
  printf("Regras: \n");
  printf("A posição inicial não pode ser: %d, %d \n", lb, cb);
  printf("A linha não pode ser menor que 0 e maior que: %d\n", nl - 1);
  printf("A coluna não pode ser menor que 0 e maior que: %d \n", nc - 1);
  do {
    printf("Digite a posição incial\n");
    do {
      printf("Linha: ");
      scanf("%d", &pil);
      if (pil < 0 || pil > (nl - 1)) {
        printf("Linha invalida, digite novamente \n");
      }
    } while (pil < 0 || pil > (nl - 1));
    do {
      printf("Coluna: ");
      scanf("%d", &pic);
      if (pic < 0 || pic > (nc - 1)) {
        printf("Coluna inválida, digite novamente \n");
      }
    } while (pic < 0 || pic > (nc - 1));
    if ((pil == lb) && (pic == cb)) {
      printf("Posição inválida , digite novamente \n");
    }
  } while ((pil == lb) && (pic == cb));
  system("clear");
  printf("Menu posição final\n");
  printf("Regras: \n");
  printf("A posição final não pode ser igual a posição inicial\n");
  printf("Posição inicial: %d,%d\n", pil, pic);
  printf("A posição final não pode ser %d, %d\n", lb, cb);
  printf("A linha não pode ser menor que 0 e maior que %d\n", nl - 1);
  printf("A coluna não pode ser menor que 0 e maior que %d\n", nc - 1);
  do {
    printf("Digite a posição final \n");
    do {
      printf("Linha: ");
      scanf("%d", &pfl);
      if (pfl < 0 || pfl > (nl - 1)) {
        printf("Linha inválida, digite novamente \n");
      }
    } while (pfl < 0 || pfl > (nl - 1));
    do {
      printf("Coluna: ");
      scanf("%d", &pfc);
      if (pfc < 0 || pfc > (nc - 1)) {
        printf("Coluna inválida, digite novamente \n");
      }
    } while (pfc < 0 || pfc > (nc - 1));
    if ((pfl == lb) && (pfc == cb)) {
      printf("Posição inválida, digite novamente \n");
    }
    if ((pfl == pil)&& (pfc == pic)){
      printf("Posição ocupada, digite novamente\n");
    }
  } while (((pfl == lb) && (pfc == cb)) || ((pfl == pil)&& (pfc == pic)));
  matriz[lb][cb] = 'O';
  system("clear");
  printf("Posição inicial A: %d, %d\n", pil, pic);
  printf("Posição inicial B: %d, %d\n", pfl, pfc);
  printf("Buraco O: %d, %d\n", lb, cb);
  auxl = pil;
  auxc = pic;
  do {
    if (pil < pfl) {
      aux = 1;
    }
    if (pil > pfl) {
      aux = 2;
    }
    if (pil == pfl) {
      aux = 3;
    }
    if (pic == pfc) {
      aux = 4;
    }
    // printf("Aux: %d \n", aux);
    switch (aux) {
    case 1:
      do {
        if (pil < pfl) {   // baixo
          if (pic < pfc) { // direita
            pil++;
            pic++;

            if ((pil == lb) && (pic == cb)) {
              pil--;
            }
            if (pil == nl) {
              pil--;
            }
            if (pic == nc) {
              pic--;
            }
            matriz[pil][pic] = 'X';
          }
          if (pic > pfc) { // esquerda
            pil++;
            pic--;

            if ((pil == lb) && (pic == cb)) {
              pil--;
            }
            if (pil == nl) {
              pil--;
            }
            if (pic == nc) {
              pic++;
              ;
            }
            matriz[pil][pic] = 'X';
          }
        }
      } while ((pil != pfl) && (pic != pfc));
      break;
    case 2:
      do {
        if (pil > pfl) {   // cima
          if (pic < pfc) { // direita
            pil--;
            pic++;

            if ((pil == lb) && (pic == cb)) {
              pil++;
            }
            matriz[pil][pic] = 'X';
          }
          if (pic > pfc) { // esquerda
            pil--;
            pic--;

            if ((pil == lb) && (pic == cb)) {
              pic++;
            }
            matriz[pil][pic] = 'X';
          }
        }
      } while ((pil != pfl) && (pic != pfc));
      break;
    case 3:
      do {
        if (pil == pfl) {  // Msm linha
          if (pic < pfc) { // direita
            pic++;
            if ((pil == lb) && (pic == cb)) {
              pil++;
            }
            matriz[pil][pic] = 'X';
            pil = pfl;
          }
          if (pic > pfc) { // esquerda
            pic--;

            if ((pil == lb) && (pic == cb)) {
              pil--;
            }
            matriz[pil][pic] = 'X';
            pil = pfl;
          }
        }
      } while ((pil != pfl) && (pic != pfc));
      break;
    case 4:
      do {
        if (pic == pfc) {  // Msm coluna
          if (pil < pfl) { // baixo
            pil++;
            if ((pil == lb) && (pic == cb)) {
              pic++;
            }
            matriz[pil][pic] = 'X';
            pic = pfc;
          }
          if (pil > pfl) { // cima
            pil--;

            if ((pil == lb) && (pic == cb)) {
              pic--;
            }
            matriz[pil][pic] = 'X';
            pic = pfc;
          }
        }
      } while ((pil != pfl) && (pic != pfc));
    }
  } while ((pil != pfl) || (pic != pfc));
  matriz[auxl][auxc] = 'A';
  matriz[pfl][pfc] = 'B';
  for (l = 0; l < nl; l++) {
    for (c = 0; c < nc; c++) {
      printf("%c - ", matriz[l][c]);
    }
    printf("\n");
  }
}
