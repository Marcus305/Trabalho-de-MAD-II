#include <iostream>
#include <vector>
#include "mva.hpp"

int main() {
    int num_recursos; // Número de filas
    int N;            // Número de clientes
    double lambda_sistema; // Taxa de chegada global

    std::cout << "=== Implementacao MVA (Trabalho MAD) ===" << std::endl;
    
    // Entrada 1: Número de clientes (N)
    std::cout << "Digite o numero de clientes no sistema (N): ";
    std::cin >> N;

    // Entrada 2: Taxa de chegada global (Lambda)
    std::cout << "Digite a taxa de chegada global (lambda do sistema): ";
    std::cin >> lambda_sistema;

    // Entrada 3: Número de filas/recursos
    std::cout << "Digite o numero de filas (recursos): ";
    std::cin >> num_recursos;

    std::vector<Dispositivo> sistema;

    // Loop para configurar cada fila individualmente
    for (int i = 0; i < num_recursos; ++i) {
        std::string nome;
        double mu;       // Taxa de serviço
        double lambda_k; // Para calcular visitas

        std::cout << "\n--- Configurando Fila " << i + 1 << " ---" << std::endl;
        std::cout << "Nome (ex: CPU): ";
        std::cin >> nome;

        std::cout << "Taxa de servico (mu) de " << nome << ": ";
        std::cin >> mu;

        std::cout << "Taxa de chegada local em " << nome << ": ";
        std::cin >> lambda_k;

        // Tempo (S), o enunciado deu Taxa (mu). S = 1/mu
        double S = (mu > 0) ? (1.0 / mu) : 0.0;

        // MVA usa Visitas (V). V = lambda_local / lambda_global
        double V = (lambda_sistema > 0) ? (lambda_k / lambda_sistema) : 0.0;

        sistema.push_back(Dispositivo(nome, S, V));
    }

    // Executa o algoritmo
    calcularMVA(N, sistema);

    return 0;
}