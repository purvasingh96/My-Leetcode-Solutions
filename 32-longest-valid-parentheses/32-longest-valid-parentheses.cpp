class Solution {
private:
    int merge(vector<pair<int, int>> nums){
        int max_len=INT_MIN, n = nums.size();
        
        if(nums.size()==0) return 0;
        if(nums.size()==1) return (nums[0].second-nums[0].first+1);
        
        int i=0;
        
        while(i<n){
            
            
            
            int cur_len = nums[i].second - nums[i].first+1;
            
            if(i+1<n && nums[i+1].first - nums[i].second == 1){
                while(i<n-1 && nums[i+1].first - nums[i].second == 1) {
                    cur_len += (nums[i+1].second - nums[i+1].first+1);
                    i+=1;
                }

            }
            
            max_len = max(max_len, cur_len);
            
            i+=1;
        }
        
        return max_len;
    }
    
public:
    int longestValidParentheses(string s) {
        
        if(s.length()<2) return 0;
        
        stack<int> st;
        vector<pair<int, int>> idx;
        int n = s.length(), i=0;
        
        if(s[0] == ')') {
            while(i<n && s[i]==')'){
                i+=1;
            }
        }
        
        for(i;i<s.length();i++){
            
            if(s[i] == '('){
                st.push(i);
            } else{
                
                if(st.empty()) {
                    continue;
                }
                
                if(idx.size()==0) idx.push_back({st.top(), i});
                
                else{
                    
                    auto x = idx.back();
                    auto y = make_pair(st.top(), i);

                    while(idx.size()!=0 && y.first<= x.first && y.second>=x.second) {
                        idx.pop_back();
                        if(idx.size()!=0) x = idx.back();
                    }
                    
                    idx.push_back(y);
                    
                }
                
                
                
                st.pop();
            }
            
        }
        
        return merge(idx);
        
    }
};