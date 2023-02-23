class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        deque<int> q;
        q.push_back(nums2[0]);
        
        for(int i=1;i<nums2.size();i++){
            while(q.size()!=0 && nums2[i]>q.back()){
                    nextGreater[q.back()]=nums2[i];
                    q.pop_back();
            } 
            q.push_back(nums2[i]);
        }
        
        vector<int> res;
        for(auto num:nums1){
            if(nextGreater.find(num)!=nextGreater.end()){
                res.push_back(nextGreater[num]);
            } else {
                res.push_back(-1);
            }
        }
        
        return res;
    }
};