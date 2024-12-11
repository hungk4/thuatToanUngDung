#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longest_increasing_subsequence(const vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    
    // Mảng lis[i] lưu độ dài LIS kết thúc tại arr[i]
    vector<int> lis(n, 1);
    
    // Duyệt qua tất cả các phần tử trong mảng
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    
    // Độ dài LIS là giá trị lớn nhất trong mảng lis
    return *max_element(lis.begin(), lis.end());
}

int main() {
    vector<int> arr ;
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
      int x; cin >> x;
      arr.push_back(x);
    }
    
    cout << "Longest Increasing Subsequence Length: " << longest_increasing_subsequence(arr) << endl;
    
    return 0;
}
