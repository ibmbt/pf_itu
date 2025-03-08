#include <iostream>
using namespace std;

void add_student_record(int rol[], int s1[], int s2[], int s3[], int s4[], int s5[], int s6[], int ch1[], int ch2[], int ch3[], int ch4[], int ch5[], int ch6[], int& size) {
    if (size >= 1000) {
        cout << "Maximum student limit reached." << endl;
        return;
    }
    cout << "Enter roll: ";
    cin >> rol[size];
    for (int i = 1; i <= 6; i++) {
        cout << "Enter Sub" << i << " Marks: ";
        if (i == 1) {
            cin >> s1[size];
        }
        else if (i == 2) {
            cin >> s2[size];
        }
        else if (i == 3) {
            cin >> s3[size];
        }
        else if (i == 4) {
            cin >> s4[size];
        }
        else if (i == 5) {
            cin >> s5[size];
        }
        else {
            cin >> s6[size];
        }

        cout << "Enter Sub" << i << " Credit Hours: ";
        if (i == 1) {
            cin >> ch1[size];
        }
        else if (i == 2) {
            cin >> ch2[size];
        }
        else if (i == 3) {
            cin >> ch3[size];
        }
        else if (i == 4) {
            cin >> ch4[size];
        }
        else if (i == 5) {
            cin >> ch5[size];
        }
        else {
            cin >> ch6[size];
        }
    }
    size++;
}


int find_student(int rol[], int size, int roll) {
    for (int i = 0; i <= size; i++) {
        if (rol[i] == roll) {
            return i;
        }
    }
    return -1;
}

double calculate_sgpa(int s1, int s2, int s3, int s4, int s5, int s6, int ch1, int ch2, int ch3, int ch4, int ch5, int ch6) {
    double total_points = 0;
    double total_credits = 0;

    int marks[6] = { s1, s2, s3, s4, s5, s6 };
    int credits[6] = { ch1, ch2, ch3, ch4, ch5, ch6 };

    for (int i = 0; i < 6; i++) {
        double point = 0;
        if (marks[i] >= 90) point = 4.0;
        else if (marks[i] >= 85) point = 3.67;
        else if (marks[i] >= 80) point = 3.33;
        else if (marks[i] >= 75) point = 3.00;
        else if (marks[i] >= 70) point = 2.67;
        else if (marks[i] >= 65) point = 2.33;
        else if (marks[i] >= 60) point = 2.00;
        else if (marks[i] >= 55) point = 1.67;
        else if (marks[i] >= 50) point = 1.00;
        else point = 0;

        total_points = total_points + (point * credits[i]);
        total_credits = total_credits + credits[i];
    }

    if (total_credits == 0) {
        return 0;
    }
    else {
        return total_points / total_credits;
    }
}

void calculate_all_sgpa(double sgpa[], int s1[], int s2[], int s3[], int s4[], int s5[], int s6[], int ch1[], int ch2[], int ch3[], int ch4[], int ch5[], int ch6[], int size) {
    for (int i = 0; i <= size; i++) {
        sgpa[i] = calculate_sgpa(s1[i], s2[i], s3[i], s4[i], s5[i], s6[i], ch1[i], ch2[i], ch3[i], ch4[i], ch5[i], ch6[i]);
    }
}

void update_student_record(int rol[], int s1[], int s2[], int s3[], int s4[], int s5[], int s6[], int ch1[], int ch2[], int ch3[], int ch4[], int ch5[], int ch6[], int size) {
    int roll;
    cout << "Enter the roll number to update: ";
    cin >> roll;
    int index = find_student(rol, size, roll);
    if (index != -1) {
        for (int i = 1; i <= 6; i++) {
            cout << "Enter new Sub" << i << " Marks: ";
            if (i == 1) {
                cin >> s1[index];
            }
            else if (i == 2) {
                cin >> s2[index];
            }
            else if (i == 3) {
                cin >> s3[index];
            }
            else if (i == 4) {
                cin >> s4[index];
            }
            else if (i == 5) {
                cin >> s5[index];
            }
            else {
                cin >> s6[index];
            }
            cout << "Enter new Sub" << i << " Credit Hours: ";
            if (i == 1) {
                cin >> ch1[index];
            }
            else if (i == 2) {
                cin >> ch2[index];
            }
            else if (i == 3) {
                cin >> ch3[index];
            }
            else if (i == 4) {
                cin >> ch4[index];
            }
            else if (i == 5) {
                cin >> ch5[index];
            }
            else {
                cin >> ch6[index];
            }
        }
        cout << "Student record updated successfully." << endl;
    }
    else {
        cout << "Student record not found." << endl;
    }
}

