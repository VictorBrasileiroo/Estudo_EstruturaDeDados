array = [5, 3, 2, 4, 7, 1, 0, 6]
arrayOrdenado = []

def BuscarMenor(arr, inicio):
    menorIndex = inicio
    for i in range(inicio, len(arr)):
        if arr[i] < arr[menorIndex]:
            menorIndex = i
    return menorIndex

def OrdenacaoSelecao(arr, arrOrd):
    for i in range(len(arr)):
        menorIndex = BuscarMenor(arr, i)
        arrOrd.append(arr[menorIndex])
        (arr[i], arr[menorIndex]) = (arr[menorIndex], arr[i])

print("Array desordenado: ", array)
OrdenacaoSelecao(array, arrayOrdenado)
print("Array ordenado: ", arrayOrdenado)