#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int n, m;
void input(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
}
int largestRectangleArea(vector<int>& heights) {
  stack<int> st;
  int size = heights.size();
  int leftSmall[size], rightSmall[size];

  // leffSmall
  for(int i = 0; i < size; i++){
    while(!st.empty() && heights[st.top()] >= heights[i]){
      st.pop();
    }
    if(st.empty()) leftSmall[i] = 0;
    else leftSmall[i] = st.top() + 1;
    st.push(i);
  } 

  while (!st.empty())
    st.pop();

  // rightSmall
  for(int i = size - 1; i >= 0; i--){
    while(!st.empty() && heights[st.top()] >= heights[i]){
      st.pop();
    }
    if(st.empty()) rightSmall[i] = size - 1;
    else rightSmall[i] = st.top() - 1;

    st.push(i);
  }

  int maxA = 0;
  for(int i = 0; i < size; i++){
    maxA = max(maxA, heights[i] * (rightSmall[i] - leftSmall[i] + 1));
  }
  return maxA;
}   

int maximalAreaOfSubMatrixOfAll(){
  int maxArea = 0;
  vector<int> heights(m, 0);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(a[i][j] == 1){
        heights[j]++;
      } else{
        heights[j] = 0;
      }
    }
    int area = largestRectangleArea(heights);
    maxArea = max(maxArea, area);
  }
  return maxArea;
}

int main() {
  input();
  cout << maximalAreaOfSubMatrixOfAll();
  return 0;
}
