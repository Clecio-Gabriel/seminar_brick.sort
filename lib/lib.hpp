#ifndef LIB
#define LIB

#include <iostream>
#include <string>
#include <iterator>
#include <chrono>
#include <algorithm>
#include <vector>

using string = std::string;

struct Metrica{
    long long comparacoes = 0;
    long long trocas = 0;
    double duracao_ms = 0;
};

namespace sortl{

//FUNCTION CALLS
int particao(std::vector<int>& vetor, int inicio, int fim, Metrica& m);
void quickSort(std::vector<int>& vetor, int inicio, int fim, Metrica& m);
void imprimeResultados(string nomeAlgoritmo, Metrica m, int numeroElementos);
void testaQuickSort(std::vector<int>& dados, int numeroElementos);

template <typename Itr>
void brick_sort(Itr first, Itr last, Metrica& m){
    bool is_sorted = false; //sort with flag

    while (not is_sorted){
        bool troca = false;

        //EVEN ITERATIONS
        auto left{first};
        while (std::distance(left, last)>1){
            auto right{left+1};
            m.comparacoes++;
            if (*left>*right){
                std::iter_swap(left, right);
                troca = true;
                m.trocas++;
            }
            left+=2;
        }

        //ODD ITERATIONS
        left = first+1;
        while (std::distance(left, last)>1){
            auto right{left+1};
            m.comparacoes++;
            if (*left>*right){
                std::iter_swap(left, right);
                troca = true;
                m.trocas++;
            }
            left+=2;
        }

        if (not troca){
            is_sorted = true;
        }
    }
    
}

template <typename Itr>
void testabrick_sort(Itr first, Itr last, const int& numeroElementos){
    Metrica m;

    auto start = std::chrono::steady_clock::now();
    brick_sort(first, last, m);
    auto end = std::chrono::steady_clock::now();
    m.duracao_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000000.0;

    imprimeResultados("Brick Sort", m, numeroElementos);
}

template <typename Itr>
void print_msg(const string& msg, const Itr start, const Itr end){
    std::cout << msg;
    
    auto runner{start};
    while (runner!=end){
        std::cout << *runner << " ";
        runner++;
    }
    
    std::cout << "\n";
}

};

#endif