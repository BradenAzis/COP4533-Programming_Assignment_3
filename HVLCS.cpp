#include <vector>
#include <iostream>
#include <map>
#include <chrono>


using namespace std;

int main() {
    // start time
    auto start = chrono::high_resolution_clock::now();


    // num chars in alphabet
    int k;
    cin >> k;

    // map of values per character
    unordered_map<char, long long> val;

    // loop through the chars and their corresponding value
    for (int i = 0; i < k; i++) {
        char c;
        long long v;
        cin >> c >> v;
        val[c] = v;
    }

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

    // Reconstruction
    string result = "";
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (A[i] == B[j]) {
            // Must check if this choice achieves DP[i][j]
            if (DP[i][j] == val[A[i]] + DP[i+1][j+1]) {
                result.push_back(A[i]);
                i++;
                j++;
            } else {
                // Character matches but DP chooses skipping
                if (DP[i+1][j] >= DP[i][j+1]) 
                    i++;
                else 
                    j++;
            }
        } else {
            // Move to better direction
            if (DP[i+1][j] >= DP[i][j+1]) i++;
            else j++;
        }
    }

    // Output
    cout << DP[0][0] << "\n";
    cout << result << "\n";

    // end time
    auto end = chrono::high_resolution_clock::now();
    double t = chrono::duration<double, milli>(end - start).count();

    // NOTE: uncomment if wanting to view/plot runtime
    // cerr << t << endl;



    return 0;
}