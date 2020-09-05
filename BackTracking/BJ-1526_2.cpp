#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> v;
int num=0;
void dfs(int len, int idx) {
    if(len==idx) {
        v.push_back(num);
        return;
    }
    num += pow(10,idx) *4;
    dfs(len,idx+1);
    num -= pow(10,idx) *4;
    num += pow(10,idx) *7;
    dfs(len,idx+1);
    num -= pow(10,idx) *7;
}
int main() {
    // 벡터만들기
    for (int i=1; i<7; i++) {
        num=0;
        dfs(i,0);
    }
    v.push_back(1000001);
    int ip;
    cin >> ip;
    sort(v.begin(), v.end());
    for (int i=0; i<v.size(); i++) {
        if(v[i] > ip) {
            cout << v[i-1] << '\n';
            break;
        }
    }
    return 0;
}