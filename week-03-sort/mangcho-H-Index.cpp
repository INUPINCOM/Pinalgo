#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int m = 0;
    int n = citations.size();

    for(int h = 0; h <= n; ++h) {
        int t = 0;
        for(const int & i : citations) {
            if(i >= h) ++t;
        }

        if(t >= h) {
            m = h;
        }
    }

    return m;
}