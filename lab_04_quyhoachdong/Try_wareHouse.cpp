#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005;
int n, T, d;
int a[N];
int t[N];
int totalTime, f, res = -1e8;
vector<int> x;
void input(){
  cin >> n >> T >> d;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++){
    cin >> t[i];
  }
}
int check(int i){
  if(totalTime + t[i] > T) return 0;
  return 1;
}
void solution(){
  f = 0;
  for(auto i : x){
    f += a[i];
  }
  res = max(res, f);
}
void Try(int k){
  if(k == 0){
    for(int i = 1; i <= n; i++){
      if(check(i)){
        x.push_back(i);
        totalTime += t[i];

        if(totalTime == T || i == n){
          solution();
        }else{
          Try(i);
        }

        x.pop_back();
        totalTime -= t[i];

      }
    }
  }
  for(int i = k + 1; i <= k + d && i <= n; i++){
    if(check(i)){
      x.push_back(i);
      totalTime += t[i];

      if(totalTime == T || i == n){
        solution();
      }else{
        Try(i);
      }

      x.pop_back();
      totalTime -= t[i];

    }

  }
}
int main() {
  input();
  Try(0);
  cout << res;
  return 0;
}