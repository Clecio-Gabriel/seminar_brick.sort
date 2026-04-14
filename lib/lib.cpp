#include "lib.hpp"

int sortl::particao(std::vector<int>& vetor, int inicio, int fim, Metrica& m) {
    int pivo = vetor[fim]; // Pivô escolhido como o último elemento
    int i = (inicio - 1);
    for (int j = inicio; j <= fim - 1; j++) {
        m.comparacoes++; // Incrementa comparação entre elementos
        if (vetor[j] <= pivo) {
            i++;
            std::swap(vetor[i], vetor[j]);
            m.trocas++; // Incrementa troca
        }
    }

    std::swap(vetor[i + 1], vetor[fim]);
    m.trocas++; // Incrementa troca
    return (i + 1);
}

void sortl::quickSort(std::vector<int>& vetor, int inicio, int fim, Metrica& m) {
    if (inicio < fim) {
        int posicaoPivo = particao(vetor, inicio, fim, m);
        quickSort(vetor, inicio, posicaoPivo - 1, m);
        quickSort(vetor, posicaoPivo + 1, fim, m);
    }
}

void sortl::imprimeResultados(string nomeAlgoritmo, Metrica m, int numeroElementos) {
    std::cout << "\n------------------------------------------" << '\n';
    std::cout << "RESULTADOS: " << nomeAlgoritmo << " (N = " << numeroElementos << ")" << '\n';
    std::cout << "Tempo: " << m.duracao_ms << " ms" << '\n';
    std::cout << "Comparacoes: " << m.comparacoes << '\n';
    std::cout << "Trocas (Swaps): " << m.trocas << '\n';
    std::cout << "------------------------------------------" << '\n';
}

void sortl::testaQuickSort(std::vector<int>& dados, int numeroElementos) {
    // Objeto que armazena as medições do teste (métricas)
    Metrica m;
    // Início da medição de tempo
    auto start = std::chrono::steady_clock::now();
    quickSort(dados, 0, numeroElementos - 1, m);
    auto end = std::chrono::steady_clock::now();
    // Cálculo da duração
    // (Milissegundos com precisão de até 6 casas decimais)
    m.duracao_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000000.0;
    imprimeResultados("QuickSort Padrao", m,numeroElementos);
}