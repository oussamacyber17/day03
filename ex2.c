#include <stdio.h>
#include <string.h>

int main() {
  int n=0;
  int i;
  char C[100];
  printf("veillez entrer une phrase\n");
  scanf("%[^\n]",C);
  for(i=0;C[i]!='\0';i++){
    n++;
  
  }
 printf("la longuer de la phrase est %d",n);
  
  
  return 0;
}