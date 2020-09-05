#include <iostream>
#include <deque>

using namespace std;



int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, idx;
        cin >> N >> idx;
        deque<int> q;
        int cnt=0;

        while(N--) {
            int en;
            cin >> en;
            q.push_back(en);
        }

        while(1) {
            
            
            
            int sw = true;
            for(int i=1; i<q.size(); i++) {
                if(q[0] < q[i]) sw = false;
            }
            
            if(sw) {
                cnt++;
                if(idx==0) break;
                q.pop_front();
                idx--;
                

            } else {
                q.push_back(q[0]);
                q.pop_front();
                if(idx==0) idx = q.size()-1;
                else  idx--;
            }

            
        }
        cout << cnt << '\n';
    }


    return 0;
}