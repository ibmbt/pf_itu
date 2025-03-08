#include <iostream>
using namespace std;

int get_string_length(char str[], int max_size);
void shift_right(char array[], int size, int idx, int no_of_times);
void shift_left(char array[], int size, int idx, int no_of_times);
int count_characters(char array[], int max_size);
int count_specific_character(char array[], const int max_size, char target_char);
int count_words(char array[], int max_size);
int count_sentences(char array[], int max_size);
int count_paragraphs(char array[], int max_size);
void append_text(char array[], int max_essay_size, char str_to_append[], int max_str_app_size);
void edit_text(char array[], int max_essay_size, char str_to_edit[], int max_edit_size, int idx);
int search_string(char array[], int max_array_size, char search_str[], int max_search_str);
void delete_str(char array[], int max_array_size, char str_to_delete[], int max_str_delete);
void search_and_replace(char array[], int max_array_size, char search_str[], int max_search_size, char edited_str[], int max_edited_size);



int main() {
    char choice;
    do {
        cout << "==========||MAIN MENU||==========" << endl;
        cout << "[1] total character count" << endl;
        cout << "[2] count target character" << endl;
        cout << "[3] total words" << endl;
        cout << "[4] total sentences" << endl;
        cout << "[5] total paragraphs" << endl;
        cout << "[6] append text" << endl;
        cout << "[7] edit text character" << endl;
        cout << "[8] search for string" << endl;
        cout << "[9] delete string" << endl;
        cout << "[0] search and replace" << endl;
        cout << "[E] to exit" << endl;
        cin >> choice;

        const int size = 1000;
        char arr[size] = { '\0' };
        char stop[5] = { 'S','T','O','P','\0'};;
        char arr1[size] = { '\0' };
        int count = 0;
        int len = 0;
        char str_to_append[size] = { '\0' };
        int index = 0;
        char str_to_search[size] = { '\0' };
        char str_to_delete[size] = { '\0' };
        char str_to_edit[size] = { '\0' };
        char target_character;
        int found = 0;

        switch (choice) {
        case '1':
            cin.ignore();
            cout << "enter essay" << endl;
            cin.getline(arr, size);
            cout << "character count: " << endl;
            cout << count_characters(arr, size) << endl;
            break;
        case '2':
            cin.ignore();
            char target;
            cout << "enter essay" << endl;
            cin.getline(arr, size);
            cout << "enter target character" << endl;
            cin >> target_character;
            cout << target_character << " is found " << count_specific_character(arr, size, target_character) << " many times. " << endl;
            break;
        case '3':
            cin.ignore();
            cout << "enter essay" << endl;
            cin.getline(arr, size);
            cout << "total words: " << count_words(arr, size) << endl;
            break;
        case '4':
            cin.ignore();
            cout << "enter essay" << endl;
            cin.getline(arr, size);
            cout << "total sentencs: " << count_sentences(arr, size) << endl;
            break;
        case '5':
            cin.ignore();
            cout << "enter 'STOP' to stop writing" << endl;
            while (true){
                cin.getline(arr, size);
                len = get_string_length(arr, size);
                if (get_string_length(arr, size) == get_string_length(stop, 5)) {
                    for (int i = 0; i < 4; i++) {
                        if (arr[i] == stop[i]) {
                            found++;
                        }
                        
                    }
                    if (found == 4) {
                        break;
                    }
                    
                }
                for (int i = 0; i < len; i++) {
                    arr1[count] = arr[i];
                    count++;
                }
                arr1[count] = '\n';
                count++;
        
            }
            cout << "total paragraphs found: " << count_paragraphs(arr1, size) << endl;
            break;
        case '6':
            cin.ignore();
            cout << "enter essay" << endl;
            cin.getline(arr, size);
            cout << "enter string to append: " << endl;
            cin.getline(str_to_append, size);
            append_text(arr, size, str_to_append, size);
            cout << "appended text is: " << endl;
            cout << arr << endl;
            break;
        case '7':
            cin.ignore();
            cout << "enter essay" << endl;
            cin.getline(arr, size);
            cout << "enter string to edit: " << endl;
            cin.getline(str_to_append, size);
            cin >> index;
            edit_text(arr, size, str_to_append, size, index);
            cout << "edited test is: " << endl;
            cout << arr << endl;
            break;
        case '8':
            cin.ignore();
            cout << "enter essay" << endl;
            cin.getline(arr, size);
            cout << "enter string to search for: " << endl;
            cin.getline(str_to_search, size);
            found = search_string(arr, size, str_to_search, size);
            if (found == -1) {
                cout << str_to_search << " not found." << endl;
            }
            else {
                cout << str_to_search << " found at index " << found << ". " << endl;
            }
            break;
        case '9':
            cin.ignore();
            cout << "enter essay" << endl;
            cin.getline(arr, size);
            cout << "enter string to delete: " << endl;
            cin.getline(str_to_delete, size);
            delete_str(arr, size, str_to_delete, size);
            cout << "text after deletion: " << endl;
            cout << arr << endl;
            break;
        case '0':
            cin.ignore();
            cout << "enter essay" << endl;
            cin.getline(arr, size);
            cout << "enter string to search for: " << endl;
            cin.getline(str_to_search, size);
            cout << "enter string to edit (add): " << endl;
            cin.getline(str_to_edit, size);
            search_and_replace(arr, size, str_to_search, size,str_to_edit, size);
            cout << "text searched for and replaced: " << endl;
            cout << arr << endl;
            break;
        default:
            if (choice != 'E') {
                cout << "Invalid choice, please try again." << endl;
            }
        }
    } while (choice != 'E');

}


