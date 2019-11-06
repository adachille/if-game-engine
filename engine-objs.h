#pragma once
#include <string>
#include "engine-objs.h"

// enum Types
// The status of the current game
enum GameStatus 
{
    LOSE,
    IN_PROGRESS,
    WIN
};
// The type of action a user can take
enum ActionType 
{
    PROGRESSIVE, // Progression actions - take the user to the next step
    FATAL, // Fatal actions - take an action that kills the user, they start over or maybe at a checkpoint? --> maybe whether they've had to restart or not is criteria for some  secret ending
    CYCLIC, // Cyclic actions - cause nothing to happen and keeps the user in the same place
    SPEC_CYCLIC // Special Cyclic actions - nothing appears to happen, but if done enough times, something interesting happens
};

// Engine OBJECTS //
struct Action;
struct Item; 

// A stucture that holds information on an action the user can take
struct Action
{
    std::string optionMessage;
    std::string resultMessage;
    ActionType actType; 
};

// A simple structure outlining an object
struct Item 
{
    std::string name;
    int id;
};