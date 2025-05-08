

#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
void get_time(int& hour, int& minute) {
    using namespace std;
    char colon;
    cout << "What time was your call started? (use military time)" << endl;
    cin >> hour >> colon >> minute;
}
void conversion(int& hour, int& minute, char& AMPM) {
    if (hour > 12) {
        hour -= 12;
        AMPM = 'P';
    }
    else {
        AMPM = 'A';
    }
}
void output(int& hour, int& minute, char& AMPM) {
    using namespace std;
    if (minute <= 0) {
        cout << "The time converted is " << hour << ":" << minute << "0 " << AMPM << "M" << endl;
    }
    else {
        cout << "The time converted is " << hour << ":" << minute << " " << AMPM << "M" << endl;
    }
}
int main()
{
    using namespace std;
    int x = 1;
    while (x == 1) {
        int hour, minute;
        char AMPM;
        get_time(hour, minute);
        conversion(hour, minute, AMPM);
        output(hour, minute, AMPM);
        cout << "type 1 to do it again, 0 to stop" << endl;
        cin >> x;
    }

}

