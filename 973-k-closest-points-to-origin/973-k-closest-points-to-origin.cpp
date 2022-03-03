class Solution {
public:
      int getDist(vector<int> points) {
        int x = points[0];
        int y = points[1];
        return (pow(x, 2) + pow(y, 2));
    }
    
    int pivotIdx(int left, int right) {
        int idx = left + (rand()%(right - left + 1));
        return idx;
    }
    
    // parition, quickSelect
    int partition(vector<vector<int>>& points, int left, int right) {
        
        int partitionIdx = left;
        int pi = pivotIdx(left, right);
        vector<int> pivot = points[pi];
        
        swap(points[pi], points[right]);
        
        for(int i=left;i<right;i++) {
            
            if(getDist(points[i]) <= getDist(pivot)) {
                
                swap(points[partitionIdx], points[i]);
                partitionIdx+=1;
                
            }
            
        }
        
        swap(points[partitionIdx], points[right]);
        return partitionIdx;
        
    }
    
    
    void quickSelect(vector<vector<int>>& points, int left, int right, int k) {
        
        while(left <= right) {
            
            int partitionIdx = partition(points, left, right);
            
            if(partitionIdx == k) return;
            else if(partitionIdx < k) left = partitionIdx + 1;
            else right = partitionIdx - 1;
            
        }
        
    }
    
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int left= 0, right=points.size()-1;
        quickSelect(points, left, right, k);
        return vector<vector<int>>(points.begin(), points.begin()+k);
        
    }
};