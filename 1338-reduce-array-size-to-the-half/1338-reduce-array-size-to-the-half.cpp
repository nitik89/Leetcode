class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mp;
        for(auto i:arr)
            mp[i]++;
        for(auto i:mp)
            pq.push(make_pair(i.second,i.first));
        int count=0;
        int ans=0;
        while(count<arr.size()/2)
        {
            count+=pq.top().first;
            pq.pop();
            ans++;
        }
        return ans;
    }
};