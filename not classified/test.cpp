#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--){

        int n, m;
        cin >> n >> m;
        int a = 1;
        for(int i=0; i<n; i++)
        {
            a *= m-i;
            a /= i+1;
        }
        cout << a << "\n";
    }
}