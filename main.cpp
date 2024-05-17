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

int near(int x, int y) {
    int count = 0;

    for (int h = y - 1; h < 2 + y; h++) {
        for (int w = x - 1; w < 2 + x; w++) {
            if (!(w == x && h == y)) {
                count += map[h][w];

                std::cout << map[h][w];
            
            } else {
                std::cout << ".";

            }
        }

        std::cout << std::endl;
    
    }

    std::cout << count << std::endl;

    return count;
}

void displayCave() {
    for (int h = 0; h < MAP_HEIGHT; h++) {
        for (int w = 0; w < MAP_WIDTH; w++) {
            std::cout << map[h][w];

        }

        std::cout << std::endl;

    }

}

int main() {
    genCave();

    // displayCave();
    near(20, 20);

    return 0;
}

