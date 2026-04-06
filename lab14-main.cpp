#include "HashTableOpen.hpp"
#include <string>

int main() {
    // variables
    HashTableOpen<string, string> dict;
    string userWord, s;
    int userChoice = 0;
    bool flag = false;

    // add data to the dictionary
    dict.insert("banana", "a fruit that many like, or a phone");
    dict.insert("cactus", "a pointy plant");
    dict.insert("dog", "a domesticated fluff ball");
    dict.insert("graph", "an awesome data structure!");
    dict.insert("haskell", "fantastic programming language, go learn it");
    dict.insert("igloo", "a cool house");
    dict.insert("phoenix", "a bird on fire");
    dict.insert("quack", "said Mr. Duck");

    // display menu
    cout << "Welcome to my open hash table dictionary program!\n";
    cout << "Here are your options:\n";
    cout << "\t1. Find\n";
    cout << "\t2. Insert\n";
    cout << "\t3. Remove\n";
    cout << "\t4. Size\n";
    cout << "\t5. Clear\n";
    cout << "\t6. Quit\n";

    // loop until the user quits
    do {
        cout << "Enter your option: ";
        cin >> userChoice;

        // check if input failed
        if (cin.fail()) {
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
            cout << "Invalid input. Please enter a number between 1 and 6.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // remove leftover newline

        switch (userChoice) {
            case 1: // find
                try {
                    cout << "Enter a key to search my dictionary: ";
                    getline(cin, userWord);
                    s = dict.find(userWord);
                    cout << s << endl;
                }
                catch (string& e) {
                    cout << e << endl;
                }
                break;

            case 2: // insert
                cout << "Enter the key of the new record: ";
                getline(cin, userWord);
                cout << "Enter the value of the new record: ";
                getline(cin, s);
                dict.insert(userWord, s);
                break;

            case 3: // remove
                try {
                    cout << "Enter the key of the record to be removed from my dictionary: ";
                    getline(cin, userWord);
                    dict.remove(userWord);
                }
                catch (string& e) {
                    cout << e << endl;
                }
                break;

            case 4: // size
                cout << "Dictionary size is " << dict.size() << endl;
                break;

            case 5: // clear
                cout << "Clearing out my dictionary . . . ";
                dict.clear();
                cout << "cleared!\n";
                break;

            case 6: // quit
                flag = true;
                break;

            default:
                cout << "Invalid choice. Enter a number between 1 and 6.\n";
                break;
        }
    } while (!flag);

    // terminate
    return 0;
}
