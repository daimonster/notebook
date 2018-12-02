#include <iostream>
#include <algorithm>
#include <array>

int main(){
    std::array<int,8> foo = {3,5,7,12,13,17,19,23};
    if(std :: all_of(foo.begin(),foo.begin() + 3,[](int i){return i%2;}))
        std::cout << "All the elements are odd numbers.\n";
    else 
        std::cout << "Not all the elements are odd numbers.\n";
    return 0;
}