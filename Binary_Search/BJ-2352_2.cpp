/**
 BOJ 2352
 - 반도체 소자가 연결될때의 규칙, 이전 숫자보다 낮은게 나올수 없음
 - 계속 증가하는 수만 나오는데, 떨어질 수 있음, LCS
 */


#include <iostream>
#include <vector>

using namespace std;
vector<int> v;


int find(int st, int en, int target) {
    if(st==en) return en;
    
    int mid = (st+en)/2;
    if(v[mid] < target) return find(mid+1, en, target);
    else return find(st, mid, target);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    for(int i=0; i<N; i++) {
        int a; cin >> a;
        if(i==0) v.push_back(a);
        
        if(v.back() < a) v.push_back(a);
        else {
            v[find(0,v.size()-1,a)] = a;
        }
    }
    
    cout << v.size() << '\n';
    return 0;
}
