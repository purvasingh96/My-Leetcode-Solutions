class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        vector<int> t_freq(26, 0);
        vector<vector<int>> s_freq(n, vector<int>(26, 0));
        unordered_map<string, bool> visited;
        visited[target] = true;
        
        for(int i=0;i<target.length();i++){
            t_freq[target[i]-'a']+=1;
        }
            
        for(int i=0;i<stickers.size();i++){
            for(auto c:stickers[i]){
                s_freq[i][c-'a']+=1;
            }
        }
            
        
        queue<vector<int>> q;
        q.push(t_freq);
        
        int c=0;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto f= q.front();
                q.pop();
                
                string temp="";
                for(int i=0;i<f.size();i++){
                    if(f[i]>0){
                        temp += string(f[i], i+'a');
                    }
                }
                
                if(temp == ""){
                    return c;
                }
                
                if(visited.find(temp) == visited.end()){
                    visited[temp] = true;
                } else {
                    continue;
                }
                
                char seek = temp[0];
                
                for(int i=0;i<n;i++){
                    if(s_freq[i][seek-'a']!=0){
                        q.push(f);
                       for(int j=0;j<s_freq[i].size();j++){
                            if(s_freq[i][j]>0){
                                q.back()[j] -= s_freq[i][j];
                            }
                        } 
                    }
                    
                }
                
                
            }
            c+=1;
        }
        
        return -1;
        
    }
};