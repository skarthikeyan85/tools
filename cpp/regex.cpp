#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <regex>

using namespace std;

int main() {
    int N;
    cin >> N;
    regex e(".+@gmail\\.com$");
    vector<string> db;

    for(int a0 = 0; a0 < N; a0++){
        string firstName;
        string emailID;
        cin >> firstName >> emailID;
        if(regex_match(emailID,e)){
            db.push_back(firstName);
        }
    }

    sort(db.begin(),db.end()); 
    for(int i = 0;i < db.size();i++) { 
        cout << db[i] << endl;
    }

    return 0;
}


