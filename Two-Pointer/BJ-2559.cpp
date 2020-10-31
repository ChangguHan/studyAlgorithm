/**
 BOJ 2559
 
 - 슬라이딩 윈도우, 앞에꺼 뺴고 더해서 하면 될듯
 O(N)
 
 - INT 초가 웞음
 */

#include <iostream>

using namespace std;

int nums[100010];
int main() {
    int N,K; cin >> N >> K;
    for(int i=0; i<N; i++) {
        cin >> nums[i];
    }
    
    int window=0;
    for(int i=0; i<K; i++) {
        window += nums[i];
    }
    
    int maxv = window;
    
    
    for(int i=1; i<=N-K; i++) {
        // 빼고, 다음꺼 더해서 맥스값이랑 비교
        window -= nums[i-1];
        window += nums[i+K-1];
        maxv = max(maxv, window);
    }
    
    cout << maxv << '\n';
    
    return 0;
}
