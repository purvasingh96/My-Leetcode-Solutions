const double pi = M_PI;
class Solution {
private:
    double slope(vector<int>& point, vector<int>& location){
        int x = point[0] - location[0];
        int y = point[1] - location[1];
        
        double angle = atan2(y, x) * (180 / pi);
        //cout<<angle<<"\n";
        if(angle<0) angle += 360;
        return angle;
    }
    
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int pointsOnMe = 0, maxPoints=0;
        vector<vector<int>> pointsNotOnMe;
        
        for(auto point:points){
            if(point == location){
                pointsOnMe+=1;
            } else{
                pointsNotOnMe.push_back(point);
            }
        }
        
        vector<double> angles;
        for(auto point:pointsNotOnMe){
            double theta = slope(point, location);
            angles.push_back(theta);
            angles.push_back(theta+360);
        }
        
        sort(angles.begin(), angles.end());
        int i=0, j=0;
        while(j<angles.size()){
            while(j<angles.size() && angles[j]-angles[i] <= angle){
                j+=1;
            }
            
            maxPoints = max(maxPoints, (j-i));
            
            while(j<angles.size() && i<j && angles[j]-angles[i]>angle){
                i+=1;
            }
        }
        
        return pointsOnMe + maxPoints;
    }
};