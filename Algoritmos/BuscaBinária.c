#include <stdio.h>

int buscaBinariaRercusiva(int array[], int valor, int start, int end){
    if(start > end){
        return -1;
    } else {
        int middle = (start + end) / 2;
        return array[middle] == valor ? middle : array[middle] > valor ? buscaBinariaRercusiva(array,valor,start, middle - 1) : buscaBinariaRercusiva(array,valor,middle + 1, end);
    }

    // Se o valor central for igual ao valor buscado ele retorna a posição do valor central, caso contrário ele verifica se o valor central é maior que o valor buscado, se for ele chama a função novamente com o valor central como o novo limite superior, caso contrário ele chama a função novamente com o valor central como o novo limite inferior
}

int buscaBinariaLoop(int array[], int valor, int tam){
    int start = 0;
    int end = tam - 1;

    while(start <= end){
        int middle = (start + end) / 2;
        if(array[middle] == valor){
            return middle;
        } else if(array[middle] > valor){
            end = middle - 1;
        } else {
            start = middle + 1;
        }
    }

    return -1;

    //Aqui funciona quase da mesma forma que a função recursiva, a diferença é que ele faz um loop enquanto o limite inferior for menor ou igual ao limite superior, e a cada iteração ele verifica se o valor central é igual ao valor buscado, se for ele retorna a posição do valor central, caso contrário ele verifica se o valor central é maior que o valor buscado, se for ele atualiza o limite superior para o valor central - 1, caso contrário ele atualiza o limite inferior para o valor central + 1
}

int main(){
    int array[] = {1,2,3,4,7,9,22,23};
    int tam = sizeof(array)/sizeof(array[0]);
    printf("%d\n",buscaBinariaRercusiva(array,2,0,tam - 1));
    printf("%d",buscaBinariaLoop(array,2,tam));
    return 0;
}