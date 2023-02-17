class Node{
public:
    string word;
    int index;
    Node(string word, int index){
        this->word=word;
        this->index=index;
    }
};

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
       vector<vector<Node*>> bucket(26);
        int ans=0;
        for(auto w:words){
            Node* temp = new Node(w, 0);
            bucket[w[0]-'a'].push_back(temp);
        }
        
        for(auto c:s){
            auto currBucket = bucket[c-'a'];
            bucket[c-'a'].clear();
            
            for(auto node:currBucket){
                node->index += 1;
                if(node->index==node->word.length()){
                    ans+=1;
                } else{
                    bucket[node->word[node->index]-'a'].push_back(node);
                }
            }  
        }
        
        return ans;
    }
};