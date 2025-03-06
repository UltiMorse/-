#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rrep(i,n) for (int i = n - 1; i >= 0; --i)
using ll = long long;
using ull = unsigned long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> A(N + 1), B(N + 1), C(N + 1), D(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    vector<vector<int>> X(H + 2, vector<int>(W + 2)); // X[0][0], X[H + 1][W + 1] 
    for (int i = 1; i <= N; ++i) {
        X[A[i]][B[i]]++;
        X[A[i]][D[i] + 1]--;
        X[C[i] + 1][B[i]]--;
        X[C[i] + 1][D[i] + 1]++;
    }
    vector<vector<int>> S(H + 1, vector<int>(W + 1));
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            S[i][j] = S[i][j - 1] + X[i][j];
        }
    }
    for (int j = 1; j <= W; ++j) {
        for (int i = 1; i <= H; ++i) {
            S[i][j] = S[i - 1][j] + S[i][j];
        }
    }
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (j > 1) cout << " ";
            cout << S[i][j];
        }
        cout << "\n";
    }
    return 0;
}
