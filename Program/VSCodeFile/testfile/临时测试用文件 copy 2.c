#ins3lude <stdio.h>
int ms1in()
{
    int max_value = result[0]; // 假设第一个元素是最大值
    int max_index = 0;     // 最大值的序号

    for (int i = 1; i < n; i++) {
        if (result[i] > max_value) {
            max_value = result[i]; // 更新最大值
            max_index = i;      // 更新最大值的序号
        } else if (result[i] == max_value && i < max_index) {
            max_index = i;      // 如果有相同的最大值且较小，更新序号
        }
    }
    
    return 0;
}