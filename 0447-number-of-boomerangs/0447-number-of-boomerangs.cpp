class Solution
{
    public:
        double calDist(int x1, int y1, int x2, int y2)
        {
            int xDiff = abs(x1 - x2);
            int yDiff = abs(y1 - y2);
            return sqrt(xDiff *xDiff + yDiff *yDiff);
        }
    int numberOfBoomerangs(vector<vector < int>> &points)
    {
        int cnt = 0;
        unordered_map<double, map<pair<int, int>, int>> mp;
        for (int i = 0; i < points.size(); i++)
        {

            for (int j = 0; j < points.size(); j++)
            {
                if (i != j)
                {

                    int x1 = points[i][0];
                    int y1 = points[i][1];
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    double dis1 = calDist(x1, y1, x2, y2);
                    mp[dis1][
                    {
                        x2,
                        y2
                    }]++;
                }
            }
        }
       	// for(auto x:mp){
       	//     cout<<x.first<<" "<<x.second<<"\n";
       	// }
        for (int i = 0; i < points.size(); i++)
        {

            for (int j = 0; j < points.size(); j++)
            {

                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                double dis1 = calDist(x1, y1, x2, y2);
                int d = mp[dis1][
                {
                    x2,
                    y2
                }];
                if (d > 1)
                    cnt += (d - 1);
            }
        }
        return cnt;
    }
};