class Solution {
public:
    bool closeStrings(string str1, string str2) {
        if(str1.length()!=str2.length()) return false;
        unordered_map<char,int>mp1,mp2;
        for(int i=0;i<str1.length();i++){
            mp1[str1[i]]++;
            mp2[str2[i]]++;
        }
        for(auto x:mp1){
            int ele=x.first;
            if(mp2.find(ele)==mp2.end()) return false;
        }
        unordered_map<int,int>h1,h2;
        for(auto x:mp1){
            int freq=x.second;
            h1[freq]++;
        }
        for(auto x:mp2){
            int freq=x.second;
            h2[freq]++;
        }
        for(auto x:h1){
            int ele=x.first;
            if(h2.find(ele)==h2.end()) return false;
            if(h1[ele]!=h2[ele]) return false; 
        }
        return true;
    }
};