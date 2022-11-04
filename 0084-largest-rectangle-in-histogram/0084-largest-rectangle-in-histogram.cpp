class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int max_area=0, n = heights.size();
        
        for(int i=0;i<n;i++){
            
            while(st.top()!=-1 && heights[st.top()] >= heights[i]){
                int ht = heights[st.top()];
                st.pop();
                int w = i - st.top() - 1;
                max_area = max(max_area, ht*w);
            }
            st.push(i);
        }
        
        while(st.top()!=-1){
            int ht = heights[st.top()];
            st.pop();
            
            int w = n - st.top()-1;
            max_area = max(max_area, ht*w);
        }
        return max_area;
    }
};