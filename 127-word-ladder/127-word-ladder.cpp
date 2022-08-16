class Solution {
public:
    int ladderLength(string b, string e, vector<string>& wordList) {
        // bfs of paths
        queue<vector<string>> q;
        q.push({b});
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        while(!q.empty()){
            
            int n = q.size();
            
            while(n--){
                
                auto path =q.front();
                q.pop();
                
                if(path.back() == e){
                    return path.size();
                }
                
                string last = path.back();
                st.erase(last);
                
                for(int i=0;i<last.length();i++){
                    string curr = last;
                    for(int j=0;j<26;j++){
                        curr[i] = (j+'a');
                        
                        if(st.find(curr)!=st.end()){
                            path.push_back(curr);
                            q.push(path);
                            path.pop_back();
                        }
                    }
                }
                
                
            }
            
        }
        
        return 0;
    }
};