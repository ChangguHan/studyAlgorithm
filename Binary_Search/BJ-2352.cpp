/**
 BOJ 2352
 
 - 모두 탐색해보는 방법?
    - 2^N, 불가
 - 꼬이는 경우
    - 어떤 순서에 어긋날때
    - 점점 증가하는 순으로 나와야함, 만약 이전값으로 돌아갈 경우에, 꼬이게됨
    - LIS 문제와 다르지 않음
 
 - 이걸 생각해낼수 있을까?
    - 안될것같음, 이런 문제를 볼때 LIS를 유도하도록 연습하는 수밖에 없음
    - 즉 이런 문제를 많이 접해서, 비슷한 문제라고 생각될떄 유추할 수 있도록
 
 - 거꾸로 하는 문제도 한번 풀어보자
 
 - inner bound 다시한번
 
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> v;
int find(int st, int en, int target) {
    if(st==en) return en;
    
    int mid = (st+en)/2;
    if(v[mid] < target) {
        return find(mid+1, en, target);
    } else {
        return find(st, mid, target);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    
    int a; cin >> a;
    v.push_back(a);
    
    for(int i=1; i<N; i++) {
        int a; cin >> a;
        if(v.back() <a) v.push_back(a);
        else {
            int idx = find(0,v.size()-1, a);
            v[idx] = a;
        }
    }
    
    cout << v.size() << '\n';
    
    
    
    return 0;
}
