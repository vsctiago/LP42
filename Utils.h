/** 
 * @file
 * @author 
 *
 * @brief Biblioteca para operações diversas.
 * 
 */

#ifndef UTILS_H
#define	UTILS_H

#ifdef	__cplusplus
extern "C" {
#endif    

#include <stdbool.h>

static const char NEWLINE = '\n';
static const char ENDSTRING = '\0';

/**
 * @brief Limpa o buffer de entrada de dados.
 * @warning Caso não exista nenhuma informação no buffer, o programa pode
 *  ficar a aguardar que exista informação no buffer.
 * 
 * Exemplo:
 * @code
 *  char car:
 * 
 *  car = getchar();
 *  limparBufferEntradaDados();
 * @endcode
 */
void limparBufferEntradaDados();

/**
 * Lê uma cadeia de caracteres (string) através da stream stdin
 * 
 * @param frase - Apontador para a frase lida.
 * @param tamanho - 	Tamanho máximo da frase a ser lida. @warning: O tamanho da frase deve ter em conta o espaço para o carácter de término da string ('\0')
 * @return 1 em caso de leitura com sucesso, 0 caso ocorra um erro.
 *  
 * Exemplo:
 *      char nome[100 + 1];
 *      printf("Introduza o seu nome: ");
 *      if (lerFrase (nome, 100 + 1) == true)
 *      	printf("O nome lido e: %s", nome);
 */
bool lerFrase(char * const frase, const unsigned int tamanho);


#ifdef	__cplusplus
}
#endif

#endif	/* UTILS_H */

