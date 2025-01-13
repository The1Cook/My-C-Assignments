// make the given program use 12 hour time instead of 24 hour time










/*
Write a program that requests the current time and a waiting time as two
integers for the number of hours and the number of minutes to wait. The
program then outputs what the time will be after the waiting period.

Use 24-hour notation for the times. Include a loop that lets the user repeat this
calculation for additional input values until the user says she or he wants
to end the program




*/


#include <iostream>
#include <string>
void get_times(int& hour, int& min, int& wait, char& AMPM) {
    using namespace std;
    char colon;
    
    cout << "here with no spaces between time and AM/PM: " << endl;
        cin >> hour >> colon >> min >> AMPM >> colon;
        cout << "How long to wait?" << endl;
        cin >> wait;
    
}
void hAM_wait(int& h, int& m, int& wait, char& AMPM) {
    h += wait / 60;
    std::cout << h;
    m = (m + wait) % 60;
    if (h >= 37 && AMPM == 'P') {
        h -= 36;
        AMPM = 'P';
    }
    else if (h >= 25 && AMPM == 'A') {
        h -= 24;
        AMPM = 'A';
    }
    else if (h >= 13 && AMPM == 'A') {
        h -= 12;
        AMPM = 'P';
    }
    else if (h >= 37 && AMPM == 'P') {
        h -= 36;
        AMPM = 'A';
    } 
    else if (h >= 25 && AMPM == 'P') {
        h -= 24;
        AMPM = 'P';
    }
    else if (h >= 13 && AMPM == 'P') {
        h -= 12;
        AMPM = 'A';
    }
    

    

}
void output(int& m, int& h, char& AMPM) {
    using namespace std;
 if (m > 9) {
            h = h % 12;
            if (h == 0)
                h = 12;
            cout << "The time it ends at is " << (h) << ":" << m << AMPM << "M" << endl;
        }
        else {
            h = h % 12;
            if (h == 0)
                h = 12;
            cout << "The time it ends at is " << (h) << ":0" << m << AMPM << "M" << endl;
        }
}
int main()
{
    using namespace std;
    int x = 1;
    int hour, min, wait;
    char AMPM;
    while (x == 1) {
        cout << "Give start time" << endl;
        get_times(hour, min, wait, AMPM);
        hAM_wait(hour, min, wait, AMPM);
        output(min, hour, AMPM);
        cout << "press 1 to do it again, 0 for exit." << endl;
        cin >> x;
    }
}


