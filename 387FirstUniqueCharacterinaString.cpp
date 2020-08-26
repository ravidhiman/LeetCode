class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> hMap;
        int n = s.length();
        int ans = -1;
        for(int i=n-1;i>=0;i--)
        {
            hMap[s[i]]++;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(hMap[s[i]] == 1)
                ans = i;
        }
        return ans;
    }
};
