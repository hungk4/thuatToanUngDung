#include <bits/stdc++.h>
using namespace std;
// O(2^n)
const int N = 1e4+5;
int a[N], x[N];
int n, res = 0;

void input(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  memset(x, -1, sizeof(x));
}

void solution(){
  int cnt = 0, last = INT_MIN;
  for(int i = 1; i <= n; i++){
    if(x[i] == 1 && a[i] > last){
      cnt++;
      last = a[i];
    } 
  }
  res = max(res, cnt);
}

void Try(int k){
  for(int u = 0; u <= 1; u++){
    x[k] = u;
    if(k == n){
      solution();
    } else Try(k+1);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  Try(1);
  cout << res;
  return 0;
}