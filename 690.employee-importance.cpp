/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 */

// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
	int ans;
    int getImportance(vector<Employee*> employees, int id) {
			unordered_map<int , Employee*> ans_map;
			for(auto elem : employees){
				ans_map[elem->id] = elem;
			}
			dfs(ans_map, id);
			return ans;
    }
		void dfs(unordered_map<int, Employee*> ans_map, int id){
			Employee* temp = ans_map[id];
			ans += temp->importance;
			if(temp->subordinates.empty()) return;

			for(int i = 0; i < temp->subordinates.size(); ++i){
				dfs(ans_map, temp->subordinates[i]);
			}

		}
};
// @lc code=end
