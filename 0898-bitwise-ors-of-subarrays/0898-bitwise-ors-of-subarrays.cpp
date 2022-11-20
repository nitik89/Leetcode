class Solution
{
    public:
        int subarrayBitwiseORs(vector<int> &arr)
        {
            unordered_set<int> st;
            for (int i = 0; i < arr.size(); i++)
            {
                int c = arr[i];
                st.insert(c);
                int p = 0;
                int j = i - 1;
                while (j >= 0 && c != p)
                {

                    c |= arr[j];
                    p |= arr[j];
                    st.insert(c);
                    j--;
                }
                // cout<<j<<" ";
                
            }
            return st.size();
        }
};