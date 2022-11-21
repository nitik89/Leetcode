class Solution
{
    public:
        int intersectionSizeTwo(vector<vector < int>> &in)
        {
            sort(in .begin(), in .end(), [& ](vector<int> &a, vector<int> &b)
            {
                if (a[1] == b[1])
                {
                    return a[0] < b[0];
                }
                return a[1] < b[1];
	});

            vector<int> vec;
            vec.push_back(in[0][1] - 1);
            vec.push_back(in[0][1]);

            for (int i = 1; i < in .size(); i++)
            {

                int s = in[i][0], e = in[i][1];

                if (vec[vec.size() - 1] == s)
                {
                    vec.push_back(e);
                }
                else if (vec[vec.size() - 1] < s)
                {
                    vec.push_back(e - 1);
                    vec.push_back(e);
                }
                else if(vec[vec.size()-2] < s){
                    vec.push_back(e);
                }
                
                
            }
            return vec.size();
        }
};