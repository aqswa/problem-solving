//
// Created by LG on 2023-03-03.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, p;
    cin >> s >> p;

    int i=0;
    int cnt = 0;
    while(p.length() > 0){
        string part = p.substr(0, p.length()-i);
        i++;
        if(s.find(part) != string::npos){
            p = p.substr(part.length(), p.length()-part.length());
            i=0;
            cnt++;
        }
    }

    cout << cnt;

    /*
    int cnt = 0;
	int len1 = strlen(S);
	int len2 = strlen(P);

	for (int i = 0; i < len2;) {
		int max = 0;
		for (int j = 0; j < len1; j++) {
			int tmp = 0;
			while (S[j+tmp] == P[i+tmp]) tmp++;
			if (max < tmp) max = tmp;
		}
		i += max;
		cnt++;
	}*/
}
