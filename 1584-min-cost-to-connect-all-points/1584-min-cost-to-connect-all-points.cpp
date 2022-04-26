class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int mstCost = 0;
        int edgesUsed = 0;
        
        // Track nodes which are visited.
        vector<bool> inMST(n);
        
        vector<int> minDist(n, INT_MAX);
        minDist[0] = 0;
        
        while (edgesUsed < n) {
            int currMinEdge = INT_MAX;
            int currNode = -1;
            
            // Pick least weight node which is not in MST.
            for (int node = 0; node < n; ++node) {
                if (!inMST[node] && currMinEdge > minDist[node]) {
                    currMinEdge = minDist[node];
                    currNode = node;
                }
            }
            
            mstCost += currMinEdge;
            edgesUsed++;
            inMST[currNode] = true;
            
            // Update adjacent nodes of current node.
            for (int nextNode = 0; nextNode < n; ++nextNode) {
                int weight = abs(points[currNode][0] - points[nextNode][0]) + 
                             abs(points[currNode][1] - points[nextNode][1]);
                
                if (!inMST[nextNode] && minDist[nextNode] > weight) {
                    minDist[nextNode] = weight;
                }
            }
        }
        
        return mstCost;
    }
};