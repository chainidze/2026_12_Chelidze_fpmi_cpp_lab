#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a ,b ,d;
    cin >> a >> b >> d;
    int curr = a * d;
    while(curr <= b){
        if(curr % 3 == 0)
            cout << curr << endl;
        curr+=d;
    }
    return 0;
}
