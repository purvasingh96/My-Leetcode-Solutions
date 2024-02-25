class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> og = arr;
        sort(arr.begin(), arr.end());
        int pos=0;
        vector<int> rank;
        unordered_map<int, int> m;
        
        for(int i=0;i<arr.size();i++){
            if(m.find(arr[i]) == m.end()){
                pos+=1;
            } 
            m[arr[i]]  = pos;
        }
        
        for(auto x:og){
            rank.push_back(m[x]);
        }
        
        return rank;
    }
};