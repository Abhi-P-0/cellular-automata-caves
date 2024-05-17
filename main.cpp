#include <iostream>

static const int MAP_WIDTH = 100;
static const int MAP_HEIGHT = 60;

int ALIVE = 1;
int DEAD = 0;
int seed = 1337;
int aliveProb = 50;

int map[MAP_HEIGHT][MAP_WIDTH];

void genCave() {
    srand(seed);

    for (int h = 0; h < MAP_HEIGHT; h++) {
        for (int w = 0; w < MAP_WIDTH; w++) {
            map[h][w]=ALIVE;

            if (rand() % 100 > aliveProb) {
                map[h][w] = DEAD;

            }

        }

    }

}

void displayCave() {
    

}

int main() {
    

    return 0;
}

