class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // O(N) but 2 pass solution
        int n = heights.size();
        
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st;
        st.push(0);
        for(int i=1;i<n;i++){
             while(!st.empty() && heights[st.top()]>=heights[i])   {
                 st.pop();
             }
            left[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        
        stack<int> st2;
        st2.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st2.empty() && heights[st2.top()]>=heights[i]){
                st2.pop();                
            }
            right[i] = st2.empty()?n:st2.top();
            st2.push(i);
        }
        
        // for(auto x:left) cout<<x<<" ";
        // cout<<"\n";
        // for(auto x:right) cout<<x<<" ";
        
        int maxarea=INT_MIN;
        for(int i=0;i<n;i++){
            maxarea = max(maxarea, heights[i]*(right[i]-left[i]-1));
        }
        
        return maxarea;
    }
};