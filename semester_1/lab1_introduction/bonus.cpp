#include <bits/stdc++.h>

using namespace std;

int main()
{
    int start = 0;
    int n = 0;
    cin >> start >> n;
    int cntr = start;
    while(cntr > 0){
        cout << "   ";
        cntr--;
    }
    int it = 1;
    int cntr2 = 7 - start;
    while(cntr2 > 0){
        cout << "  " << it;
        cntr2--;
        it++;
    }
    cout << endl;
    while(it + 7 <= n){
        for(int x = 0 ; x < 7; x++){
        cout << " ";
        if(it+x < 10){
            cout << " " << it + x;
        }
        else{
            cout << it + x;
        }
        }
        cout << endl;
        it += 7;
    }
    while(it <= n){
        cout << " " << it;
        it++;
    }
    return 0;
}
