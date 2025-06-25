#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

main() {
  setlocale(LC_ALL, "portuguese");
  srand(time(NULL));
  int a, pil, pic;
  int b, pfl, pfc;
  int aux, aux2, auxl, auxc;
  int nl, nc;
  int l, c;
  int lb, cb, nb, nbaux;
  int timer = 0;
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
  if ((nc * nl) % 2 == 0) {
    nbaux = (nc * nl) / 6;
  } else {
    nbaux = (nc * nl) / 5;
  }
  system("clear");
  printf("Menu obstáculos:\n ");
  printf("Regras: \n");
  printf("É necessário ter pelo menos 1 obstáculo \n");
  printf("Não pode ter mais que %d obstáculos\n", nbaux);
  do {
    printf("Digite a quantidade de obstáculos: ");
    scanf("%d", &nb);
    if (nb <= 0 || nb > nbaux) {
      printf("Quantidade inválida, digite novamente \n");
    }
  } while (nb <= 0 || nb > nbaux);
  int vetorl[nb];
  int vetorc[nb];
  int auxlb, auxcb;
  int temp;
  for (l = 0; l < nb; l++) {
    auxlb = rand() % nl;
    if (auxlb <= 0) {
      l--;
    }
    vetorl[l] = auxlb;
  }
  for (c = 0; c < nb; c++) {
    auxcb = rand() % nc;
    if (auxcb <= 0) {
      c--;
    }
    vetorc[c] = auxcb;
  }
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
  printf("Obstáculos: \n");
  for (temp = 0; temp < nb; temp++) {
    printf("%d: %d , %d\n", temp + 1, vetorl[temp], vetorc[temp]);
  }
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
    auxlb = 0;
    auxcb = 0;
    for (temp = 0; temp < nb; temp++) {
      if ((pil == vetorl[temp]) && (pic == vetorc[temp])) {
        printf("O local %d , %d ja esta ocupado com obstáculo\n", pil, pic);
      } else {
        auxlb++;
        auxcb++;
      }
    }
  } while ((auxlb != nb) && (auxcb != nb));
  system("clear");
  printf("Menu posição final\n");
  printf("Regras: \n");
  printf("A posição final não pode ser igual a posição inicial\n");
  printf("Posição inicial: %d,%d\n", pil, pic);
  printf("A posição final não pode ser %d, %d\n", lb, cb);
  printf("A linha não pode ser menor que 0 e maior que %d\n", nl - 1);
  printf("A coluna não pode ser menor que 0 e maior que %d\n", nc - 1);
  printf("Obstáculos: \n");
  for (temp = 0; temp < nb; temp++) {
    printf("%d: %d , %d\n", temp + 1, vetorl[temp], vetorc[temp]);
  }
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
    auxlb = 0;
    auxcb = 0;
    for (temp = 0; temp < nb; temp++) {
      if ((pfl == vetorl[temp]) && (pfc == vetorc[temp])) {
        printf("A posição %d , %d já está ocupada \n", pfl, pfc);
      } else {
        auxlb++;
        auxcb++;
      }
    }
  } while ((auxlb != nb) && (auxcb != nb));
  for (temp = 0; temp < nb; temp++) {
    matriz[vetorl[temp]][vetorc[temp]] = 'O';
  }
  system("clear");
  printf("Tamanho matriz: %d x %d\n", nl, nc);
  printf("Posição inicial A: %d , %d\n", pil, pic);
  printf("Posição inicial B: %d , %d\n", pfl, pfc);
  printf("Obstáculos: \n");
  for (temp = 0; temp < nb; temp++) {
    printf("%d: %d , %d \n", temp, vetorl[temp], vetorc[temp]);
  }
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

            if (matriz[pil][pic] == 'O') {
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

            if (matriz[pil][pic] == 'O') {
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
        timer++;
      } while ((pil != pfl) && (pic != pfc));
      break;
    case 2:
      do {
        if (pil > pfl) {   // cima
          if (pic < pfc) { // direita
            pil--;
            pic++;

            if (matriz[pil][pic] == 'O') {
              pil++;
            }
            matriz[pil][pic] = 'X';
          }
          if (pic > pfc) { // esquerda
            pil--;
            pic--;

            if (matriz[pil][pic] == 'O') {
              pic++;
            }
            matriz[pil][pic] = 'X';
          }
        }
        timer++;
      } while ((pil != pfl) && (pic != pfc));
      break;
    case 3:
      do {
        if (pil == pfl) {  // Msm linha
          if (pic < pfc) { // direita
            pic++;
            if (matriz[pil][pic] == 'O') {
              pil++;
              if (pil == nl) {
                pil = pil - 2;
              }
            }
            matriz[pil][pic] = 'X';
            pil = pfl;
          }
          if (pic > pfc) { // esquerda
            pic--;

            if (matriz[pil][pic] == 'O') {
              pil--;
              if (pil < 0) {
                pil = pil + 2;
              }
            }
            matriz[pil][pic] = 'X';
            pil = pfl;
          }
        }
        timer++;
      } while ((pil != pfl) && (pic != pfc));
      break;
    case 4:
      do {
        if (pic == pfc) {  // Msm coluna
          if (pil < pfl) { // baixo
            pil++;
            if (matriz[pil][pic] == 'O') {
              pic++;
              if (pic == nc) {
                pic = pic - 2;
              }
            }
            matriz[pil][pic] = 'X';
            pic = pfc;
          }
          if (pil > pfl) { // cima
            pil--;

            if (matriz[pil][pic] == 'O') {
              pic--;
              if (pic < 0) {
                pic = pic + 2;
              }
            }
            matriz[pil][pic] = 'X';
            pic = pfc;
          }
        }
        timer++;
      } while ((pil != pfl) && (pic != pfc));
    }
  } while (((pil != pfl) || (pic != pfc)) || (timer == (nl * nl * nc)));
  matriz[auxl][auxc] = 'A';
  matriz[pfl][pfc] = 'B';
  // printf("Timer: %d\n", timer);
  for (l = 0; l < nl; l++) {
    for (c = 0; c < nc; c++) {
      printf("%c - ", matriz[l][c]);
    }
    printf("\n");
  }
}
