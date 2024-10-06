
/*
0A D F
1B F E
2C A H
3D B C
4E G E
5F H B
6G C D
7H E A
Your starting state is: D*/


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_STATES 8

void moveState(char input);
void updateState(char input[]);
void printStateMachine();
void garbageIdentify();
void isReachable(char state, int reachable[]);
void deleteState(char input[]);

char currentState;
char states[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
char nextStates0[] = {'D', 'F', 'A', 'B', 'G', 'H', 'C', 'E'};
char nextStates1[] = {'F', 'E', 'H', 'C', 'E', 'B', 'D', 'A'};
bool deletedStates[MAX_STATES] = {false};
int numOfStates;

void printStartingState() {
    printf("Your starting state is: %c\n", currentState);
}

int main(int argc, char *argv[]) {
    currentState = 'D';
    numOfStates = sizeof(states) / sizeof(states[0]);
    printStartingState();

    char input[4];

    while (scanf(" %s", input) == 1) {
        switch (input[0]) {
            case '0':
            case '1':
                moveState(input[0]);
                break;
            case 'c':
                updateState(input);
                break;
            case 'p':
                printStateMachine();
                break;
            case 'g':
                garbageIdentify();
                break;
            case 'd':
                deleteState(input);
                break;
            case 'e':
                exit(0);
            default:
                break;
        }
    }
    return 0;
}

void moveState(char input) {
    for (int i = 0; i < numOfStates; ++i) {
        if (currentState == states[i]) {
            currentState = (input == '0') ? nextStates0[i] : nextStates1[i];
            printf("%c\n", currentState);
            break;
        }
    }
}

void updateState(char input[]) {
    char targetInput = input[1];
    char newState = input[2];

    if (newState < 'A' || newState > 'H') {
        printf("Invalid state.\n");
        return;
    }

    for (int i = 0; i < numOfStates; ++i) {
        if (currentState == states[i]) {
            if (targetInput == '0') {
                nextStates0[i] = newState;
            } else if (targetInput == '1') {
                nextStates1[i] = newState;
            }
            break;
        }
    }
}

void printStateMachine() {
    for (int i = 0; i < numOfStates; ++i) {
        if (!deletedStates[i]) {
            printf("%c %c %c\n", states[i], nextStates0[i], nextStates1[i]);
        }
    }
}

void garbageIdentify() {
    int reachable[MAX_STATES] = {0};
    isReachable(currentState, reachable);

    bool allReachable = true;
    for (int i = 0; i < numOfStates; ++i) {
        if (!reachable[i] && !deletedStates[i]) {
            allReachable = false;
            break;
        }
    }

    if (allReachable) {
        printf("No garbage\n");
    } else {
        printf("Garbage:");
        for (int i = 0; i < numOfStates; ++i) {
            if (!reachable[i] && !deletedStates[i]) {
                printf(" %c", states[i]);
            }
        }
        printf("\n");
    }
}

void isReachable(char state, int reachable[]) {
    for (int i = 0; i < numOfStates; ++i) {
        if (state == states[i] && !reachable[i]) {
            reachable[i] = 1;
            isReachable(nextStates0[i], reachable);
            isReachable(nextStates1[i], reachable);
        }
    }
}

void deleteState(char input[]) {
    if (input[1]) {
        char stateToDelete = input[1];
        for (int i = 0; i < numOfStates; ++i) {
            if (states[i] == stateToDelete) {
                if (deletedStates[i]) {
                    printf("Deleted.\n");
                } else {
                    deletedStates[i] = true;
                    printf("Deleted: %c\n", stateToDelete);
                }
                break;
            }
        }
    } else {
        int reachable[MAX_STATES] = {0};
        isReachable(currentState, reachable);

        int deletedNow = 0;
        for (int i = 0; i < numOfStates; ++i) {
            if (!reachable[i] && !deletedStates[i]) {
                deletedStates[i] = true;
                if (deletedNow++ == 0) {
                    printf("Deleted: %c", states[i]);
                } else {
                    printf(", %c", states[i]);
                }
            }
        }

        if (deletedNow == 0) {
            printf("No states deleted.\n");
        } else {
            printf("\n");
        }
    }
}
