
/*
Write a program that requests the current time and a waiting time as two
integers for the number of hours and the number of minutes to wait. The
program then outputs what the time will be after the waiting period. 

Use 24-hour notation for the times. Include a loop that lets the user repeat this
calculation for additional input values until the user says she or he wants
to end the program




*/


#include <iostream>
void get_times(int& hour, int& min, int&wait) {
    using namespace std;
    char colon;
    cout << "here: " << endl;
    cin >> hour >> colon >> min;
    cout << "How long to wait?" << endl;
    cin >> wait;
}
void hAM_wait(int&h, int&m, int&wait) {
    
    m += (h*60 + wait);
}
void output(int& m) {
    using namespace std;
    if (m%60 <= 9) {
        cout << "The wait will be until " << m/60 << ":0" << m%60 << endl;
    }
    else {
        cout << "The wait will be until " << m/60 << ":" << m%60 << endl;
    }
}
int main()
{
    using namespace std;
    int x = 1;
    int hour, min, wait;
    
    while (x == 1) {
        cout << "Give start time" << endl;
        get_times(hour, min, wait);
        hAM_wait(hour, min, wait);
        output(min);
        cout << "press 1 to do it again, 0 for exit." << endl;
        cin >> x;
    }
}
