#include "estruturas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Matricula(Materias *disciplinas, int n, Periodos *periodos, int periodoAtual) {
    for(int i = 0; i < n; i++) {
        //vai analisar se a materia do loop é do periodo atual dele e se precisa ser matriculada
        if (disciplinas[i].periodo == periodoAtual && disciplinas[i].matricular){
            int podeMatricular = 0; //serve para indicar se a disciplina pode ser matriculada

            // se a disciplina nao tiver preque ela pode ser matriculada
            if (disciplinas[i].pre_req == NULL){
                podeMatricular = 1;
            } 
            // Se ela tiver, olha apenas se ele tá como false, ou seja, se ele reprovou no pre-req da matéria ele n vai conseguir fazer tal.
            else{
                Materias *prereq = disciplinas[i].pre_req;
                if (prereq->matricular == false){
                    podeMatricular = 1;
                }
            }

            // se puder matricular --> achar a posição vazia dentro do array dos periodos e materias --> preenche com a materia e muda o matricular para false.
            if (podeMatricular){
                int pos = -1;
                for (int j = 0; j < 8; j++) {
                    if (strcmp(periodos[periodoAtual].disciplinasCursando[j].cod_comp, "") == 0){
                        pos = j;
                        break;
                    }
                }

                //se achou a pos --> preenche e muda matricular
                if (pos != -1){
                    periodos[periodoAtual].disciplinasCursando[pos] = disciplinas[i];
                    disciplinas[i].matricular = false; // Marca como matriculada
                }
            }
        }
    }
}

//exemplo de como fazer isso recursivo 
void LoopDeMatricula(Materias *disciplinas, int n, Periodos *periodos, int periodoAtual){
    if(periodoAtual <= 10){
        Matricula(disciplinas,n,periodos,periodoAtual);
    }
    return LoopDeMatricula(disciplinas,n,periodos,periodoAtual+1);
}