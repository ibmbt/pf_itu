#include <iostream>
using namespace std;

int DaysInAMonth(int month, int year);
bool IsLeapYear(int year);
bool IsValidDate(int day, int month, int year);
bool IsValidCurrentDate(int dob_day, int dob_month, int dob_year, int c_day, int c_month, int c_year);

int main()
{
    char repeat = 'Y', choice;
    while (repeat == 'Y' || repeat == 'y')
    {
        cout << "============|MENU|============" << endl;
        cout << "[1] Date Validation and Age Calculator" << endl;
        cin >> choice;
        if (choice == '1')
        {
            int dob_day, dob_month, dob_year;
            int c_day, c_month, c_year;
            int age_day, age_month, age_year;
            bool flag = false;
            while (!flag)
            {
                cout << "Enter current date (dd/mm/yyyy): " << endl;
                cin >> c_day >> c_month >> c_year;
                cout << "Enter your date of birth (dd/mm/yyyy): " << endl;
                cin >> dob_day >> dob_month >> dob_year;

                if ((IsValidDate(dob_day, dob_month, dob_year) && IsValidDate(c_day, c_month, c_year)) && (IsValidCurrentDate(dob_day, dob_month, dob_year, c_day, c_month, c_year)))
                {
                    flag = true;
                }
                else
                {
                    if (!(IsValidDate(dob_day, dob_month, dob_year)))
                    {
                        cout << "invalid date of birth" << endl;
                    }
                    if (!(IsValidDate(c_day, c_month, c_year)))
                    {
                        cout << "invalid current date " << endl;
                    }
                    if (!(IsValidCurrentDate(dob_day, dob_month, dob_year, c_day, c_month, c_year)))
                    {
                        cout << "date of birth is greater than the current date " << endl;
                    }
                }
            }
            age_year = c_year - dob_year;
            age_month = c_month - dob_month;
            age_day = c_day - dob_day;
            if (age_day < 0)
            {
                if (c_month == 1)
                {
                    age_day = age_day + DaysInAMonth(12, c_year - 1);
                }
                else
                {
                    age_day = age_day + DaysInAMonth(c_month - 1, c_year);
                }
                age_month--;
            }
            if (age_month < 0)
            {
                age_year--;
                age_month = age_month + 12;
            }
            if (age_day < 0)
            {
                if (IsLeapYear(c_year))
                {
                    age_day = age_day + 2;
                }
                else
                {
                    age_day = age_day + 3;
                }
            }

            cout << "Your age is: " << age_year << " years, " << age_month << " months, and " << age_day << " days." << endl;
        }
        else if (choice == 'e' || choice == 'E')
        {
            cout << "EXITING....";
            return -1;
        }
        else
        {
            cout << "invalid entry " << endl;
        }
        cout << "do you want to run again? (y/n): " << endl;
        cin >> repeat;
    }
    return 0;
}

int DaysInAMonth(int month, int year)
{
    if (month < 1 || month > 12)
    {
        return -1;
    }
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        return 31;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    else if (month == 2)
    {
        if (IsLeapYear(year))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
}

bool IsLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return true;
    }
    return false;
}

bool IsValidDate(int day, int month, int year)
{

    if (month < 1 || month > 12)
    {
        return false;
    }

    if (day > DaysInAMonth(month, year) || day < 1)
    {
        return false;
    }

    return true;
}

bool IsValidCurrentDate(int dob_day, int dob_month, int dob_year, int c_day, int c_month, int c_year)
{
    if ((c_year < dob_year) || (c_year == dob_year && c_month < dob_month) || (c_year == dob_year && c_month == dob_month && c_day < dob_day))
    {
        return false;
    }

    return true;
}