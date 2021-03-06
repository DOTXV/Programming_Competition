/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode* pruneTree(TreeNode* root)
    {
        if(pruneit(root)) //last one for root
        {
            root = NULL;
        }
        return root;
    }
    bool pruneit(TreeNode* cur) //1 for need prune
    {
        if(cur == NULL)
        {
            return 0;
        }
        //due to left_check & right_check & (cur->val == 0); null<-0->null should also be deleted
        if(cur->left == NULL && cur->right == NULL && cur->val == 0)
        {
            return 1;
        }
        //due to left_check & right_check & (cur->val == 0);  null<-0->true should also be deleted
        if(cur->left == NULL && cur->right  && pruneit(cur->right) && cur->val == 0)
        {
            return 1;
        }
        //due to left_check & right_check & (cur->val == 0); true<-0->null should also be deleted
        if(cur->left && cur->right == NULL && pruneit(cur->left) && cur->val == 0)
        {
            return 1;
        }


        bool left_check = pruneit(cur->left);
        bool right_check = pruneit(cur->right);

        if(left_check) //if left subtree needs to be pruned
        {
            cur->left = NULL;
        }
        if(right_check) //if right subtree needs to be pruned
        {
            cur->right = NULL;
        }

        return left_check & right_check & (cur->val == 0); //subtree only delete for this one

    }
};
