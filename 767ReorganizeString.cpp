class Solution {
public:
 string reorganizeString(string S) {
        
        int len = S.length();
        if(len ==0)
            return S;
        
        string str(len,'*');
        vector<pair<char,int>> vec(26,make_pair('*',0));
        
        for(int i=0;i<len;++i)
        {
            vec[S[i]-'a'].first = S[i];
            vec[S[i]-'a'].second++;
        }
     
        sort(vec.begin(),vec.end(),[](const auto &a,const auto &b){
           return a.second>b.second; 
        });
        
        int j=0;
        auto ele = vec[j];
        int cur_len = ele.second;
        int i=0;   
     
        while(i<len)
        {
            str[i] = ele.first;
            if(i!=0 && str[i] == str[i-1])
                return "";
            --cur_len;
            if(j<vec.size()-1 && cur_len == 0)
            {
                ele = vec[++j];
                cur_len = ele.second;
            }
            i += 2;
            if(i%2 == 0 && i>=len)
                i = 1;
        }
        
        return str;
    }
};
