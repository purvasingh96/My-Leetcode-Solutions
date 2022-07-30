class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> whole(26, 0);
        vector<string> res;
        
        for(auto word:words2) {
            vector<int> sub(26, 0);
            
            for(auto c: word){
                sub[c-'a']+=1;
                whole[c-'a'] = max(whole[c-'a'], sub[c-'a']);
            }
            
        }
        
        for(auto word:words1){
            vector<int> sub(26, 0);
            for(auto c:word) sub[c-'a']+=1;
            bool keep=true;
            for(int i=0;i<whole.size();i++){
                if(sub[i] < whole[i]) {
                    keep=false;
                    break;
                }
            }
            if(keep) res.push_back(word);
        }
        
      return res;  
    }
};