#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005;
int n, T, d;
int a[N];
int t[N];
int res = -1e8;
int dp[N][N]; // dp[i][j] la luong huong hang lay duoc lon nhat khi xet i  va tong thoi gian lay la j
vector<int> x;
void input(){
  cin >> n >> T >> d;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++){
    cin >> t[i];
  }
}

int main() {
  input();
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= T; j++){
      if(j >= t[i]){
        dp[i][j] = a[i];
        int max_pre = 0;
        for(int k = 1; k <= d; k++){
          if(i >= k){
            max_pre = max(max_pre, dp[i-k][j-t[i]]);
          }
        }
        dp[i][j] += max_pre;
      }
    }
  }
  int res = -1e8;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= T; j++){
      cout << dp[i][j] << ' ';
      if(dp[i][j] > res) res = dp[i][j];
    }
    cout << endl;
  }
  cout << res;

  return 0;
}