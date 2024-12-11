#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int m, n;
vector<int> T[MAX];
int conflict[MAX][MAX];
int x[MAX];
int res = 1e9;
int load[MAX];

void input(){
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        int k; cin >> k;
        for(int j = 1; j <= k; j++){
            int c; cin >> c;
            T[c].push_back(i);
        }
    }
    int k ; cin >> k;
    for(int u = 1; u <= k; u++){
        int i, j; cin >> i >> j;
        conflict[i][j] = 1;
        conflict[j][i] = 1;
    }

}
int check(int k, int t){
    for(int i = 1; i <= k - 1; i++){
        if(conflict[i][k] == 1 && x[i] == t){
            return 0;
        }
    }
    return 1;
}
void solution(){
    int load_max = -1e9;
    for(int t = 1; t <= m; t++){
        load_max = max(load_max, load[t]);
    }

    res = min(load_max, res);
}
void Try(int k){
    for(int i = 0; i < T[k].size(); i++){
        int t = T[k][i];
        if(check(k, t)){
            x[k] = t;
            load[t]++;

            if(k == n){
                solution();
            } else{
                if(load[t] < res)
                    Try(k+1);
            }

            load[t]--;
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