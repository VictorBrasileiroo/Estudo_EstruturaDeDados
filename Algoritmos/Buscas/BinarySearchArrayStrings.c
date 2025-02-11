#include <stdio.h>
#include <string.h>
#define MAX 999


void ordenarNomes(char* nomes[], int qntNomes) {
    for (int i = 0; i < qntNomes - 1; i++) {
        for (int j = 0; j < qntNomes - 1 - i; j++) {
            if (strcmp(nomes, nomes[j + 1]) > 0) {
                char* temp = nomes[j];
                nomes[j] = nomes[j + 1];
                nomes[j + 1] = temp;
            }
        }
    }
}

int BinarySearch(char* nomes[], char name[], int qntNomes) {
    int inicio = 0;
    int fim = qntNomes - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(nomes[meio], name);
        if (cmp == 0) {
            return meio;
        }
        if (cmp > 0) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    return -1;  
}

int main() {
    char* nomes[] = {"Victor", "Karla"};
    int qntNomes = sizeof(nomes)/sizeof(nomes[0]);
    //Ordena
    ordenarNomes(nomes, qntNomes);

    //String que vai ser buscada
    char nameToFind[MAX];
    fgets(nameToFind, MAX, stdin);
    nameToFind[strcspn(nameToFind, "\n")] = '\0';  // Remover '\n'

    int index = BinarySearch(nomes, nameToFind, qntNomes);
    printf("%d\n", index);  

    return 0;
}
