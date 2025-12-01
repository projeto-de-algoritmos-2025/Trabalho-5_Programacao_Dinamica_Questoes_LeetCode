#include <string.h>
#include <stdlib.h>
#define ALFABETO 26

int backtrack(char** palavras, int qtdPalavras, int indice, int* frequencia, int* pontos);
int maxScoreWords(char** words, int wordsSize, char* letters, int lettersSize, 
                  int* score, int scoreSize) {
    int frequencia[ALFABETO] = {0};
    for (int i = 0; i < lettersSize; i++) {
        frequencia[letters[i] -'a']++;
    }
    return backtrack(words, wordsSize, 0, frequencia, score);
}
int backtrack(char** palavras, int qtdPalavras, int indice, int* frequencia, int* pontos) {
    if (indice == qtdPalavras)
        return 0;
    int melhor = backtrack(palavras, qtdPalavras, indice + 1, frequencia, pontos);
    char* palavra = palavras[indice];
    int repetida[ALFABETO] = {0};
    int ganho = 0;
    int possivel = 1;

    for (int i = 0; palavra[i] != '\0'; i++) {
        int c = palavra[i] - 'a';
        repetida[c]++;
        if (repetida[c] > frequencia[c]) {
            possivel = 0;
            break;
        }
        ganho += pontos[c];
    }
    if (possivel) {
        for (int i = 0; i < ALFABETO; i++)
            frequencia[i] -= repetida[i];
        int candidato = ganho + backtrack(palavras, qtdPalavras, indice + 1, frequencia, pontos);
        if (candidato > melhor)
            melhor = candidato;
        for (int i = 0; i < ALFABETO; i++)
            frequencia[i] += repetida[i];
    }
    return melhor;
}
int maxScoreWords(char** words, int wordsSize, char* letters, int lettersSize, 
                  int* score, int scoreSize) {
    int frequencia[ALFABETO] = {0};
    for (int i = 0; i < lettersSize; i++) {
        frequencia[letters[i] -'a']++;
    }
    return backtrack(words, wordsSize, 0, frequencia, score);
}
