class Solution {
    
struct ListNode{
    
    int depth;
    int inVal, outVal;
    vector<ListNode*> next;
    ListNode(int inV, int outV) : inVal(inV), outVal(outV), depth(1) {}
};    

public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        vector<ListNode*> inPath, outPath;
        vector<ListNode*> graph;
        
        // BUILD GRAPH
        for(int i = 0; i < pairs.size(); ++i){
            ListNode *node  = new ListNode(pairs[i][0], pairs[i][1]);
            for(int j = 0; j < graph.size(); ++j){
                if(graph[j]->outVal < node->inVal)
                    graph[j]->next.push_back(node);
                else if(graph[j]->inVal > node->outVal)
                    node->next.push_back(graph[j]);
            }
            graph.push_back(node);
        }
        
        
        for(int i = 0; i < graph.size(); ++i){
            if(graph[i]->depth == 1)
                maxDepth = max(maxDepth, DFS(graph[i]));
            else
                maxDepth = max(maxDepth, graph[i]->depth);
        }
            
        return maxDepth;
    }
    
    int DFS(ListNode* node){
        
        if(node->depth > 1)
            return node->depth;
        
        for(int i = 0; i < node->next.size(); ++i)
            node->depth = max(node->depth, DFS(node->next[i]) + 1);
        return node->depth;
    }
    
    int maxDepth = 0;
    
};