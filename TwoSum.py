def QuickSort(arr,left,right):
        if left < right:
            pivot = Particion(arr,left,right)
            QuickSort(arr,left,pivot-1)
            QuickSort(arr,pivot+1,right)
        return arr

def Particion(arr,left,right):
    i = left - 1
    pivo = arr[right]

    for j in range(left,right):
        if arr[j] <= pivo:
            i += 1
            (arr[i],arr[j]) = (arr[j],arr[i])
    (arr[i+1],arr[right]) = (arr[right],arr[i+1])
    return i+1
    
array = [10,2,6,3,89,23]
QuickSort(array,0,len(array)-1)
print(array)