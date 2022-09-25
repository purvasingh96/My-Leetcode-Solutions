class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int curr=0, ans=0;
        
        while(curr<height.size()){
            
            while(!st.empty() && height[curr] > height[st.top()]){
                
                int top = st.top();
                st.pop();
                
                if(st.empty()) break;
                
                int w = curr - st.top() - 1;
                int h = min(height[curr], height[st.top()]) - height[top];
                
                ans+= w*h;
                
            }
            
            st.push(curr);
            curr+=1;
        }
        
        return ans;
    }
};