/**
 BOJ 1300
 - 그냥 수 다 넣으면, O(N^2), e10으로 시간초과
 - 숫자 K에서 작은거 확인해보는 방법 O(N)
 - 이걸 이진탐색으로하면? >> lgN
 - 시간복잡도 O(NlgN)
 - 구체적 방법
    - 이진탐색으로 해당숫자보다 작거나 같은수를 구함
    - 이 숫자가 K보다 크거나 같은수를 구함, inner bound
 */

#include <iostream>
#include <algorithm>

using namespace std;
int N,K;
int cal2(int mid) {
    int rs=0;
    for(int j=1; j<=N; j++) {
        rs += min(N, mid/j);
    }
    return rs;
}
int cal(int st, int en, int num ) {
    if(st==en) return en;
    int mid = (st+en)/2;
    
    if(cal2(mid) < num) {
        return cal(mid+1, en, num);
    } else {
        return cal(st, mid, num);
    }
}
int main() {
    cin >> N >> K;
    cout << cal(1,1e9, K) << '\n';
    return 0;
}
