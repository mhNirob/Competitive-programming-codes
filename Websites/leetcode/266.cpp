#include <iostream>

//  Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return root;
        }
        
        *root = TreeNode(root->val, root->right, root->left);

        invertTree(root->right);
        invertTree(root->left);

        return root;
    }
};

// Function to print the binary tree in an inorder traversal
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    std::cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution solution;
    std::cout << "Original tree: ";
    inorderTraversal(root);
    std::cout << std::endl;

    TreeNode* invertedRoot = solution.invertTree(root);

    std::cout << "Inverted tree: ";
    inorderTraversal(invertedRoot);
    std::cout << std::endl;

    // TODO: Don't forget to deallocate the memory allocated for the tree nodes

    return 0;
}






