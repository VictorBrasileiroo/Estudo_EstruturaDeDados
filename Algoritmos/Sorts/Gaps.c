#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int next;
} Gaps;

void AbraCadaBra(Gaps nums[], int qnt) {
    for(int i = 0; i < qnt; i++) {
        int dist = 0;
        if(i != qnt - 1) {
            dist = (nums[i+1].value - nums[i].value) - 1;
            if(dist < 0) dist = 0; // Prevenir valores negativos
        }
        nums[i].next = dist;
    }
    // O último elemento terá next = 0, já que não há próximo elemento
    nums[qnt-1].next = 0;
}

void AddGaps(Gaps nums[], int tam) {
    // Calcular o tamanho do novo array
    int count = 0;
    for(int i = 0; i < tam; i++) {
        count += nums[i].next;
    }
    
    int newTam = tam + count;
    int* arr = (int*) malloc(newTam * sizeof(int));
    
    if(arr == NULL) {
        printf("Erro: Falha na alocação de memória\n");
        return;
    }
    
    // Inicializar com valores inválidos para detectar posições não preenchidas
    for(int i = 0; i < newTam; i++) {
        arr[i] = -1;
    }
    
    // Preencher o array com os valores e lacunas
    int pos = 0;
    for(int i = 0; i < tam; i++) {
        arr[pos] = nums[i].value;
        pos++;
        
        // Adicionar os valores nas lacunas (se existirem)
        for(int j = 0; j < nums[i].next; j++) {
            arr[pos] = -1; // Valor para as lacunas (pode ser outro valor ou manter vazio)
            pos++;
        }
    }
    
    // Imprimir o array resultante
    for(int i = 0; i < newTam; i++) {
        printf("%d --> ", arr[i]);
    }
    printf("\n");
    
    // Liberar a memória alocada
    free(arr);
}

int main() {
    int qntNums;
    printf("Digite a quantidade de números: ");
    scanf("%d", &qntNums);
    
    if(qntNums <= 0) {
        printf("Erro: Quantidade inválida\n");
        return 1;
    }
    
    Gaps* vetor = (Gaps*) malloc(qntNums * sizeof(Gaps));
    
    if(vetor == NULL) {
        printf("Erro: Falha na alocação de memória\n");
        return 1;
    }
    
    printf("Digite os %d números:\n", qntNums);
    for(int i = 0; i < qntNums; i++) {
        scanf("%d", &vetor[i].value);
    }
    
    printf("Valores originais:\n");
    for(int i = 0; i < qntNums; i++) {
        printf("%d --> ", vetor[i].value);
    }
    printf("\n");
    
    // Ordenação bubble sort
    for(int i = 0; i < qntNums - 1; i++) {
        for(int j = 0; j < qntNums - i - 1; j++) {
            if(vetor[j].value > vetor[j+1].value) {
                int t = vetor[j].value;
                vetor[j].value = vetor[j+1].value;
                vetor[j+1].value = t;
            }
        }
    }
    
    printf("Valores ordenados:\n");
    for(int i = 0; i < qntNums; i++) {
        printf("%d --> ", vetor[i].value);
    }
    printf("\n");
    
    AbraCadaBra(vetor, qntNums);
    
    printf("Valores das lacunas:\n");
    for(int i = 0; i < qntNums; i++) {
        printf("%d --> ", vetor[i].next);
    }
    printf("\n");
    
    printf("Array com lacunas preenchidas:\n");
    AddGaps(vetor, qntNums);
    
    // Liberar a memória alocada
    free(vetor);
    
    return 0;
}