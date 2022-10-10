class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        //decreasing monotonic stack
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            
            while(!st.empty() && heights[st.top()] <= heights[i]){
                st.pop();
            }
            
            st.push(i);
        }
        
        vector<int> res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};