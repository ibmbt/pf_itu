#include <iostream>
using namespace std;

bool is_point_inside_flat_rectangle(
    float x1, float y1,
    float x2, float y2,
    float x3, float y3,
    float x4, float y4,
    float test_x, float test_y) {
    if ((test_x >= x1 && test_x <= x4)&&(test_y >= y1 && test_y <= y2)) {
        return true;
    }
    else {
        return false;
    }
}

float get_slope_of_line(float x1, float y1, float x2, float y2) {
    float ans = (y2 - y1) / (x2 - x1);
    return ans;
}

float get_y_intercept(float x1, float y1, float x2, float y2) {
    float ans = y1 - (get_slope_of_line(x1, y1, x2, y2) * x1);
    return ans;

}

void print_equation(float x1, float y1, float x2, float y2) {
    if (get_slope_of_line(x1, y1, x2, y2) == 0) {
        cout << "y=" << get_y_intercept(x1, y1, x2, y2) << endl;
    }
    else if (get_y_intercept(x1, y1, x2, y2) == 0) {
        cout << "y=" << get_slope_of_line(x1, y1, x2, y2) << "x" << endl;
    }
    else {
        cout << "y=" << get_slope_of_line(x1, y1, x2, y2) << "x+" << get_y_intercept(x1, y1, x2, y2) << endl;
    }

}

bool is_point_above_the_line(float x1, float y1, float x2, float y2, float test_x, float test_y) {
    float slope = get_slope_of_line(x1, y1, x2, y2);
    float y_intercept = get_y_intercept(x1, y1, x2, y2);
    if (test_y >= ((slope * test_x) + y_intercept)) {
        return true;
    }
    else {
        return false;
    }
}

bool is_point_below_the_line(float x1, float y1, float x2, float y2, float test_x, float test_y) {
    if (is_point_above_the_line(x1, y1, x2, y2, test_x, test_y)) {
        return false;
    }
    else {
        return true;
    }
}

bool is_point_inside_rotated_rectangle(
    float x1, float y1,
    float x2, float y2,
    float x3, float y3,
    float x4, float y4,
    float test_x, float test_y) {
    if (((is_point_above_the_line(x1, y1, x2, y2, test_x, test_y)) && (is_point_above_the_line(x1, y1, x4, y4, test_x, test_y))) &&
        ((is_point_below_the_line(x2, y2, x3, y3, test_x, test_y)) && (is_point_below_the_line(x3, y3, x4, y4, test_x, test_y)))) {
        return true;
    }
    else{
        return false;
    }
}

int main() {
    char repeat = 'Y', choice;
    while (repeat == 'Y' || repeat == 'y') {
        cout << "============|LAB-10|============" << endl;
        cout << "[1] check point" << endl;
        cout << "[2] slope of line" << endl;
        cout << "[3] y-intercept of line" << endl;
        cout << "[4] in form y=mx+c" << endl;
        cout << "[5] check positoin of test point above line" << endl;
        cout << "[6] check positoin of test point below line" << endl;
        cout << "[7] check point in rotated rectangle" << endl;

        float x1, x2, x3, x4, y1, y2, y3, y4, xt, yt;


        cin >> choice;
        if (choice == '1') {
            cout << "enter p1 (x,y): " << endl;
            cin >> x1 >> y1;
            cout << "enter p2 (x,y): " << endl;
            cin >> x2 >> y2;
            cout << "enter p3 (x,y): " << endl;
            cin >> x3 >> y3;
            cout << "enter p4 (x,y): " << endl;
            cin >> x4 >> y4;
            cout << "enter test point (x,y): " << endl;
            cin >> xt >> yt;
            //add enter new point? enter new rectangle? choice..
            if (is_point_inside_flat_rectangle(x1, y1, x2, y2, x3, y3, x4, y4, xt, yt)) {
                cout << "point inside the rectangle" << endl;
            }
            else {
                cout << "point outside rectangle" << endl;
            }

        }
        else if (choice == '2') {
            cout << "enter point 1 (x,y)" << endl;
            cin >> x1 >> y1;
            cout << "enter point 2 (x,y)" << endl;
            cin >> x2 >> y2;
            cout << "slope of line: " << get_slope_of_line(x1, y1, x2, y2);
        }
        else if (choice == '3') {
            cout << "enter point 1 (x,y)" << endl;
            cin >> x1 >> y1;
            cout << "enter point 2 (x,y)" << endl;
            cin >> x2 >> y2;
            cout << "y-intercept of line is: " << get_y_intercept(x1,y1,x2,y2);

        }
        else if (choice == '4') {
            cout << "enter point 1 (x,y)" << endl;
            cin >> x1 >> y1;
            cout << "enter point 2 (x,y)" << endl;
            cin >> x2 >> y2;
            print_equation(x1, y1, x2, y2);
            

        }
        else if (choice == '5') {
            cout << "enter point 1 (x,y)" << endl;
            cin >> x1 >> y1;
            cout << "enter point 2 (x,y)" << endl;
            cin >> x2 >> y2;
            cout << "enter test point (x,y): " << endl;
            cin >> xt >> yt;
            if (is_point_above_the_line(x1, y1, x2, y2, xt, yt)) {
                cout << "point is above the line" << endl;
            }
            else {
                cout << "point is not above the line" << endl;
            }
        }
        else if (choice == '6') {
            cout << "enter point 1 (x,y)" << endl;
            cin >> x1 >> y1;
            cout << "enter point 2 (x,y)" << endl;
            cin >> x2 >> y2;
            cout << "enter test point (x,y): " << endl;
            cin >> xt >> yt;
            if (is_point_below_the_line(x1, y1, x2, y2, xt, yt)) {
                cout << "point is below the line" << endl;
            }
            else {
                cout << "point is not below the line" << endl;
            }
            
        }
        else if (choice == '7') {
            cout << "enter p1 (x,y): " << endl;
            cin >> x1 >> y1;
            cout << "enter p2 (x,y): " << endl;
            cin >> x2 >> y2;
            cout << "enter p3 (x,y): " << endl;
            cin >> x3 >> y3;
            cout << "enter p4 (x,y): " << endl;
            cin >> x4 >> y4;
            cout << "enter test point (x,y): " << endl;
            cin >> xt >> yt;
            if (is_point_inside_rotated_rectangle(x1,  y1, x2,  y2, x3,  y3, x4,  y4, xt, yt)) {
                cout << "point inside the rectangle" << endl;
            }
            else {
                cout << "point outside rectangle" << endl;
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
