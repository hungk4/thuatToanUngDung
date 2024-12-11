#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
int n, k;
int a[N], f[N];

void input(){
  cin >> n >> k;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++){
    f[i] = INT_MAX;
  }
}

int main() { 
  input();

  f[1] = 0, f[2] = abs(a[2] - a[1]);
  for(int i = 3; i <= n; i++){
    for(int j = 1; j <= k; j++){
      if(i - j >= 1){
        f[i] = min(f[i], abs(a[i] - a[i-j]) + f[i-j]);
      }
    }
  }
  cout << f[n];
  return 0;
}

// input 
// 5 3
// 5 1 1 4 7