#include "mva.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm> // Para std::max

void calcularMVA(int N, std::vector<Dispositivo>& dispositivos) {
    double X_sistema = 0.0;

    // --- ALGORITMO MVA (Iteração n=1 até N) ---
    for (int n = 1; n <= N; ++n) {
        double soma_VR = 0.0;

        // 1. Calcular Tempo de Resposta (R)
        for (auto& dev : dispositivos) {
            dev.R = dev.S * (1.0 + dev.L);
            soma_VR += (dev.V * dev.R);
        }

        // 2. Calcular Throughput Global (X)
        if (soma_VR > 0) 
            X_sistema = (double)n / soma_VR;
        else 
            X_sistema = 0;

        // 3. Atualizar L, U, X_local e W para a próxima iteração
        for (auto& dev : dispositivos) {
            dev.X_local = dev.V * X_sistema;
            dev.U = dev.S * dev.X_local;
            dev.L = dev.R * dev.X_local;
            dev.W = dev.R - dev.S; 
        }
    }

    // --- CÁLCULOS GLOBAIS ---
    double R_sistema = 0.0;
    double W_sistema = 0.0;
    double L_sistema = 0.0; 
    double U_maximo = 0.0; 

    // Se X_sistema > 0, R_sistema é N/X (Lei de Little global)
    if (X_sistema > 0)
        R_sistema = (double)N / X_sistema;

    for (const auto& dev : dispositivos) {
        // L global é a soma de todos os L locais
        L_sistema += dev.L;
        
        // W global é a soma dos W locais ponderados pelas visitas
        W_sistema += (dev.W * dev.V);

        // Maior Utilização
        if (dev.U > U_maximo) {
            U_maximo = dev.U;
        }
    }

    // --- RELATÓRIO FINAL ---
    std::cout << "\n\n\n" << std::endl;
    std::cout << "\n================ RESULTADOS GLOBAIS (SISTEMA) ================" << std::endl;
    std::cout << std::fixed << std::setprecision(4);
    
    std::cout << "1. Tempo Medio de Resposta (R): " << R_sistema << " seg" << std::endl;
    std::cout << "2. Tempo Medio de Espera   (W): " << W_sistema << " seg" << std::endl;
    std::cout << "3. Utilizacao do Sistema   (U): " << (U_maximo * 100.0) << "%" << std::endl;
    std::cout << "4. Clientes no Sistema     (L): " << L_sistema << std::endl;
    std::cout << "   Throughput do Sistema   (X): " << X_sistema << " clientes/unidade_tempo" << std::endl;

    std::cout << "\n================ DETALHES POR RECURSO ================" << std::endl;
    std::cout << std::left << std::setw(15) << "Recurso" 
              << std::setw(15) << "R (Resp)" 
              << std::setw(15) << "W (Espera)" 
              << std::setw(15) << "U (Util %)" 
              << std::setw(15) << "L (Clientes)" << std::endl;
    std::cout << "---------------------------------------------------------------------------" << std::endl;

    for (const auto& dev : dispositivos) {
        std::cout << std::left << std::setw(15) << dev.nome 
                  << std::setw(15) << dev.R 
                  << std::setw(15) << dev.W 
                  << std::setw(15) << (dev.U * 100.0) 
                  << std::setw(15) << dev.L << std::endl;
    }
    std::cout << "===========================================================================\n";
}