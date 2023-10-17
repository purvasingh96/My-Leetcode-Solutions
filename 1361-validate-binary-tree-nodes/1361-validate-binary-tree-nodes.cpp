class Solution {

public:
    bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
        vector<int> indegree(n, 0);
        int totalNodes=n;
        
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> m;
        for(int i=0;i<n;i++){
           m[i].push_back(left[i]);
            m[i].push_back(right[i]);
            if(left[i]!=-1) indegree[left[i]]+=1;
            if(right[i]!=-1) indegree[right[i]]+=1;
        }
        
        int root=-1, c=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                c+=1;
                if(c>1) return false;
                else {
                    root=i;
                }
            }
        }
        
        if(root==-1) return false;
        
        queue<int> q;
        q.push(root);
        visited[root] = true;
        totalNodes-=1;
        
        while(!q.empty()){
            int f = q.front();
            q.pop();
            
            int l = m[f][0], r = m[f][1];
            if(l!=-1){
                if(!visited[l]){
                    visited[l] = true;
                    totalNodes-=1;
                    q.push(l);
                } else {
                    return false;      
                }
               
            }
            
            if(r!=-1){
                if(!visited[r]){
                    totalNodes-=1;
                    visited[r]=true;
                    q.push(r);
                } else {
                    return false;
                }
                
            }
        }
        
        
        return totalNodes == 0;
    }
};