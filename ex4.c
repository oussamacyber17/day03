#include <stdio.h>
#include <string.h>

int main() {
  
  char S[100];
  char C[100];
  int n;
    
  printf("veillez entrer une phrase\n");
  scanf(" %[^\n]", C);
  printf("veillez entrer une phrase\n");
  scanf(" %[^\n]", S);
    
  n= strcmp(S,C);
  if(n==0){
    printf("les deux chaines sont la meme");
  }
  else{
    printf("les deux chaines ne sont pas meme");
  }

  
  
  return 0;
}