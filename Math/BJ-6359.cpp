#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int rs=0;
        for (int j=1; j<=n; j++) {
            int cnt=0;
            for(int i=1; i*i<=j; i++) {
                if(j%i==0) {
                    cnt++;
                    if(j!=i*i) cnt++;
                }
            }
            if(cnt%2==1) rs++;
        }

        cout << rs << '\n';
        
        
    }

    return 0;
}