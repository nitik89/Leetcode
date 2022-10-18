class Solution
{
    public:
        string countAndSay(int n)
        {
            if (n == 1)
            {
                return "1";
            }
            string x = countAndSay(n - 1);
            x.push_back(' ');
            string ans;
            int i = 0;
            while (i < x.size())
            {
                if (x[i] == ' ')
                {
                    break;
                }
                int cnt = 1;
                char curr = x[i];
                while (i + 1 < x.size() && x[i] == x[i + 1])
                {
                    cnt++;
                    i++;
                }
                i++;
                ans.push_back(cnt + '0');
                ans.push_back(curr);
            }
            return ans;
        }
};