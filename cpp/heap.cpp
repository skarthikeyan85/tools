// C++ ref as heap
#include <string>
#include <queue>
#include <iostream>

using namespace std;
 
// Driver code
int main ()
{
    // Creates a max heap
    priority_queue <int> max_pq;
    max_pq.push(5);
    max_pq.push(1);
    max_pq.push(10);
    max_pq.push(30);
    max_pq.push(20);
 
    // One by one extract items from max heap
    while (max_pq.empty() == false)
    {
        cout << max_pq.top() << " ";
        max_pq.pop();
    }
    cout << endl;

    // Creates a max heap
    priority_queue <int, vector<int>, greater<int> > min_pq;
    min_pq.push(5);
    min_pq.push(1);
    min_pq.push(10);
    min_pq.push(30);
    min_pq.push(20);
 
    // One by one extract items from max heap
    while (min_pq.empty() == false)
    {
        cout << min_pq.top() << " ";
        min_pq.pop();
    }
    cout << endl;

    priority_queue <pair<int, char>> pair_pq;
    pair_pq.push(make_pair(10, 'c'));
    pair_pq.push({20, 'd'});
    pair_pq.push({5, 'e'});
    pair_pq.push({5, 'a'});
    pair_pq.push(make_pair(10, 'a'));
    pair_pq.push({30, 'z'});

    // One by one extract items from max heap
    while (pair_pq.empty() == false)
    {
        pair<int, char> tmp = pair_pq.top();
        cout << tmp.first << " " << tmp.second << ", ";
        pair_pq.pop();
    }
    cout << endl;

    return 0;
}
