#include <iostream>
#include <string>

using namespace std;

void read_display() {
    system("cls");
    cout << "\t\tREAD AND DISPLAY\n";
    cout << "Please input information about the 2D array:\n";
    int row_input, col_input;
    cout << "Rows (max 5): ";
    cin >> row_input;
    cout << "Columns (max 5): ";
    cin >> col_input;
    int a[5][5];
    cout << "Now input the elements of the matrix:\n";
    if (row_input > 0 && row_input <= 5 && col_input > 0 && col_input <= 5) {
        for (int row = 0; row < row_input; row++) {
            for (int col = 0; col < col_input; col++) {
                cin >> a[row][col];
            }
        }
        cout << "Result:\n";
        for (int row = 0; row < row_input; row++) {
            for (int col = 0; col < col_input; col++) {
                cout << a[row][col] << "  ";
            }
            cout << endl;
        }
        cout << endl;
    } else {
        cout << "Please input valid numbers from 1 to 5!\n";
    }
}

void transpose() {
    system("cls");
    cout << "\t\tTRANSPOSE OF MATRIX\n";
    int a[5][5], trans[5][5], r, c;
    cout << "Please input information about the 2D array:\n";
    cout << "Rows (max 5): ";
    cin >> r;
    cout << "Columns (max 5): ";
    cin >> c;
    if (r > 0 && r <= 5 && c > 0 && c <= 5) {
        cout << "Enter the elements of the matrix:\n";
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> a[i][j];
            }
        }
        cout << "Entered Matrix:\n";
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << " " << a[i][j];
                if (j == c - 1)
                    cout << endl << endl;
            }
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                trans[j][i] = a[i][j];
            }
        }
        cout << "Transpose of Matrix:\n";
        for (int i = 0; i < c; ++i) {
            for (int j = 0; j < r; ++j) {
                cout << " " << trans[i][j];
                if (j == r - 1)
                    cout << endl << endl;
            }
        }
        cout << endl;
    } else {
        cout << "Please input valid numbers from 1 to 5!\n";
    }
}

void sum_matrices() {
    system("cls");
    cout << "\t\tSUM OF TWO MATRICES\n";
    cout << "\tNOTE: Rows 1 = Rows 2 && Columns 1 = Columns 2\n";
    cout << "Please input details for the First Matrix:\n";
    int row_input, col_input;
    cout << "Rows (max 5): ";
    cin >> row_input;
    cout << "Columns (max 5): ";
    cin >> col_input;
    int a[5][5];
    cout << "Now input the elements of the First Matrix:\n";
    if (row_input > 0 && row_input <= 5 && col_input > 0 && col_input <= 5) {
        for (int row = 0; row < row_input; row++) {
            for (int col = 0; col < col_input; col++) {
                cin >> a[row][col];
            }
        }
        cout << "First Matrix:\n";
        for (int row = 0; row < row_input; row++) {
            for (int col = 0; col < col_input; col++) {
                cout << a[row][col] << "  ";
            }
            cout << endl;
        }
    } else {
        cout << "Please input valid numbers from 1 to 5!\n";
        return;
    }
    cout << endl;
    cout << "Please input details for the Second Matrix:\n";
    int row_input2, col_input2;
    cout << "Rows (max 5): ";
    cin >> row_input2;
    cout << "Columns (max 5): ";
    cin >> col_input2;
    int b[5][5];
    cout << "Now input the elements of the Second Matrix:\n";
    if (row_input2 > 0 && row_input2 <= 5 && col_input2 > 0 && col_input2 <= 5) {
        for (int row = 0; row < row_input2; row++) {
            for (int col = 0; col < col_input2; col++) {
                cin >> b[row][col];
            }
        }
        cout << "Second Matrix:\n";
        for (int row = 0; row < row_input2; row++) {
            for (int col = 0; col < col_input2; col++) {
                cout << b[row][col] << "  ";
            }
            cout << endl;
        }
    } else {
        cout << "Please input valid numbers from 1 to 5!\n";
        return;
    }
    int sum[5][5];
    if (row_input == row_input2 && col_input == col_input2) {
        for (int row = 0; row < row_input; row++) {
            for (int col = 0; col < col_input; col++) {
                sum[row][col] = a[row][col] + b[row][col];
            }
        }
        cout << endl << "Sum of two matrices:\n";
        for (int row = 0; row < row_input; row++) {
            for (int col = 0; col < col_input; col++) {
                cout << sum[row][col] << "  ";
            }
            cout << endl;
        }
    } else {
        cout << endl << "These matrices cannot be added.\n";
    }
}

