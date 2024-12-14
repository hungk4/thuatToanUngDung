#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005;
int n, m;
int a[N][N];
int l[N], r[N], h[N], res=-1e8;
void input(){
   cin >> n >> m;
   for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
         cin >> a[i][j];
      }
   }
}
int maxRec(int i){
   for(int j = 1; j <= m; j++){
      l[j] = 0; r[j] = m+1;
      if(a[i][j] == 1) h[j] += 1;
      else h[j] = 0;
   }

   for(int j = 1; j <= m; j++){
      for(int v = j + 1; v <= m; v++){
         if(h[v] < h[j]){
            r[j] = v;
            break;
         }
      }
   }
   for(int j = m; j >= 1; j--){
      for(int v = j-1; v >= 1; v--){
         if(h[v] < h[j]){
            l[j] = v;
            break;
         }
      }
   }
   int ans = -1e8;
   for(int j = 1; j <= m; j++){
      if(h[j]){
         ans = max(ans, h[j] * (r[j] - l[j] - 1));
      }
   }
   return ans;
}

int main() {
   input();
   for(int i = 1; i <= n; i++){
      res = max(maxRec(i), res);
   }
   cout << res;
   return 0;
}