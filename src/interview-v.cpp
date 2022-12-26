/*
from Yuan Yao (internal) to Everyone:    1:35  PM
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note:
The solution set must not contain duplicate triplets.
Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::vector;
using std::cout;
using std::endl;
using std::map;
using std::pair;

struct iTriple {
	int i;
	int j;
	int k;
};

class C {
  public:
    vector<vector<int>> solution(const vector<int>& v) {
      if (v.empty()) return result;

      MEM mem(v.size());
      for (auto& m: mem) {
      	m = PAIR(v.size(), pair<bool,int>(false, 0));
      }

      for (int i = 0; i < v.size()-2; i++) {
        find_v(v, i, mem);
      }

      return result;
    }

  private:
    typedef vector<pair<bool, int>> PAIR;
    typedef vector<vector<pair<bool, int>>> MEM;
    vector<vector<int>> result;
    set<iTriple> s;


    void find_v(const std::vector<int>& v, int index, MEM& mem) {
    	for (int i = index+1; i < v.size(); i++) {
	    	for (int j = index+1; j < v.size(); j++) {

    		if (i == j) continue;

    		if (!mem[i][j].first) {
    			mem[i][j] = pair<bool,int>(true, v[i]+v[j]);
    			mem[j][i] = pair<bool,int>(true, v[i]+v[j]);
    		}

    		if (v[index] + mem[i][j].second == 0) {
    			result.push_back({v[index], v[i], v[j]});
    			if (v[i] < v[j])
    			iTriple(min())
    		}
    	}
    }
    }
};


int main() {

  vector<int> v{-1, 0, 1, 2, -1, -4};
  for (auto i: v) {
    cout << i << " ";
  }
  cout << endl;

  C c;
  auto r = c.solution(v);

  cout << "resutl size: " << r.size() << endl;
  for (auto i: r) {
    for (auto j: i) {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}

