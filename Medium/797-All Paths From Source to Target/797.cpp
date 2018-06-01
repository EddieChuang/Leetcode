class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    
        int source = 0;
        int target = graph.size() - 1;
        vector<int> path;
        findPath(graph, source, target, path);
          
        return ans;
    }
    
    void findPath(vector<vector<int>> graph, int source, int target, vector<int> path){
        
        path.push_back(source);
        if(source == target){
            ans.push_back(path);
            return;
        }
        
        vector<int> next = graph[source];
        for(int i = 0; i < next.size(); ++i){
            findPath(graph, next[i], target, path);
        }
    }

    vector<vector<int>> ans;
};