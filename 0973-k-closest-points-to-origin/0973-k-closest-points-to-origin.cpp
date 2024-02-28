class Solution {
private:
    int dist(vector<int>& points){
        return pow(points[0], 2) + pow(points[1], 2);
    }
    
    int partition(vector<vector<int>>& points, int start, int end){
        int pivot = dist(points[end]);
        int i=start-1;
        for(int j=start;j<end;j++){
            if(dist(points[j]) < pivot){
                i+=1;
                swap(points[i], points[j]);
            }
        }
        i+=1;
        swap(points[i], points[end]);
        return i;
    }
    
    void quickSort(vector<vector<int>>& points, int start, int end, int k){
        if(start<=end){
            int pivot = partition(points, start, end);
            if(k<pivot){
                quickSort(points, start, pivot-1, k);
            } else {
                quickSort(points, pivot+1, end, k);
            }
        }
    }
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        quickSort(points, 0, points.size()-1, k);
        vector<vector<int>> ans(points.begin(), points.begin()+k);
        return ans;
    }
};