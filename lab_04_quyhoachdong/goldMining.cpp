#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
const int N = 1e6 + 5;
int n, l1, l2;
int a[N];
ll res = -1e18;
ll dp[N];
void input(){
  cin >> n >> l1 >> l2;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
}


int main() {
  input();
  priority_queue<ii> q;
	q.push({0, 0});
  for(int i = 1; i <= n; i++){
    if(i - l1 > 0) q.push({dp[i-l1], i-l1});
    while(!q.empty()){
        if(q.top().second < i - l2) q.pop();
        else break;
    }
    dp[i] = a[i] + q.top().first;
    
  }
  for(int i = 1; i <= n; i++){
    res = max(res, dp[i]);
  }
  cout << res;

  // for(int i = 1; i <= n; i++){
  //   dp[i] = a[i];
  //   for(int k = l1; k <= l2; k++){
  //     if(i - k >= 0)
  //       dp[i] = max(a[i] + dp[i-k], dp[i]);
  //   }
  //   res = max(res, dp[i]);
  // }
  // for(int i = 1; i <= n; i++){
  //   cout << dp[i] << ' ';
  // }
  // cout << res;
  return 0;
}
