#include <stdio.h>

int bubbleSort(int* arr, int tam){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam - 1 - i; j++){
            if(arr[j] >= arr[j+1]){
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }

    //achar o count
    int dist[tam];
    for(int i = 0; i < tam; i++){
        dist[i] = arr[i] - arr[i+1];
    }
    // for(int i = 0; i < tamGap; i++){
    //     if(i%2==0){
    //         output[i] = 0;
    //     }
    //     else{
    //         output[i] = arr[i/2];
    //     }
    // }

    for(int i = 0; i < tam; i++){
        printf("%d");
    }
    
    return tamGap;
}



#include <stdio.h>

int main(){
    int arr[999];
    int qntnums;
    scanf("%d", &qntnums);

    for(int i = 0; i < qntnums; i++) scanf("%d",&arr[i]);
    printf("ARRAY PRIMÁRIO:\n");

    for(int i = 0; i < qntnums; i++){
        if(i != qntnums - 1){
            printf("%d -> ",arr[i]);
        }else{
            printf("%d\n",arr[i]);
        }
    };

    int tamanhoNovo = bubbleSort(arr,qntnums);
    printf("ARRAY ORDENADO:\n");
    for(int i = 0; i < tamanhoNovo; i++){
        if(i != tamanhoNovo - 1){
            printf("%d -> ",arr[i]);
        }else{
            printf("%d\n",arr[i]);
        }
    };
    return 0;
}