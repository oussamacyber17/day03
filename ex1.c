#include <stdio.h>
#include <string.h>

int main() {
  char c[50];
  printf("veuillez entrer une phrase");
  scanf("%[^\n]",c); 
  printf("la phrase est %s",c);
  
  return 0;
}