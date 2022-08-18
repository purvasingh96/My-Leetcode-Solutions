class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        int target = arr.size()/2;
        priority_queue<int> pq;
        
        for(auto x:arr) {
            freq[x]+=1;
            if(freq[x] >= target) return 1;
        }
        
        
        for(auto x:freq){
            pq.push(x.second);
        }
        
        int count=0, ans=0;
        
        while(count<target){
            int top = pq.top();
            pq.pop();
            
            if(count+top >= target){
                return ans+1;
            } else {
                count+=top;
                ans+=1;
            }
        }
        
       return ans;
        
    }
};