class MyCompare{
public:
    // row, col, val
    bool operator()(const vector<int>& a, const vector<int>& b){
        return a[2] > b[2];
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>, vector<vector<int>>, MyCompare> pq;
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i=0;i<m;i++){
            pq.push({i, 0, matrix[i][0]});
        }
        
        
        int count=0;
        int ans=0;
        while(count!=k){
            auto f = pq.top();
            int row = f[0], col=f[1], val=f[2];
            ans = val;
            pq.pop();
            count+=1;
            if(col+1<n) pq.push({row, col+1, matrix[row][col+1]});
        }
        
        return ans;
    }
};