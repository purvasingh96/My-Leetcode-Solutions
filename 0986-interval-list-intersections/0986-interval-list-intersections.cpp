class Solution {
private:
    bool hasIntersection(vector<int> s1, vector<int> s2){
        int start1 = s1[0], end1 = s1[1];
        int start2 = s2[0], end2 = s2[1];
        
        // 2 intersects 1
        // complete
        if(end1 < start2 || end2 < start1){
            return false;
        }
        return true;
    }
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& s1, vector<vector<int>>& s2) {
        int i=0, j=0;
        vector<vector<int>> res;
        while(i<s1.size() && j<s2.size()){
            
                // intersection
                vector<int> ans = {max(s1[i][0], s2[j][0]), min(s1[i][1], s2[j][1])};
                if(ans[0] <= ans[1]){
                    res.push_back(ans);
                }
                    if(s1[i][1] < s2[j][1]) {
                        i+=1;
                    } else{
                        j+=1;
                    }
                
             
        }
        return res;
    }
};