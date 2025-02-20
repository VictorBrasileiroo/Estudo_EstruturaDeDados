#include <stdio.h>

//PS: MODIFICA DIRETAMENTE O ARRAY N PRECISA CRIAR UM NOVO!

void QuickSort(int* arr,int left,int right){
    if(left < right){
        int pivot = Particion(arr,left,right);
        QuickSort(arr,left,pivot-1);
        QuickSort(arr,pivot+1,right);
    }
}

int Particion(int* arr,int left,int right){
    int i = left - 1;
    int pivot = arr[right];

    for(int j = left; j < right; j++){
        if(arr[j] <= pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[right];
    arr[right] = temp;

    return i + 1;
}

int main(){
    int arr[] = {22,3,5,232,11,22};
    int tam = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    QuickSort(arr,0,tam-1);
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}