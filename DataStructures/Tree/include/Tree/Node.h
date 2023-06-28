#pragma once
#include <memory>

namespace DataStructures::Tree {
    template<typename T>
    struct Node {

        T val;

        Node(T v);

        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
    };
}