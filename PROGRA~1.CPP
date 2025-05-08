// Programming projects for C++ Chapter 5 Assignment 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Write a program that tells what coins to give out for any amount of change
from 1 cent to 99 cents. For example, if the amount is 86 cents, the output
would be something like the following:

 86 cents can be given as
3 quarter(s) 1 dime(s) and 1 penny(pennies)


 Use coin denominations of 25 cents (quarters), 10 cents (dimes), and 1 cent
(pennies). Do not use nickel and half-dollar coins. Your program will use
the following function (among others):

void compute_coins(int coin_value, int& num, int& amount_left);
//Precondition: 0 < coin_value < 100; 0 <= amount_left < 100.
//Postcondition: num has been set equal to the maximum number
//of coins of denomination coin_value cents that can be obtained
//from amount_left. Additionally, amount_left has been decreased
//by the value of the coins, that is, decreased by
//num * coin_value.


 For example, suppose the value of the variable amount_left is 86. Then,
after the following call, the value of number will be 3 and the value of
amount_left will be 11 (because if you take 3 quarters from 86 cents, that
leaves 11 cents):


*/


#include <iostream>
void compute_coins(int coin_value, int& num, int& amount_left) {
    
        num = amount_left / coin_value;
        amount_left = amount_left % coin_value;
}
//Precondition: 0 < coin_value < 100; 0 <= amount_left < 100.
//Postcondition: num has been set equal to the maximum number
//of coins of denomination coin_value cents that can be obtained
//from amount_left. Additionally, amount_left has been decreased
//by the value of the coins, that is, decreased by
//num * coin_value.
int main()
{
    using namespace std;
    int quarters, dimes, pennies, start, left;
    int x = 1;
    while (x == 1) {
        cout << "Type the cents you want to calculate" << endl;
        cin >> start;
        while (start < 0 || start > 100) {
            std::cout << "No, try again bozo\n";
            std::cin >> start;
        }
        left = start;
        compute_coins(25, quarters, left);
        compute_coins(10, dimes, left);
        compute_coins(1, pennies, left);
        cout << start << " cents can be given as" << endl;
        cout << quarters << " quarter(s) " << dimes << " dime(s) and " << pennies << " penny(pennies)" << endl;
        cout << "type 1 if again, 0 if done." << endl;
        cin >> x;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
