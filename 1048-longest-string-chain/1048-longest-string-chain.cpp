class Solution {
public:
    int ans=1;
    unordered_map<string, bool> M;
    
    void bfs(string &src)
    {
        M[src] = true;
        
        queue<pair<string, int>>Q;
        Q.push({src, 1});
        
        while(Q.size())
        {
            auto [s, d] = Q.front();
            Q.pop();
            
            ans = max(ans, d);
            
            for(int i=0; i<s.size(); i++)
            {
                string t = s.substr(0, i) + s.substr(i+1);
                
                if(M.find(t) != M.end() and M[t] == false)
                {
                    M[t] = true;
                    Q.push({t, d+1});
                }
            }
        }
    }
    
    int longestStrChain(vector<string>& words) {
       
        for(auto w:words)
            M[w] = false;
        
        sort(words.begin(), words.end(), [](auto a, auto b){
            return a.size() > b.size();
        });
        
        for(auto &w:words)
        {
            if(M[w] == false)
                bfs(w);
        }
        
        return ans;
    }
};