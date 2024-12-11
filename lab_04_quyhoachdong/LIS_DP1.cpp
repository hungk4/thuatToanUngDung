#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int a[N], dp[N], n;
void input(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
}

void solution(){
  for(int i = 1; i <= n; i++){
    dp[i] = 1;
  }
  int res = 1;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j < i; j++){
      if(a[i] > a[j]){
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    res = max(res, dp[i]);
  }
  cout << res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solution();
  return 0;
}