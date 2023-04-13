class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int left=0, right=0;
        int m = pushed.size(), n = popped.size();
        stack<int> st;
        
        while(left<m && right<n){
            while(left<m && pushed[left]!=popped[right]){
                st.push(pushed[left]);
                left+=1;
            }
            //left-=1;
            if(pushed[left] == popped[right]) st.push(pushed[left]);
            //left+=1;
            while(right<m && !st.empty() && st.top() == popped[right]){
                st.pop();
                right+=1;
            }
            if(left>=m && !st.empty() && st.top()!=popped[right]){
                    return false;
            }
            left+=1;
        }
        
        while(right<n){
            if(st.top()!=popped[right]) return false;
            st.pop();
            right+=1;
        }
        
        return true;
    }
};