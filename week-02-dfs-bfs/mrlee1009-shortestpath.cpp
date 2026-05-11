#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int answer = -1;
    queue<pair<int, int>> q;
    int max_x = maps.size(); int max_y = maps[0].size();
    
    q.push({0, 0});
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(x == max_x-1 && y == max_y-1) return maps[x][y];
        
        if(x+1 < max_x && maps[x+1][y] == 1) {
            maps[x+1][y] = maps[x][y] + 1;
            q.push({x+1, y});
        }
        
        if(y+1 < max_y && maps[x][y+1] == 1) {
            maps[x][y+1] = maps[x][y] + 1;
            q.push({x, y+1});
        }
        
        if(x > 0 && maps[x-1][y] == 1) {
            maps[x-1][y] = maps[x][y] + 1;
            q.push({x-1, y});
        }
        
        if(y > 0 && maps[x][y-1] == 1) {
            maps[x][y-1] = maps[x][y] + 1;
            q.push({x, y-1});
        }
    }
    
    return answer;
}