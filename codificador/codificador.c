#include <stdio.h>
#include <windows.h> // Biblioteca com sleep e o beep
#include <string.h>
#include <ctype.h>

const char *codMorse[] = {
    ".-", "-...", "-.-.", "-..", ".", // A, B, C, D, E
    "..-.", "--.", "....", "..", ".---", // F, G, H, I, J
    "-.-", ".-..", "--", "-.", "---", // K, L, M, N, O
    ".--.", "--.-", ".-.", "...", "-", // P, Q, R, S, T
    "..-", "...-", ".--", "-..-", "-.--", "--..", // U, V, W, X, Y, Z
    "-----", ".----", "..---", "...--", "....-", // 0, 1, 2, 3, 4
    ".....", "-....", "--...", "---..", "----.", // 5, 6, 7, 8, 9
};

const char *decodMorse[] = {
    "A", "B", "C", "D", "E", // .- , -... , -.-. , -.. , .
    "F", "G", "H", "I", "J", // ..-. , --. , .... , .. , .---
    "K", "L", "M", "N", "O", // -.- , .-.. , -- , -. , ---
    "P", "Q", "R", "S", "T", // .--. , --.- , .-. , ... , -
    "U", "V", "W", "X", "Y", "Z", // ..- , ...- , .-- , -..- , -.-- , --..
    "0", "1", "2", "3", "4", // ----- , .---- , ..--- , ...-- , ....-
    "5", "6", "7", "8", "9", // ..... , -.... , --... , ---.. , ----.
};

void codificarMorse (const char *mensagem) {
    printf("Mensagem codificada para Morse: ");
    int i = 0;
    while (mensagem[i] != '\0'){
        if (mensagem[i] != " "){
            char c = toupper(mensagem[i]);
            if (isalpha(c)){
                printf("%s ", codMorse[c - 'A']);
            } else if (isdigit(c)){
                printf("%s ", codMorse[c - '0' + 26]);
            }
        } else {
            printf(" ");
        }
        i++;
    }
}

void decodificarMorse(const char *mensagem) {
    printf("Mensagem decodificada para linguagem natural: ");
    char *token = strtok((char *)mensagem, " ");
    while (token != NULL){
        int i = 0;
        while (strcmp(token, decodMorse[i] != 0)){
            i++;
        }
        printf("%c", i < 26 ? i + 'A' : (i < 36 ? (i - 26) + 'O' : decodMorse[i][0]));
        token = strtok(NULL, " ");
    }
}

char espacamento(){
    return printf("------------------------------------------------------------------------------- \n");
}

void sleep(int segundos){
    Sleep(segundos * 1000);
}

int main(){
    // Declaração das variáveis
    char frase[100]; // Variável para armazenar a frase
    int realizarOperacao; // Variável para escolher a operação a ser realizada

    espacamento();

    // Início do programa

    printf("Ola, seja bem-vindo ao codificador/descodificador de codigo morse!! \n");
    printf("Antes de comecar, eu quero te passar algumas dicas: \n\n");

    sleep(2);

    printf("* Nao utilize acentos na hora de escrever a frase que sera codificada!\n");

    sleep(1);

    printf("* Caso use, as letras acentuadas nao serao codificadas \n");

    espacamento();
    sleep(2);

    while(TRUE){
        // Pedindo ao usuário qual operação ele quer realizar
        printf("\n\n");
        printf("Qual operacao voce deseja realizar: \n1. Codificar     2. Decodificar     3. Sair\n");
        printf("Sua escolha: ");
        scanf("%d", &realizarOperacao);

        espacamento();

        // Solicitando a frase
        printf("Digite uma frase: ");
        fflush(stdin);  // Função para quebrar o input feito pelo scanf
        fgets(frase, sizeof(frase), stdin); // Input para entrada da frase

        sleep(2);

        // Opções do usuário
        if (realizarOperacao == 1){ // Codificador
            codificarMorse(frase);
        }
        else if (realizarOperacao == 2){ // Decodificador
            decodificarMorse(frase);
        }
        else if (realizarOperacao == 3){
            printf("Obrigado por usar o nosso programa, adeus!");
            break;
        }
        else{
            printf("Opcao invalida, vamos começar novamente");
        }
    }
    
    return 0;
}