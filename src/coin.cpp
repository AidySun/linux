#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {

	vector<int> v;

public:
	int coinChange(vector<int>& coins, int amount) {

		v.resize(amount);
		return dp(coins, amount);
	}

	int dp(vector<int>& coins, int amount) {

		if (amount < 0) return -1;
		if (amount == 0) return 0;

		if (v[amount - 1] != 0) {
			return v[amount-1];
		}

		int m = INT_MAX;
		for (auto c: coins) {
			int subCount = dp(coins, amount - c);
			if (subCount == -1) {
				continue;
			}
			m = min(m, subCount);
		}
		v[amount-1] = (m == INT_MAX) ? -1 : 1+m;

		return (m == INT_MAX) ? -1 1+m;
	}
};

class Solution1 {
	vector<int>count;
	int dp(vector<int>& coins, int rem) {
		if (rem < 0) return -1;
		if (rem == 0) return 0;

		cout << rem << ": ";
		for (int i = 0; i < count.size(); i++) {
			if (count[i] != 0 && count[i] != -1) {
				cout << "[" << i << "]=" << count[i] << ", ";
			}
		}
		cout << endl;

		if (count[rem - 1] != 0) return count[rem - 1];
		int Min = INT_MAX;
		for (int coin:coins) {
			int res = dp(coins, rem - coin);
			if (res >= 0 && res < Min) {
				Min = res + 1;
			}
		}
		count[rem - 1] = Min == INT_MAX ? -1 : Min;
		return count[rem - 1];
	}
public:
	int coinChange(vector<int>& coins, int amount) {
		if (amount < 1) return 0;
		count.resize(amount);
		return dp(coins, amount);
	}
};


/*
[186,419,83,408]
6249
*/
int main() {

	vector<int> v{186,419,83,408};
	Solution s;

	int i = s.coinChange(v, 6249);
	cout << " i = " << i << endl;
	return 0;
}
