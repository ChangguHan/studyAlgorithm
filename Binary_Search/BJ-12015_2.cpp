/**
 
 BOJ 12015
 
 연속적이지 않아도되는, 어떤 순서만 맞으면 상관없는 수열 구하는 문제인 LCS
 - 수가 작으면 dp로 이전 값들 중 작은 수중 가장 길었던 것으로 구하면 됨 N^2
 - 수가 클 경우에, 이진탐색으로 이전것중에 같거나 큰값에 대치
    - 큰것에만 대치하면 안됨, 그럼 중복되는 것이 발생할 수 있음, outer_bound 사용해야함
 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int find(int st, int en, int target) {
    if(st==en) return en;
    
    int mid = (st+en)/2;
    // 현재는 같거나 클때 이렇게 해줌
    // mid와 target이 같을때, 위를 탐색해주는게 아니라 그 값을 찾아주는거지
    
    // 만약 그 위를 찾고싶을때는 같을떄 위를 찾아주면됨
    if(v[mid] < target) {
        return find(mid+1, en, target);
    } else {
        return find(st, mid, target);
    }
}

// 만약 작거나 같은 값을 구해야한다면
int find2(int st, int en, int target) {
    if(st==en) return en;
    
    int mid = (st+en)/2;
    if((st+en)%2!=0) mid++;
    
    // 현재는, 같을떄 이전의 값을 찾아주니까
    // 작은값이고
    // 같거나 이전의 값을 찾아줄떄는, v[mid] <= target을 사용하면 됨
    if(v[mid] < target) {
        return find(mid, en, target);
    } else {
        return find(st, mid-1, target);
    }
    
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    int a; cin >> a; v.push_back(a);
    for(int i=1; i<N; i++) {
        int n; cin >> n;
        if(n > v.back()) v.push_back(n);
        else {
            int idx = find(0,v.size()-1, n);
            v[idx] = n;
        }
    }
    cout << v.size() << '\n';
    return 0;
}
