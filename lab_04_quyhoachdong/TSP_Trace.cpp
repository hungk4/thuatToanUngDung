#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 20;
int n;
int c[N][N];
int dp[N][1 << N];
void input(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++) cin >> c[i][j];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  for(int i = 1; i <= n; i++){
    for(int s = 0; s <= (1 << n) - 1; i++)
      dp[i][s] = -1e8;
  }

  
  return 0;
}