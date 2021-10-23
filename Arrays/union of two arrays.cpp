/* Union of two arrays.
   Author : Manvi Goyal
   Date modified : 23-10-2021 */

#include<bits/stdc++.h>

using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n], b[m];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  set < int > unionn;
  for (int i = 0; i < n; i++) {
    unionn.insert(a[i]);
  }
  for (int i = 0; i < m; i++) {
    unionn.insert(b[i]);
  }
  for (auto it = unionn.begin(); it != unionn.end(); ++it)
    cout << ' ' << * it;
}