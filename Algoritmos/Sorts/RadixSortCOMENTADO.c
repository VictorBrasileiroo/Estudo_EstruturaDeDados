 //{45,90,802}
    //max = 802 --> exp = 1
    //802 / 1 = 802 > 0 true --> while
    //90 --> 0 --> count[0]++ --> count[0] = 1;
    //802 --> 2 --> count[2]++ --> count[2] = 1;
    //45 --> 5 --> count[5]++ --> count[5] = 1;

    //situação atual do count: 
        //count[0] = 1
        //count[1] = 0
        //count[2] = 1;
        //count[3-4] = 0;
        //count[5] = 1
        //count[6-9] = 0
        //[1,0,1,0,0,1,0,0,0,0]
    
    //Acumular
        //count[0] = 1;
        //count[1] = 1; --> de 0 a 1 ficam na posição até 1
        //count[2] = 2;
        //count[3] = 2;
        //count[4] = 2; --> de 2 a 4 ficam na posição até 2
        //count[5] = 3;
        //count[6] = 3;
        //count[7] = 3;
        //count[8] = 3;
        //count[9] = 3; --> de 5 a 9 ficam até a posição 3
        // O que tiramos aqui --> aqui basicmanete é a ordenação/posicão que podem ficar --> ou seja número que terminam em 0 ou 1 podem ficar até a posição 1 do array --> entre 2 e 4 podem ficar até a posição 2 do array

    // sem usar programação podemos fazer já a ordenação só de olho
    // quais números terminam em 0 ou 1 --> posição 1 =  90
    //quais terminam de 2 a 4 --> posição 2 = 802
    //quais terminam de 5 a 9 --> posição 3 = 45
    //{90,802,45}

    //For para fazer essa análise

    // digito = arr[2]/exp%10 --> digito_laco_1 = 802/1%10 = 2
    //digito = 2
    //output[count[2] - 1] = arr[2] --> count[2] = 2
    //output[2-1] = 802
    //output[1] = 802
    
    //digito2 = arr[1]/exp%10 --> 90/1%10 = 0
    //digito = 0
    //output[count[0] - 1] = arr[1] --> count[0] = 1
    //output[0] = 90

    //digito3 = arr[0]/exp%10 --> 45/1%10 = 5;
    //digito = 5;
    //output[count[5]-1] = arr[i] --> count[5] = 3
    //output[2] = arr[0]

    //E por fim fazer essa transformação
    //arr[] = {90,802,45} 

    //dezena e centena resumida
    //count[0 - 3] == 1
    //count[4-8] == 2
    //count[9] == 3

    //{802,45,90}

    //count[0-7] = 2
    //count[8-9] = 3
    //ps: ele sempre vai escolher o menor quando tiver mais de 1 com o mesmo digito --> pois ele já acumulou o menor primeiro --> por isso decrementa!
    //{45,90,802};

#include <stdio.h>
#include <stdlib.h>

// Função que retorna o maior número do array.
// Isso é necessário para determinar quantas casas decimais precisaremos processar.
int getMax(int* arr, int tam) {
    int max = arr[0];
    for (int i = 1; i < tam; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Função que implementa o Radix Sort
void radixSort(int* arr, int tam) {
    // Obtém o maior número do array para saber quantas casas decimais iremos analisar.
    int max = getMax(arr, tam);
    // 'exp' representa a casa decimal atual: 1 para unidades, 10 para dezenas, 100 para centenas, etc.
    int exp = 1;

    // Array auxiliar que armazenará os números ordenados temporariamente.
    int output[tam];

    // Loop principal: enquanto houver casas decimais a serem processadas (max/exp > 0)
    while (max / exp > 0) {
        // Array 'count' para contar a frequência dos dígitos de 0 a 9 para a posição atual.
        int count[10] = {0};

        // PASSO 1: Calcular a frequência de cada dígito na posição atual (definida por 'exp').
        // Exemplo: Se exp == 1, extrai o dígito das unidades.
        for (int i = 0; i < tam; i++) {
            // (arr[i] / exp) % 10 extrai o dígito na casa atual.
            // Por exemplo, para arr[i] = 802 e exp = 1, temos: (802 / 1) % 10 = 2.
            count[(arr[i] / exp) % 10]++;
        }
        // Após esse laço, cada posição de count[] indica quantos números possuem o dígito correspondente.
        // Ex: count[2] = 1 significa que há 1 número com dígito 2 na posição atual.

        // PASSO 2: Transformar 'count' em um array de contagem acumulativa.
        // Isso determina as posições finais de cada dígito no array ordenado.
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        /* 
           Exemplo: Se após o laço, count[2] for 5, isso significa que os números com o dígito 2 na posição atual
           deverão ocupar as posições até o índice 4 (considerando que a contagem inicia em 1) no array ordenado.
        */

        // PASSO 3: Construir o array de saída ordenado pela posição atual.
        // Percorremos o array original de trás para frente para manter a ordenação estável.
        for (int i = tam - 1; i >= 0; i--) {
            // Extrai o dígito da posição atual do elemento.
            int digito = (arr[i] / exp) % 10;
            // Usa o array 'count' para determinar a posição correta no array 'output'.
            // Subtrai 1, pois os índices de array iniciam em 0.
            output[count[digito] - 1] = arr[i];
            // Decrementa o contador para que, se houver outro número com o mesmo dígito,
            // ele seja colocado na posição anterior.
            count[digito]--;
        }

        //--------------------------- EXEMPLO DO PASSO 3 ---------------------------------
// Iniciamos com i = 7 (último elemento):
// Elemento: arr[7] = 66
// Dígito extraído: (66 / 1) % 10 = 6
// count[6] atual: 8
// Ação: Coloca 66 na posição 8 - 1 = 7 do output:
// output[7] = 66
// Decrementa: count[6] passa de 8 para 7.

// i = 6:
// Elemento: arr[6] = 2
// Dígito: (2 / 1) % 10 = 2
// count[2] atual: 4
// Ação: Coloca 2 na posição 4 - 1 = 3 do output:
// output[3] = 2
// Decrementa: count[2] passa de 4 para 3.

// i = 5:
// Elemento: arr[5] = 24
// Dígito: (24 / 1) % 10 = 4
// count[4] atual: 5
// Ação: Coloca 24 na posição 5 - 1 = 4:
// output[4] = 24

//-------------------------------------------------------------------------


        // PASSO 4: Copiar os números ordenados do array 'output' de volta para o array original.
        for (int i = 0; i < tam; i++) {
            arr[i] = output[i];
        }

        // Atualiza o expoente para passar para a próxima casa decimal.
        exp *= 10;
    }
}

int main() {
    // Exemplo de array a ser ordenado.
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int tam = sizeof(arr) / sizeof(arr[0]);

    // Exibe o array original.
    printf("Array original:\n");
    for (int i = 0; i < tam; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Chama a função Radix Sort para ordenar o array.
    radixSort(arr, tam);

    // Exibe o array ordenado.
    printf("Array ordenado:\n");
    for (int i = 0; i < tam; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
