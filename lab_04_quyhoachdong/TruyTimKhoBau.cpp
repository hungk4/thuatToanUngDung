#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
using iii = pair<pair<int, int>, int>;
using ll = long long;
int n;
iii a[N];
long long dp[N];
ll res = -1e18;
void input(){
   cin >> n;
   for(int i = 1; i <= n; i++){
      cin >> a[i].first.first >> a[i].first.second >>  a[i].second ;
   }
}
bool cmp(iii x, iii y){
   return x.first.first * x.first.second < y.first.first * y.first.second;
}
int main() {
   input();
   sort(a+1, a+n+1, cmp);

   for(int i = 1; i <= n; i++) dp[i] = a[i].second;

   
   for(int i = 1; i <= n; i++){
      for(int j = 1; j < i; j++){
         if(a[i].first.first >= a[j].first.first && a[i].first.second >= a[j].first.second){
            dp[i] = max(dp[i], a[i].second + dp[j]);
         }
      }
      res = max(res, dp[i]);
   }

   
   cout << res;

   return 0;
}