class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        stack<string> st;
        vector<string> res;
        map<string, multiset<string>> adj;
        
        for(auto t:tickets){
            adj[t[0]].insert(t[1]);
        }
        
        st.push("JFK");
        
        while(!st.empty()){
            
            string f = st.top();
            
            if(adj[f].size()==0){
                
                st.pop();
                res.push_back(f);
                
                
            } else{
                
                auto it = adj[f].begin();
                st.push(*it);
                adj[f].erase(it);
                
            }
            
        }
        
        reverse(res.begin(), res.end());
        return res;
        
    }
};