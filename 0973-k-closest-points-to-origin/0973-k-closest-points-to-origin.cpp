class Solution {
private:
    int partition(vector<pair<int, int>>& data, int start, int end){
        int pivot = data[end].second;
        int i=start-1;
        
        for(int j=start;j<end;j++){
            if(data[j].second <= pivot){
                swap(data[++i], data[j]);
            }
        }
        
        swap(data[++i], data[end]);
        return i;
    }
    
    void quickSort(vector<pair<int, int>>& data, int k, int start, int end){
        if(start<=end){
           int pivot = partition(data,start, end);
        
            if(pivot == k){
                return;
            } else if(k<pivot){
                quickSort(data, k, start, pivot-1);
            } else if(k > pivot){
                quickSort(data, k, pivot+1, end);
            } 
        }
        
    }
    
     int distance(vector<int>& point){
       return pow(point[0], 2) + pow(point[1], 2);
   }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, int>> data;
        
        for(int i=0;i<points.size();i++){
            data.push_back({i, distance(points[i])});
        }
        quickSort(data, k, 0, points.size()-1);
        
        vector<vector<int>> res;
        for(int i=0;i<k;i++){
            int idx = data[i].first;
            res.push_back(points[idx]);
        }
        return res;
    }
};