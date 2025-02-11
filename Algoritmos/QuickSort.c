#include <stdio.h>

//PS: MODIFICA DIRETAMENTE O ARRAY N PRECISA CRIAR UM NOVO!

void QuickSort(int* arr,int left,int right){
    if(left < right){
        int pivot = Particion(arr,left,right);
        QuickSort(arr,left,pivot-1);
        QuickSort(arr,pivot+1,right);
    }
    return arr;
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