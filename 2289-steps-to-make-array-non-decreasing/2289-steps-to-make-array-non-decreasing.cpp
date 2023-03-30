class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int, int>> st;
        for(int i=nums.size()-1;i>=0;i--){
            int steps=0;
            while(!st.empty() && st.top().first < nums[i]){
                steps = max(steps+1, st.top().second);
                st.pop();
            }
            st.push({nums[i], steps});
        }
        
        int ans=0;
        while(!st.empty()){
            ans = max(ans, st.top().second);
            st.pop();
        }
        return ans;
    }
};