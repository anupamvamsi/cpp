    // Code written from using https://www.daniweb.com/programming/software-development/threads/321321/heads-and-tails-game as a reference.
    // Compile: "g++ -o heads_tails.exe heads_tails.cpp"
    // Run    : "./heads_tails.exe"
    
    #include <iostream>
    #include <ctime>
    #include <cstdlib> // for srand

    using namespace std;
    
    int main ()
     {
         char guess;
         char ans;
         int no_of_plays;
         const int LOW = 0;  // It will auto range the output to within H and T
         const int HIGH = 1;
         int random_integer;
         cout << "THE GAME OF HEAD OR TAILS" << endl;
         cout << "" << endl;
         cout << "Do you want to play? " << endl;
         cout << "Y/y for yes, N/n for no \n" << endl;
         cin >> ans;
         if (ans == 'y' || ans == 'Y') {
            cout << "\nHow many times do you want to play?  " << endl;
            cin >> no_of_plays;
            cout << "\n";
         }
         else {
              cout << "\nThanks for playing!  " << endl;
         }
         for ( int a = 0; a < no_of_plays; a++)
         {
            cout << "Call it, Heads or Tails?" << endl;
            cout << "(Heads - 'h', Tails - 't')" << endl;
            cin >> guess;
            srand((unsigned int) time(NULL));
            random_integer = rand() % (HIGH - LOW + 1) + LOW;
            char randomCoin;
            if (random_integer == 1)
             {
               cout << "\nCoin was tails," << endl;
               randomCoin = 't';
             }
            if (random_integer == 0)
            {
             cout <<  "\nCoin was heads," << endl;
             randomCoin = 'h';
            }
            if (guess == randomCoin)
            {
              cout << "You got it!\n" << endl;
            }
            else
            {
              cout << "You missed it!\n" << endl;
            }
         }
         //system("pause");
         cout << "\nThanks for playing!  \n" << endl;

         return 0;
         }