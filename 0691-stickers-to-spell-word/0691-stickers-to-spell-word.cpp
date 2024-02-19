class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        queue<vector<int>> q;
        int n = stickers.size();
        vector<vector<int>> s_freq(n, vector<int>(26, 0));
        vector<int> t_freq(26, 0);
        unordered_set<string> visited;
        
        
        for(int i=0;i<stickers.size();i++){
            for(auto c:stickers[i]){
                s_freq[i][c-'a']+=1;
            }
        }
        
        for(auto c:target){
            t_freq[c-'a']+=1;
        }
        
        //visited.insert(target);
        
        q.push(t_freq);
        int c=0;
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                auto t_f = q.front();
                q.pop();
                
                string temp="";
                for(int i=0;i<26;i++){
                    if(t_f[i]>0){
                        string s(t_f[i], i+'a');
                        temp+=s;
                    }
                }
                //cout<<"temp: "<<temp<<"\n";
                if(temp == ""){
                    return c;
                }
                if(!visited.count(temp)){
                    visited.insert(temp);
                } else {
                    continue;
                }
                
                char temp_target = temp[0];
                
                for(auto s_f:s_freq){
                    if(s_f[temp_target-'a']!=0){
                        // explore
                        q.push(t_f);
                        for(int i=0;i<s_f.size();i++){
                            if(s_f[i]!=0){
                                q.back()[i] -= s_f[i];
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