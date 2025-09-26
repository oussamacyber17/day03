#include <stdio.h>
#include <string.h>

int main() {
    char A[50];
    char s;
    int i;
    int count = 0;

    printf("Veuillez entrer une phrase: ");
    scanf("%[^\n]", A);   

    getchar(); /

    printf("Veuillez entrer un caractere: ");
    scanf("%c", &s);      

    for (i = 0; i < strlen(A); i++) {
        if (A[i] == s) {
            count++;
        }
    }

    if (count > 0) {
        printf("Le caractere '%c' apparait %d fois dans la phrase.\n", s, count);
    } else {
        printf("On n'a pas ce caractere dans cette chaine.\n");
    }

    return 0;
}