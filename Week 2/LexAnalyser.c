#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Token types
enum TokenType {
    KEYWORD,
    IDENTIFIER,
    INTEGER,
    RELATIONAL_OPERATOR,
    // Add more token types as needed
};

// Structure for tokens
struct Token {
    enum TokenType type;
    char lexeme[100];
};

// Symbol table structure
struct SymbolTableEntry {
    char lexeme[100];
    // Add more attributes as needed
};

// Define keywords
const char *keywords[] = {
    "if", "else", "while", "int", // Add more keywords
};

int isKeyword(char *str) {
    // Check if the given string is a keyword
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        perror("Error opening files");
        return 1;
    }

    char currentChar;
    char lexeme[100];
    int lexemeIndex = 0;

    while ((currentChar = fgetc(inputFile)) != EOF) {
        if (isalpha(currentChar)) { // Identifiers and keywords
            lexeme[lexemeIndex++] = currentChar;
            while (isalnum(currentChar = fgetc(inputFile))) {
                lexeme[lexemeIndex++] = currentChar;
            }
            lexeme[lexemeIndex] = '\0';
            lexemeIndex = 0;

            if (isKeyword(lexeme)) {
                // Handle keywords
                fprintf(outputFile, "Keyword: %s\n", lexeme);
            } else {
                // Handle identifiers
                fprintf(outputFile, "Identifier: %s\n", lexeme);
                // Add lexeme to symbol table
            }
        }
        // Add code for other token types here
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
