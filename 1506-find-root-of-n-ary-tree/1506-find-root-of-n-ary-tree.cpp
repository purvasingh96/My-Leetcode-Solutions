/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        int val=tree[0]->val;
        for(auto x:tree[0]->children){
            val = val^x->val;
        }
        for(int i=1;i<tree.size();i++){
            val = val ^ tree[i]->val;
            for(auto x:tree[i]->children){
                val = val ^ x->val;
            }
        }
        
        for(auto x:tree) {
            if(val == x->val) return x;
        }
        return NULL;
    }
};