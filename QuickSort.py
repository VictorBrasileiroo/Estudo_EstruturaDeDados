array = [10, 7, 8, 9, 1, 5]

def QuickSort(arr,left,rigth):
    #Aqui são as extremidades do array
    if left < rigth:
        #Aqui é o pivô --> valor que vai ser comparado 
        pivot = Particion(arr,left,rigth)
        #Aqui é a chamada recursiva para a esquerda e direita --> no caso eu faço o quick no lado esquerdo e depois no lado direito do pivô até que o array esteja ordenado
        QuickSort(arr,left,pivot-1)
        QuickSort(arr,pivot+1,rigth)
    return arr

def Particion(arr,left,rigth):
    # Nosso pivo sera o ultimo elemento do array
    pivot = arr[rigth]
    # Como estudado o I sempre sera o menor elemento --> "comeca fora do array"
    i = left - 1
    # Aqui eu percorro o array e comparo o elemento com o pivô
    for j in range(left,rigth):
        # Se o elemento for menor ou igual ao pivô eu incremento 1 no i e troco o elemento de lugar com o elemento em j
        if arr[j] <= pivot:
            i = i + 1
            arr[i],arr[j] = arr[j],arr[i]
    # Aqui só preciso colocar o pivô no lugar correto --> que é o i + 1 --> "meio do array"
    arr[i+1],arr[rigth] = arr[rigth],arr[i+1]
    return i + 1

print("ARRAY DESORDENADO: ",array)
print("ARRAY ORDENADO: ",QuickSort(array,0,len(array)-1))