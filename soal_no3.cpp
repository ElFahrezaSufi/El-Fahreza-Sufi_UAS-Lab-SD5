#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int calculateDepth(int employee, map<int, vector<int>>& managers, map<int, int>& memo) {
    if (memo.count(employee)) {
        return memo[employee];
    }

    int maxDepth = 0;

    for (int subordinate : managers[employee]) {
        maxDepth = max(maxDepth, calculateDepth(subordinate, managers, memo));
    }
    
    memo[employee] = 1 + maxDepth;
    return memo[employee];
}

int main() {
    int n;
    
    cout << "Masukkan Jumlah Karyawan: ";
    cin >> n;

    vector<int> rootEmployees;
    map<int, vector<int>> managers;
    
    cout << "Masukkan nilai p(i):" << endl;
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        if (p == -1) {
            rootEmployees.push_back(i);
        } else {
            managers[p].push_back(i);
        }
    }

    int maxGlobalDepth = 0;
    map<int, int> memo;

    for (int root : rootEmployees) {
        int currentDepth = calculateDepth(root, managers, memo);
        maxGlobalDepth = max(maxGlobalDepth, currentDepth);
    }

    cout << "Jumlah minimum grup yang harus dibentuk: " << maxGlobalDepth << endl;

    return 0;
}