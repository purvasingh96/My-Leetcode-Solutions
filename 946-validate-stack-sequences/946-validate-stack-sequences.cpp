class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        
        int left=0, right=0;
        
        while(left<pushed.size() && right<popped.size()) {
            
            while(left< pushed.size() && pushed[left]!=popped[right]) {
                
                st.push(pushed[left]);
                left+=1;
                
            }
            
            if(left < pushed.size()) {
                st.push(pushed[left]);
                left+=1;
            }
            
            
            while(!st.empty() && right < popped.size() && st.top() == popped[right]) {
                
                st.pop();
                right+=1;
            }
            
            if(left >= pushed.size() && right < popped.size()) return false;
            
            
            
        }
        
        return true;
    }
};