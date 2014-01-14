#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "Utils.h"

void limparBufferEntradaDados(){
    char ch;

    while ((ch = getchar()) != NEWLINE && ch != EOF);
}

bool lerFrase(char * const frase, const unsigned int tamanho) { 
    unsigned int sTam;
    
    if (fgets(frase, tamanho, stdin) != NULL) { 
        sTam = strlen(frase) - 1; 
        if (frase[sTam] == NEWLINE) 
                frase[sTam] = ENDSTRING; 
        return true; 
    } else { 
        return false; 
    }
} 

