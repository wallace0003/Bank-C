#include <stdio.h>
#include "bank.h"

int main() {
    int opcao;

    while (1) {
        printf("\nOpção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            funcao1();
        } else if (opcao == 2) {
            funcao2();
        } else if (opcao == 3) {
            funcao3();
        } else if (opcao == 4) {
            funcao4();
        } else if (opcao == 5) {
            funcao5();
        } else if (opcao == 6) {
            funcao6();
        } else if (opcao == 7) {
            funcao7();
        } else if (opcao == 8) {
            funcao8();
        } else if (opcao == 0) {
            printf("Saindo...");
            break;
        } else {
            printf("Opção inválida!\n");
        }
    }

    return 0;
}
