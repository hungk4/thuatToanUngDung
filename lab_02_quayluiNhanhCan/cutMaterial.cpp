#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 20;
int n, H, W, ok = 0;
int h[N], w[N];
int visited[20][20];
void input(){
   cin >> H >> W;
   cin >> n;
   for(int i = 1; i <= n; i++){
      cin >> h[i] >> w[i];
   }
}
int check(int k, int u, int I, int J){
   int hk = h[k];
   int wk = w[k];
   if(u == 1){
      hk = w[k];
      wk = h[k];
   }
   for(int i = I ; i <= I + hk - 1; i++){
      for(int j = J; j <= J + wk - 1; j++){
         if(visited[i][j] == 1) return 0;
      }
   }
   return 1;
}
void mark(int k, int u, int I, int J, int value){
   int hk = h[k];
   int wk = w[k];
   if(u == 1){
      hk = w[k];
      wk = h[k];
   }
   for(int i = I ; i <= I + hk - 1; i++){
      for(int j = J; j <= J + wk - 1; j++){
         visited[i][j] = value;
      }
   }
}
void Try(int k){
   for(int u = 0; u <= 1; u++){
      int hk = h[k];
      int wk = w[k];
      if(u == 1){
         hk = w[k];
         wk = h[k];
      }
      for(int i = 1; i <= H - hk + 1; i++){
         for(int j = 1; j <= W - wk + 1; j++){
            if(check(k, u, i, j)){
               mark(k, u, i, j, 1);
               if(k == n){
                  ok = 1;
                  return;
               } else Try(k+1);

               mark(k, u, i, j, 0);
            }
         }
      }
   }

}
int main() {
   input();
   Try(1);
   cout << ok ;
   return 0;
}