int get_string_length(char array[], int max_size) {
    int length = 0;
    while (length < max_size && array[length] != '\0') {
        length++;
    }
    return length;
}

void shift_right(char array[], int size, int idx, int no_of_times) {
    for (int j = 0; j < no_of_times; j++) {
        for (int i = size - 1; i > idx; i--) {
            array[i] = array[i - 1];
        }
    }
}

void shift_left(char array[], int size, int idx, int no_of_times) {
    for (int j = 0; j < no_of_times; j++) {
        for (int i = idx; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
    }
}

int count_characters(char array[], int max_size) {
    int count = 0, max = 0;
    max = get_string_length(array, max_size);
    for (int i = 0; i < max; i++) {
        if (array[i] != ' ') {
            count++;
        }
    }
    return count;
}

int count_specific_character(char array[], const int max_size, char target_char) {
    int count = 0, max = 0;
    max = get_string_length(array, max_size);
    for (int i = 0; i < max; i++) {
        if (array[i] == target_char) {
            count++;
        }
    }
    return count;
}

int count_words(char array[], int max_size) {
    int count = 1, max = 0;
    max = get_string_length(array, max_size);
    for (int i = 0; i < max; i++) {
        if (array[i] == ' ') {
            count++;
        }
    }
    return count;

}

int count_sentences(char array[], int max_size){
    int count = 1, max = 0;
    max = get_string_length(array, max_size);
    for (int i = 0; i < max; i++) {
        if ((array[i] == '.' && array[i + 1] == ' ') || (array[i] == '?' && array[i + 1] == ' ')){
            count++;
        }
    }
    return count;
}

int count_paragraphs(char array[], int max_size) {
    int count = 0, max = 0;
    max = get_string_length(array, max_size);
    for (int i = 0; i < max; i++) {
        if (array[i] == '\n') {
            count++;
        }
    }
    return count;
}

void append_text(char array[], int max_array_size, char str_to_append[], int max_str_app_size) {
    int len_array = get_string_length(array, max_array_size);
    int len_array_append = get_string_length(str_to_append, max_str_app_size);
    if (len_array + len_array_append < max_array_size) {
        int i = 0;
        array[len_array] = ' ';
        while (str_to_append[i] != '\0') {
            array[len_array + i + 1] = str_to_append[i];
            i++;
        }
        array[len_array + i+1] = '\0';
    }
}

void edit_text(char array[], int max_array_size, char str_to_edit[], int max_edit_size, int idx) {
    int len_array = get_string_length(array, max_array_size);
    int len_array_edit = get_string_length(str_to_edit, max_edit_size);
    if (len_array + len_array_edit < max_array_size) {
        shift_right(array, max_array_size, idx, len_array_edit+1);
        for (int i = 0; i < len_array_edit; i++) {
            array[idx + i] = str_to_edit[i];
        }
        array[idx + len_array_edit] = ' ';
    }
}

int search_string(char array[], int max_array_size, char search_str[], int max_search_str) {
    int len_array = get_string_length(array, max_array_size);
    int len_search_str = get_string_length(search_str, max_search_str);
    bool found = false;
    for (int i = 0; i < len_array; i++) {
        if (search_str[0] == array[i]) {
            found = true;
            for (int j = 1; j < len_search_str; j++) {
                if (search_str[j] != array[i + j]) {
                    found = false;
                    break;
                }

            }
            if (found == true) {
                return i;
            }
        }
    }
    return -1;

}


void delete_str(char array[], int max_array_size, char str_to_delete[], int max_str_delete) {
    int len_array = get_string_length(array, max_array_size);
    int len_delete_str = get_string_length(str_to_delete, max_str_delete);
    int idx = search_string(array, max_array_size, str_to_delete, max_str_delete);
    if (idx != -1) {
        if (idx == 0) {
            if (array[idx + len_delete_str] == ' ') {
                shift_left(array, len_array, idx, len_delete_str + 1);
            }
            else {
                shift_left(array, len_array, idx, len_delete_str);
            }
        }
        else if (array[idx - 1] == ' ') {
            shift_left(array, len_array, idx - 1, len_delete_str + 1);
        }
        else if (array[idx + len_delete_str] == ' ') {
            shift_left(array, len_array, idx, len_delete_str + 1);
        }
        else {
            shift_left(array, len_array, idx, len_delete_str);
        }
        len_array = len_array - (len_delete_str + 1);
        if (len_array >= 0) {
            array[len_array] = '\0';
        }
    }
}


void search_and_replace(char array[], int max_array_size, char search_str[], int max_search_size, char edited_str[], int max_edited_size) {
    int idx = 0;
    do {
        int len_array = get_string_length(array, max_array_size);
        int len_search_str = get_string_length(search_str, max_search_size);
        int len_edit_str = get_string_length(edited_str, max_edited_size);
        int diff = len_search_str - len_edit_str;
        idx = search_string(array, max_array_size, search_str, max_search_size);
        if (idx != -1) {
            if (diff > 0) {
                shift_left(array, len_array, idx, diff);
                for (int i = 0; i < len_edit_str; i++) {
                    array[idx + i] = edited_str[i];
                }
                array[len_array - diff] = '\0';
            }
            else {
                diff = diff * (-1);
                len_array = len_array + diff;
                shift_right(array, len_array, idx, diff);
                for (int i = 0; i < len_edit_str; i++) {
                    array[idx + i] = edited_str[i];
                }
            }
        }
    } while (idx != -1);
}