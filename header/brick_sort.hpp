#ifndef SORT_HPP
#define SORT_HPP

#include <iterator>
#include <algorithm>

template <typename Itr>
void brick_sort(Itr first, Itr last){
    bool is_sorted = false; //sort with flag

    while (not is_sorted){
        bool troca = false;

        //EVEN ITERATIONS
        auto left{first};
        while (std::distance(left, last)>1){
            auto right{left+1};
            if (*left>*right){
                std::iter_swap(left, right);
                troca = true;
            }
            left+=2;
        }

        //ODD ITERATIONS
        left = first+1;
        while (std::distance(left, last)>1){
            auto right{left+1};
            if (*left>*right){
                std::iter_swap(left, right);
                troca = true;
            }
            left+=2;
        }

        if (not troca){
            is_sorted = true;
        }
    }
    
}

#endif