#include <iostream>
#include <string> 
using namespace std; 

// Returns true if s is a number else false 
bool isNumber(string s) 
{ 
    for (int i = 0; i < s.length(); i++) 
        if (isdigit(s[i]) == false) 
            return false; 
  
    return true; 
} 

struct item {
    string name;
    int id;
};

enum GameStatus {
    lose,
    in_progress,
    win
};

/* 
4 main types of actions:
1. Progression actions - take the user to the next step
2. Fatal actions - take an action that kills the user, they start over or maybe at a checkpoint? 
--> maybe whether they've had to restart or not is criteria for some  secret ending
3. Cyclic actions - cause nothing to happen and keeps the user in the same place
4. Special Cyclic actions - nothing appears to happen, but if done enough times, something interesting happens
*/
enum ActionType {
    progressive,
    fatal,
    cyclic,
    spec_cyclic
};

int main()
{
    // STRING UTILS
    const string BREAKER = "___________________________________________________";

    // INVENTORY
    // Intialize the player's inventory
    // The user should be able to collect items by engulfing them
    const int N_ITEMS = 100; 
    item items[N_ITEMS] = {};
    // An initial item that the player doens't know they have
    items[0].name = "Secret Starting Item";
    items[0].id = -99;

    // PROGRESS related variables
    GameStatus gameStatus = in_progress; // The game status is here
    int progress = 0; // Saves a player's progress
    int action = -1; // Signifies no action is selected

    // Print introduction scene
    cout << "You've woken up.\n\n";
    cout << "Everything is black. There is no sound. You cannot move...\n\n";
    cout << "The void in front of you slowly begins to vibrate, then tremble, and finally, boil. You see three dark green spikes slowly emerge from the vigorously churning bubbles...\n\n";
    cout << "They continue to grow upwards and begin twisting in on themselves, like overgrown nails...\n\n";
    cout << "The mass is now forced outwards by its own growth, inching closer and closer to you. But you cannot move...\n\n";
    cout << "The first green spike makes contact with your chest, pushing it's edge into your body. There is no sound. There is no pain nor blood. The spike slowly pushes its way out through your back. You notice the spike's growth slowly die down. There is now only the slow vibration of the mass back and forth... back and forth...\n\n";
    cout << "The dark green mass stops entirely. The spike is only sticking a couple inches out of your back. You feel control slowly flow back into your body...\n\n";

    // Action Loop
    cout << BREAKER << endl;
    while (action == -1) { 

        // Tell the player possible actions
        cout << "How do you proceed?\n\n";
        cout << "1. push down on the spike and hoist yourself off of it.\n";
        cout << "2. kick your feet and yell at the void.\n";
        cout << "3. take a nap. \n";

        // Take in action
        string temp;
        cin >> temp;

        // Check to see if input is an int, if not, restart iteration
        if (isNumber(temp)) 
        {
            action = stoi(temp);
        }

        cout << endl;
        // Choose an outcome
        if (action == 1) 
        {   
            // Progression Action
            cout << "You struggle to push your body off the spike...\n\n The spike is halfway out of your body when you notice that the black void that once supported your weight is now gone. With your feet freely dangling, you no longer want to push yourself off the spike. Panicking you remove your hands from the green mass. The end promptly snaps, and you begin to fall through the void...\n\n";
        } else if (action == 2)
        {
            // Cyclic action
            cout << "You struggle against the green spike that penetrates your body... It doesn't seem to mind. You scream hysterically at the void. It stays silent...\n\n";
        } else if (action == 3) {
            // Fatal action
            cout << "With no sensation of pain, no dripping blood, or sights to intrigue, you find your eyes begin to close. The insomnia that has plagued you all your life takes hold. The black void becomes darker...\n\n When you open your eyes, you find yourself at a desk in a small gray cubicle. The bulky computer in front of you displays the Microsoft Windows 95 logo. You glance around for a moment, Tom is glaring at you. He's wearing overalls. You turn your head to back to your computer and open up Excel. You immediately save the file out of habit. You sigh and name the file 'Spreadsheet.xls'. Dreams are crazy, you think to yourself.\n\n";
        }

        // Update the state and continue
        cout << BREAKER << endl;
        if (action == 1)
        {
            break; // Break out of the loop
        } else if (action == 2)
        {
            action = -1;
        } else if (action == 3)
        {
            gameStatus = lose;
            break; // End game
        }

    }
    action = -1;

    if (gameStatus == lose)
    {
        cout << "You may want to try again.\n\n";
        cout << BREAKER << "\nDebug info\n";
        cout << "gameStatus: " << gameStatus << endl;
        cout << "action: " << action << endl;
        cout << "progress: " << progress << endl;
        cout << "items: " << items << endl;
        return 0;
    }

    cout << BREAKER << "\nDebug info\n";
    cout << "gameStatus: " << gameStatus << endl;
    cout << "action: " << action << endl;
    cout << "progress: " << progress << endl;
    cout << "items: " << items << endl;
    return 0;
}