#include <iostream>
#include <string>

using namespace std;

string decrypt(const string& encryptedMessage, int key) {
    string decryptedMessage;
    for (char c : encryptedMessage) {
        int originalChar;
        if (c - key < 32)
            originalChar = 127 - (32 - (c - key));
        else
            originalChar = c - key;

        decryptedMessage += static_cast<char>(originalChar);
    }
    return decryptedMessage;
}

int main() {
    string encryptedMessage = ":mmZ\\dxZmx]Zpgy";

    for (int key = 1; key <= 100; ++key) {
        string decryptedMessage = decrypt(encryptedMessage, key);
        cout << "Key " << key << ": " << decryptedMessage << endl;
    }

    return 0;
}
