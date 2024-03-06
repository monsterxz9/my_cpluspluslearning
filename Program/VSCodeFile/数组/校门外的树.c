/* #include <stdio.h>
int main()
{
    int l,m;
    scanf("%d %d",&l,&m);
    int u[m],v[m];
    int i;
    int count;
    for ( i = 1; i <= m; i++)
    {
        
        scanf("%d %d",&u[i],&v[i]);
        
        
    }
    
    for (i = 1; i <= m; i++)
    {
        printf("%d ",u[i]);
    }
    printf("\n");
    for (i = 1; i <= m; i++)
    {
        printf("%d ",v[i]);
    }
    return 0;
}
 */

#include <stdio.h>

int main() {
    int l, m;
    scanf("%d %d", &l, &m);

    int trees[l + 1]; // 创建一个数组来表示马路上的树，数组下标表示树的位置，初始化为1
    for (int i = 0; i <= l; i++) {
        trees[i] = 1;
    }

    // 处理每个区域，将区域内的树标记为0
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        for (int j = u; j <= v; j++) {
            trees[j] = 0;
        }
    }

    // 统计剩余的树的数量
    int remaining_trees = 0;
    for (int i = 0; i <= l; i++) {
        remaining_trees += trees[i];
    }

    printf("%d\n", remaining_trees);

    return 0;
}
/* 
这个程序首先创建一个长度为l+1的整数数组来表示马路上的树，
数组的每个元素初始化为1，表示有树。
然后，根据输入的区域信息，将区域内的树的位置在数组中标记为0
，表示这些树将被移走。最后，遍历数组并统计剩余的树的数量，将结果输出。

请注意，这个程序假设输入数据是有效的，并且没有对输入进行错误检查。
在实际应用中，可能需要添加更多的错误检查和边界条件的处理。
 */