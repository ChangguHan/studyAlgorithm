/**
 BOJ 1920
 N개에 대해 M번 찾아야함
 O(NM) e10으로 시간초과
 
 이진탐색 O(MlgN)으로 끝내자
 
 범위 모두 찬에 들어가서 int 가능
 */

#include <iostream>
#include <algorithm>

using namespace std;

int nums[100010];

int search(int st, int en, int target) {
    if(st==en) {
        if(nums[st] == target) return 1;
        else return 0;
    }
    
    int mid = (st+en)/2;
    if(nums[mid] == target) return 1;
    else if(nums[mid] > target) return search(st, mid, target);
    else return search(mid+1, en, target);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M; cin >> N;
    for(int i=0; i<N; i++) cin >> nums[i];
    sort(nums, nums+N);
    cin >> M;
    while(M--) {
        int a; cin >> a;
        cout << search(0,N, a) << '\n';
    }
    return 0;
}
