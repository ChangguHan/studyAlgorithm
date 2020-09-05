#include <iostream>

using namespace std;
int a,b,c;
int mem[1000000] = {-1};
int recur(int num, int pow) {
    if(pow<1000000) {
        if(mem[pow] != -1) return mem[pow];
    }    
    if(pow==0) return 1;
    if(pow==1) return num%c;
    int mid = pow/2;
    int rs=0;
    if(pow<1000000) {
        mem[pow] =  (recur(num,mid) * recur(num, pow-mid))%c;
        rs =mem[pow];
    }
    else rs =  (recur(num,mid) * recur(num, pow-mid))%c;
    return rs;
}
int main() {
    cin >> a >> b >> c;
    fill(mem, mem+1000000,-1);
    // int rs = a%c;
    // for (int i=1; i<b; i++ ) {
    //     rs= (rs * a)%c;
    // }

    cout << recur(a,b) << '\n';



    return 0;
}