# [21,2323,56,3,666,1,0.5,2] --> acha o menor index (0.5)
# manda o index do 0.5 para o selection sort 
# o selectionsort troca com o valor incial do array
#[0.5,2323,56,3,666,1,21,2]
# em seguida ele vai chamar o LowerIndexSearch comecando do segundo item pois o primeiro já ta ordenado

def LowerIndexSearch(arr, start):
    lowerIndex = start
    for i in range(start, len(arr)):
        if arr[i] < arr[lowerIndex]:
            lowerIndex = i
    return lowerIndex

def SelectionSort(arr):
    for j in range(len(arr)):
        lowerValue = LowerIndexSearch(arr,j)
        (arr[j],arr[lowerValue]) = (arr[lowerValue],arr[j])

array = [21,2323,56,3,666,1,0.5,2]

SelectionSort(array)
print(array)