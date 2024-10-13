#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int a[1005][1005];
int d[1005][1005];
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
int n, m, r, c;

int maze(int r, int c){
  queue<ii> q;
  q.push({r, c});
  a[r][c] = 1;
  while(!q.empty()){
    ii x = q.front();
    q.pop();
    int i = x.first;
    int j = x.second;

    if(i == 1 || i == n || j == 1 || j == m ){
      return d[i][j] + 1;
    } 

    for(int k = 0; k < 4; k++){
      int di = i + dx[k];
      int dj = j + dy[k];
      if(a[di][dj] == 0){
        d[di][dj] = d[i][j] + 1;
        q.push({di, dj});
        a[di][dj] = 1;
      }
    }
  }
  return -1;
}
int main() {
  cin >> n >> m >> r >> c;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> a[i][j];
    }
  }
  cout << maze(r, c);
  return 0;
}