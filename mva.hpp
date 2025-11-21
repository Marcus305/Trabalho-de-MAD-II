#ifndef MVA_HPP
#define MVA_HPP

#include <string>
#include <vector>

struct Dispositivo {
    std::string nome;
    
    // Inputs
    double S; // Tempo de Serviço (1/mu)
    double V; // Visitas (Calculado via lambdas)
    
    // Variáveis de Estado (Iterativas)
    double L; // Número médio de clientes (Queue Length)
    
    // Variáveis de Saída (Resultados por iteração)
    double R; // Tempo de Resposta (Residence Time)
    double W; // Tempo de Espera (Wait Time)
    double U; // Utilização
    double X_local; // Throughput do dispositivo

    Dispositivo(std::string n, double s, double v) 
        : nome(n), S(s), V(v), L(0.0), R(0.0), W(0.0), U(0.0), X_local(0.0) {}
};

// Protótipo da função
void calcularMVA(int N, std::vector<Dispositivo>& dispositivos);

#endif