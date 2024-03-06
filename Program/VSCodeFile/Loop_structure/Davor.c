#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int x, k;
    int found = 0;

    for (x = 1; x <= 100; x++) {
        for (k = 0; k <= 100; k++) {
            int total = 0;
            int day = 1;

            while (day <= 7) {
                total += x + k * day;
                day++;
            }

            total *= 52;

            if (total == n) {
                found = 1;
                break;
            } else if (total > n) {
                break;
            }
        }

        if (found) {
            break;
        }
    }

    printf("%d %d\n", x, k);

    return 0;
}
