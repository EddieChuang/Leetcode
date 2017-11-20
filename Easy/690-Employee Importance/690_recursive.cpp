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
        
        for(int i = 0; i < employees.size(); ++i)
        {
            if(employees[i]->id == id)
            {
                int importance = 0;
                for(int j = 0; j < employees[i]->subordinates.size(); ++j)
                    importance += getImportance(employees, employees[i]->subordinates[j]);

                return importance += employees[i]->importance;
            }
        }
    }
};