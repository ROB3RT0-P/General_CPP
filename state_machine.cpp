#include <iostream>

enum class State 
{
    Idle,
    Working,
    Finished
};

class StateMachine 
{
public:
    StateMachine() : currentState(State::Idle) {}

    void transitionTo(State newState) 
    {
        currentState = newState;
    }

    void performAction() 
    {
        switch (currentState) 
        {
            case State::Idle:
                std::cout << "Machine is idle." << std::endl;
                break;
            case State::Working:
                std::cout << "Machine is working." << std::endl;
                break;
            case State::Finished:
                std::cout << "Machine has finished its task." << std::endl;
                break;
        }
    }

private:
    State currentState;
};

int main() 
{
    StateMachine machine;

    machine.performAction();

    machine.transitionTo(State::Working);
    machine.performAction();

    machine.transitionTo(State::Finished);
    machine.performAction();

    return 0;
}
