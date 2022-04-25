class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,double>>vec;
        for(int i=0;i<quality.size();i++){
            vec.push_back({double( double(wage[i])/double(quality[i])),quality[i]});
        }
        sort(vec.begin(),vec.end());  
        
        priority_queue<double>pq;
        double sum=0;
        for(int i=0;i<k;i++){
            pq.push(vec[i].second);
            sum+=vec[i].second;
        }
        double ans=vec[k-1].first*sum;
        // cout<<ans<<" ";
        for(int i=k;i<quality.size();i++){
            double tp=pq.top();
            pq.pop();
            sum-=tp;
            sum+=vec[i].second;
            ans=min(ans,vec[i].first*sum);
            pq.push(vec[i].second);
        }
        return ans;
        
        
    }
};