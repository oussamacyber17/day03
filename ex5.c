#include <stdio.h>
#include <string.h>

int main() {
  int i=0;
  char C[100];
  printf("veillez entrer une phrase\n");
  scanf("%[^\n]",C);
  for(i=strlen(C)-1;i>=0;i--){
    printf("%c",C[i]);
  
  }

  
  
  return 0;
}