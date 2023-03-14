class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        stack<int> st;
        int i=0;
        
        while(i<height.size()){
            while(!st.empty() && height[i] > height[st.top()]){
                int j = st.top(); st.pop();
                if(st.empty()) break;
                
                int diff = height[j];
                int area = (min(height[i], height[st.top()]) - diff) * (i-st.top()-1);
                ans += area;
                
            }
            
            st.push(i++);
        }
        
        return ans;
    }
};