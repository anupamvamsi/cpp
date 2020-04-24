#include <iostream>

using namespace std;

int main()
{
    int a = 7;
    const std::string password = "helloworld";
    string input;

    /* WHILE LOOP:
        while (a > 0)
        {
            cout << "Hello World! I'm excited!\n";
            a--;
        }

        cout << "\nProgram 1 quitting... Entering next program...\n";
    */

    /* DO-WHILE LOOP: [CAN BE USED TO AVOID REPEATING CODE LINES]
        do
        {
            cout << "\nEnter password: ";
            cin >> input;
            if (input == password)
                cout << "\nYou may pass!\n";
            else
                cout << "\nYou shall not pass!\n";
        } while (input != password);

        cout << "\nProgram 2 quitting... Entering next program...\n";

    */

    /* WHILE LOOP: [TO SEE HOW CODE LINES GET REPEATED]

        cout << "\nEnter password: ";
        cin >> input;

        while (input != password)
        {
            cout << "\nYou shall not pass!\n";

            cout << "\nEnter password: ";
            cin >> input;
        }

        cout << "\nYou may pass!\n\n";

    */

    /* FOR LOOP: [VALID SYNTAX, CAUSES INFINITE LOOP]
        for (;;)
        {
            cout << "Hello Wooorrrrllllddd!\n";
        }
    */

    /* FOR LOOP: ["int i=0" RUNS FIRST. "i++" STARTS RUNNING FROM SECOND TIME THE LOOP RUNS.]
        for (int i=0; i < 5; i++)
        {
            cout << "Hello World! :D\n";
        }
    */

    /* BREAK AND CONTINUE:
        for (int i = 0; i < 12; i++)
        {
            cout << "Looping number: " << i+1 << "\n";

            if (i+1 == 6)
            {
                cout << "Sixer! Continue!\n";
                continue;
            }
            
            if (i+1 == 10)
            {
                cout << "TEN?! WE SHOULD'VE STOPPED AT NINE! THAT'S IT, WE GOTTA STOP!\n\n";
                break;
            }
        }
    */

    /* DO-WHILE LOOP WITH BREAK AND CONTINUE: [TO AVOID CONDITION IN WHILE]
        do
        {
            cout << "\nEnter password: ";
            cin >> input;
            if (input != password)
            {
                cout << "\nYou shall not pass!\n";
                continue;
            }
            else
            {
                cout << "\nYou may pass!\n";
                break;
            }
        } while (true);

        cout << "\nProgram 7 quitting... Entering next program...\n";

    */

    return 0;
}