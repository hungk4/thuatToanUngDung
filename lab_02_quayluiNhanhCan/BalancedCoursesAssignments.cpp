#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int m, n;
vector<int> T[MAX]; // T[i] is the list of teachers that can be assigned to course i​
bool conflict[MAX][MAX];
int x[MAX]; //  x[i] là giáo viên được phân công dạy môn i 
int load[MAX];
int res = 1e9;

void input(){
  cin >> m >> n;
  for(int t = 1; t <= m; t++){
    int k; cin >> k;
    for(int j = 1; j <= k; j++){
      int c; cin >> c;
      T[c].push_back(t);
    }
  }

  int k; cin >> k;
  for(int u = 1; u <= k; u++){
    int i, j; cin >> i >> j;
    conflict[i][j]=true;
    conflict[j][i]=true;
  }
}
int check(int k, int t){
  for(int i = 1; i <= k-1; i++){
    if(conflict[i][k] == 1 && x[i] == t) return 0;
  }
  return 1;

}
void solution(){
  int load_max = -1e9;
  for(int i = 1; i <= m; i++){
    load_max = max(load[i], load_max);
  }
  res = min(res, load_max);
}
void Try(int k){
  for(int i = 0; i < T[k].size(); i++){
    int t = T[k][i]; // giao vien t
    if(check(k, t)){
      x[k] = t;
      load[t] += 1;

      if(k == n){
        solution();
      } else {
        if(load[t] < res)
          Try(k+1);
      }

      load[t] -= 1;
    }

  }
}
int main() {
  input();
  Try(1);
  if(res == 1e9) cout << -1;
  else cout << res;
  return 0;
}