class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> m;
        unordered_map<string, int> w;
        vector<int> ans;
        
        for(auto word:words) w[word]+=1;
        
        int n = s.length();
        int len = words[0].length();
        int words_len = words.size();
        int total_len = len*words_len;
        
        
        for(int i=0;i<(len);i++){
            m.clear();
            int left=i, right=i;
            int found=0;
            
            while(right<s.length()){
                
                string str = s.substr(right, len);
                
                if(w.find(str)!=w.end()) {
                    m[str]+=1;
                    found+=1;
                    
                    while(m[str] > w[str]){
                        string cur = s.substr(left, len);
                        m[cur]-=1;
                        left += len;
                        found-=1;
                    }
                    
                    if(found == words_len) ans.push_back(left);
                    right+=len;

                } 
            
                else {
                    m.clear();
                    found=0;
                    right+=len;
                    left=right;

                }
                
                
            }
            
            
        }
        
        return ans;
        
    }
};