class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        // map to store key vs coordinates
        //cout<<board.size();
        unordered_map<int, pair<int, int>> m;
        int n = board.size(), c=1;
        bool rev=false;
        
        for(int i=n-1;i>=0;i--){
            if(rev){
                for(int j=n-1;j>=0;j--){
                    m[c++] ={i, j};
                }    
            } else {
                for(int j=0;j<n;j++){
                    m[c++] ={i, j};
                }
            }
            
            rev = !rev;
        }
        
        vector<int> dist(n*n+1, -1);
        queue<int> q;
        
        dist[1]=0;
        q.push(1);
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(int next=curr+1;next<=min(curr+6, n*n);next++){
                int row = m[next].first, col = m[next].second;
                
                int dst = board[row][col] != -1 ? board[row][col]: next;
                
                if(dist[dst]==-1){
                    dist[dst] = dist[curr]+1;
                    q.push(dst);
                }
                
            }
        }
        
        return dist[n*n];
        
    }
};