class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& inorder, int left_node, int right_node, vector<int>& postorder, int pleft, int pright) {
        int i = 0;

        if (left_node > right_node || pleft > pright) 
            return NULL;

        TreeNode* cur = new TreeNode(postorder[pright]);

        for ( i = left_node; i < inorder.size(); ++i) {
            if (inorder[i] == cur->val) break;
        }
        cur->left = buildTree(inorder, left_node, i - 1, postorder, pleft, pleft + i - left_node - 1);
        cur->right = buildTree(inorder, i + 1, right_node, postorder, pleft + i - left_node, pright - 1);
        return cur;
    }
};