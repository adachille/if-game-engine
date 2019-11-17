#include <iostream>
#include <string> 
#include <vector>
#include <chrono>
#include <thread>

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

void StorySequence(const std::vector<std::string> storyLines, const unsigned charsPerSecond=20, const unsigned timeBetweenLines=1000, const unsigned newLines=2) {
    // Cap the speed of printing at 1000 chars per second
    unsigned ms_per_char;
    if (charsPerSecond > 1000) 
        ms_per_char = 1;
    else 
        ms_per_char = 1000 / charsPerSecond;

    // Iterate through lines
    for (unsigned lineInd = 0; lineInd < storyLines.size(); lineInd++) 
    {
        // Print each char in line and then wait for ms_per_char time
        std::string curLine = storyLines.at(lineInd);
        for (unsigned charInd = 0; charInd < curLine.size(); charInd++)
        {
            std::cout << curLine[charInd];
            std::this_thread::sleep_for(std::chrono::milliseconds(ms_per_char));
        }

        // Print the newlines between story lines
        for (unsigned i = 0; i < newLines; i++) 
        {
            std::cout << std::endl;
        }

        // Wait between each line
        std::this_thread::sleep_for(std::chrono::milliseconds(timeBetweenLines));
    }
}

void PlayGame() 
{
    Setup();

    // Story Sequence 1 //
    std::vector<std::string> storyLines;
    storyLines.push_back("You've woken up.");
    storyLines.push_back("Everything around you is pitch black, only your body is illuminated. You can see your arms, legs, and feet but you are completely paralyzed and cannot move. There is only silence and stillness...");
    storyLines.push_back("A short distance in front of you, a small dark green circle appears. The dot slowly grows larger and you begin to notice an almost imperceptible vibration... It's movement grows more violent as it reaches a tremble... and finally a boil. From the stew, You see three dark green spikes slowly emerge from the vigorously churning bubbles...");
    storyLines.push_back("The spikes grow upwards rapidly and begin to twist in on themselves, like overgrown nails...");
    storyLines.push_back("The mass is now forced outwards by its own growth, towards you... It inches closer and closer, but you cannot move...");
    storyLines.push_back("You look down as the first green spike gently touches your chest. It continues moving, pushing it's edge into your body with no resistance. There is no sound. There is no pain nor blood. The spike slowly pushes its way forward and out through your back... You notice the boil start to die down, and with it, the spike's growth. You feel it's slow vibration in your chest... Finally, it comes to stop.");
    storyLines.push_back("You suddenly feel control flow back into your body...");
    StorySequence(storyLines);


    // Action Sequence 1 //
    // Define Actions
    struct Action action1;
    action1.optionMessage = "throw your fists down on the spike.";
    action1.resultMessage = "Lifting your hands high over your head, you hurl yours fists at the spike. You feel nothing as the spike shatters. Whatever was holding you in place before is no longer there and you begin to fall through the void...";
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