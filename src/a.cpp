#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {

    int maxL = 0;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> sWords(wordDict.begin(), wordDict.end());
        for (auto& w: sWords) {
        	maxL = max(maxL, (int)(w.length()));
        }

        vector<vector<int>> bp(s.length());
        for (auto& b: bp) {
        	b = vector<int>(s.length(), -1);
        }

        for (auto w: sWords) {
        	cout << w << " ";
        }

        return backTracking(s, 0, s.length(), sWords, bp);
    }

    bool backTracking(const string& s, 
                        int start, int end, // [start, end)
                        unordered_set<string>& sWords, 
                        vector<vector<int>>& bp) {
    	cout << start << " ";
        if (start >= end) {
            cout << "true";
            return true;
        }
        
        for (int i = 0; i < end; i++) {
        	for (int j = 0; j < i; j++) {
        		if (bp[j][i] == 0 || 
        			(bp[j][i] != 1 && sWords.find(s.substr(j, i-j+1)) == sWords.end())) {
        			bp[j][i] = 0;
        			continue;
        		}

        		bp[j][i] = 1;
        		cout << "bp["<<start<<"]["<<i<<"]=1\n";
        		break;
        	}
        }
        return false;
    }
};

int main() {
	string s2 = "aaab";
	vector<string> v2 = {"aa", "aaa"};
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	vector<string> v {
		"b","aa","aaa","aaab","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"
	};
	Solution sol;

	bool r = sol.wordBreak(s, v);
	cout << " r : " << r << endl;


	return 0;
}