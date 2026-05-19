#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Num {
    string str;
    int num;
    size_t length;

    Num(int n = 0) {
        this->num = n;
        this->str = to_string(n);
        this->length = this->str.length();
    }

    bool operator>(const Num& other) const {
        return this->str + other.str > other.str + this->str;
    }

};

string solution(vector<int> numbers) {
    string answer = "";
    size_t N = numbers.size();
    vector<Num> ary(N);
    for(size_t i = 0; i < N; ++i) {
        ary[i] = Num(numbers[i]);
    }

    sort(ary.begin(), ary.end(), [](Num & a, Num & b){return a>b;});

    for(Num & num : ary) {
        answer += num.str;
    }

    if(answer[0] == '0') return "0";

    return answer;
}