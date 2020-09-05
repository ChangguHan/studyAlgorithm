#include <iostream>

using namespace std;
int gcd(int a, int b) {
    if(a==0) return b;
    return gcd(b%a, a);
}
int main() {
    int T;
    cin >> T;

    while(T--) {
        int M,N,x,y;
        cin >> M >> N >> x >> y;
        int gcdv = gcd(M,N);
        int lcm = M*N/gcdv;
        bool sw=true;
        for (int i=x; i<=lcm+x; i= i+M) {
            if(i%N == y || (i%N== 0 && y==N)) {
                cout << i << '\n';
                sw = false;
                break;
            }
        }
        if(sw) cout << -1 << '\n';
    }

    return 0;
}