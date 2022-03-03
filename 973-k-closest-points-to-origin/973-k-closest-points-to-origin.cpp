class Solution {
public:
    int getDist(vector<int> points) {
        int x = points[0];
        int y = points[1];
        return (pow(x, 2) + pow(y, 2));
    }
    
    vector<vector<int>> splitDistances(vector<int>& remaining, int mid, vector<double>& distances) {
        
        vector<vector<int>> res(2);
        vector<int>& closer = res[0];
        vector<int>& farther = res[1];
        
        for(int i:remaining) {
            if(distances[i] <= mid) {
                closer.push_back(i);
            } else {
                farther.push_back(i);
            }
        }
        
        return res;
        
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<double> distance;
        vector<int> remaining;
        double low =0, high = 0;
        
        for(int i=0;i<points.size();i++) {
            double d = getDist(points[i]);
            distance.push_back(d);
            high = max(high, d);
            remaining.push_back(i);
            
        }
        
        vector<int> closest;
        
        while(k) {
            
            double mid = low + (high - low)/2;
            vector<vector<int>> res = splitDistances(remaining, mid, distance);
            
            vector<int> closer = res[0];
            vector<int> farther = res[1];
            
            if(closer.size() > k) {
                remaining.swap(closer);
                high = mid;
            } else {
                
                k -= closer.size();
                closest.insert(closest.end(), closer.begin(), closer.end());
                remaining.swap(farther);
                low=mid;
                
            }
            
        }
        
        vector<vector<int>> final_res;
        
        for(auto i:closest) {
            final_res.push_back(points[i]);
        }
        return final_res;
            
            
            
            
            
            
            
            
            
            
            
            
            
        
    }
};