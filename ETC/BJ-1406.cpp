// 연결리스트 문제

#include <iostream>
#include <string>

using namespace std;

const int maxi = 500010;
int nxt[maxi];
int pre[maxi];
char eval[maxi];
int cur=0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(nxt,nxt+maxi, -1);
    fill(pre,pre+maxi, -1);
    fill(eval,eval+maxi, -1);

    string ip;
    cin >> ip;
    for(int i=1; i<=ip.size(); i++) {
        eval[i] = ip[i-1];
        if(i!=ip.size())nxt[i] = i+1;
        if(i!=1)pre[i] = i-1;
    }
    cur = ip.size();

    // pre[cur] = cur-1;

    int m;
    cin >> m;
    while(m--) {
        char o;
        cin >> o;
        if(o=='P') {
            char c;
            cin >> c;
            int tmp = cur;
            while(eval[cur]!=-1) cur++;
            eval[cur] = c;
            if(nxt[cur] !=-1) nxt[cur] = nxt[tmp];
            pre[cur] = tmp;
            pre[nxt[cur]] = cur;
            nxt[tmp] = cur;
            
            
        } else if(o=='L') {
            if(pre[cur]!=-1) cur = pre[cur];
        } else if(o=='B') {
            if(pre[cur]!=-1) {
                nxt[pre[cur]] = nxt[cur];
                pre[nxt[cur]] = pre[cur];
                eval[cur] = -1;
                cur = pre[cur];
            }
        } else if(o=='D') {
            if(nxt[cur]!=-1) cur = nxt[cur];
        }

    }
    int icur = 1;
    while(nxt[icur]!=-1) {
        cout << eval[icur];
        icur = nxt[icur];
    }
    cout << '\n';


    return 0;
}
