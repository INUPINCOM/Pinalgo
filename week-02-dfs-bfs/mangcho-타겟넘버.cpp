#include <vector>
using namespace std;

void dfs(int index, int current, int& res, vector<int>& numbers, int target) {
    if (index == (int)numbers.size()) {
        if (current == target) ++res;
        return;
    }

    dfs(index + 1, current + numbers[index], res, numbers, target);
    dfs(index + 1, current - numbers[index], res, numbers, target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(0, 0, answer, numbers, target);
    return answer;
}