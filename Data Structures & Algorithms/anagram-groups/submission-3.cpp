class Solution {
public:
    void check(vector<string>& strs, string s, vector<vector<string>> &ans, int i, int n, vector<int> &vis){
        vector<string> temp;
        temp.push_back(s);
        for(int j = i; j < n; j++){
            if(s.size()!=strs[j].size()) continue;
            unordered_map<char, int> mp1;
            for(auto it: s) mp1[it]++;
            if(!vis[j]){
                for(auto it: strs[j]){
                    if(mp1.contains(it)){
                        mp1[it]--;
                    }
                    if(mp1[it] == 0){
                        mp1.erase(it);
                    }
                }
                if(mp1.size() == 0){
                    temp.push_back(strs[j]);
                    vis[j] = 1;
                }
            }
        }
        ans.push_back(temp);
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<int> vis(strs.size(), 0);
        for(int i =0; i < strs.size(); i++){
            if(!vis[i]){
                vis[i] = 1;
                check(strs, strs[i], ans, i, strs.size(), vis);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
