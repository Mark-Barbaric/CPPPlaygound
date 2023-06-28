#pragma once
#include <memory>

namespace Datastructures::Tree {
    template<typename T>
    struct Node {

        T val;

        Node(T v);

        Node* left;
        Node* right;
    };
}