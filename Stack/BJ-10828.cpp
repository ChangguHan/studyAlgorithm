#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    while(N--){
        string ip;
        int n;
        cin >> ip;
        if(ip == "push") {
            cin >> n;
            s.push(n);
        } else if(ip == "top") {
            if(!s.empty()) cout << s.top() << '\n';
            else cout << -1 << '\n';
        } else if(ip == "size") {
            cout << s.size() << '\n';
        }else if(ip == "empty") {
            cout << s.empty() << '\n';
        }else if(ip == "pop") {
            if(!s.empty()){
                cout << s.top() << '\n';
                s.pop();
            }
            else cout << -1 << '\n';
            
        }

    }



    return 0;
}