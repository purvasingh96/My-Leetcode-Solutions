class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> cinData;
    unordered_map<string, pair<double, double>> checkoutData;
    
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        cinData[id] = {stationName, t};
    }
    
    void checkOut(int id, string end, int t) {
        auto checkinValues = cinData[id];
        cinData.erase(id);
        string start =  checkinValues.first;

        string key = start+"->"+end;
        checkoutData[key].first += (t - checkinValues.second);
        checkoutData[key].second += 1;
        
    }
    
    double getAverageTime(string s, string e) {
        string key = s+"->"+e;
        double totalTime = checkoutData[key].first;
        double trips = checkoutData[key].second;
        
        return totalTime/trips;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */