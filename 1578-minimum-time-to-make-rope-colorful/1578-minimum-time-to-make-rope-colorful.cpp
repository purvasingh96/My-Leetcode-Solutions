class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        stack<pair<char, int>> st;
        int ans=0;
        for(int i=0;i<neededTime.size();i++){
            
            if(st.empty() || st.top().first != colors[i]){
                st.push({colors[i], neededTime[i]});
            } else {
                if(st.top().second < neededTime[i]) {
                    ans += st.top().second;
                    st.pop();
                    st.push({colors[i], neededTime[i]});
                } else{
                    ans += neededTime[i];
                    
                }
            }
            
        }
        return ans;
    }
};