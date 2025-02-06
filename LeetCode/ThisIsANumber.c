// INTEGRANTES DO GRUPO DE ESTRUTURA DE DADOS 2024.2
// 1. VICTOR ANDRÉ LOPES BRASILEIRO
// 2. ERASMO DA SILVA SÁ JUNIOR
// 3. ARTUR FERREIRA MARQUES DA SILVA
// 4. MARIO DIEGO FERREIRA DOS SANTOS
// 5. CAIO HENRIQUE GAVAZZA PATRIOTA

#include <stdio.h>
#define MAX 999

void VerificadorDeNumero(char value[]){
    int natural = 1, inteiro = 0, real = 0;
    for(int i = 0; value[i] != '\0'; i++){
        if(value[i] == '-'){
            inteiro = 1;
            natural = 0;
        }
        if(value[i] == ','){
            real = 1;
            natural = 0;
        }
    }


    if(real && inteiro){
        printf("O NÚMERO É INTEIRO E REAL");
    }else if(natural){
        printf("O NUMERO É NATURAL, INTEIRO E REAL");
    }else if(inteiro)    {
        printf("O NUMERO É INTEIRO");
    }else if(real){
        printf("O NUMERO É REAL E NATURAL");
    }
}

int main(){
    char value[MAX];
    fgets(value, MAX, stdin);
    VerificadorDeNumero(value);
    return 0;
}