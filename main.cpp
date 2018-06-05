#include <iostream>
#include "tree.hpp"

using namespace BSTree;

int main(){
    Tree<int> tree = {5, 3, 4, 2, 7, 0, 9, 6, 8};
    
    auto it = tree.begin();
    auto end = tree.end();
    
    for(; it != end;++it) {
      std::cout << *it << ' ';
    }


return 0;
}
