#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int c[N][N];
int d[N], visited[N];
int n;
int res = INT_MAX;
void input(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin >> c[i][j];
    }
  }
}


int main() {
  input();
  cout << res;
  return 0;
}