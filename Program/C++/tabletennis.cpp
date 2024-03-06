#include <bits/stdc++.h>

using namespace std;
vector<char> n;

void output(int &w, int &l) {
    cout << w << ":" << l << endl;
    w = 0;
    l = 0;
}

void res11(const vector<char> &vec) {
    int w = 0;
    int l = 0;

    for (char c: vec) {
        if (c == 'W') {
            w++;
        } else if (c == 'L') {
            l++;
        }
        if (c == 'E') {
            output(w, l);
        }
        if ((w >= 11 || l >= 11) && abs(w - l) > 1) {
            output(w, l);
            continue;
        }

        if (w > 11 || l > 11) {
            if (abs(w - l) > 1) {
                output(w, l);
                continue;
            } else if (abs(w - l) <= 1) {
                continue;
            }
        }
    }
}


void res21(const vector<char> &vec) {
    int w = 0;
    int l = 0;

    for (char c: vec) {
        if (c == 'W') {
            w++;
        } else if (c == 'L') {
            l++;
        }
        if (c == 'E') {
            output(w, l);
        }
        if ((w >= 21 || l >= 21) && abs(w - l) > 1) {
            output(w, l);
            continue;
        }

        if (w > 21 || l > 21) {
            if (abs(w - l) > 1) {
                output(w, l);
                continue;
            }
        } else if (abs(w - l) <= 1) {
            continue;
        }
    }
}


int main() {
    char res;
    do {
        cin >> res;
        n.push_back(res);
    } while (res != 'E');
    res11(n);
    cout << endl;
    res21(n);
}
/*
#include <stdio.h>
#include <math.h>
// 处理比赛结果
void process_match_results(char results[])
{
    int score_11[2] = {0, 0}; // 11分制得分
    int score_21[2] = {0, 0}; // 21分制得分

    for (int i = 0; results[i] != 'E'; i++)
    {
        char result = results[i];

        if (result == 'W')
        {
            score_11[0]++;
            score_21[0]++;
        }
        else if (result == 'L')
        {
            score_11[1]++;
            score_21[1]++;
        }

        // 检查11分制比赛结果
        if (score_11[0] >= 11 && abs(score_11[0] - score_11[1]) >= 2)
        {
            printf("%d:%d\n", score_11[0], score_11[1]);
            score_11[0] = score_11[1] = 0;
        }

        // 检查21分制比赛结果
        if (score_21[0] >= 21 && abs(score_21[0] - score_21[1]) >= 2)
        {
            printf("%d:%d\n", score_21[0], score_21[1]);
            score_21[0] = score_21[1] = 0;
        }
    }
}

int main()
{
    char results[2501]; // 假设最多有2500行比赛结果

    // 读取输入直到遇到'E'
    char c;
    int i = 0;
    while (scanf("%c", &c) == 1 && c != 'E')
    {
        results[i++] = c;
    }
    results[i] = '\0'; // 以空字符结尾

    // 处理比赛结果并打印得分
    process_match_results(results);

    return 0;
}
*/
