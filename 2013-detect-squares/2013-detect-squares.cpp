#define pp pair<int, int>
class DetectSquares {
map<pair<int, int>, int> m;

public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        m[{point[0], point[1]}]+=1;
    }
    
    int count(vector<int> point) {
        int ans=0;
        for(auto it:m){
            auto p = it.first;
            if(p.first!=point[0] && p.second!=point[1] && abs(point[0] - p.first) == abs(point[1]-p.second)){
                pp a = {p.first, point[1]};
                pp b = {point[0], p.second};
                pp c = {p.first, p.second};
                
                ans += m[a]*m[b]*m[c];
            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */