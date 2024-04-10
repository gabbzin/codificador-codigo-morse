#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // Biblioteca com sleep e o beep

/*
    Caso se trate de uma frase, existe um silêncio de três unidades entre uma palavra e outra.
    No caso de mensagens mais longas, com mais de uma frase,
    o intervalo entre o fim de uma sentença e o começo de outra é de sete unidades.

    Os pontos têm duração curta, de uma unidade;
    Os traços têm duração mais longa, que duram, em média, três unidades de tempo.
*/

void sleep(int segundos){
    Sleep(segundos * 1000);
}

int main(){
    // Declaração das variáveis
    char frase[] = {};
    int i;

    // Início do programa

    printf("Ola, seja bem-vindo a codificador de codigo morse!! \n");
    printf("Antes de comecar, eu quero te passar algumas dicas: \n\n");

    sleep(2);

    printf("* Nao utilize acentos na hora de escrever a frase que sera codificada!\n");

    sleep(1);

    printf("* Caso use, as letras acentuadas nao serao codificadas \n");

    sleep(2);

    printf("Digite a frase que deseja codificar: ");
    scanf("%s", &frase);

    
    return 0;
}