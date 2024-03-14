class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> m;
        vector<int> og = arr;
        sort(arr.begin(), arr.end());
        int rank=0, n=arr.size();
       
        for(int i=0;i<arr.size();i++){
            if(m.find(arr[i])==m.end()){
                rank+=1;    
            }
            m[arr[i]] = rank;
        }
        vector<int> ans;
        for(auto x:og){
            ans.push_back(m[x]);
        }
        
        return ans;
        
    }
};