#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int c[N][N];
int dp[N][1 << N], visited[N];

// tinh toan dp[i][s] bang cach
// 1. xet tat ca trang thai cua s
// 2. xet tung thanh i la diem den cuoi
// 3. tim hanh trinh toi uu tu cac thanh j den i (j nam trong tap s)

int n, res = INT_MAX;
void input(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin >> c[i][j];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  for(int i = 1; i <= n; i++){
    for(int s = 0; s <= (1 << n) - 1; s++){
      dp[i][s] = 1e8;
    }
  }

  // trang thai ban dau: chi tham thanh pho 1, va ket thuc tai 1 luon
  dp[1][1] = 0;


  // duyet qua tat ca trang thai s (s bieu dien tap thanh pho da duoc tham vi du 0101 la 1 va 3 da dc tham)
  for(int s = 1; s <= (1 << n) - 1; s++){
    for(int i = 1; i <= n; i++){
      // neu thanh pho i ko co trong s bo qua
      if((s & (1 << (i-1))) == 0) continue; 

      // duyet qua cac thanh pho j de den i
      for(int j = 1; j <= n; j++){
        if((s & ( 1 << (j-1))) == 0) continue; // neu thanh pho j chua tham thi bo qua

        int pre_s = s ^ (1 << (i-1)); // trang thai truoc do chua den i
        /*
        vi du xet i = 3
        s = 0101 
        pre_s = 0101 XOR 0100 = 0001
        */


        // dp[i][s] la gia tri nho nhat trong tuyen tap s ma ket thuc tai i
        // vi du i = 3
        // s = 1101
        // xet dp[3][s] = min dp[1][1001] + c[1][3], dp[4][1001] + c[4][3])
        dp[i][s] = min(dp[i][s], dp[j][pre_s] + c[j][i]);

      }
    }
  }
  for(int i = 2; i <= n; i++){
    res = min(res, dp[i][(1<<n) - 1] + c[i][1]);
  }
  cout << res;
  
  return 0;
}