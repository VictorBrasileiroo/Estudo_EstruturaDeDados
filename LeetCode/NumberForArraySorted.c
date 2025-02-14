#include <stdio.h>

void BubbleSort(int* arr, int tam){
    for(int i = 0; i <= tam - 1; i++){
        for(int j = 0; j <= tam - 1 - i; j++){  
            if(arr[j] > arr[j+1]){
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
}

int NumberForArray(int* arr, int n, int i){
    int exp = 1;
    while(n/exp > 0){
        arr[i] = (n/exp)%10;
        i++;
        exp *= 10;
    }
    BubbleSort(arr,i);
    return i;
}

int main(){
    int arr[10], number;
    scanf("%d",&number);
    int tam = NumberForArray(arr,number,0);
    for(int i = 0; i < tam; i++){
        if(i != tam - 1) printf("%d --> ", arr[i]);
        else printf("%d", arr[i]);
    }
    return 0;
}