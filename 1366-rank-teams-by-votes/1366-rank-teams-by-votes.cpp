
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes[0].length();
        if(votes.size()==1) return votes[0];
        string ans = votes[0];
        
        
        vector<vector<int>> ranks(26, vector<int>(n+1, 0));
        
        for(auto v:votes){
            for(int i=0;i<v.length();i++){
                
                ranks[v[i]-'A'][i+1] +=1;
                
            }
        }
        
       
        
        sort(ans.begin(), ans.end(),[&](const char& a, const char& b){
            if(ranks[a-'A'] == ranks[b-'A']) return a<b;
            return ranks[a-'A'] > ranks[b-'A'];
        });
        
        return ans;
        
    }
};