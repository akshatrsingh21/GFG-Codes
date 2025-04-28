class Solution {
  public:
    pair<int,int>solve(Node *root){
        if(!root) return {0,0};
        auto l=solve(root->left);
        auto r=solve(root->right);
        
        int include=root->data + l.second+r.second;
        int exclude=max(l.first,l.second)+max(r.first,r.second);
        return {include,exclude};
    }
    int getMaxSum(Node *root) {
        //CodeGenius
        auto ans=solve(root);
        return max(ans.first,ans.second);
        
        
    }
};
