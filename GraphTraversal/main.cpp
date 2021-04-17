#include <cstdio>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph
{
public:
    int vn, en;

    vector<int> *edges;

    void Init(const char *_filename)
    {
        FILE *input = fopen(_filename, "r");
        fscanf(input, "%d", &vn);
        fscanf(input, "%d", &en);
        edges = new vector<int>[vn];
        for (int i = 0; i < en; i++)
        {
            char a, b;
            fscanf(input, " %c %c", &a, &b);
            int x, y;
            x = a - 'A';
            y = b - 'A';
            edges[x].push_back(y);
        }

        fclose(input);
    }
};

void BFS(Graph &_g, int _stIdx = 0)
{
    bool *visit = new bool[_g.vn];
    for (int i = 0; i < _g.vn; i++)
    {
        visit[i] = false;
    }
    queue<int> q;
    visit[_stIdx] = true;
    q.push(_stIdx);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        printf("%c ", x + 'A');

        for (int i = 0; i < _g.edges[x].size(); i++)
        {
            if (!visit[_g.edges[x][i]])
            {
                q.push(_g.edges[x][i]);
                visit[_g.edges[x][i]] = true;
            }
        }
    }
    delete[] visit;
}

void DFS(Graph &_g, int _stIdx = 0)
{
    bool *visit = new bool[_g.vn];
    for (int i = 0; i < _g.vn; i++)
    {
        visit[i] = false;
    }
    stack<int> s;
    visit[_stIdx] = true;
    s.push(_stIdx);
    while (!s.empty())
    {
        int x = s.top();
        s.pop();
        printf("%c ", x + 'A');

        // for (int i = 0; i < _g.edges[x].size(); i++)
        for (int i = _g.edges[x].size() - 1; i >= 0; i--)
        {
            if (!visit[_g.edges[x][i]])
            {
                s.push(_g.edges[x][i]);
                visit[_g.edges[x][i]] = true;
            }
        }
    }
    delete[] visit;
}

int main(int argc, char **argv)
{
    Graph g;
    g.Init(argv[1]);
    printf("BFS : ");
    BFS(g);
    printf("\nDFS : ");
    DFS(g);
    printf("\n");
    return 0;
}