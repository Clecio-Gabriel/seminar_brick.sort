#include "lib.hpp"

int main() {
    // Exemplo de teste com vetor de 10000 elementos
    int N = 100;
    std::vector<int> dados(N);
    // Semente de anonimização com número fixo
    // para gerar sempre os mesmos valores
    srand(42);
    // Preenchendo com valores aleatórios
    for(int i = 0; i < N; i++) dados[i] = rand() % 100000;
    std::vector<int> teste2 = dados;

    sortl::testabrick_sort(dados.begin(), dados.end(), N);
    sortl::testaQuickSort(teste2, N);
    
    return 0;
}