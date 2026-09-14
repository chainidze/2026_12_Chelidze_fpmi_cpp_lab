#include <bits/stdc++.h>

int main()
{
    using namespace std;
    int a, b;
    cin >> a >> b;
    for(int chisl1 = a; chisl1 <= b ; chisl1++){
        int druz = 1;
        for(int x = 2; x * x <= chisl1 ; x++){
            if(chisl1 % x == 0){
                druz += x;
                if(chisl1 / x != x)
                    druz += chisl1 / x;
            }
        }
        int check = 1;
        int chisl2 = druz;
        if(chisl2 <= chisl1) continue;
        for(int x = 2; x * x<= chisl2 ; x++){
            if(chisl2 % x == 0){
                check += x;
                if(chisl2 / x != x)
                    check += chisl2 / x;
            }
        }
        if(druz == chisl2 && check == chisl1) cout << chisl1 << ":" << chisl2 << endl;
    }
    return 0;
}
