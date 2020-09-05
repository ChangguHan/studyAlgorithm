#include <iostream>

using namespace std;

int N;
int num[201];

int main() {
    cin >> N;
    while(N--) {
        int a;
        cin >> a;
        num[a+100]++;
    }
    int b;
    cin >> b;
    cout << num[b+100] << '\n';


    return 0;
}
