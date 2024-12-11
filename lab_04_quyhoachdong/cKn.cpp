#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
// cach 1 : dung nghich dao module
// cach 2 : quy hoach dong
// nCk = n-1Ck-1 + n-1Ck
const int N = 1005;
int dp[N][N]; // dp[4][3] la 4C3
int main() {
  for(int i = 0; i <= 1000; i++){
    for(int j = 0; j <= i; j++){
      if(j == 0 || j == i){
        dp[i][j] = 1;
      } else{
        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
        
      }
    }
  }
  cout << dp[4][3];
  return 0;
}

//0 --> 1
//1 --> 1 1
//2 --> 1 2 1
//3 --> 1 3 3 1
//4 --> 1 4 6 4 1
//5 --> 1 5 10 10 5 1