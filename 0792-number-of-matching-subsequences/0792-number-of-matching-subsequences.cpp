class Node{
 public:
    string s;
    int i;
    Node(string s, int i){
        this->s=s;
        this->i=i;
    }
};
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<Node*>> res(26);
        for(auto word:words){
            Node* node = new Node(word, 0);
            res[word[0]-'a'].push_back(node);
        }
        int ans=0;
        for(int i=0;i<s.length();i++){
            char c = s[i];
            vector<Node*> curr = res[c-'a'];
            res[c-'a'].clear();
            
            for(auto node:curr){
                
                    node->i += 1;
                    int idx = node->s[node->i];
                    if(node->i == (node->s).length()) {
                        ans+=1;
                    } else {
                        res[node->s[node->i] - 'a'].push_back(node);
                    }   
            }
        }
        
        return ans;
    }
};