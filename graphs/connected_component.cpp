#include <bits/stdc++.h>
using namespace std;

void makeGraph(int M, vector<int> *g)
{
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void bfs(vector<int> *g, bool *check, int v)
{
    queue<int> q;
    check[v] = true;
    q.push(v);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < g[now].size(); i++)
        {
            int next = g[now][i];
            if (!check[next])
            {
                q.push(next);
                check[next] = true;
            }
        }
    }
}

int getConnectedComponent(int N,vector<int> *g)
{
    bool check[N + 1];
    memset(check,false,sizeof(check));

    int ans = 0;

    for (int i = 1; i <= N; i++)
    {
        if (check[i])
            continue;

        bfs(g, check, i);
        ans++;
    }
    return ans;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> g[N + 1];

    makeGraph(M, g);

    cout << getConnectedComponent(N, g);
}