void print_student_record(int roll, int s1, int s2, int s3, int s4, int s5, int s6, int ch1, int ch2, int ch3, int ch4, int ch5, int ch6, double sgpa) {
    cout << "Student Roll Number: " << roll << endl;
    cout << "Subject 1 Marks: " << s1 << "  Credit Hours: " << ch1 << endl;
    cout << "Subject 2 Marks: " << s2 << "  Credit Hours: " << ch2 << endl;
    cout << "Subject 3 Marks: " << s3 << "  Credit Hours: " << ch3 << endl;
    cout << "Subject 4 Marks: " << s4 << "  Credit Hours: " << ch4 << endl;
    cout << "Subject 5 Marks: " << s5 << "  Credit Hours: " << ch5 << endl;
    cout << "Subject 6 Marks: " << s6 << "  Credit Hours: " << ch6 << endl;
    cout << "SGPA: " << calculate_sgpa(s1, s2, s3, s4, s5, s6, ch1, ch2, ch3, ch4, ch5, ch6) << endl;
}

void print_students_record(int rol[], int s1[], int s2[], int s3[], int s4[], int s5[], int s6[], int ch1[], int ch2[], int ch3[], int ch4[], int ch5[], int ch6[], double sgpa[], int size) {
    if (size == 0) {
        cout << "No student records found.\n";
        return;
    }

    calculate_all_sgpa(sgpa, s1, s2, s3, s4, s5, s6, ch1, ch2, ch3, ch4, ch5, ch6, size);

    for (int i = 0; i < size; i++) {
        cout << "Student " << (i + 1) << ":\n";
        print_student_record(rol[i], s1[i], s2[i], s3[i], s4[i], s5[i], s6[i], ch1[i], ch2[i], ch3[i], ch4[i], ch5[i], ch6[i], sgpa[i]);
    }
}

void delete_student_record(int rol[], int s1[], int s2[], int s3[], int s4[], int s5[], int s6[], int ch1[], int ch2[], int ch3[], int ch4[], int ch5[], int ch6[], int& size) {
    int roll;
    cout << "Enter the roll number to delete: ";
    cin >> roll;
    int index = find_student(rol, size, roll);
    if (index != -1) {
        for (int i = index; i < size - 1; i++) {
            rol[i] = rol[i + 1];
            s1[i] = s1[i + 1];
            s2[i] = s2[i + 1];
            s3[i] = s3[i + 1];
            s4[i] = s4[i + 1];
            s5[i] = s5[i + 1];
            s6[i] = s6[i + 1];
            ch1[i] = ch1[i + 1];
            ch2[i] = ch2[i + 1];
            ch3[i] = ch3[i + 1];
            ch4[i] = ch4[i + 1];
            ch5[i] = ch5[i + 1];
            ch6[i] = ch6[i + 1];
        }
        size--;
        cout << "Student record with roll number " << roll << " deleted successfully." << endl;
    }
    else {
        cout << "Student record not found." << endl;
    }
}


int main() {
	int rollnumber[1000], sub1[1000], sub2[1000], sub3[1000], sub4[1000], sub5[1000], sub6[1000];
	int credithour1[1000], credithour2[1000], credithour3[1000], credithour4[1000], credithour5[1000], credithour6[1000];
	int size = 0, choice = -1, index = 0;
	double sgpa[1000];

    do {
        cout << "Student Record Management System" << endl;
        cout << "[1] Add Student Record" << endl;
        cout << "[2] Update Student Record" << endl;;
        cout << "[3] Show Student Record" << endl;
        cout << "[4] Show All Students' Records" << endl;
        cout << "[5] Delete Student Record" << endl;
        cout << "[6] Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: add_student_record(rollnumber, sub1, sub2, sub3, sub4, sub5, sub6, credithour1, credithour2, credithour3, credithour4, credithour5, credithour6, size); break;
        case 2: update_student_record(rollnumber, sub1, sub2, sub3, sub4, sub5, sub6, credithour1, credithour2, credithour3, credithour4, credithour5, credithour6, size); break;
        case 3: {
            int roll_number;
            cout << "roll number of student? " << endl;
            cin >> roll_number;
            index = find_student(rollnumber, size, roll_number);
            if (index != -1) {
                print_student_record(roll_number, sub1[index], sub2[index], sub3[index], sub4[index], sub5[index], sub6[index], credithour1[index], credithour2[index], credithour3[index], credithour4[index], credithour5[index], credithour6[index], sgpa[index]);
            }
            else {
                cout << "Student record not found." << endl;
            }
            break;
        }
        case 4: print_students_record(rollnumber, sub1, sub2, sub3, sub4, sub5, sub6,credithour1, credithour2, credithour3, credithour4, credithour5, credithour6, sgpa, size); break;
        case 5: delete_student_record(rollnumber, sub1, sub2, sub3, sub4, sub5, sub6, credithour1, credithour2, credithour3, credithour4, credithour5, credithour6, size); break;
        case 6: cout << "Exiting..." << endl; break;
        default: cout << "Invalid choice. Please try again." << endl; break;
        }

    } while (choice != 6);


	return 0;
}