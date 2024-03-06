#include <algorithm> // 包含sort函数需要的头文件
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int L, M;
    cin >> L >> M;

    vector<int> start;
    vector<int> finish;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        start.push_back(a);
        finish.push_back(b);
    }

    sort(start.begin(), start.end());
    sort(finish.begin(), finish.end());

    for (int i = 0; i < start.size() - 1; i++) {
        if (start[i + 1] <= finish[i]) {
            start.erase(start.begin() + i + 1); // 移除 start[i+1]
            finish.erase(finish.begin() + i);   // 移除 finish[i]
            i--;
        }
    }
    int t = 0;
    for (int i = 0; i < start.size(); i++) {
        t += finish[i] - start[i] + 1;
    }

    cout << L + 1 - t << endl;
}
