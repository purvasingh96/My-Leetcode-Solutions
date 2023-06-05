class Solution {
private:
    double slope(vector<int>& coord1, vector<int>& coord2){
        int x1 = coord1[0], y1 = coord1[1], x2 = coord2[0], y2 = coord2[1];
        if(x2 == x1) return INT_MAX;
        return (double)(y2-y1)/(x2-x1);
    }
public:
    bool checkStraightLine(vector<vector<int>>& coord) {
        if(coord.size()==2) return true;
        double m = slope(coord[0], coord[1]);
        for(int i=1;i<coord.size();i++){
            if(slope(coord[i], coord[i-1])!=m) return false;
        }
        
        return true;
    }
};