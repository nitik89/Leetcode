

class Solution
{
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
    {
        vector<int>myrow(500,0);
        vector<int>mycol(500,0);
        int n = rowConditions.size();
        int m = colConditions.size();
       
        vector<vector<int>> rg(k + 1), cg(k + 1);
        for (int i = 0; i < n; i++)
        {
            myrow[rowConditions[i][1]]++;
            rg[rowConditions[i][0]].push_back(rowConditions[i][1]);
        }
        for (int i = 0; i < m; i++)
        {
            mycol[colConditions[i][1]]++;
            cg[colConditions[i][0]].push_back(colConditions[i][1]);
        }
       
        queue<int> cq, rq;
        for (int i = 1; i <= k; i++)
        {
            if (myrow[i] == 0)
                rq.push(i);
            if (mycol[i] == 0)
                cq.push(i);
        }
        vector<int> rows(k + 1), cols(k + 1);
        int c = 0;
        while (cq.size())
        {
            int i = cq.front();
            cq.pop();
            cols[i] = c++;
            for (auto j = begin(cg[i]); j != end(cg[i]); j++)
            {
                --mycol[*j];
                if (mycol[*j] == 0)
                {
                    cq.push(*j);
                }
            }
        }
        if (c != k)
            return vector<vector<int>>();
        c = 0;
        while (rq.size())
        {
            int i = rq.front();
            rq.pop();
            rows[i] = c++;
            for (auto x:rg[i])
            {
                --myrow[x];
                if (myrow[x] == 0)
                {
                    rq.push(x);
                }
            }
        }
        if (c != k)
            return vector<vector<int>>();
        vector<vector<int>> ret(k, vector<int>(k, 0));
        for (int i = 1; i <= k; i++)
        {
            ret[rows[i]][cols[i]] = i;
        }
        return ret;
    }
};