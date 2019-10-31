#include <iostream>
#include <string> 
#include <vector>

// HELPER OBJECTS //
enum GameStatus 
{
    lose,
    in_progress,
    win
};

struct item 
{
    std::string name;
    int id;
};

enum ActionType 
{
    progressive, // Progression actions - take the user to the next step
    fatal, // Fatal actions - take an action that kills the user, they start over or maybe at a checkpoint? --> maybe whether they've had to restart or not is criteria for some  secret ending
    cyclic, // Cyclic actions - cause nothing to happen and keeps the user in the same place
    spec_cyclic // Special Cyclic actions - nothing appears to happen, but if done enough times, something interesting happens
};
struct action
{
    std::string optionMessage;
    std::string resultMessage;
    ActionType actType; 
};


// UTIL METHODS //
// Returns true if s is a number else false 
bool isNumber(std::string s) 
{ 
    for (int i = 0; i < s.length(); i++) 
        if (isdigit(s[i]) == false) 
            return false; 
  
    return true; 
} 


// GLOBAL STATE // 
// std::string UTILS
    const std::string BREAKER = "___________________________________________________";

// INVENTORY
// Intialize the player's inventory
// The user should be able to collect items by engulfing them
std::vector<struct item> items = {};

// PROGRESS VARS
GameStatus gameStatus = in_progress; // The game status is here
int progress = 0; // Saves a player's progress


// GAME METHODS //

// Print Debug info
void PrintDebugInfo ()
{
    std::cout << BREAKER << "\nDebug info\n";
    std::cout << "gameStatus: " << gameStatus << std::endl;
    std::cout << "progress: " << progress << std::endl;
}

void Setup() {
    // An initial item that the player doens't know they have
    item secretItem;
    secretItem.name = "Secret Starting Item";
    secretItem.id = -99;
    items.push_back(secretItem);
    return;
}

void PlayerAction(std::vector<struct action> actions) {
    int actionInd = -1;

    // Action Loop
    std::cout << BREAKER << std::endl;
    while (true) { 
        std::cout << "How do you proceed?\n\n";

        // Tell the player possible actions
        for (int i = 0; i < actions.size(); i++)
        {
             std::cout << i + 1 << ". " << actions.at(i).optionMessage << std::endl;
        }

        // Take in action
        std::string temp;
        std::cin >> temp;

        // TODO: add in checks for bad ints
        // Check to see if input is an int, if not, restart iteration
        if (isNumber(temp)) 
        {
            actionInd = stoi(temp) - 1;
        }

        // Choose an outcome
        action selectedAction = actions.at(actionInd);
        std::cout << std::endl;
        std::cout << selectedAction.resultMessage << "\n\n";

        // Update the state based on type of action and continue
        std::cout << BREAKER << std::endl;
        if (selectedAction.actType == progressive)
        {
            return;
        } else if (selectedAction.actType == fatal)
        {
            gameStatus = lose;
            return;
        }
    }
}

void PlayGame() 
{
    // Print introduction scene
    std::cout << "You've woken up.\n\n";
    std::cout << "Everything is black. There is no sound. You cannot move...\n\n";
    std::cout << "The void in front of you slowly begins to vibrate, then tremble, and finally, boil. You see three dark green spikes slowly emerge from the vigorously churning bubbles...\n\n";
    std::cout << "They continue to grow upwards and begin twisting in on themselves, like overgrown nails...\n\n";
    std::cout << "The mass is now forced outwards by its own growth, inching closer and closer to you. But you cannot move...\n\n";
    std::cout << "The first green spike makes contact with your chest, pushing it's edge into your body. There is no sound. There is no pain nor blood. The spike slowly pushes its way out through your back. You notice the spike's growth slowly die down. There is now only the slow vibration of the mass back and forth... back and forth...\n\n";
    std::cout << "The dark green mass stops entirely. The spike is only sticking a couple inches out of your back. You feel control slowly flow back into your body...\n\n";

    // Action Sequence 1 //
    // Define Actions
    struct action action1;
    action1.optionMessage = "push down on the spike and hoist yourself off of it.";
    action1.resultMessage = "You struggle to push your body off the spike...\n\nThe spike is halfway out of your body when you notice that the black void that once supported your weight is now gone. With your feet freely dangling, you no longer want to push yourself off the spike. Panicking you remove your hands from the green mass. The end promptly snaps, and you begin to fall through the void...";
    action1.actType = progressive;
    struct action action2;
    action2.optionMessage = "kick your feet and yell at the void.";
    action2.resultMessage = "You struggle against the green spike that penetrates your body... It doesn't seem to mind. You scream hysterically at the void. It stays silent...";
    action2.actType = cyclic;
    struct action action3;
    action3.optionMessage = "take a nap.";
    action3.resultMessage = "With no sensation of pain, no dripping blood, or sights to intrigue, you find your eyes begin to close. The insomnia that has plagued you all your life takes hold. The black void becomes darker...\n\nWhen you open your eyes, you find yourself at a desk in a small gray cubicle. The bulky computer in front of you displays the Microsoft Windows 95 logo. You glance around for a moment, Tom is glaring at you. He's wearing overalls. You turn your head to back to your computer and open up Excel. You immediately save the file out of habit. You sigh and name the file 'Spreadsheet.xls'. Dreams are scarygit, you think to yourself.";
    action3.actType = fatal;
    // Add actions and call Player Action
    std::vector<struct action> actions;
    actions.push_back(action1);
    actions.push_back(action2);
    actions.push_back(action3);
    PlayerAction(actions);

    // Check for game end
    if (gameStatus == lose)
    {
        PrintDebugInfo();
        return;
    }

    PrintDebugInfo();
    return;
}

int main()
{
    Setup();
    PlayGame();
    return 0;
}