#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n;
long long a[N];
long long dp[N][2], res = -1e18; 
// dp[i][1] tong le lien tiep lon nhat ket thuc tai i
// dp[i][2] tong chan _____________________________ i
void input(){
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
}
int main() {
  input();
  if(abs(a[1]) % 2 == 0){
    dp[1][2] = a[1];
    dp[1][1] = -1e18;
  } else{
    dp[1][2] = -1e18;
    dp[1][1] = a[1];
  }

  for(int i = 2; i <= n; i++){
    if(abs(a[i]) % 2 == 0){
      dp[i][2] = max(a[i], a[i] + dp[i-1][2]);
      dp[i][1] = max((long long)-1e18, a[i] + dp[i-1][1]);
    } else {
      dp[i][2] = max((long long)-1e18, a[i] + dp[i-1][1]);
      dp[i][1] = max(a[i], a[i] + dp[i-1][2]);
    }

  }

  for (int i = 1; i <= n; i++) {
    if (dp[i][2] > res) {
      res = dp[i][2];
    }
  }
  if(res == -1e18){
    cout << "NOT_FOUND";
  } else cout << res;
  
  return 0;
}