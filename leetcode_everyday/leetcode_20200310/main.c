/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int longest_path(struct TreeNode *root, int *longest)
{
    int left = 0, right = 0;

    if (!root) {
        return 0;
    }

    left = longest_path(root->left, longest);
    right = longest_path(root->right, longest);
    if (root->left) {
        left++;
    }
    if (root->right) {
        right++;
    }
    *longest = *longest < (left + right) ? (left + right) : *longest;
    return (left > right) ? left : right;
}

int diameterOfBinaryTree(struct TreeNode* root){
    int longest = 0;
    (void)longest_path(root, &longest);
    return longest;
}