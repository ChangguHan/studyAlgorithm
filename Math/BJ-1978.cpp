#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int rs=0;
    while(N--) {
        int n;
        cin >> n;
        bool sw = false;
        if(n!=1) {
            for(int i=2; i*i<=n; i++) {
                if(n%i == 0){
                    sw = true;
                    break;
                }
            }
            if(!sw) rs++;
        } 
        
    }

    cout << rs << '\n';


    return 0;
}