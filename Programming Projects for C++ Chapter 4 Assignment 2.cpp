

#include <iostream>
double hat_size(double w, double h);
double jacket_size(double w, double h, int a);
double waist_size(double w, int a);

int main()
{
    using namespace std;
    int x = 1;
    while (x == 1) {
        int w;
        int h;
        int a;
        cout << "What's ur weight in pounds?" << endl;
        cin >> w;
        cout << "What's ur height in inches?" << endl;
        cin >> h;
        cout << "What's ur age?" << endl;
        cin >> a;
        cout << "Hat size: " << hat_size(w, h) << endl;
        cout << "Jacket size: " << jacket_size(w, h, a) << endl;
        cout << "Waist size in inches: " << waist_size(w, a) << endl;
        cout << "Are you done? enter 1 if no, 0 or anything else if yes." << endl;
        cin >> x;
    }

}
double hat_size(double w, double h)
{
    return((w / h) * 2.9);
}
double jacket_size(double w, double h, int a) 
{
    double addition;
    if (a >= 30) {
        addition  = .125 * ((a - 30) / 10);
    }
    else {
        addition = 0;
    }
    
    return(((h * w) / 288) + addition);
}
double waist_size(double w, int a)
{
    double addition;
    if (a >= 28) {
        addition = .1 * ((a - 28) / 2);
    }
    else {
        addition = 0;
    }
    return( (w / 5.7) + addition);
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
