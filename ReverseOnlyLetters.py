teste = 'ab-c-d'

def Testar(string):
    inicio = 0
    fim = len(string) - 1
    string = list(string)
    while (inicio < fim):
        if string[inicio].isalpha() and string[fim].isalpha():
            (string[inicio], string[fim]) = (string[fim], string[inicio])
            inicio += 1
            fim -= 1
        else:
            if not string[inicio].isalpha():
                inicio += 1
            if not string[fim].isalpha():
                fim -= 1

    return ''.join(string)

print(Testar(teste))