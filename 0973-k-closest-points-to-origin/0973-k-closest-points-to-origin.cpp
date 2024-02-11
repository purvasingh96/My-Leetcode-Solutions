class Solution {
private:
    int partition(vector<pair<int, int>>& data, int start, int end){
        int pivot = data[end].second;
        int i = start-1;
        
        for(int j=start;j<end;j++){
            if(data[j].second <= pivot){
                swap(data[++i], data[j]);
            }
        }
        
        swap(data[i+1], data[end]);
        return i+1;
    }
   
    void quickSelect(vector<pair<int, int>>& data, int k, int start, int end){
        if(start<=end){
            int pivot = partition(data, start, end);
            
            if(k == pivot){
                return;
            } else if(k < pivot){
                quickSelect(data, k, start, pivot-1);
            } else if(k>pivot){
                quickSelect(data, k, pivot+1, end);
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
        quickSelect(data, k, 0, data.size()-1);
        
        vector<vector<int>> res;
        for(int i=0;i<k;i++){
            res.push_back(points[data[i].first]);
        }
        return res;
    }
};