void product() {
    system("cls");
    cout << "\t\tMULTIPLY TWO MATRICES\n";
    cout << "\tNOTE: Rows 1 = Columns 2\n";
    cout << "Please input details for the First Matrix:\n";
    int row_input, col_input;
    cout << "Rows (max 5): ";
    cin >> row_input;
    cout << "Columns (max 5): ";
    cin >> col_input;
    int a[5][5];
    cout << "Now input the elements of the First Matrix:\n";
    if (row_input > 0 && row_input <= 5 && col_input > 0 && col_input <= 5) {
        for (int row = 0; row < row_input; row++) {
            for (int col = 0; col < col_input; col++) {
                cin >> a[row][col];
            }
        }
        cout << "First Matrix:\n";
        for (int row = 0; row < row_input; row++) {
            for (int col = 0; col < col_input; col++) {
                cout << a[row][col] << "  ";
            }
            cout << endl;
        }
    } else {
        cout << "Please input valid numbers from 1 to 5!\n";
        return;
    }
    cout << endl;
    cout << "Please input details for the Second Matrix:\n";
    int row_input2, col_input2;
    cout << "Rows (max 5): ";
    cin >> row_input2;
    cout << "Columns (max 5): ";
    cin >> col_input2;
    int b[5][5];
    cout << "Now input the elements of the Second Matrix:\n";
    if (row_input2 > 0 && row_input2 <= 5 && col_input2 > 0 && col_input2 <= 5) {
        for (int row = 0; row < row_input2; row++) {
            for (int col = 0; col < col_input2; col++) {
                cin >> b[row][col];
            }
        }
        cout << "Second Matrix:\n";
        for (int row = 0; row < row_input2; row++) {
            for (int col = 0; col < col_input2; col++) {
                cout << b[row][col] << "  ";
            }
            cout << endl;
        }
    } else {
        cout << "Please input valid numbers from 1 to 5!\n";
        return;
    }
    int multi[5][5];
    if (row_input == col_input2) {
        for (int row = 0; row < row_input; row++) {
            for (int col = 0; col < col_input2; col++) {
                multi[row][col] = 0;
                for (int i = 0; i < col_input; i++) {
                    multi[row][col] += a[row][i] * b[i][col];
                }
            }
        }
        cout << endl << "Result of Multiplication:\n";
        for (int row = 0; row < row_input; row++) {
            for (int col = 0; col < col_input2; col++) {
                cout << multi[row][col] << "  ";
            }
            cout << endl;
        }
    } else {
        cout << endl << "These matrices cannot be multiplied.\n";
    }
}

void main_menu_view() {
    system("color 3F");
    cout << "\t\t\t===============================\n";
    cout << "\t\t\t\tM A I N  M E N U\n";
    cout << "\t\t\t===============================\n";
    cout << "\t\t\t[1] Read and Display Matrix\n";
    cout << "\t\t\t[2] Transpose\n";
    cout << "\t\t\t[3] Sum of Two Matrices\n";
    cout << "\t\t\t[4] Product of Two Matrices\n\n";
}

int main() {
    cout << __cplusplus << std::endl;
    while (true) {
        main_menu_view();
        cout << "\t\t\tYOUR CHOICE: ";
        string user_choice;
        cin >> user_choice;

        if (user_choice == "1")
            read_display();
        else if (user_choice == "2")
            transpose();
        else if (user_choice == "3")
            sum_matrices();
        else if (user_choice == "4")
            product();
        else {
            system("cls");
            cout << "\t\tYou have entered an invalid choice. Please try again!\n";
            continue;
        }

        cout << "\nDo you want to return to the main menu? (Yes = 1, No = Any "
                "Key)\n";
        string respond;
        cout << "Your choice: ";
        cin >> respond;
        if (respond != "1")
            break;

        system("cls");
    }

    return 0;
}
