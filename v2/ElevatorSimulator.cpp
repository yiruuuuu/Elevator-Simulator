// 
// The elevator moving speed is one floor per second.

#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>

using namespace std;

class Elevator {

    private:

    int current_floor;

    public:

    // constructor
    Elevator(int floor = 1) {
        current_floor = floor;
    }

    // 顯示目前所在的樓層
    void display_floor() {
        cout << "第 " << current_floor << " 樓" << endl;
    }

    // 移動到指定樓層
    void move(int floor) {

        if(current_floor == floor) {
            cout << "\n抵達";
            display_floor();
            return;
        } else if(current_floor < floor) {
            cout << "電梯往上..." << endl;
        } else {
            cout << "電梯往下..." << endl;
        }

        

        while(current_floor != floor) {

            if(current_floor < floor) {
                ++ current_floor;
            } else {
                -- current_floor;
            }

            cout << "\r>" << setw(3) << current_floor << flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            cout << "\r>>" << setw(2) << current_floor << flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }

        cout << "\n抵達";
        display_floor();
    }

    // 取得當前樓層
    int get_current_floor() {
        return current_floor;
    }
};

int main() {

    Elevator elevator1(1);
    Elevator elevator2(5);

    int user_floor, desired_floor;

    while(1) {

        // 
        cout << "\n============ 電梯 ============" << endl;
        cout << "電梯1 在";
        elevator1.display_floor();
        cout << "電梯2 在";
        elevator2.display_floor();

        // 輸入目前所在樓層
        while(1) {
            cout << "\n輸入目前所在樓層 (1-10，0 結束):";
            cin >> user_floor;

            if(user_floor == 0) {
                return 0;
            } else if(user_floor < 0 || user_floor > 10){
                cout << "無效輸入，請從新輸入！";
            } else {
                break;
            }
        }

        // 輸入要去的樓層
        while(1) {
            cout << "\n輸入想去的樓層 (1-10):";
            cin >> desired_floor;

            if(desired_floor < 1 || desired_floor > 10) {
                cout << "無效輸入，請從新輸入！";
            } else {
                break;
            }
        }

        // 
        int dist1 = abs(elevator1.get_current_floor() - user_floor);
        int dist2 = abs(elevator2.get_current_floor() - user_floor);

        if(dist1 <= dist2) {
            /*
            elevator1比較近
            */
            cout << "╔═══════╗" << endl;
            cout << "║ 電梯1 ║ " << endl;
            cout << "╚═══════╝" << endl;

            if(elevator1.get_current_floor() < user_floor) {
                // 電梯往上到user所在樓層
                elevator1.move(user_floor);
                elevator1.move(desired_floor);
            } else if(elevator1.get_current_floor() > user_floor) {
                // 電梯往下到user所在樓層
                elevator1.move(user_floor);
                elevator1.move(desired_floor);
            } else {
                // 電梯在user所在樓層
                elevator1.move(user_floor);
                elevator1.move(desired_floor);
            }
        } else {
            /*
            elevator2比較近
            */
            cout << "╔═══════╗" << endl;
            cout << "║ 電梯2 ║ " << endl;
            cout << "╚═══════╝" << endl;

            if(elevator2.get_current_floor() < user_floor) {
                // 電梯往上到user所在樓層
                elevator2.move(user_floor);
                elevator2.move(desired_floor);
            } else if(elevator2.get_current_floor() > user_floor) {
                // 電梯往下到user所在樓層
                elevator2.move(user_floor);
                elevator2.move(desired_floor);
            } else {
                // 電梯在user所在樓層
                elevator2.move(user_floor);
                elevator2.move(desired_floor);
            }
        }

    }
}