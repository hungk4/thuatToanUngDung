#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 5;  // Chọn giá trị maxN lớn hơn số nhiệm vụ tối đa
int n, m;
vector<int> a[maxN];  // Danh sách kề
int d[maxN];  
int deg[maxN];  // Bậc vào của các nhiệm vụ
int t[maxN]; // thoi gian hoan thanh cua i

void input() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> d[i];  // Đọc thời gian hoàn thành của từng nhiệm vụ
  }
  for (int i = 1; i <= m; i++) {
    int x, y; 
    cin >> x >> y;  
    a[x].push_back(y);
    deg[y]++;  
  }
}


int topoBfs() {
  queue<int> q;
  
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) {
      q.push(i);
    }
  }

  vector<int> topo;
  
  int t_trc = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    topo.push_back(u);
    t[u] = t_trc + d[u];
    t_trc = t[u];
    for (int v : a[u]) {
      deg[v]--;  
      if (deg[v] == 0) {
        q.push(v);  
      }
    }
  }
  if(topo.size() < n) cout << "ton tai chu trinh";
  else {
    for(int x : topo){
      cout << x << ' ';
    }
  }
  cout << endl;

  // Tìm thời gian hoàn thành cuối cùng của dự án
  int res = INT_MIN;
  for (int i = 1; i <= n; i++) {
    cout << t[i] << ' ';
    res = max(res, t[i]);  
  }
  cout << endl;
  return res;
}

int main() {
  input();  
  cout << topoBfs();  
  return 0;
}
