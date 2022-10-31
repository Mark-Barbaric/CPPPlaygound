#include "BST.h"

namespace Datastructures::Tree{

    template<typename T>
    void BST<T>::insertNode(T t){
        if(!m_root){
            m_root = std::make_unique<Node<T>>(t);
            return;
        }
    }

    template void BST<int>::insertNode(int);
}