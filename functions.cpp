#include <iostream>
using namespace std;

int count_characters(char array[], int max_size)
{
    int count = 0, max = 0;
    max = get_string_length(array, max_size);
    for (int i = 0; i < max; i++)
    {
        if (array[i] != ' ')
        {
            count++;
        }
    }
    return count;
}

int count_specific_character(char array[], const int max_size, char target_char)
{
    int count = 0, max = 0;
    max = get_string_length(array, max_size);
    for (int i = 0; i < max; i++)
    {
        if (array[i] == target_char)
        {
            count++;
        }
    }
    return count;
}

int count_words(char array[], int max_size)
{
    int count = 1, max = 0;
    max = get_string_length(array, max_size);
    for (int i = 0; i < max; i++)
    {
        if (array[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

int count_sentences(char array[], int max_size)
{
    int count = 1, max = 0;
    max = get_string_length(array, max_size);
    for (int i = 0; i < max; i++)
    {
        if ((array[i] == '.' && array[i + 1] == ' ') || (array[i] == '?' && array[i + 1] == ' '))
        {
            count++;
        }
    }
    return count;
}

int count_paragraphs(char array[], int max_size)
{
    int count = 0, max = 0;
    max = get_string_length(array, max_size);
    for (int i = 0; i < max; i++)
    {
        if (array[i] == '\n')
        {
            count++;
        }
    }
    return count;
}

void append_text(char array[], int max_array_size, char str_to_append[], int max_str_app_size)
{
    int len_array = get_string_length(array, max_array_size);
    int len_array_append = get_string_length(str_to_append, max_str_app_size);
    if (len_array + len_array_append < max_array_size)
    {
        int i = 0;
        array[len_array] = ' ';
        while (str_to_append[i] != '\0')
        {
            array[len_array + i + 1] = str_to_append[i];
            i++;
        }
        array[len_array + i + 1] = '\0';
    }
}

void edit_text(char array[], int max_array_size, char str_to_edit[], int max_edit_size, int idx)
{
    int len_array = get_string_length(array, max_array_size);
    int len_array_edit = get_string_length(str_to_edit, max_edit_size);
    if (len_array + len_array_edit < max_array_size)
    {
        shift_right(array, max_array_size, idx, len_array_edit + 1);
        for (int i = 0; i < len_array_edit; i++)
        {
            array[idx + i] = str_to_edit[i];
        }
        array[idx + len_array_edit] = ' ';
    }
}

int search_string(char array[], int max_array_size, char search_str[], int max_search_str)
{
    int len_array = get_string_length(array, max_array_size);
    int len_search_str = get_string_length(search_str, max_search_str);
    bool found = false;
    for (int i = 0; i < len_array; i++)
    {
        if (search_str[0] == array[i])
        {
            found = true;
            for (int j = 1; j < len_search_str; j++)
            {
                if (search_str[j] != array[i + j])
                {
                    found = false;
                    break;
                }
            }
            if (found == true)
            {
                return i;
            }
        }
    }
    return -1;
}

void delete_str(char array[], int max_array_size, char str_to_delete[], int max_str_delete)
{
    int len_array = get_string_length(array, max_array_size);
    int len_delete_str = get_string_length(str_to_delete, max_str_delete);
    int idx = 0;
    idx = search_string(array, max_array_size, str_to_delete, max_str_delete);
    shift_left(array, len_array, idx, len_delete_str);
    array[len_array - len_delete_str] = '\0';
}

void search_and_replace(char array[], int max_array_size, char search_str[], int max_search_size, char edited_str[], int max_edited_size)
{
    int len_array = get_string_length(array, max_array_size);
    int len_search_str = get_string_length(search_str, max_search_size);
    int len_edit_str = get_string_length(edited_str, max_edited_size);
    int diff = len_search_str - len_edit_str;
    int idx = 0;
    idx = search_string(array, max_array_size, search_str, max_search_size);
    if (diff > 0)
    {
        shift_left(array, len_array, idx, diff);
        for (int i = 0; i < len_edit_str; i++)
        {
            array[idx + i] = edited_str[i];
        }
        array[len_array - diff] = '\0';
    }
    else
    {
        diff = diff * (-1);
        len_array = len_array + diff;
        shift_right(array, len_array, idx, diff);
        for (int i = 0; i < len_edit_str; i++)
        {
            array[idx + i] = edited_str[i];
        }
    }
}

int get_string_length(char array[], int max_size)
{
    int length = 0;
    while (length < max_size && array[length] != '\0')
    {
        length++;
    }
    return length;
}

void shift_right(char array[], int size, int idx, int no_of_times)
{
    for (int j = 0; j < no_of_times; j++)
    {
        for (int i = size - 1; i > idx; i--)
        {
            array[i] = array[i - 1];
        }
    }
    // abcdef --> abc_def
}

void shift_left(char array[], int size, int idx, int no_of_times)
{
    for (int j = 0; j < no_of_times; j++)
    {
        for (int i = idx; i < size - 1; i++)
        {
            array[i] = array[i + 1];
        }
    }
    // abcdef ---> abcef
}

void ascending_sort(int numbers[], int size)
{
    int min = 0, temp = 0;

    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (numbers[j] < numbers[min])
            {
                min = j;
            }
        }
        temp = numbers[min];
        numbers[min] = numbers[i];
        numbers[i] = temp;
    }
}

void merge_sorted(int arr1[], int s1, int arr2[], int s2, int merged[])
{
    int i = 0, j = 0, k = 0;

    ascending_sort(arr1, s1);
    ascending_sort(arr2, s2);

    while (i < s1 && j < s2)
    {
        if (arr1[i] < arr2[j])
        {
            merged[k] = arr1[i];
            k = k + 1;
            i = i + 1;
        }
        else
        {
            merged[k] = arr2[j];
            k = k + 1;
            j = j + 1;
        }
    }
    while (i < s1)
    {
        merged[k] = arr1[i];
        k = k + 1;
        i = i + 1;
    }
    while (j < s2)
    {
        merged[k] = arr2[j];
        k = k + 1;
        j = j + 1;
    }
    cout << "union of arrays: ";
    for (int x = 0; x < k; x++)
    {
        cout << merged[x] << " ";
    }
    cout << endl;
}

void insert_into_sorted_array(int arr[], int &size, int element)
{
    int position = 0;
    position = binary_search(arr, size, element);

    for (int i = size; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    size++;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
        cout << endl;
    }
}

void union_arrays(int arr1[], int n, int arr2[], int m)
{
    int k = n + m;
    int merged[100];

    for (int i = 0; i < n; i++)
    {
        merged[i] = arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        merged[n + i] = arr2[i];
    }
    ascending_sort(merged, k);
    for (int i = 0; i < k; i++)
    {
        cout << merged[i] << " ";
    }
    cout << endl;
}

int count_distinct(int arr1[], int size)
{
    ascending_sort(arr1, size);
    int count = 0;

    for (int i = 1; i < size; i++)
    {
        if (arr1[i] != arr1[i - 1])
        {
            count++;
        }
        else
        {
        }
    }

    return count;
}

int binary_search(int numbers[], int size, int find)
{
    int start = 0, end = size - 1, mid = 0;
    ascending_sort(numbers, size);
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (find == numbers[mid])
        {
            return mid;
        }
        else if (find > numbers[mid])
        {
            start = mid + 1;
        }
        else if (find < numbers[mid])
        {
            end = mid - 1;
        }
    }
    return -1;
}

void remove(int numbers[], int size, int remove_number)
{
    int capacity = 0;
    int p1 = 0, p2 = 0;
    for (int p2 = 0; p2 < size; p2++)
    {
        if (numbers[p2] != remove_number)
        {
            numbers[p1] = numbers[p2];
            p1 = p1 + 1;
        }
    }
    capacity = p1;
}

int binaryindex_search(int numbers[], int size)
{
    int start = 0, end = size - 1, mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (mid + 1 == numbers[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return start;
}

int power(double base, int exponent)
{
    int ans = 1;
    for (int i = 0; i < exponent; i++)
    {
        ans = ans * base;
    }
    return ans;
}

int factorial(int n)
{
    int ans = 1;
    while (n != 1)
    {
        ans = ans * n;
        n--;
    }
    return ans;
}

double array_mean(int arr[], int size)
{
    double sum = 0.0;
    double average = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    average = sum / size;
    return average;
}

int sum_of_digits(int num)
{
    int ans = 0;
    while (num != 0)
    {
        ans = ans + (num % 10);
        num = num / 10;
    }
    return ans;
}

bool is_prime(int num)
{
    if (num < 2)
    {
        return false;
    }
    for (int i = 2; i <= (sqrt(num)); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
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

bool is_point_inside_flat_rectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float test_x, float test_y)
{
    if ((test_x >= x1 && test_x <= x4) && (test_y >= y1 && test_y <= y2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

float get_slope_of_line(float x1, float y1, float x2, float y2)
{
    float ans = (y2 - y1) / (x2 - x1);
    return ans;
}

float get_y_intercept(float x1, float y1, float x2, float y2)
{
    float ans = y1 - (get_slope_of_line(x1, y1, x2, y2) * x1);
    return ans;
}

void print_equation(float x1, float y1, float x2, float y2)
{
    if (get_slope_of_line(x1, y1, x2, y2) == 0)
    {
        cout << "y=" << get_y_intercept(x1, y1, x2, y2) << endl;
    }
    else if (get_y_intercept(x1, y1, x2, y2) == 0)
    {
        cout << "y=" << get_slope_of_line(x1, y1, x2, y2) << "x" << endl;
    }
    else
    {
        cout << "y=" << get_slope_of_line(x1, y1, x2, y2) << "x+" << get_y_intercept(x1, y1, x2, y2) << endl;
    }
}

bool is_point_above_the_line(float x1, float y1, float x2, float y2, float test_x, float test_y)
{
    float slope = get_slope_of_line(x1, y1, x2, y2);
    float y_intercept = get_y_intercept(x1, y1, x2, y2);
    if (test_y >= ((slope * test_x) + y_intercept))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_point_below_the_line(float x1, float y1, float x2, float y2, float test_x, float test_y)
{
    if (is_point_above_the_line(x1, y1, x2, y2, test_x, test_y))
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool is_point_inside_rotated_rectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float test_x, float test_y)
{
    if (((is_point_above_the_line(x1, y1, x2, y2, test_x, test_y)) && (is_point_above_the_line(x1, y1, x4, y4, test_x, test_y))) &&
        ((is_point_below_the_line(x2, y2, x3, y3, test_x, test_y)) && (is_point_below_the_line(x3, y3, x4, y4, test_x, test_y))))
    {
        return true;
    }
    else
    {
        return false;
    }
}
