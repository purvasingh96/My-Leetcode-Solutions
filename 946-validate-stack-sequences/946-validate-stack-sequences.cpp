class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        
        int left=0, right=0;
        
        for(int left=0;left<pushed.size();left++) {
            
            st.push(pushed[left]);
            
            while(!st.empty() && right < popped.size() && st.top() == popped[right]) {
                
                st.pop();
                right+=1;
            }
            
        }
        
        return st.empty();
    }
};