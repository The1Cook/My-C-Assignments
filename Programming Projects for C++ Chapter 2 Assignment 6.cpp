/*An employee is paid at a rate of $16.78 per hour for the first 40 hours
worked in a week. Any hours over that are paid at the overtime rate of one and - one - half times that.
From the worker’s gross pay, 6 % is withheld for
Social Security tax, 14 % is withheld for federal income tax, 5 % is withheld
for state income tax, and $10 per week is withheld for union dues.If the
worker has three or more dependents, then an additional $35 is withheld
to cover the extra cost of health insurance beyond what the employer pays.

Write a program that will read in the number of hours worked in a week
and the number of dependents as input and will then output the worker’s
gross pay, each withholding amount, and the net take - home pay for the
week.For a harder version, write your program so that it allows the calculation to be repeated as often as the user wishes.If this is a class exercise, ask
your instructor whether you should do this harder version*/
#include <iostream>
#include<string>

using namespace std;

int main()
{
    int k = 0;
    while (k == 0) {
        cout << "Give the # of hours you worked and the # of dependents" << endl;
        int hours = 0;
        cin >> hours;
        int dependents = 0;
        cin >> dependents;
        float grossPay = 16.78 * hours;
        if (hours > 40)
            float grossPay = (16.78 * hours) + ((hours - 40) * (16.78 * 1.5));
        cout << "Gross Pay: " << grossPay << endl;
        float AfterSocial = (grossPay * 0.06);
        cout << "After Social Security tax: " << AfterSocial << endl;
        float AfterFed = (grossPay * 0.14);
        cout << "After Federal Income Tax: " << AfterFed << endl;
        float AfterState = (grossPay * 0.05);
        cout << "After State Income Tax: " << AfterState << endl;
        
        float AfterEverything = grossPay - AfterSocial - AfterFed - AfterState - 10;
        if (dependents >= 3)
            AfterEverything -= 35;
        cout << "After all that boring stuff you get to take home $" << AfterEverything << endl;

        cout << "Again? 0 for yes, 1 for no. " << endl;
        cin >> k;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
