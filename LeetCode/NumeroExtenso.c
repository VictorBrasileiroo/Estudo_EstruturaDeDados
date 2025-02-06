#include <stdio.h>
#include <stdlib.h>

char* Unidade(int value){
    char *numeros[] = {"um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove"};
    return numeros[value - 1];
}

char* Dezena(int value){
    char *numeros[] = {"vinte", "trinta", "quarenta", "cinquenta", "sesenta", "setenta", "oitenta", "noventa"};
    return numeros[value - 2];
}

char* Centena(int value){
    char *numeros[] = {"cento", "duzentos", "tresentos", "quatrocentos", "quinhetos", "seicentos", "setecetnos", "oitocentos", "novecentos"};
    return numeros[value - 1];
}

char* ValorExtenso(int value){
    int valueCentena = value / 100;
    int valueDezena = (value/10) % 10;
    int valueUnidade = value % 10;
        
    char *resultado = (char*)malloc(50 * sizeof(char));
    
    snprintf(resultado, 50, "%s e %s e %s", Centena(valueCentena), Dezena(valueDezena), Unidade(valueUnidade));
    
    return resultado;
}
int main()
{
    char* numero = ValorExtenso(2);
    printf("%s", numero);
    free(numero);
    return 0;
}