/*
 BOJ 1300
 N으로 배열 만들면, 시간초과남
 
 int 가능
 
 어떤 수일때, N번 돌아서 그 밑에 몇개있는지 확인할 수 있음
 그럼 어떤수를 이분탐색하면서 각각 몇개있는지 확인하자
 */

#include <iostream>

using namespace std;
int minv = 1e9;
int N,K;
void search(int st, int en, int num) {
    if(st>en) return;
    int mid = (st+en)/2;
    int cnt=0;
    for(int i=1; i<=N; i++) {
        cnt += min(N,mid/i);
    }
    if(cnt >= num) {
        minv = min(mid, minv);
        return search(st, mid-1, num);
    } else {
        return search(mid+1, en, num);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    search(0,K,K);
    cout << minv << '\n';
    return 0;
}
