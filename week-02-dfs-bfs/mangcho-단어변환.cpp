#include <string>
#include <vector>

using namespace std;

vector<string> words;
size_t length;

int change(string& begin, string& target, int index, const int& cnt) {
    if(begin == target) return cnt;
    if(index == length) return 0;

    bool MainFlag = false;
    int Min = 50;
    for(int i = index; i < length; ++i) {
        for(auto word : words) {
            bool flag = true;
            for(int j = 0; j < length; ++j) {   //word랑 i번째 빼고 같은지 확인
                if(j == i) {
                    if(word[j] == begin[j]) {
                        flag = false;
                        break;
                    }
                } else {
                    if(word[j] != begin[j]) {
                        flag = false;
                        break;
                    }
                }
            }

            if(flag) {
                int tmp = change(word, target, i+1, cnt+1);
                if(tmp < Min) Min = tmp;
                MainFlag = true;
            }
        }
    }
    
    return MainFlag ? Min : 0;
}

int solution(string begin, string target, vector<string> ary) {
    words = move(ary);
    length = begin.size();
    bool flag = true;
    for(int i = 0; i < words.size(); ++i) {
        if(words[i] == target) {
            flag = false;
            break;
        }
    }
    if(flag) return 0;

    int answer = change(begin, target, 0, 0);
    return answer;
}