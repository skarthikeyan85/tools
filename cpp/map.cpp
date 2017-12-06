#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int num = 0, j = 0, tmp,tmp2;
    int c,a,b;
    string tstr;
    map <string,int> m;

    cin >> num;

    for (j = 0 ; j < num; j++) {
        cin >> tmp >> tstr;
        if (tmp == 1) {
            map<string,int>::iterator itr=m.find(tstr);
            cin >> tmp2;
            if (itr == m.end()) {
                m.insert(make_pair(tstr,tmp2));
            } else {
                itr->second += tmp2; 
            }
        }
        if (tmp == 2) {
            m.erase(tstr);
        }
        if (tmp == 3) {
            map<string,int>::iterator itr=m.find(tstr);
            cout << (itr == m.end() ? 0 : itr->second) << '\n';
        }
    }


    return 0;
}
