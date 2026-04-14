#include <iostream>
#include <string>
#include <iterator>

using string = std::string;

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