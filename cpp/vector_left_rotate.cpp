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

using namespace std;

vector<int> array_left_rotation(vector<int> a, int n, int k) {
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[(i + (n-k))%n] = a[i];
    }
    return b;
}

struct Player {
    string name;
    int score;
};

bool compare(Player p1, Player p2) {
    if (p1.score > p2.score)
        return true;
    if (p1.score == p2.score)
        return p1.name < p2.name;
    return false;
}

vector<Player> comparator(vector<Player> players) {
    sort(players.begin(), players.end(), compare);
    return players;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotation(a, n, k);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;

    cin >> n;
    vector< Player > players;
    string name;
    int score;
    
    for(int i = 0; i < n; i++){
        cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }

    vector<Player > answer = comparator(players);
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i].name << " " << answer[i].score << endl;
    }
    return 0;
}
