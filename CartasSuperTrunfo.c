#include <stdio.h>
#include <string.h> // Necessário para usar funções como strcpy e fgets

// Define uma estrutura para representar uma carta do Super Trunfo
struct CartaSuperTrunfo {
    char estado;           // Estado (A-H)
    char codigo[5];        // Código da Carta (ex: A01)
    char nomeCidade[50];   // Nome da Cidade
    int populacao;         // População da cidade
    float area;            // Área em km²
    float pib;             // PIB em bilhões de reais
    int pontosTuristicos;  // Número de pontos turísticos
};

// Função para ler os dados de uma carta
void lerCarta(struct CartaSuperTrunfo *carta) {
    printf("\n--- Cadastro de Carta ---\n");

    // Ler Estado
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &carta->estado); // Espaço antes de %c para consumir o newline anterior

    // Ler Código da Carta
    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%s", carta->codigo);

    // Limpar o buffer do teclado após ler o código (string)
    // Isso é importante para evitar problemas com o próximo scanf/fgets
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Ler Nome da Cidade
    printf("Digite o Nome da Cidade: ");
    fgets(carta->nomeCidade, sizeof(carta->nomeCidade), stdin);
    // Remover o caractere de nova linha que fgets pode adicionar
    carta->nomeCidade[strcspn(carta->nomeCidade, "\n")] = 0;

    // Ler População
    printf("Digite a População da Cidade: ");
    scanf("%d", &carta->populacao);

    // Ler Área
    printf("Digite a Área da Cidade (em km²): ");
    scanf("%f", &carta->area);

    // Ler PIB
    printf("Digite o PIB da Cidade (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    // Ler Número de Pontos Turísticos
    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

// Função para exibir os dados de uma carta
void exibirCarta(struct CartaSuperTrunfo carta, int numeroCarta) {
    printf("\n--- Carta %d ---\n", numeroCarta);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area); // %.2f para formatar com 2 casas decimais
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("----------------\n");
}

int main() {
    struct CartaSuperTrunfo carta1, carta2;

    printf("=== CADASTRO DE CARTAS SUPER TRUNFO ===\n");

    // Ler dados da primeira carta
    lerCarta(&carta1);

    // Ler dados da segunda carta
    lerCarta(&carta2);

    // Exibir dados da primeira carta
    exibirCarta(carta1, 1);

    // Exibir dados da segunda carta
    exibirCarta(carta2, 2);

    return 0;
}
