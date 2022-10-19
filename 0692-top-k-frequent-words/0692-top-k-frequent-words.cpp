class Solution {
public:
   class comp
	{
	//The main reason for calling the compare function was that as I had created a max-heap of pair<int,string> my top elements in the example 1 would be {2,love} and then {2,i} and we wanted the solution to be in lexicographical order so this compare function was needed.
		public:
		bool operator() (pair<int,string> &a, pair<int,string> &b)
		{
			if(a.first==b.first&&a.second>b.second)
			{
				return true;
			}
            else if(a.first<b.first){
            return true;
            }
            return false;
			
		}
   };
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int>mp;
        for(auto x:words){
            mp[x]++;
        }
         priority_queue<pair<int,string>,vector<pair<int,string> > , comp  > pq;
        for(auto x:mp){
         
             pq.push({x.second,x.first});
        }
        vector<string>ans;
        while(k!=0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
     
};