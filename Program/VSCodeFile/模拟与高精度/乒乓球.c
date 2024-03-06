#include <stdio.h>
#include <stdlib.h>
// 处理比赛结果
void process_match_results(char results[]) {
  int score_11[2] = {0, 0}; // 11分制得分
  int score_21[2] = {0, 0}; // 21分制得分

  for (int i = 0; results[i] != 'E'; i++) {
    char result = results[i];

    if (result == 'W') {
      score_11[0]++;
      score_21[0]++;
    } else if (result == 'L') {
      score_11[1]++;
      score_21[1]++;
    }

    // 检查11分制比赛结果
    if (score_11[0] >= 11 && abs(score_11[0] - score_11[1]) >= 2) {
      printf("%d:%d\n", score_11[0], score_11[1]);
      score_11[0] = score_11[1] = 0;
    }

    // 检查21分制比赛结果
    if (score_21[0] >= 21 && abs(score_21[0] - score_21[1]) >= 2) {
      printf("%d:%d\n", score_21[0], score_21[1]);
      score_21[0] = score_21[1] = 0;
    }
  }
}

int main() {
  char results[2501]; // 假设最多有2500行比赛结果

  // 读取输入直到遇到'E'
  char c;
  int i = 0;
  while (scanf("%c", &c) == 1 && c != 'E') {
    results[i++] = c;
  }
  results[i] = '\0'; // 以空字符结尾

  // 处理比赛结果并打印得分
  process_match_results(results);

  return 0;
}
