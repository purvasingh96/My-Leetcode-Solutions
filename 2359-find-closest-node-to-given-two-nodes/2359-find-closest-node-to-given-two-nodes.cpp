class Solution {
private:
    
    void dfs(vector<int>& edges, vector<int>& res, int node){
        int i=node, count=0;
        int n = edges.size();
        
        vector<bool> visited(n, false);
        while(i!=-1 && !visited[i]){
            res[i] = count;
            visited[i]=true;
            i=edges[i];
            count+=1;
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        
        vector<int> res1(n, -1);
        vector<int> res2(n, -1);
        
        dfs(edges, res1, node1);
        if(node1==node2) res2=res1;
        else dfs(edges, res2, node2);
        
        int i=0;
        int minval=INT_MAX;
        int minidx=-1;
        while(i<n){
            if(res1[i]!=-1 && res2[i]!=-1){
                
                int val = max(res1[i], res2[i]);
                if(val < minval){
                    minval = val;
                    minidx=i;
                }
                
                
            }
            
            i+=1;
        }
        
        return minidx;
    }
};