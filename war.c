#include <stdio.h>
#include <stdlib.h>

// Definição da struct Territorio
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

int main() {
    // Criação do array para armazenar 5 territórios
    struct Territorio territorios[5];
    
    printf("=== Cadastro de Territórios ===\n");
    
    // Loop para cadastrar os 5 territórios
    for(int i = 0; i < 5; i++) {
        printf("\n--- Território %d ---\n", i + 1);
        
        printf("Nome: ");
        scanf("%s", territorios[i].nome);
        
        printf("Cor do exército: ");
        scanf("%s", territorios[i].cor);
        
        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
    }
    
    // Exibição dos dados cadastrados
    printf("\n=== Dados dos Territórios Cadastrados ===\n");
    for(int i = 0; i < 5; i++) {
        printf("\nTerritório %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exército: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
    }
    
    return 0;
}