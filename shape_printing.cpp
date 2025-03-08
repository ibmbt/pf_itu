#include <iostream>
using namespace std;

int main() {
    char repeat = 'Y', choice;
    int count = 0;
    char space = ' ';
    int n, size = 0;
    while (repeat == 'Y' || repeat == 'y') {
        cout << "============|MENU|============" << endl;
        cout << "Press: " << endl;
        cout << "[T] For Right Tringle" << endl;
        cout << "[I] For Inverted Right Triangle" << endl;
        cout << "[s] For Hollow Square" << endl;
        cout << "[D] For Diamond" << endl;
        cout << "[H] For Houurglass" << endl;
        cout << "[d] For Hollow Diamond" << endl;
        cout << "[S] For Hexagon Star Pattern" << endl;
        cout << "[C] For Concentric Rectangles" << endl;
        cout << "[E] or [e] To Exit" << endl;
        cout << "Enter Your Choice: " << endl;
        cin >> choice;
        if (choice == 'T') {
            cout << "=====|RIGHT TRIANGLE|=====" << endl;
            cout << "enter size of triangle: " << endl;
            cin >> n;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j <= i; j++) {
                    cout << "*";
                }
                cout << endl;
            }
        }
        else if (choice == 'I') {
            cout << "=====|INVERTED TRIANGLE|=====" << endl;
            cout << "enter size of triangle: " << endl;
            cin >> n;
            for (int i = 0; i < n; i++) {
                for (int j = n; j > i; j--) {
                    cout << "*";
                }
                cout << endl;
            }
        }
        else if (choice == 's') {
            cout << "=====|HOLLOW SQUARE|=====" << endl;
            cout << "enter size of square: " << endl;
            cin >> n;
            for (int i = 0; i < n; i++) {
                count = n;
                if (i == 0 || i == n-1) {
                    while (count >= 0) {
                        cout << "*";
                        count--;
                    }
                    cout << endl;
                }
                else {
                    cout << "*";
                    for (int j = 1; j < n; j++) {
                        cout << space;
                    }
                    cout << "*" << endl;

                }
            }
        }
        else if (choice == 'D') {
            cout << "=====|DIAMOND|=====" << endl;
            cout << "enter size of diamond in odd number (because it is a diamond): " << endl;
            cin >> n;
            for (int i = 1; i <= (n / 2) + 1; i++) {
                for (int j = 1; j <= (n / 2) + 1 - i; j++) {
                    cout << space;
                }
                for (int j = 1; j <= (2 * i) - 1; j++) {
                    cout << "*";
                }
                cout << endl;
            }
            for (int i = (n / 2); i >= 1; i--) {
                for (int j = 1; j <= (n / 2) + 1 - i; j++) {
                    cout << space;
                }
                for (int j = 1; j <= (2 * i) - 1; j++) {
                    cout << "*";
                }
                cout << endl;
            }
        }
        else if (choice == 'H') {
            cout << "=====|HOURGLASS|=====" << endl;
            cout << "enter size of Hourglass: " << endl;
            cin >> n;
            for (int i = (n / 2) + 1; i >= 1; i--) {
                for (int j = 1; j <= (n / 2) + 1 - i; j++) {
                    cout << space;
                }
                for (int j = 1; j <= (2 * i) - 1; j++) {
                    cout << "*";
                }
                cout << endl;
            }
            for (int i = 1; i < (n / 2) +1; i++) {
                for (int j = 1; j <= (n / 2)  - i; j++) {
                    cout << space;
                }
                for (int j = 1; j <= (2 * i) + 1; j++) {
                    cout << "*";
                }
                cout << endl;
            }
        }
        else if (choice == 'd') {
            cout << "=====|HOLLOW DIAMOND|=====" << endl;
            cout << "enter size of diamond in odd number (because it is a diamond): " << endl;
            cin >> n;
            for (int i = 1; i <= (n / 2) + 1; i++) {
                for (int j = 1; j <= (n / 2) + 1 - i; j++) {
                    cout << space;
                }
                cout << "*";
                if (i > 1) {
                    for (int j = 1; j <= (2 * i) - 3; j++) {
                        cout << space;
                    }
                    cout << "*";
                }
                cout << endl;
            }
            for (int i = (n / 2); i >= 1; i--) {
                for (int j = 1; j <= (n / 2) + 1 - i; j++) {
                    cout << space;
                }
                cout << "*";
                if (i > 1) {
                    for (int j = 1; j <= (2 * i) - 3; j++) {
                        cout << space;
                    }
                    cout << "*";
                }
                cout << endl;
            }

        }
        else if (choice == 'S') {
            int ct = 0;
            cout << "=====|HEXAGON|=====" << endl;
            cout << "enter size of Hexagon: " << endl;
            cin >> n;
            ct = n;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n - i; j++) {
                    cout << space;
                }
                for (int x = 1; x <= ct; x++) {
                    cout << "*";
                }
                ct = ct + 2;
                cout << endl;
            }
            ct = ct - 2;
            for (int i = 1; i < n; i++) {
                for (int j = 0; j <= i-1; j++) {
                    cout << space;
                }
                for (int x = 1; x < ct -1; x++) {
                    cout << "*";
                }
                ct = ct - 2;
                cout << endl;
            }
        }
        else if (choice == 'C') {
            int digit_print = 0;
            cout << "=====|CONCENTRIC RECTANGLES|=====" << endl;
            cout << "enter size of Rectangle: " << endl;
            cout << "Enter a number: ";
            cin >> n;
            for (int i = 1; i <= n; i++) {
                digit_print = n;
                for (int j = 1; j < 2 * n; j++) {
                    if (i > j) {
                        cout << digit_print;
                        digit_print--;
                    }
                    else if ((i + j) >= 2 * n) {
                        cout << digit_print;
                        digit_print++;
                    }
                    else {
                        cout << digit_print;
                    }
                }
                cout << endl;
            }
            for (int i = 1; i < n; i++) {
                int digit_print = n;
                for (int j = 1; j < 2 * n; j++) {
                    if ((n - i) > j) {
                        cout << digit_print;
                        digit_print--;
                    }
                    else if ((n - i + j) >= 2 * n) {
                        cout << digit_print;
                        digit_print++;
                    }
                    else {
                        cout << digit_print;
                    }
                }
                cout << endl;
            }
            
        }
        else if (choice == 'e' || choice == 'E') {
            cout << "EXITING....";
            return -1;
        }
        else {
            cout << "invalid entry " << endl;
        }
        cout << "do you want to run again? (y/n): " << endl;
        cin >> repeat;

    }

    return 0;
}
