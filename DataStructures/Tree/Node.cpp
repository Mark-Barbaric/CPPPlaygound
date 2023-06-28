#include "Node.h"

namespace Datastructures::Tree {
    template<typename T>
    Node<T>::Node(T v):val(v)
    {

    }

    template class Node<int>;
}