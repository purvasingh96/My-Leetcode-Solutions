class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int ans=0, i=0;
        
        
        for(;i<height.size();i++){
            
            if(st.empty() || height[i] <= height[st.top()]){
                st.push(i);
            } else {
                
                while(!st.empty() && height[i] > height[st.top()] ){
                    
                    int j = st.top();st.pop();
                    
                    int diff = height[j];
                    
                    if(st.empty()) break;
                    
                    int h = min(height[i], height[st.top()]) - diff;
                    int w = i - st.top() - 1;
                    
                    ans += h*w;
                    
                }
                
                st.push(i);
                
            }
            
        }
        
        return ans;
    }
};