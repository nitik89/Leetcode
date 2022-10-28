class Solution
{
    public:
        int numSpecialEquivGroups(vector<string> &words)
        {
            unordered_set<string>st;
            for (auto x: words)
            {
                string a = "", b = "";
                for (int i = 0; i < x.size(); i++)
                {
                    if (i % 2 == 0)
                    {
                        a += x[i];
                    }
                    else
                    {
                        b += x[i];
                    }
                }
                sort(a.begin(), a.end());
                sort(b.begin(), b.end());
                string temp=a+' '+b;
                st.insert(temp);
            }
            
            return st.size();
        }
};