class Solution {
private:
    vector<int> root;
public:
    /*
     Idea here is to divide vertices into two independent subsets which are not           having any edge between them, now we are iterating through all edges of a           single vertex. As there should not be any edge between final two indepedent         subsets we are making all edges of this vertex into single group, before that       we are checking if the source vertex and destination vertex has same parent         if yes, they belong to same disjoint set and dividing these vertices into two       independent subsets is not possible
     */  
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        root.resize(n);
        for(int i=0;i<n;i++) {
            root[i]=i;
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<graph[i].size();j++) {
                
                if(find(i) == find(graph[i][j])) {
                    // adjacent vertices can;t be in the same set
                    return false;
                }
                // union all vertices that are i's neighbours.
                union1(graph[i][0], graph[i][j]);
                
            }
        }
        
        return true;
        
    }
    
    int find(int x) {
        if(root[x] == x) return x;
        return root[x] = find(root[x]);
    }
    
    void union1(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        
        if(rx!=ry) {
            root[ry] = rx;
        }
    }
};