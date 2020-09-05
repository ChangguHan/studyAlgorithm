#include <iostream>

using namespace std;

int L,A,B,C,D;

int main() {
    cin >> L >> A >> B >> C >> D;

    cout << L- max((A+C-1)/C, (B+D-1)/D);

    return 0;
}