#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n =0;
    cin >> n;
    int curr = 1;
    int prev = 0;
    if(n >= 0) cout << 0 << " ";
    if(n >= 1) cout << 1 << " ";
    for(int i = 3 ; i < n ; i++){
        int neew = curr + prev;
        prev = curr;
        curr = neew;
        cout << curr << " ";
    }
    return 0;
}
