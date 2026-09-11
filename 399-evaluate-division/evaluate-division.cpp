class Solution {
public:

    void dfs(unordered_map<string, vector<pair<string, double>>> &gph, unordered_set<string> &vis, string src, string dst, double product, double & ans) {
        vis.insert(src);
        if(src == dst){
            ans = product;
            return;
        }
        for(auto &it : gph[src]){
            string nextsource = it.first;
            double val  = it.second;

            if(vis.find(nextsource) == vis.end()){
                dfs(gph, vis, nextsource, dst, (product * val), ans);
            }
        }
        return;

    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;

        //1. Create Graph
        unordered_map<string, vector<pair<string, double>>> gph;
        int n = equations.size();
        int i=0;
        for(auto &it : equations) {
            string src = it[0];
            string dst = it[1];
            double v = values[i++];

            gph[src].push_back({dst, v});
            gph[dst].push_back({src, 1.0 / v});
        }

        //2.Iterate in query and append the res;
        
        for(auto &it : queries) {
            string src = it[0];
            string dst = it[1];
            double ans = -1;
            unordered_set<string> vis;

            if(gph.find(src) == gph.end() || gph.find(dst) == gph.end()) {
                res.push_back(ans);
            } else {
                double product = 1.0;
                //3. call dfs
                dfs(gph, vis, src, dst, product, ans);
                res.push_back(ans);
            }
        }
        return res;
    }
};