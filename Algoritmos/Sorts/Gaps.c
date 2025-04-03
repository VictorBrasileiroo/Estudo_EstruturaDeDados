#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;           // Valor do elemento
    int gaps;            // Número de espaços vazios até o próximo elemento
} Element;

// Função para ordenar o array de elementos
void sortElements(Element arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].value > arr[j+1].value) {
                // Troca os elementos
                Element temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Função para calcular as lacunas entre elementos
void calculateGaps(Element arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // Calcula a distância entre valores consecutivos
        int gap = arr[i+1].value - arr[i].value - 1;
        arr[i].gaps = (gap > 0) ? gap : 0;
    }
    // O último elemento tem 0 lacunas
    if (size > 0) {
        arr[size-1].gaps = 0;
    }
}

// Função para exibir os elementos e suas lacunas
void displayElements(Element arr[], int size) {
    printf("Valores e lacunas:\n");
    for (int i = 0; i < size; i++) {
        printf("Valor: %d, Lacunas: %d\n", arr[i].value, arr[i].gaps);
    }
    printf("\n");
}

// Função para exibir o array com os espaços vazios representados
void displayWithGaps(Element arr[], int size) {
    printf("Array com lacunas preenchidas:\n");
    
    for (int i = 0; i < size; i++) {
        printf("%d --> ", arr[i].value);
        
        // Exibe os espaços vazios
        for (int j = 0; j < arr[i].gaps; j++) {
            printf("vazio --> ");
        }
    }
    printf("\n");
}

// Função para adicionar um novo elemento
int addElement(Element arr[], int size, int maxSize, int value) {
    if (size >= maxSize) {
        printf("Erro: O array está cheio\n");
        return size;
    }
    
    // Adiciona o novo valor
    arr[size].value = value;
    arr[size].gaps = 0;
    size++;
    
    // Reordena e recalcula as lacunas
    sortElements(arr, size);
    calculateGaps(arr, size);
    
    return size;
}

// Função para remover um elemento
int removeElement(Element arr[], int size, int value) {
    int found = -1;
    
    // Procura o elemento a ser removido
    for (int i = 0; i < size; i++) {
        if (arr[i].value == value) {
            found = i;
            break;
        }
    }
    
    if (found == -1) {
        printf("Erro: Valor %d não encontrado\n", value);
        return size;
    }
    
    // Remove o elemento deslocando os elementos posteriores
    for (int i = found; i < size - 1; i++) {
        arr[i] = arr[i+1];
    }
    
    size--;
    
    // Recalcula as lacunas
    calculateGaps(arr, size);
    
    return size;
}

int main() {
    int maxSize = 100;  // Tamanho máximo do array
    Element* elements = (Element*)malloc(maxSize * sizeof(Element));
    
    if (elements == NULL) {
        printf("Erro: Falha na alocação de memória\n");
        return 1;
    }
    
    int size = 0;
    int option, value;
    
    // Inicializando com os valores do seu diagrama
    elements[0].value = 3;
    elements[1].value = 5;
    elements[2].value = 6;
    size = 3;
    
    // Ordenar e calcular lacunas
    sortElements(elements, size);
    calculateGaps(elements, size);
    
    do {
        printf("\nMenu:\n");
        printf("1. Exibir elementos e lacunas\n");
        printf("2. Exibir array com lacunas preenchidas\n");
        printf("3. Adicionar elemento\n");
        printf("4. Remover elemento\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                displayElements(elements, size);
                break;
            case 2:
                displayWithGaps(elements, size);
                break;
            case 3:
                printf("Digite o valor a ser adicionado: ");
                scanf("%d", &value);
                size = addElement(elements, size, maxSize, value);
                break;
            case 4:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &value);
                size = removeElement(elements, size, value);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida\n");
        }
    } while (option != 0);
    
    free(elements);
    return 0;
}