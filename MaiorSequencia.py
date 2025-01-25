array = [100,200,4,50,3,2,101,102,103,104]

def BubbleSort(arr):
    for i in range(len(arr) - 1):
        for j in range(len(arr) - 1 - i):
            if arr[j] > arr[j + 1]:
                (arr[j], arr[j + 1]) = (arr[j + 1], arr[j])

def MaiorSequencia(arr):
    count = 1
    maxCount = 0
    for j in range(len(arr) - 1):
        if arr[j + 1] == arr[j] + 1:
            count += 1
        else:
            if(count > maxCount):
                maxCount = count
            count = 0
    return maxCount

BubbleSort(array)
maiorSequencia = MaiorSequencia(array)
print("Array ordenado: ", array)
print("Maior sequencia: ", maiorSequencia)