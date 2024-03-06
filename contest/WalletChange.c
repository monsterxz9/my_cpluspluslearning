/*
#include <stdio.h>

// Function to determine the winner for each test case
void wallet_exchange(int t, int test_cases[0],int test_case[1]) {
    for (int i = 0; i < t; i++) {
        int a = test_cases[0];
        int b = test_cases[1];

        // Determine the winner for the current test case
        if ((a - 1) % 2 == 0 && (b - 1) % 2 == 0) {
            printf("Alice\n");
        } else if ((a - 1) % 2 == 1 && (b - 1) % 2 == 1) {
            printf("Bob\n");
        } else {
            printf((a < b) ? "Alice\n" : "Bob\n");
        }
    }
}

int main() {
    int t;
    scanf_s("%d",&t);
    for (int i = 0; i < t; ++i) {
        int test_cases[2];
        scanf_s("%d %d",&test_cases[0],&test_cases[1]);
        wallet_exchange(t, &test_cases[0],&test_cases[1]);
    }



    return 0;
}
*/
#include <stdio.h>

// Function to determine the winner for each test case
void wallet_exchange(int t, int test_cases[][2]) {
    for (int i = 0; i < t; i++) {
        int a = test_cases[i][0];
        int b = test_cases[i][1];

        // Determine the winner for the current test case
        if ((a - 1) % 2 == 0 && (b - 1) % 2 == 0) {
            printf("Alice\n");
        } else if ((a - 1) % 2 == 1 && (b - 1) % 2 == 1) {
            printf("Bob\n");
        } else {
            printf((a < b) ? "Alice\n" : "Bob\n");
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);

    int test_cases[t][2];  // Declare a 2D array to store test cases

    for (int i = 0; i < t; ++i) {
        scanf("%d %d", &test_cases[i][0], &test_cases[i][1]);
    }

    // Call the function to determine the winners
    wallet_exchange(t, test_cases);

    return 0;
}




