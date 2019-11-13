#include <iostream>
#include <string> 
#include <vector>

#include "engine.h"
#include "engine-objs.h"
#include "utils.h"

// std::string UTILS
const std::string BREAKER = "___________________________________________________";

// GAME STATE // 
// INVENTORY
// Intialize the player's inventory
// The user should be able to collect items by engulfing them
std::vector<struct Item> items = {};

// PROGRESS VARS
GameStatus gameStatus = IN_PROGRESS; // The game status is here
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
    Item secretItem;
    secretItem.name = "Secret Starting Item";
    secretItem.id = -99;
    items.push_back(secretItem);
    return;
}

void PlayerAction(std::vector<struct Action> actions) {
    int actionInd = -1;

    // Action Loop
    std::cout << BREAKER << std::endl;
    while (true) { 
        std::cout << "How do you proceed?\n\n";

        // Tell the player possible actions
        for (int i = 0; (unsigned) i < actions.size(); i++)
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
        Action selectedAction = actions.at(actionInd);
        std::cout << std::endl;
        std::cout << selectedAction.resultMessage << "\n\n";

        // Update the state based on type of action and continue
        std::cout << BREAKER << std::endl;
        if (selectedAction.actType == PROGRESSIVE)
        {
            return;
        } else if (selectedAction.actType == FATAL)
        {
            gameStatus = LOSE;
            return;
        }
    }
}

void PlayGame() 
{
    Setup();

    // Story Sequence 1 //
    std::cout << "You've woken up.\n\n";
    std::cout << "Everything around you is pitch black, only your body is illuminated. You can see your arms, legs, and feet but you are completely paralyzed and cannot move. There is only silence and stillness...\n\n";
    std::cout << "A short distance in front of you, a small dark green circle appears. The dot slowly grows larger and you begin to notice an almost imperceptible vibration... It grows in movement until it reaches tremble... and finally a boil. From the stew, You see three dark green spikes slowly emerge from the vigorously churning bubbles...\n\n";
    std::cout << "The spikes grow upwards until their weight causes them to begin twisting in on themselves, like overgrown nails...\n\n";
    std::cout << "The mass is now forced outwards by its own growth, towards you... It inches closer and closer, but you cannot move...\n\n";
    std::cout << "You look down as the first green spike gently touches your chest. It continues moving, pushing it's edge into your body with no hesitation. There is no sound. There is no pain nor blood. The spike slowly pushes its way forward and out through your back. But, you notice the boil start to die down, and with it, the spike's growth grinds to a halt. You feel it's slow vibration in your chest... Finally, it comes to stop.\n\n";
    std::cout << "The spike is only sticking a couple inches out of your back. You suddenly feel control flow back into your body...\n\n";

    // Action Sequence 1 //
    // Define Actions
    struct Action action1;
    action1.optionMessage = "push down on the spike and hoist yourself off of it.";
    action1.resultMessage = "You struggle to push your body off the spike...\n\n The spike is halfway out of your body when it suddenly snaps, and you begin to fall through the void...";
    action1.actType = PROGRESSIVE;
    struct Action action2;
    action2.optionMessage = "kick your feet and yell at the void.";
    action2.resultMessage = "You struggle against the green spike that penetrates your body... It doesn't seem to mind. You scream hysterically at the void. It stays silent...";
    action2.actType = CYCLIC;
    struct Action action3;
    action3.optionMessage = "take a nap.";
    action3.resultMessage = "With no sensation of pain, no dripping blood, or sights to intrigue, you find your eyes begin to close. The insomnia that has plagued you all your life takes hold. The black void becomes darker...\n\nWhen you open your eyes, you find yourself at your familiar desk in your familiar small, grey cubicle. The bulky computer in front of you displays the Microsoft Windows 95 logo. You glance around for a moment, Tom is glaring at you. He's wearing overalls today. You avert your eyes and turn your head to back to the computer, opening up Excel. You immediately save the file, a habit built from many occasions of lost progress. You sigh and name the file 'Spreadsheet.xls'. Dreams are scary, you think to yourself.";
    action3.actType = FATAL;
    // Add actions and call Player Action
    std::vector<struct Action> actions;
    actions.push_back(action1);
    actions.push_back(action2);
    actions.push_back(action3);
    PlayerAction(actions);

    // Story Sequence 2 //
    

    // Action Sequence 2 //

    // Check for game end
    if (gameStatus == LOSE)
    {
        PrintDebugInfo();
        return;
    }

    PrintDebugInfo();
    return;
}