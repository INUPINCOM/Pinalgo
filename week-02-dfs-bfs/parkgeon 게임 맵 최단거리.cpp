#include <queue>
#include <vector>
using namespace std;

int solution(vector<vector<int>> maps) {
    int n = maps.size();     // 행 개수
    int m = maps[0].size();  // 열 개수
    const vector<pair<int, int>> dirs = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1},
    };

    queue<pair<int, int>> q;
    q.push({n - 1, m - 1});

    while (!q.empty()) {
        auto [x, y] = q.front();

        q.pop();  // 꺼내오고 삭제

        //0,0 에 도착했다면 return
        if (x == 0 && y == 0) return maps[0][0];

        for (auto dir : dirs) {
            int next_x = x + dir.first, next_y = y + dir.second;

            // map 벗어난 경우
            if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m) continue;   
            // 벽이거나 이미 방문한 경우
            if (maps[next_x][next_y] == 0 || maps[next_x][next_y] != 1) continue;  

            q.push({next_x, next_y});
            maps[next_x][next_y] = maps[x][y]+1;         
        }
    }

    return -1;  // 도달 불가
}