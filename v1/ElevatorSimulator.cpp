#include <iostream>

using namespace std;

class Elevator {

    private:

    int current_floor;

    public:

    // 
    Elevator(int floor = 1) {
        current_floor = floor;
    }

    //
    void display_floor() {
        cout << "在第 " << current_floor << " 樓" << endl;
    }

    //
    void move(int floor) {
        current_floor = floor;
        display_floor();
    }

    //
    int get_current_floor() {
        return current_floor;
    }
};

int main() {

    Elevator elevator1(1);
    Elevator elevator2(5);

    int user_floor, desired_floor;

    while(1) {
        cout << "\n========== 電梯 ==========" << endl;
        cout << "電梯1 ";
        elevator1.display_floor();
        cout << "電梯2 ";
        elevator2.display_floor();

        cout << "\n輸入目前所在樓層 (1-10，0 結束):";
        cin >> user_floor;
        if (user_floor == 0) {
            break;
        }

        cout << "輸入想去的樓層 (1-10):";
        cin >> desired_floor;

        int dist1 = abs(elevator1.get_current_floor() - user_floor);
        int dist2 = abs(elevator2.get_current_floor() - user_floor);

        if(dist1 <= dist2) {
            if(elevator1.get_current_floor() < user_floor) {
                cout << "電梯1往上中..." << endl;
                cout << "電梯1 ";
                elevator1.move(user_floor);
                cout << "電梯1 ";
                elevator1.move(desired_floor);
            } else if(elevator1.get_current_floor() > user_floor) {
                cout << "電梯1往下中..." << endl;
                cout << "電梯1 ";
                elevator1.move(user_floor);
                cout << "電梯1 ";
                elevator1.move(desired_floor);
            } else {
                cout << "電梯1 ";
                elevator1.move(user_floor);
                cout << "電梯1 ";
                elevator1.move(desired_floor);
            }
        } else {
            if(elevator2.get_current_floor() < user_floor) {
                cout << "電梯2往上中..." << endl;
                cout << "電梯2 ";
                elevator2.move(user_floor);
                cout << "電梯2 ";
                elevator2.move(desired_floor);
            } else if(elevator2.get_current_floor() > user_floor) {
                cout << "電梯2往下中..." << endl;
                cout << "電梯2 ";
                elevator2.move(user_floor);
                cout << "電梯2 ";
                elevator2.move(desired_floor);
            } else {
                cout << "電梯2 ";
                elevator2.move(user_floor);
                cout << "電梯2 ";
                elevator2.move(desired_floor);
            }
        }

    }
}