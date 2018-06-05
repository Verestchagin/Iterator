#include "node.hpp"
using namespace std;

namespace BSTree {

    template<typename T>
    class iterator;

    template <typename T>
    class pre_iterator;

    template <typename T>
    class post_iterator;

    template<typename T>
    class iterator {

        using pointer = T *;
        using reference = T &;
        using value_type = T;

    public:
        iterator(){
            ptr=nullptr;
        }

    private:
        Node<T>* ptr;
    };
    

    template <typename T>
    class pre_iterator : iterator<T> {
    public:
        pre_iterator();
        pre_iterator(Node<T>* ptr,Node<T>* troot);
        auto operator *() -> T&;
        auto operator++() ->pre_iterator<T>&;
        auto simetryc() -> bool;
        template <typename T2>
        friend auto operator!=(pre_iterator<T2>& lhs, pre_iterator<T2>& rhs) -> bool{
            if(lhs.node!=rhs.node)
                return true;
            else
                return false;
        }
    private:
        Node<T>* root;
        Node<T>* node;
    };

    template <typename T>
    class post_iterator : iterator<T> {
    public:
        post_iterator();
        post_iterator(Node<T>* ptr);
    private:
        Node<T>* node;
    };
    
    
    template <typename T>
    pre_iterator<T>::pre_iterator(){
        node=nullptr;
        root=nullptr;
    }

    template <typename T>
    pre_iterator<T>::pre_iterator(Node<T>* ptr,Node<T>* troot){
        node=nullptr;
        root=nullptr;
        node=ptr;
        root=node;
    }
    
    template <typename T>
    auto simetryc() -> bool{
        
    }
    
    template <typename T>
    auto pre_iterator<T>::operator *() -> T&{
        return node->data;
    }
    template <typename T>
    auto pre_iterator<T>::operator++() ->pre_iterator<T>&{
        if(root==node && node->parent!=nullptr){
            node=node->parent;
            return *this;
        }
        while(true){
            if(root == node->right){
                if(node->left!=nullptr){
                    root=node;
                    node=node->left;
                    break;
                }else{
                    root=node;
                    node=node->parent;
                    break;
                }
            }else if(root == node->left){
                root=node;
                node=node->parent;
                break;
            }else if(node == root->right){
                if(node->right!=nullptr){
                    root=node;
                    node=node->right;
                    continue;
                }else if(node->right==nullptr){
                    root=node;
                    break;
                }
            }else if(node == root->left){
                if(node->right!=nullptr){
                    root=node;
                    node=node->right;
                    continue;
                }/*else if(node->left!=nullptr){
                    root=node;
                    node=node->left;
                    continue;
                }*/else if(node->left==nullptr && node->right==nullptr){
                    root=node;
                    node=node->parent;
                    continue;
                }
            }
        }
        return *this; 
    }  
    
        
        /*
        if(node == root && node->right != nullptr){
            node=node->right;
        }
        
        if(root == node->parent->right){
            while(root == node->parent->right){
                root=node;
                node=node->parent;
            }
        }
        */
        /*
        while(true){
            if(node->left == nullptr && node->right == nullptr){
                root=node;
                node=node->parent;
                break;
            }
            if(node->right != nullptr && root == node->left){
                root=node;
                node=node->right;
            }
            if(node->left !=nullptr && root->right == node){
                
            }
        }
        */   
}
