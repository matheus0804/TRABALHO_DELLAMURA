#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

// Remove traços e pontos de um CPF
void removeNonDigits(char *cpf) {
    char *ptr = cpf;
    while (*cpf) {
        if (*cpf != '.' && *cpf != '-') {
            *ptr++ = *cpf;
        }
        cpf++;
    }
    *ptr = '\0';
}

// Valida um CPF
int validateCPF(char *cpf) {
    regex_t regex;
    if (regcomp(&regex, "^[0-9]{11}$", 0) != 0) {
        fprintf(stderr, "Erro ao compilar a expressão regular para CPF\n");
        exit(EXIT_FAILURE);
    }

    int result = regexec(&regex, cpf, 0, NULL, 0);
    regfree(&regex);

    return result == 0;
}

// Valida um valor em BRL (Real Brasileiro)
int validateBRL(char *value) {
    regex_t regex;
    if (regcomp(&regex, "^R\\$ [0-9]+\\.[0-9]{2}$", 0) != 0) {
        fprintf(stderr, "Erro ao compilar a expressão regular para BRL\n");
        exit(EXIT_FAILURE);
    }

    int result = regexec(&regex, value, 0, NULL, 0);
    regfree(&regex);

    return result == 0;
}

// Valida um número de telefone
int validatePhoneNumber(char *phoneNumber) {
    regex_t regex;
    if (regcomp(&regex, "^[0-9]{2}9[0-9]{8}$", 0) != 0) {
        fprintf(stderr, "Erro ao compilar a expressão regular para número de telefone\n");
        exit(EXIT_FAILURE);
    }

    int result = regexec(&regex, phoneNumber, 0, NULL, 0);
    regfree(&regex);

    return result == 0;
}

int main() {
    // Teste com CPF
    char cpf[] = "123.456.789-09";
    removeNonDigits(cpf);
    if (validateCPF(cpf)) {
        printf("CPF válido: %s\n", cpf);
    } else {
        printf("CPF inválido: %s\n", cpf);
    }

    // Teste com BRL
    char brl[] = "R$ 123.45";
    if (validateBRL(brl)) {
        printf("Valor BRL válido: %s\n", brl);
    } else {
        printf("Valor BRL inválido: %s\n", brl);
    }

    // Teste com número de telefone
    char phoneNumber[] = "5511987654321";
    if (validatePhoneNumber(phoneNumber)) {
        printf("Número de telefone válido: %s\n", phoneNumber);
    } else {
        printf("Número de telefone inválido: %s\n", phoneNumber);
    }

    return 0;
}