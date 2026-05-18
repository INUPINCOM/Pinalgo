#include <string>
#include <vector>

using namespace std;

int find_parent(vector<int>& parent, int x) {
    // root 반환
    if(parent[x] == x) return x;
    // root에서 갈 수 있는 노드들은 모두 root를 가리키게 함
    return parent[x] = find_parent(parent, parent[x]);
}

void union_net(vector<int>& parent, int a, int b) {
    int rootA = find_parent(parent, a);
    int rootB = find_parent(parent, b);
    
    if(rootA != rootB) parent[rootB] = rootA;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> parent(n);
    
    for(int i=0; i<n; i++) parent[i] = i;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(computers[i][j]) union_net(parent, i, j);
        }
    }
    
    for(int i=0; i<n; i++) if(parent[i] == i) answer++;
    return answer;
}