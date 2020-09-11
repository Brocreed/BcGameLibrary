/*
Program Name: BC Game Library
Author: Broc Reed
Date: 09/08/2020
Purpose: A game library that containes a log in screen, menu, 2 games (random number and pattern), as well as a logout function to end the program
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{
    //Constants
    const string USERNAME = "BcStudent";                                                //Set's login username
    const string PASSWORD = "Password";                                                 //Set's login password
    const int MIN_VALUE = 1;                                                            //Min Value for random number game
    const int MAX_VALUE = 20;                                                           //Max Value for random number game

    //Variables
    int attempts = 0, loginSuccess = 0, logOut = 0, menuChoice, randomNumber, userGuess, userPatternInput;
    string passwordInput, usernameInput;
    unsigned randomSeed;

    cout << "BC GAME LIBRARY\n";
    do                                                                                  //Starts login loop
    {
        cout << "Log in to access your library: \n";
        cout << "Username: ";
        cin >> usernameInput;                                                           //Gets user input for username
        cout << "Password: ";
        cin >> passwordInput;                                                           //Gets user input for username

        if (usernameInput != USERNAME || passwordInput != PASSWORD)                     //Checks if username or password is incorrect
        {
            cout << "\nLogin Failed! Invalid username or password\n\n";
            attempts++;                                                                 //Adds 1 to attempt counter
        }
        else {
            cout << "\nLogin Success!\n";
                loginSuccess = 1;                                                       //Sets loginSuccess to true if both username and password were correct
            }                                                                     

        if (attempts == 3)                                                              //Checks if failed attempts is equal to 3 in order to end the program
        {
            cout << "Too many failed login attempts. Goodbye :)\n";
            return 0;
        }
    } while (attempts < 3 && !loginSuccess);    

    do                                                                                  //Starts menu loop
    {
        cout << "\nWelcome to your BC Game Library\n\n";
        cout << "GAMES:\n";
        cout << "1. Random number game\n";
        cout << "2. Print pattern game\n";
        cout << "3. Logout\n";
        cout << "Enter the game number to play: ";
        cin >> menuChoice;

        switch (menuChoice)                                                             //Starts menu switch statement
        {
            case 1:                                                                     //Random number game selection
                //random number setup
                randomSeed = time(0);
                srand(time(0));
                randomNumber = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
                //cout << "***DEBUG*** " << randomNumber << endl;

                //Start of random number game
                cout << "RANDOM NUMBER GAME\n";
                cout << "Guess what number I'm thinking of? (Between 1-20)\n";
                cout << "Your guess: ";

                while (userGuess != randomNumber)                                       //Starts while loop checking if userGuess equals randomNumber
                {
                    cin >> userGuess;
                    if (userGuess < randomNumber)                                       //Checks if guess is too low
                    {
                        cout << "Nope! Your guess is too low \n";
                        if (userGuess < MIN_VALUE)                                      //Checks if guess is below minimum
                        {
                            cout << "Remember the lowest value is " << MIN_VALUE << endl;
                        }
                    }
                    else if (userGuess > randomNumber)                                  //Checks if guess is too high
                    {
                        cout << "Nope! Your guess is too high \n";
                        if (userGuess > MAX_VALUE)                                      //Checks if guess is above maximum
                        {
                            cout << "Remember the highest value is " << MAX_VALUE << endl;
                        }
                    }
                    else                                                                //If not too high or too low then declares the number is guessed
                    {
                        cout << "You guessed it!";
                    }
                }
                break;

            case 2:                                                                     //Pattern game selection
                cout << "Enter a number: ";
                cin >> userPatternInput;                                                //Gets user input for pattern iterations
                cout << endl;
                for (int patternRow = 0; patternRow < userPatternInput; patternRow++)   //Starts for loop for row iterations
                {
                    for (int patternColumn = 0; patternColumn <= patternRow; patternColumn++) //Starts for loop for column iterations
                    {
                        cout << "*";
                    }
                    cout << endl;
                }
                break;

            case 3:                                                                     //Logout selection
                cout << "Logging out\n";
                logOut = 1;                                                             //Ends the menu do while loop
                break;

            default:                                                                    //Default for inputs not assigned to a case
                cout << "\nInvalid game number\n";
        }
    } while (!logOut);                                                                  //Checking for logout to be true to end program
    return 0;
}