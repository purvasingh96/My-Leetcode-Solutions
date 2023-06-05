class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int, int> indegree;
        vector<int> ans;
        
        for(auto e:edges){
            int u = e[0], v=e[1];
            indegree[v]+=1;
        }
        
        for(int i=0;i<n;i++){
            if(indegree.find(i)==indegree.end()){
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};