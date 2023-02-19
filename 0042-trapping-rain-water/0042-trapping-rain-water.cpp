class Solution {
public:
    int trap(vector<int>& height) {
        stack<pair<int, int>> st;
        int i=0, n = height.size(), area=0;
        
        while(i<n && height[i]==0){
            i+=1;
        }
        if(i>=n) return 0;
        st.push({height[i], i});
        i+=1;
        
        while(i<n && !st.empty()){
            while(i<n && height[i]<st.top().first){
                st.push({height[i], i});
                i+=1;
            }
            
            int diff = st.top().first;
            st.pop();
            
            if(i<n){
                if(!st.empty()){
                    area += (min(height[i], st.top().first)-diff)*(i-st.top().second-1);
                }
                
            }
            if(st.empty()) {
                st.push({height[i], i});
                i+=1;
            }
        }
        
        return area;
    }
};