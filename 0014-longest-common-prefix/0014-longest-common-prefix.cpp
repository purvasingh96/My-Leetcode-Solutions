class TrieNode{
public:
    vector<TrieNode*> dict;
    string val;
    int reps;
    TrieNode(){
        dict.resize(26, NULL);
        reps=0;
        val="";
    }
};

class Solution {
private:
    TrieNode* root;
    
    void insert(string s){
        TrieNode* node = root;
        
        for(int i=0;i<s.length();i++){
            
            if(node->dict[s[i]-'a']==NULL){
                node->dict[s[i]-'a'] = new TrieNode();
            }
            
            
            node = node->dict[s[i]-'a'];
            node->reps+=1;
            string temp(1, (s[i]));
            node->val=temp;
        }
        
    }
    
    void print(TrieNode* node){
        for(int i=0;i<26;i++){
            if(node->dict[i]!=NULL){
                cout<<(char)(i+'a')<<" ";
                print(node->dict[i]);
            }
        }
    }
    
    void longestPrefix(int n, TrieNode* node, string& res){
       for(int i=0;i<26;i++){
           if(node->dict[i]){
               if(node->dict[i]->reps==n){
                   string temp(1, (i+'a'));
                   res+=temp;
                   longestPrefix(n, node->dict[i], res);
               }
           }
       }
    }
    
public:
    string longestCommonPrefix(vector<string>& strs) {
        root = new TrieNode();
        int n = strs.size();
        string res="";
        
        for(auto word:strs) insert(word);
        TrieNode* node = root;
        // print(node);
        longestPrefix(n, node, res);
        return res;
        
    }
};