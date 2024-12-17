#include <bits/stdc++.h>
using namespace std;

const int N = 16;  // Giới hạn n tối đa (vì TSP có độ phức tạp O(n^2 * 2^n), nên chỉ cần n <= 16)
int c[N][N];  // Ma trận chi phí
int dp[N][1 << N];  // dp[i][mask] = chi phí tối thiểu khi thăm các thành phố theo mask và kết thúc tại thành phố i
int n;
int INF = 1e9;

// Hàm nhập dữ liệu
void input() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> c[i][j];  // Nhập ma trận chi phí
        }
    }
}

// Hàm tính toán TSP bằng DP với bitmask
int tsp() {
    // Thay thế memset bằng vòng lặp for để khởi tạo dp
    for (int i = 1; i <= n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            dp[i][mask] = INF;  // Khởi tạo mọi giá trị của dp[i][mask] là INF
        }
    }
    
    // Trạng thái ban đầu: chỉ thăm thành phố i, chi phí từ thành phố i đến chính nó là 0
    for(int i = 1; i <= n; i++) {
        dp[i][1 << (i-1)] = 0;  // Chỉ thăm thành phố i
    }

    // Duyệt qua tất cả các mask (tập các thành phố đã thăm)
    for(int mask = 1; mask < (1 << n); mask++) {
        for(int i = 1; i <= n; i++) {
            // Nếu thành phố i chưa được thăm trong mask thì bỏ qua
            if ((mask & (1 << (i-1))) == 0) continue;
            
            // Duyệt qua tất cả các thành phố j để tìm cách cập nhật dp[i][mask]
            for(int j = 1; j <= n; j++) {
                // Nếu thành phố j đã được thăm (trong mask) và j khác i
                if (mask & (1 << (j-1)) && j != i) {
                    int prev_mask = mask ^ (1 << (i-1));  // Mask trước khi thăm thành phố i
                    dp[i][mask] = min(dp[i][mask], dp[j][prev_mask] + c[j][i]);
                }
            }
        }
    }

    // Tìm chi phí tối thiểu khi thăm tất cả các thành phố và quay lại thành phố 1
    int res = INF;
    for(int i = 1; i <= n; i++) {
        res = min(res, dp[i][(1 << n) - 1] + c[i][1]);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    input();  // Nhập dữ liệu
    
    // Tính toán TSP và in kết quả
    int result = tsp();
    cout << result << endl;
    
    return 0;
}
