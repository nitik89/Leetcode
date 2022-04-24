class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>station;
    //id --> startStation, startTime
    map<pair<string,string>,pair<int,int>>avg;
    //startStation,endStation ---> total duration, total journeys
   UndergroundSystem(){
       avg.clear();
       station.clear();
   }
    void checkIn(int id, string stationName, int t) {
        station[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
       
            pair<string,int>p1=station[id];
            //calculate duration
            int startTime=p1.second;
            string startStation=p1.first;
        int cal=t-startTime;
            if(avg.find({startStation,stationName})==avg.end()){
                avg[{startStation,stationName}]={cal,1};
            }
        else{
            pair<int,int>p2=avg[{startStation,stationName}];
            int totalTime=p2.first;
            int totalJourneys=p2.second;
            avg[{startStation,stationName}]={totalTime+cal,totalJourneys+1};
        }
    
    }
    
    double getAverageTime(string startStation, string endStation) {
        int totalTime=avg[{startStation,endStation}].first;
        int totalJourney=avg[{startStation,endStation}].second;
        double average=(double)totalTime/(double)totalJourney;
        return average;
        
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */