/*
Write a program that allows the user to type in any one-line question and
then answers that question. The program will not really pay any attention
to the question, but will simply read the question line and discard all that
it reads. It always gives one of the following answers:
I'm not sure, but I think you will find the answer in Chapter #N.
That's a good question.
If I were you, I would not worry about such things.
That question has puzzled philosophers for centuries.
I don't know. I'm just a machine.
Think about it and the answer will come to you.
I used to know the answer to that question, but I've forgotten it.
The answer can be found in a secret place in the woods.
These answers are stored in a file (one answer per line), and your program
simply reads the next answer from the file and writes it out as the answer
to the question. After your program has read the entire file, it simply
closes the file, reopens the file, and starts down the list of answers again.
Whenever your program outputs the first answer, it should replace
the two symbols #N with a number between 1 and 18 (including the
possibility of 1 and 18). In order to choose a number between 1 and 18,
your program should initialize a variable to 18 and decrease the variable’s
value by 1 each time it outputs a number so that the chapter numbers
count backward from 18 to 1. When the variable reaches the value 0,
your program should change its value back to 18. Give the number 17
the name NUMBER_OF_CHAPTERS with a global named constant declaration
using the const modifier.
(Hint: Use the function new_line defined in this chapter.)*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>  
#include <ctime>    

using namespace std;

const int NUMBER_OF_CHAPTERS = 18;  


void replaceChapterNumber(string& answer, int chapterNumber) {
    size_t pos = answer.find("#N");
    if (pos != string::npos) {
        answer.replace(pos, 2, to_string(chapterNumber));
    }
}

int main() {
    // Open the file containing answers
    ifstream inputFile("answers.txt");
    if (!inputFile) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    int chapterNumber = NUMBER_OF_CHAPTERS;
    string answer;

    srand(time(0));

    while (true) {
        string question;
        getline(cin, question);
        if (getline(inputFile, answer)) {

            replaceChapterNumber(answer, chapterNumber);

            cout << answer << endl;

            chapterNumber--;
            if (chapterNumber == 0) {
                chapterNumber = NUMBER_OF_CHAPTERS;
            }
        }
        else {
            inputFile.clear();
            inputFile.seekg(0);
        }
    }
    inputFile.close();
    return 0;
}
