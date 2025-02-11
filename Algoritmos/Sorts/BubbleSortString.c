void ordenarNomes(char* nomes[], int qntNomes) {
    for (int i = 0; i < qntNomes - 1; i++) {
        for (int j = 0; j < qntNomes - 1 - i; j++) {
            if (strcmp(nomes, nomes[j + 1]) > 0) {
                char* temp = nomes[j];
                nomes[j] = nomes[j + 1];
                nomes[j + 1] = temp;
            }
        }
    }
}