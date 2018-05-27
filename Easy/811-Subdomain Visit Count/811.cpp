class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        
        map<string, int> count;
        for(int i = 0; i < cpdomains.size(); ++i){
            int pos = cpdomains[i].find(" ");
            int n   = stoi(cpdomains[i].substr(0, pos));
            string domain = cpdomains[i].substr(pos+1);
            count[domain] += n;
            for(int j = 0; j < domain.size(); ++j){
               if(domain[j] == '.'){
                   count[domain.substr(j+1)] += n;
               }  
            }
        }
        vector<string> ans;
        for(map<string, int>::iterator it = count.begin(); it != count.end(); it++){
            ans.push_back(to_string(it->second) + " " + it->first);
        }
        return ans;
    }
};