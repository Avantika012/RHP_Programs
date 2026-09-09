#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
void solve() {
    int R;
    cin >> R;
    map<int, vector<pair<int, int>>> graph;
    while (R--) {
        int src, dest, dist;
        cin >> src >> dest >> dist;
        graph[src].push_back({dest, dist});
        graph[dest].push_back({src, dist});
    }
    int start, end;
    cin >> start >> end;
    map<int, int> distance;
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
        > pq;
    distance[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [currDist, city] = pq.top();
        pq.pop();
        if (distance[city] < currDist)
            continue;
        for (auto [nextCity, edgeDist] : graph[city]) {
            int newDist = currDist + edgeDist;
            if (distance.find(nextCity) == distance.end() ||
                newDist < distance[nextCity]) {
                distance[nextCity] = newDist;
                pq.push({newDist, nextCity});
            }
        }
    }
    if (distance.find(end) != distance.end()) {
        cout << distance[end] << endl;
    } 
    else {
        cout << "City " << end
             << " cannot be reached from City "
             << start << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc=1;
    while(tc--)
      solve();
}