#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> isChecked(n, false);

    for (int i = 0; i < n; ++i) {
        if (isChecked[i]) continue;
        queue<int> q;
        q.push(i);
        isChecked[i] = true;

        while (!q.empty()) {
            int j = q.front();
            q.pop();

            for (int k = 0; k < n; ++k) {
                if (computers[j][k] && !isChecked[k]) { 
                    q.push(k);
                    isChecked[k] = true;
                }
            }
        }
        ++answer;                    
    }

    return answer;
}