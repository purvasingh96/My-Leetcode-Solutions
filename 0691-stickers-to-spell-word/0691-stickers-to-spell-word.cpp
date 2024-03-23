class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        vector<int> tf(26, 0);
        int n = stickers.size();
        
        for(auto c:target){
            tf[c-'a']+=1;
        }
        
        vector<vector<int>> cf(n, vector<int>(26, 0));
        
        for(int i=0;i<n;i++){
            for(auto c:stickers[i]){
                cf[i][c-'a']+=1;
            }
        }
        
        queue<vector<int>> q;
        q.push(tf);
        bool complete=false;
        
        unordered_map<string, bool> seen;
        int count=0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                
                auto f = q.front();
                q.pop();
                
                string temp="";
                for(int i=0;i<26;i++){
                    if(f[i]>0){
                        string c(f[i], i+'a');
                        temp += c;
                    }
                }
                if(temp == ""){
                    complete=true;
                    return count;
                }
                
                if(seen.find(temp) == seen.end()){
                    seen[temp] = true;
                } else {
                    continue;
                }
                
                for(auto x:cf){
                    q.push(f);
                    for(int i=0;i<26;i++){
                        if(x[i]>0){
                            q.back()[i] -= x[i];
                            
                        }
                    }
                }
                
                
            }
            count+=1;
        }
        
        return complete ? count : -1;
        
    }
};