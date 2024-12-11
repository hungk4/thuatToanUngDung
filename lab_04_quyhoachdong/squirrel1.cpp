#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
int n;
int a[N], f[N];

void input(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
}

int main() { 
  input();
  f[1] = 0, f[2] = abs(a[2] - a[1]);
  for(int i = 3; i <= n; i++){
    f[i] = min(
        abs(a[i] - a[i-1]) + f[i-1],
        abs(a[i] - a[i-2]) + f[i-2]
    );
    
  }
  cout << f[n];
  return 0;
}

// input 
// 9
// 3 7 2 4 8 1 1 5 5