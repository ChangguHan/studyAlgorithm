#include <iostream>
#include <deque>

using namespace std;

int N,M;
deque<int> dq;
int cnt=0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int tmp;
    for (int i=1; i<=N; i++) dq.push_back(i);
    
    int index;
    while (M--) {
        cin >> tmp;

        for(int i=0; i<dq.size(); i++) {
            if(dq[i] == tmp) index = i;
        }

        if(index <= dq.size()-index) {
            while(1) {
                // cout << dq.front() << '\n';
                // cout << tmp << '\n';
                // cout << (dq.front() == tmp) << '\n';
                // cout << '\n';
                if(dq.front() == tmp) {
                    dq.pop_front();
                    break;
                }
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
        } else {
            while(1) {
                if(dq.front() == tmp) {
                    dq.pop_front();
                    break;
                }
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }
    }
    cout << cnt;

    return 0;
}