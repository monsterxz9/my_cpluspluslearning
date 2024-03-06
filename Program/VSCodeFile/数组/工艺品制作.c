/* #include <stdio.h>
int main()
{
    int w,x,h;
    scanf("%d %d %d",&w,&x,&h);

    return 0;
} */

#include <stdio.h>

int main() {
    int w, x, h;
    scanf("%d %d %d", &w, &x, &h);

    int q;
    scanf("%d", &q);

    int cubes[21][21][21] = {0}; // 创建一个三维数组，默认初始化为0

    int total_volume = w * x * h; // 初始时总体积等于立方体的体积

    for (int i = 0; i < q; i++) {
        int x1, y1, z1, x2, y2, z2;
        scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);

        // 遍历并更新被切割的小方块
        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                for (int z = z1; z <= z2; z++) {
                    if (cubes[x][y][z] == 0) {
                        cubes[x][y][z] = 1;
                        total_volume--;
                    }
                }
            }
        }
    }

    printf("%d\n", total_volume);

    return 0;
}
