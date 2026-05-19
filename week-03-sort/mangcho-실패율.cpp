#include <algorithm>
#include <vector>
using namespace std;

struct Stage {
   private:
    int total_cnt = 0;
    int fail_cnt = 0;
    double fail_rate = 0;

   public:
    int stage_num = 0;

    Stage(int s = 0, int t = 0, int f = 0) { 
        this->stage_num = s, 
        this->total_cnt = t, 
        this->fail_cnt = f; 
    }

    /*total_cnt를 1증가 시키는 함수
    success가 false일때만 fail_cnt 1증가 및 fail_rate 재계산
    */
    void challenge(bool success) {
        ++this->total_cnt;
        if (!success) {
            ++this->fail_cnt;
        }

        this->fail_rate = (double)(this->fail_cnt) / this->total_cnt;
    }

    const double & getFailRate() { return this->fail_rate; }
};

bool compare(Stage a, Stage b) {
    const double &afr = a.getFailRate(), &bfr = b.getFailRate();
    if (afr == bfr)
        return a.stage_num < b.stage_num;
    else
        return afr > bfr;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer(N);
    vector<Stage> ary(N);
    for (int i = 0; i < N; ++i) {
        ary[i].stage_num = i + 1;
    }

    for (auto n : stages) {
        for (int i = 0; i < n - 1 && i < N; ++i) {
            ary[i].challenge(true);
        }
        if (n - 1 < N) ary[n - 1].challenge(false);
    }


    sort(ary.begin(), ary.end(), compare);

    for (int i = 0; i < N; ++i) {
        answer[i] = ary[i].stage_num;
    }

    return answer;
}