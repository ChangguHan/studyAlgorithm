#include <iostream>
#include <queue>


using namespace std;

int N,a,b;
queue<int> q;
int cnt=0;

int main() {
    cin >> N >> a >> b;
    if(a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    for (int i=1; i<=N; i++) q.push(i);

    int tmpa,tmpb;
    bool returnflag = false;

    while(1) {
        int qsize = q.size();
        cnt++;
        for (int i=0; i<(qsize+1)/2; i++) {
            //마지막 한개남은경우
            if((qsize%2 == 1) && i==(qsize+1)/2-1) {
                q.push(q.front());
                q.pop();
                continue;
            }
            tmpa = q.front();
            q.pop();
            tmpb = q.front();
            q.pop();
            if(tmpa == a && tmpb == b) {
                returnflag = true;
                break;
            }
            if(tmpa == a || tmpb == a) {
                q.push(a);
                continue;
            }
            if(tmpa == b || tmpb == b) {
                q.push(b);
                continue;
            }
            q.push(tmpa);
            

        }
        
        if(returnflag) break;

    }

    
    cout << cnt;


    return 0;
}
