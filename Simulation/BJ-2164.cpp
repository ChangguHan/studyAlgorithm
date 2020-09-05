#include <iostream>
#include <queue>

#define MAX 500001
using namespace std;

int N;
queue<int> q;

int main() {
    cin >> N;
    for (int i=1; i<=N; i++) q.push(i);

    while(1) {
        if(q.size() == 1) {
            cout << q.front();
            break;
        }
        q.pop();
        q.push(q.front());
        q.pop();
    }

    return 0;
}