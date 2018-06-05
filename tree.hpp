#include "iterator.hpp"
#include <iostream>

using namespace std;

namespace BSTree {
template <typename T>
    class Tree {
    public:
       // using iterator = pre_order::iterator;
        //using reverse_iterator = post_order::iterator;

        Tree(std::initializer_list<T>);

        auto push_back(Node<T>*&,Node<T>*&,const T&) -> Node<T>*;

        auto begin() -> pre_iterator<T>;
        auto end() -> pre_iterator<T>;

        //auto rbegin() -> reverse_iterator;
        //auto rend() -> reverse_iterator;

    private:
        Node<T>* root;
    };
    
    template <typename T>
    Tree<T>::Tree(std::initializer_list<T> list){
            root = nullptr;
            for(auto i : list){
                push_back(root,root,i);
        }
    }

    template <typename T>
    auto Tree<T>::push_back(Node<T>*& root, Node<T>*& parent,const T& value) -> Node<T>* {
    if (root == nullptr) {
        root = new Node<T> {value, nullptr, nullptr, nullptr,false};
        if(root != this->root)
            root->parent = parent;
    } else {
        if (root->data < value) {
            root->left = push_back(root->left, root, value);
        } else if (root->data > value) {
            root->right = push_back(root->right, root, value);
        } else if(root -> data == value) {
            cout<<"tree is have this node"<<endl;
            return root;
        }
    }
    return root;
}
    template <typename T>
    auto Tree<T>::begin() -> pre_iterator<T>{
        Node<T>* curr=root;
        while(curr->right!=nullptr){
            curr=curr->right;
        }
        pre_iterator<T> iter(curr,root);
        return iter;
    }
    template <typename T>
    auto Tree<T>::end() -> pre_iterator<T>{
        Node<T>* curr=root;
        while(curr->left!=nullptr){
            curr=curr->left;
        }
        pre_iterator<T> iter(curr,root);
        return iter;
    }
}
