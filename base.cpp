#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm> // Para o std::swap

using namespace std;
using namespace std::chrono;

// Estrutura para armazenar as métricas da análise experimental
struct Metrica {
    long long comparacoes = 0;
    long long trocas = 0;
    double duracao_ms = 0;
};

// --- ALGORITMO QUICKSORT (Particionamento de Lomuto) ---
int particao(vector<int>& vetor, int inicio, int fim, Metrica& m) {
    int pivo = vetor[fim]; // Pivô escolhido como o último elemento
    int i = (inicio - 1);
    for (int j = inicio; j <= fim - 1; j++) {
        m.comparacoes++; // Incrementa comparação entre elementos
        if (vetor[j] <= pivo) {
            i++;
            swap(vetor[i], vetor[j]);
            m.trocas++; // Incrementa troca
        }
    }

    swap(vetor[i + 1], vetor[fim]);
    m.trocas++; // Incrementa troca
    return (i + 1);
}

void quickSort(vector<int>& vetor, int inicio, int fim, Metrica& m) {
    if (inicio < fim) {
        int posicaoPivo = particao(vetor, inicio, fim, m);
        quickSort(vetor, inicio, posicaoPivo - 1, m);
        quickSort(vetor, posicaoPivo + 1, fim, m);
    }
}

// --- UTILITÁRIOS PARA O PROFESSOR E ALUNOS ---
void imprimeResultados(string nomeAlgoritmo, Metrica m, int numeroElementos) {
    cout << "\n------------------------------------------" << endl;
    cout << "RESULTADOS: " << nomeAlgoritmo << " (N = " << numeroElementos << ")" << endl;
    cout << "Tempo: " << m.duracao_ms << " ms" << endl;
    cout << "Comparacoes: " << m.comparacoes << endl;
    cout << "Trocas (Swaps): " << m.trocas << endl;
    cout << "------------------------------------------" << endl;
}
void testaQuickSort(vector<int>& dados, int numeroElementos) {
    // Objeto que armazena as medições do teste (métricas)
    Metrica m;
    // Início da medição de tempo
    auto start = steady_clock::now();
    quickSort(dados, 0, numeroElementos - 1, m);
    auto end = steady_clock::now();
    // Cálculo da duração
    // (Milissegundos com precisão de até 6 casas decimais)
    m.duracao_ms = duration_cast<nanoseconds>(end - start).count() / 1000000.0;
    imprimeResultados("QuickSort Padrao", m,numeroElementos);
}

int main() {
    // Exemplo de teste com vetor de 10000 elementos
    int N = 10000;
    vector<int> dados(N);
    // Semente de anonimização com número fixo
    // para gerar sempre os mesmos valores
    srand(42);
    // Preenchendo com valores aleatórios
    for(int i = 0; i < N; i++) dados[i] = rand() % 100000;
    testaQuickSort(dados, N);
    
    return 0;
}