#pragma once

#include <memory>

namespace Datastructures::Tree{
    template<typename T>
    struct Node{

        Node() = default;
        Node(T t):m_val(t){}

        T m_val;
        std::unique_ptr<Node<T>> m_left;
        std::unique_ptr<Node<T>> m_right;
    };
};