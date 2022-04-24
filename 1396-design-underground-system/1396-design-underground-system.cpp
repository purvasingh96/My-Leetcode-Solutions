class UndergroundSystem {
private:
    map<int, pair<string, int>> cache;
    map<vector<string>, vector<int>> m;
    
public:
    UndergroundSystem() {
        //cache.resize(1000000);    
    }
    
    void checkIn(int id, string stationName, int t) {
        auto info = make_pair(stationName, t);
        cache[id] = info;
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkInInfo = cache[id];
        
        cache[id] = {};
        
        int time_diff = t - checkInInfo.second;
        
        vector<string> locations;
        locations.push_back(checkInInfo.first);
        locations.push_back(stationName);
      
        m[locations].push_back(time_diff);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double avg = 0.0;
        vector<string> locations;
        locations.push_back(startStation);
        locations.push_back(endStation);
        
        for(auto t:m[locations]) {
            
            avg += t;
            
        }
        
        return avg/(m[locations].size());
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */