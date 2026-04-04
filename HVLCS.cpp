#include <vector>
#include <iostream>
#include <map>

using namespace std;

int main() {

    // map of values per character
    unordered_map<char, long long> val;

    string A, B;
    cin >> A >> B;

    int n = A.size();
    int m = B.size();

    // DP[i][j] = max value of common subsequence of A[i:], B[j:]
    vector<vector<long long>> DP(n+1, vector<long long>(m+1, 0));

    // TODO: DP Algorithm
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {

            if (A[i] == B[j]) {
                DP[i][j] = val[A[i]] + DP[i+1][j+1];
            } else {
                DP[i][j] = max(DP[i+1][j], DP[i][j+1]);
            }
        }
    }

    // TODO: String Reconstruction?



    return 0;
}