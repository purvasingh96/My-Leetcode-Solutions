class Solution {
private:
    bool willNeverMeet(int a, int b){
        return ((a<0 && b<0) || (a>0 && b>0) || a<0 && b>0);
    }
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        
        
        for(int i=0;i<nums.size();i++){
            if(st.empty() || willNeverMeet(st.top(), nums[i])){
                st.push(nums[i]);
            } else{
                bool push=false;
                while(!st.empty() && !willNeverMeet(st.top(), nums[i])){
                    
                    int top = st.top();
                    int weight_top = abs(st.top());
                    int weight_i = abs(nums[i]);
                    
                    // case 1: both have same weight
                    if(weight_top == weight_i){
                        push=false;
                        st.pop();
                        break;
                    } else if(weight_top > weight_i){
                        push=false;
                        break;
                    } else if(weight_top < weight_i){
                        push=true;
                        st.pop();
                    }
                    
                }
                
                if(push) st.push(nums[i]);
                
            }
        }
        
        int n = st.size();
        vector<int> res(n);
        int i=n-1;
        
        while(!st.empty()){
            res[i--] = st.top();
            st.pop();
        }
        
        return res;
        
    }
};