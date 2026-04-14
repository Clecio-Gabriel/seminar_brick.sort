#include <vector>
#include <array>

#include "lib/lib.hpp"     //WORKING

#define YES 1
#define NO 0

#define VECTOR NO
#define ARRAY NO
#define LIST NO
#define STRING NO

int main(){

    #if VECTOR
    std::vector <int> vec {42, 7, 100, 19, 3, 88, 12, 1, 55, 24, 9, 67, 15, 31, 5, 20, 11, 4, 14, 2};
    sortl::print_msg("COM VETOR:\nVetor original:\n", vec.cbegin(), vec.cend());
    sortl::brick_sort(vec.begin(), vec.end());
    sortl::print_msg("Vetor ordenado:\n",vec.cbegin(), vec.cend());
    #endif

    #if ARRAY

    #endif

    #if STRING
    string str = "como funciona?";
    print_msg("COM STRING:\nString original:\n", str.begin(), str.end());
    brick_sort(str.begin(), str.end());
    print_msg("String ordenada:\n", str.begin(), str.end());
    #endif

    return EXIT_SUCCESS;
}