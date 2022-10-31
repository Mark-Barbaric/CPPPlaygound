#pragma once
#include "Node.h"

#include <memory>

namespace Datastructures::Tree{

    template<typename T>
    class BST{

        public:

        void insertNode(T newData);

        private:
            std::unique_ptr<Node<T>> m_root;
    };
};