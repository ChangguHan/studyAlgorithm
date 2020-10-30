/**
 BOJ 12015
 
 - 추상화
 어떤 순서를 띄엄띄엄 만족하는 배열의 최대길이를 구하는 문제
 
 - 개수가 작으면 DP로 O(N^2)로 해야하는데
 - 이번건 길이가 NlgN만 허락해줌
 
 - 각 원소돌면서
    - 마지막것보다 클경우 추가해주고
    - 아닐경우, 해당 원소보다 같은 위치에 대치해줌
        - 크기만 하면 안됨, 그러면 같은 원소가 중보고딜 수 있으니까
 
 - O(NlgN)
 
 
 - 이제 직접 lower_bound를 구현해보자
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int find(int st, int en, int val) {
    if(st >= en) return en;
        
    int mid = (st+en)/2;
    // 포함할때는 같을때 이전것을 검색해주고
    // 포함하지 않을때는, 같을때 이후것을 검색해줌
    // 그래야 리턴할때 해당값을 포함해주지 않음
    // 리턴할때는 다음것을 찾기 떄문에
    if(v[mid] >= val) {
        return find(st, mid, val);
    } else {
        return find(mid+1, en, val);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    
    int first; cin >> first;
    v.push_back(first);
    for(int i=1; i<N; i++) {
        int nxt; cin >> nxt;
        if(nxt > v.back()) v.push_back(nxt);
        else {
            int idx = find(0,v.size()-1, nxt);
            v[idx] = nxt;
        }
    }
    
    cout << v.size() << '\n';
    
    return 0;
}
