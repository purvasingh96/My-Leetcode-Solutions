class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        typedef pair<int, int> pp;
        auto comp = [&](const pp& a, const pp& b) {
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        };
        priority_queue<pp, vector<pp>, decltype(comp)> pq(comp);
        
        for(int i=0;i<matrix.size();i++){
            pq.push({i, 0});
        }
        
        pair<int, int> ans;
        while(k--){
            ans = pq.top();
            int row = ans.first, col = ans.second;
            pq.pop();
            if(col+1 < matrix[0].size()){
                pq.push({row, col+1});    
            }
        }
        
        return matrix[ans.first][ans.second];
    }
};