#include <Node.h>
#include <vector>

namespace Algorithms::Tree {
    
    using namespace Datastructures::Tree;

    std::string InorderTraversalRecursive(const Node<int>* root){
        if(!root){
            return "";
        }

        return InorderTraversalRecursive(root->left) + std::to_string(root->val) + InorderTraversalRecursive(root->right);
    }

}