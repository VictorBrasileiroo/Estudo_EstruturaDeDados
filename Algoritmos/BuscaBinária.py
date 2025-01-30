array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
arraynomes = ["Ana", "Bia", "Carlos", "Daniel", "Eduardo", "Fernanda", "Gustavo", "Hugo", "Igor", "João"]

def buscaBinariaLoop(array, valor):
    inicio = 0
    fim = len(array) - 1
    etapas = 0
    while inicio <= fim:
        print(f'Etapa {etapas}')
        meio = (inicio + fim) // 2
        etapas += 1
        if array[meio] == valor:
            return meio
        elif array[meio] < valor:
            inicio = meio + 1
        else:
            fim = meio - 1
    return -1

def buscaBinariaRecursiva(array, valor, inicio, fim):
    meio = (inicio + fim) // 2
    if(array[meio] == valor):
        return meio
    else:
        if(array[meio] < valor):
            return buscaBinariaRecursiva(array,valor,meio+1,fim)
        else:
            return buscaBinariaRecursiva(array,valor,inicio,meio-1)

print(buscaBinariaLoop(array, 9))
print(buscaBinariaLoop(arraynomes, "Hugo"))
print(buscaBinariaRecursiva(array, 9,0,(len(array) - 1)))