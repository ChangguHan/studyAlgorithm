/**
 BOJ 12015 LCS
 
- 수가작으면 O(N^2)로 dp 계산하면 되는데
- 수가 크므로 불가능
 
 - 끝에 숫자보다 클경우, 추가해주고
 - 작을경우, 해당 숫자보다 작거나 같은값에 교체해주면됨
    - 이때 lowerbound 사용
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> rs;
int find(int st, int en, int target) {
    if(st==en) return en;
    
    int mid = (st+en)/2;
    if(rs[mid] < target) {
        return find(mid+1, en, target);
    } else {
        return find(st, mid, target);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    
    
    for(int i=0; i<N; i++) {
        int a; cin >> a;
        if(i==0) rs.push_back(a);
        
        if(rs.back() < a) rs.push_back(a);
        else {
//            vector<int>::iterator it = lower_bound(rs.begin(), rs.end(), a);
//            *it =a;
            // lower_bound 직접 구현
            rs[find(0,rs.size()-1, a)] = a;
        }
    }
    
    cout << rs.size() << '\n';
    return 0;
}
