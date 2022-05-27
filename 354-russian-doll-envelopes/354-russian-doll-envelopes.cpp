class MyCompare{
public:
    bool operator()(vector<int>& a, vector<int>& b){
        if(a[0] != b[0]){
            return a[0]<b[0];
        }
        
        return a[1] > b[1];
    }
};
class Solution {
private:
    int binarySearch(vector<int> sub, int e){
        int left=0, right=sub.size()-1;
        while(left<right){
            int mid = left + (right-left)/2;
            
            if(sub[mid]==e) return mid;
            else if(sub[mid] < e) {
                left = mid+1;
            } else{
                right=mid;
            }
        }
        
        return left;
    }
public:
    int maxEnvelopes(vector<vector<int>>& e) {
          sort(e.begin(), e.end(), [](const vector<int>& a, const vector<int>& b){
              if(a[0]!=b[0]) return a[0] < b[0];
              return a[1]>b[1];
          });
          vector<int> sub;
        sub.push_back(e[0][1]);
        
        for(int i=1;i<e.size();i++){
            if(e[i][1] > sub.back()){
                sub.push_back(e[i][1]);
            } else{
                int j = binarySearch(sub, e[i][1]);
                sub[j] = e[i][1];
            }
        }
        
        return sub.size();
    }
};