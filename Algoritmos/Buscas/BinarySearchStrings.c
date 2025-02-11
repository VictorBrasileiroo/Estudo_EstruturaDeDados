#include <stdio.h>
#include <string.h>
#define MAX 999

typedef struct {
    char nome[MAX];
} Nomes;


void ordenarNomes(Nomes nomes[], int qntNomes) {
    for (int i = 0; i < qntNomes - 1; i++) {
        for (int j = 0; j < qntNomes - 1 - i; j++) {
            if (strcmp(nomes[j].nome, nomes[j + 1].nome) > 0) {
                Nomes temp = nomes[j];
                nomes[j] = nomes[j + 1];
                nomes[j + 1] = temp;
            }
        }
    }
}

int BinarySearch(Nomes nomes[], char name[], int qntNomes) {
    int inicio = 0;
    int fim = qntNomes - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(nomes[meio].nome, name);
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
    int qntNomes;
    scanf("%d", &qntNomes);
    getchar(); 

    //Cria o struct --> Com uma quantidade limitade
    Nomes nomes[qntNomes];

    //faz os scans
    for (int i = 0; i < qntNomes; i++) {
        fgets(nomes[i].nome, MAX, stdin);
        nomes[i].nome[strcspn(nomes[i].nome, "\n")] = '\0';  // Remover '\n'
    }

    //Ordena
    ordenarNomes(nomes, qntNomes);

    //String que vai ser buscada
    char nameToFind[MAX];
    fgets(nameToFind, MAX, stdin);
    nameToFind[strcspn(nameToFind, "\n")] = '\0';  // Remover '\n'

    int index = BinarySearch(nomes, nameToFind, qntNomes);
    printf("%d\n", index);  // Apenas imprime o índice do nome encontrado

    return 0;
}
