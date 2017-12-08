#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool ransom_note(vector<string> magazine, vector<string> ransom) {
    unordered_map<string, int> m;

    for (int i = 0; i < magazine.size(); i++) {
        auto it = m.find(magazine[i]);
         if (it == m.end()) {
            m.insert({magazine[i],1});
         } else {
            it->second++;
         }
    }

    for (int i = 0; i < ransom.size(); i++) {
         auto it = m.find(ransom[i]);
         if (it != m.end()) {
             it->second--;
             if (!it->second) {
                m.erase(ransom[i]);
             }
         } else {
             return false;
         }
    }
    
    return true;
}

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
