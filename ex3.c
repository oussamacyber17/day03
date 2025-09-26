#include <stdio.h>
#include <string.h>

int main() {
 char resultat[100];
  char S[100];
  char C[100];
 
    
  printf("veillez entrer une phrase\n");
  scanf(" %[^\n]", C);
  printf("veillez entrer une phrase\n");
  scanf(" %[^\n]", S);
    strcpy(resultat,C);
    strcat(resultat,S);
    printf("%s",resultat);
  
  
  return 0;
}