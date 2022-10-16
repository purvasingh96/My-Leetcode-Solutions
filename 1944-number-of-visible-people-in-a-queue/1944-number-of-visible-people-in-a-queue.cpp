class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        vector<int> res(heights.size());
        
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && st.top() < heights[i]){
                res[i]+=1;
                st.pop();
            }
            
            if(!st.empty()) res[i]+=1;
            st.push(heights[i]);
        }
        
        return res;
    }
};