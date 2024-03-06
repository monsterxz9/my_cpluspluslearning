/* #include <stdio.h>
void function(int n)
{   
    int a[n][n];
    int t=1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j]=t;    
            t++; 
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);  
    function(n);
    return 0;
} */
#include <stdio.h>

void fillMatrix(int n, int mat[n][n]) {
    int num = 1;
    for (int layer = 0; layer < (n + 1) / 2; layer++) {
        // Top row
        for (int i = layer; i < n - layer; i++) {
            mat[layer][i] = num++;
        }

        // Right column
        for (int i = layer + 1; i < n - layer; i++) {
            mat[i][n - layer - 1] = num++;
        }

        // Bottom row
        for (int i = n - layer - 2; i >= layer; i--) {
            mat[n - layer - 1][i] = num++;
        }

        // Left column
        for (int i = n - layer - 2; i > layer; i--) {
            mat[i][layer] = num++;
        }
    }
}

void printMatrix(int n, int mat[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int mat[n][n];
    fillMatrix(n, mat);
    printMatrix(n, mat);

    return 0;
}
