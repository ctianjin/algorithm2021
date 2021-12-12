class Solution {
public:
    TreeNode* convertBST(TreeNode* root){
	    if(root == NULL)
		   return nullptr;
        convertBST(root->right);
        value += root->val;
        root->val = value;
        convertBST(root->left);
        return root; 
	}
public:
    int value = 0;
};