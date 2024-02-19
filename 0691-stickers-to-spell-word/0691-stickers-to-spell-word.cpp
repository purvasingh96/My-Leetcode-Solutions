class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        vector<int> t_freq(26, 0);
        vector<vector<int>> s_freq(n, vector<int>(26, 0));
        int c=0;
        unordered_set<string> visited;
        queue<vector<int>> q;
        
        for(auto c:target){
            t_freq[c-'a']+=1;
        }
        q.push(t_freq);
        
        for(int i=0;i<stickers.size();i++){
            for(auto c:stickers[i]){
                s_freq[i][c-'a']+=1;
            }
        }
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto t_f = q.front();
                q.pop();
                
                string temp="";
                for(int i=0;i<t_f.size();i++){
                    if(t_f[i]>0){
                        string j(t_f[i], i+'a');
                        temp += j;
                    }
                }
                cout<<"temp: "<<temp<<"\n";
                if(temp == ""){
                    return c;
                }
                
                if(visited.count(temp)){
                    continue;
                } else {
                    visited.insert(temp);
                }
                
                // create neighbors
                char seek = temp[0];
                for(int i=0;i<s_freq.size();i++){
                    if(s_freq[i][seek-'a']!=0){
                        // explore
                        q.push(t_f);
                        for(int j=0;j<s_freq[i].size();j++){
                            if(s_freq[i][j]!=0){
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