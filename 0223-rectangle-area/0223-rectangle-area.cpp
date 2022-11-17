class Solution {
private:
    int dist(int x1, int y1, int x2, int y2){
        int d1 = pow((x2-x1), 2);
        int d2 = pow((y2-y1), 2);
        return sqrt(d1+d2);
    }
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a1 = (ay2 - ay1) * (ax2-ax1);
        int a2 = (by2 - by1) * (bx2 - bx1);
        
        int l = min(ax2, bx2) - max(ax1, bx1);
        int w = min(ay2, by2) - max(ay1, by1);
        
        int a3=0;
        if(l > 0 && w>0) a3=(l*w);
        
        return a1 + a2 - a3;
    }
};