#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int mod = 1e9 + 7;
int n, k1, k2;
int dp[N][1];
// dp[i][0] so cach xep tu ngay 1-> i voi i la nghi
// dp[i][1] ____________________________ i la ngay cuoi cung cua dot lam viec
void input(){
  cin >> n >> k1 >> k2;
}

int main() {
  input();
  dp[0][0] = 1;
  dp[0][1] = 1;

  for(int i = 1; i <= n; i++){
    dp[i][0] = dp[i-1][1];
    for(int k = k1; k <= k2; k++){
      if(i - k >= 0){
        dp[i][1] += dp[i-k][0];
      }
    }
  }
  for(int u = 0; u <= 1; u++){
    for(int i = 1; i <= n; i++){
      cout << dp[i][u] << ' ';
    }
    cout << endl;
  }
  cout << dp[n][0] + dp[n][1];
  return 0;
}