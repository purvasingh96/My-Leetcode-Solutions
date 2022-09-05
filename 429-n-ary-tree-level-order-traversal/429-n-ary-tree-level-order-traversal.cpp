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
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> res;
        if(!root) return res;
        q.push(root);
        
        while(!q.empty()){
            
            int n = q.size();
            vector<int> temp;
            while(n--){
                
                auto f = q.front();
                q.pop();
                temp.push_back(f->val);
                if(f->children.size()!=0){
                    for(auto c:f->children)  q.push(c);
                }
                
            }
            res.push_back(temp);
        }
        return res;
    }
};