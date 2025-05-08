#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
const int MAX_HEALTH = 100;
const int MAX_HISTORY = 5;
// Function declarations
void displayHealthBar(int health);
int takeDamage(int currentHealth, int damage, int damageHistory[], int& index);
void heal(int& currentHealth, int amount);
void showStatusEffects(const vector<string>& effects);
void loadPlayerData(string& name, int& health);
int main() {
    string playerName;
    int health;
    loadPlayerData(playerName, health);
    int damageHistory[MAX_HISTORY] = { 0 };
    int historyIndex = 0;
    vector<string> statusEffects;
    cout << "Welcome, " << playerName << "!" << endl;
    char choice;
    do {
        cout << "\nCurrent Health: " << health << endl;
        displayHealthBar(health);
        cout << "Choose an action:\n"
            << "D - Take damage\n"
            << "H - Heal\n"
            << "S - Add status effect\n"
            << "V - View status effects\n"
            << "Q - Quit\n"
            << "Enter choice: ";
        cin >> choice;
        choice = toupper(choice);
        if (choice == 'D') {
            int damage;
            cout << "Enter damage amount: ";
            cin >> damage;
            health = takeDamage(health, damage, damageHistory, historyIndex);
        }
        else if (choice == 'H') {
            int healAmount;
            cout << "Enter heal amount: ";
            cin >> healAmount;
            heal(health, healAmount);
        }
        else if (choice == 'S') {
            string effect;
            cout << "Enter status effect to add: ";
            cin >> effect;
            statusEffects.push_back(effect);
        }
        else if (choice == 'V') {
            showStatusEffects(statusEffects);
        }
    } while (choice != 'Q');
    cout << "\nGame session ended. Stay healthy, " << playerName << "!\n";
    return 0;
}
// Loads player data from file
void loadPlayerData(string& name, int& health) {
    ifstream file("playerdata.txt");
    if (!file) {
        cout << "Error: Could not open playerdata.txt.\n";
        exit(1);
    }
    getline(file, name);
    file >> health;
    file.close();
}
// Displays a simple health bar
void displayHealthBar(int health) {
    int barLength = 20;
    int filled = (health * barLength) / MAX_HEALTH;
    cout << "[";
    for (int i = 0; i < filled; ++i) cout << "#";
    for (int i = filled; i < barLength; ++i) cout << "-";
    cout << "]" << endl;
}
// Applies damage and stores history in array
int takeDamage(int currentHealth, int damage, int damageHistory[], int& index) {
    currentHealth -= damage;
    if (currentHealth < 0) currentHealth = 0;
    damageHistory[index % MAX_HISTORY] = damage;
    index++;

    cout << "You took " << damage << " damage!" << endl;
    return currentHealth;
}
// Heals the player
void heal(int& currentHealth, int amount) {
    currentHealth += amount;
    if (currentHealth > MAX_HEALTH) currentHealth = MAX_HEALTH;
    cout << "You healed " << amount << " health!" << endl;
}
// Shows status effects
void showStatusEffects(const vector<string>& effects) {
    if (effects.empty()) {
        cout << "No active status effects." << endl;
    }
    else {
        cout << "Status Effects: ";
        for (const string& effect : effects) {
            cout << effect << " ";
        }
        cout << endl;
    }
}
