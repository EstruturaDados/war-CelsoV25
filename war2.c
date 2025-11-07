#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

void atacar(struct Territorio* a, struct Territorio* d) {
    printf("\n%s (%s) ataca %s (%s)\n", a->nome, a->cor, d->nome, d->cor);
    
    int dado_a = rand() % 6 + 1;
    int dado_d = rand() % 6 + 1;
    printf("Dados: %d vs %d - ", dado_a, dado_d);
    
    if (dado_a > dado_d) {
        printf("Atacante vence!\n");
        d->tropas -= rand() % 3 + 1;
        
        if (d->tropas <= 0) {
            d->tropas = 0;
            strcpy(d->cor, a->cor);
            int transferir = a->tropas / 3;
            transferir = transferir < 1 ? 1 : transferir;
            d->tropas = transferir;
            a->tropas -= transferir;
            printf("%s conquistado! %d tropas transferidas.\n", d->nome, transferir);
        }
    } else if (dado_d > dado_a) {
        printf("Defensor vence!\n");
        a->tropas -= rand() % 2 + 1;
        if (a->tropas < 0) a->tropas = 0;
    } else {
        printf("Empate!\n");
    }
}

void exibir(struct Territorio* t, int qtd) {
    printf("\n=== TERRITÓRIOS ===\n");
    for(int i = 0; i < qtd; i++) {
        printf("%d. %s (%s) - %d tropas\n", 
               i+1, t[i].nome, t[i].cor, t[i].tropas);
    }
}

int main() {
    srand(time(NULL));
    
    int qtd;
    printf("Quantidade de territórios: ");
    scanf("%d", &qtd);
    
    if(qtd <= 0) qtd = 3; // Valor padrão
    
    struct Territorio* territorios = malloc(qtd * sizeof(struct Territorio));
    
    // Cadastro rápido
    for(int i = 0; i < qtd; i++) {
        printf("\nTerritório %d:\n", i+1);
        printf("Nome Cor Tropas: ");
        scanf("%s %s %d", territorios[i].nome, territorios[i].cor, &territorios[i].tropas);
    }
    
    exibir(territorios, qtd);
    
    char op;
    do {
        int a, d;
        printf("\nAtacante e Defensor (ex: 1 2): ");
        scanf("%d %d", &a, &d);
        a--; d--;
        
        if(a >= 0 && a < qtd && d >= 0 && d < qtd && a != d && territorios[a].tropas > 0) {
            atacar(&territorios[a], &territorios[d]);
            exibir(territorios, qtd);
        } else {
            printf("Ataque inválido!\n");
        }
        
        printf("Continuar? (s/n): ");
        scanf(" %c", &op);
    } while(op == 's' || op == 'S');
    
    printf("\n=== FINAL ===\n");
    exibir(territorios, qtd);
    free(territorios);
    
    return 0;
}
