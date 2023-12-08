#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int dfs(TreeNode* root, int currentSum) {
    if (root == NULL) {
        return 0;
    }
    currentSum = currentSum * 10 + root->val;
    if (root->left == NULL && root->right == NULL) {
        return currentSum;
    }
    return dfs(root->left, currentSum) + dfs(root->right, currentSum);
}


int sumNumbers(TreeNode* root) {
    return dfs(root, 0);
}

int main() {
    // Example
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    cout << "Total sum of all root-to-leaf numbers: " << sumNumbers(root) << endl;

    return 0;
}
