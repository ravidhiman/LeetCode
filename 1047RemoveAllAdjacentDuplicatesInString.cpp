class Solution {
public:
    string removeDuplicates(string S) {
        string stk;
        size_t len = S.length();
        for(size_t i=0;i<len;i++)
        {
            if(stk.length() == 0)//empty
            {
                stk.push_back(S[i]);
                continue;
            }
            char top = stk[stk.length()-1];
            if(top == S[i])
                stk.pop_back();
            else
                stk.push_back(S[i]);
        }
        return stk;
    }
};
