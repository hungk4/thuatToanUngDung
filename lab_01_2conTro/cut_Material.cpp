#include <bits/stdc++.h>
using namespace std;
int H, W, n;
int h[20];
int w[20];
int marked[20][20];
int ok = 0; 

void input(){
  cin >> H >> W;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> h[i] >> w[i];
  }
}
bool check(int wx, int hy, int k, int u){
  int hk = h[k], wk = w[k];
  if(u == 1){
    // xoay 90 hinh chu nhat
    hk = w[k];
    wk = h[k];
  }
  if((wx + wk) > W) return false;
  if((hy + hk) > H) return false;
  for(int i = wx; i <= wx + wk - 1; i++){
    for(int j = hy; j <= hy + hk - 1; j++){
      if(marked[i][j] ) return false;
    }
  }
  return true;
}
void doMark(int wx, int hy, int k, int u, int value){
    int hk = h[k], wk = w[k];
    if(u == 1){
      // xoay 90 hinh chu nhat
      hk = w[k];
      wk = h[k];
    }
  for(int i = wx; i <= (wx + wk - 1); i++){
    for(int j = hy; j <= (hy + hk - 1); j++){
      marked[i][j] = value;
    }
  }
}
void Try(int k){
  for(int u = 0; u <= 1; u++){
    int hk = h[k], wk = w[k];
    if(u == 1){
      // xoay 90 hinh chu nhat
      hk = w[k];
      wk = h[k];
    }

    for(int wx = 0; wx <= (W - wk); wx++){
      for(int hy = 0; hy <= (H - hk); hy++){
        if(check(wx, hy, k, u)){
          doMark(wx, hy, k, u, 1);

          if(k == n){
            ok = 1;
          } else Try(k+1);

          doMark(wx, hy, k, u, 0);
        }
      }
    }
  }
}
int main() {
  input();
  memset(marked, 0, sizeof(marked));
  Try(1);
  cout << ok;
  return 0;
}