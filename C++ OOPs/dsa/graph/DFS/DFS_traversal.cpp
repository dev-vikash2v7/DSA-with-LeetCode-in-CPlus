#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preorder(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val << " ";  // Visit root
    preorder(root->left);       // Traverse left subtree
    preorder(root->right);      // Traverse right subtree
}

void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);        // Traverse left subtree
    cout << root->val << " ";   // Visit root
    inorder(root->right);       // Traverse right subtree
}

void postorder(TreeNode* root) {
    if (root == NULL) return;
    postorder(root->left);      // Traverse left subtree
    postorder(root->right);     // Traverse right subtree
    cout << root->val << " ";   // Visit root
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Preorder traversal: \n";
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;

    postorder(root);
    cout << endl;


    return 0;
}
