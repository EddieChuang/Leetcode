/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        
        queue<int> q;
        q.push(id);
        int importance = 0;
        while(!q.empty())
        {
            int ID = q.front();
            q.pop();
            
            for(int i = 0; i < employees.size(); ++i)
            {
                if(employees[i]->id == ID)
                {
                    for(int j = 0; j < employees[i]->subordinates.size(); ++j)   
                        q.push(employees[i]->subordinates[j]);
                    importance += employees[i]->importance;
                }
            }
        }
        return importance; 
    }
};