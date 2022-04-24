// https://leetcode.com/problems/design-underground-system/
// 1396. Design Underground System

class Station {
public:
    int id;
    string stationName;
    int t;
    string mode;
    Station() {
        
    }
    Station(int id,string stationName,int t,string mode)
    {
        this->id = id;
        this->stationName = stationName;
        this->t = t;
        this->mode = mode;
    }
};


class UndergroundSystem {
public:
    // map<string,vector<pair<Station,Station>>> mp;
    map<int,pair<Station,Station>> person;
    map<pair<string,string>,vector<int>> cal;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        Station st(id,stationName,t,"checkIn");
        // bn[id] = st;
        person[id].first = st;
    }
    
    void checkOut(int id, string stationName, int t) {
        Station st=Station(id,stationName,t,"checkOut");
        person[id].second = st;
        int time = person[id].second.t - person[id].first.t;
        string source = person[id].first.stationName;
        string destination = stationName;
        cal[{source,destination}].push_back(time);
    }
    
    double getAverageTime(string startStation, string endStation) {
        vector<int> time = cal[{startStation,endStation}];
        double ans = 0;
        for(int t:time)
            ans = ans + t;
        ans /= time.size();
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
