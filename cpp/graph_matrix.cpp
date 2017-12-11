#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Graph {
    int V;                  //Number of vertices
    list<int> vertex;
    vector<vector<int>> matrix;

  public:
    Graph(int V);
    void addEdge(int v, int w);
    vector<int> BFS(int s);
    void DFS(int s);
    void DFSUtil(int v, vector<int> &visited, int *ind);
    void DFSNonRec(int s);
    int numComps(void);
    void disp(void);
};

bool find_vis(vector <int>visited, int ser)
{
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == ser) {
            return true;
        }
    }
    return false;
}

Graph::Graph (int V)
{
    this->V = V;
    matrix = vector<vector<int>>(V+1, vector<int>(V+1, 0));
}

void Graph::addEdge(int v, int w)
{
    matrix[v][w] = 1;
    matrix[w][v] = 1;
    
    if (find (vertex.begin(), vertex.end(), v) == vertex.end()) {
        vertex.push_back(v);
    }
    if (find (vertex.begin(), vertex.end(), w) == vertex.end()) {
        vertex.push_back(w);
    }
}

void Graph::DFSUtil(int s, vector<int> &visited, int *ind)
{
    int i = 0;
    visited[*ind] = s;
    *ind += 1;

    for (i = 1; i <= V; i++) {
        if (matrix[s][i] && (s != i) &&
            find(visited.begin(), visited.end(), i) == visited.end()) {
            DFSUtil(i, visited, ind);
        }
    }
}

void Graph::DFS(int s)
{
    vector <int> visited(V,0);
    int ind = 0, i = 0;

    cout << "Following is DFS from vertex: " << s << endl;

    DFSUtil(s, visited, &ind);
    for (i = 0; i < visited.size(); i++)
        cout << visited[i] << " ";
    cout << endl;
}

vector<int> Graph::BFS(int s)
{
    int ind = 0, i = 0;
    queue<int> q;
    vector<int> visited(V,0);


    q.push(s);
    visited[ind++] = s;

    while (!q.empty()) {
        s = q.front();
        q.pop();

        for (int i = 1; i <= V; i++) {
            if (matrix[s][i] && (s != i) &&
                find(visited.begin(), visited.end(), i) == visited.end()) {
                q.push(i);
                visited[ind++] = i;
            }
        }
    }

    return visited;
}

int Graph::numComps(void)
{
    int i = 0, s  = 0;

    for( auto const& v : vertex ) {
            s = v;
            break;
    }

    vector <int>ans = BFS(s);
    return ans.size();
}

void Graph::DFSNonRec(int s)
{
    vector <int> visited(V,0);
    int ind = 0, i = 0;
    stack<int> st;

    cout << "Following is DFSNonRec from vertex: " << s << endl;

    st.push(s);
    visited[ind++] = s;

    while (!st.empty()) {
        s = st.top();
        st.pop();

        for (int i = 1; i <= V; i++) {
            if (matrix[s][i] && (s != i) &&
                find(visited.begin(), visited.end(), i) == visited.end()) {
                st.push(i);
                visited[ind++] = i;
            }
        }
    }

    for (i = 0; i < ind; i++)
        cout << visited[i] << " ";
    cout << endl;
}

void Graph::disp(void)
{
    int i = 0;

    cout << "Following is vertex list:" << endl;
    for( auto const& v : vertex ) {
        cout << v << " ";
    }
    cout << endl;
}

int main()
{
    Graph g(4);

    g.addEdge(4, 1);
    g.addEdge(4, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    g.disp();

    vector<int> b = g.BFS(2);
    cout << "Following is BFS from vertex: 2 " << endl;
    for( auto const& val : b) {
        cout << val << " ";
    }
    cout << endl;

    g.DFS(2);
    g.DFSNonRec(2);

    return 0;
}
 
 
