#include <iostream>

static const int MAP_WIDTH = 100;
static const int MAP_HEIGHT = 60;

int ALIVE = 1;
int DEAD = 0;
int seed = 1337;
int aliveProb = 50;
int generations = 10;

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

                // std::cout << map[h][w];
            
            } else {
                // std::cout << ".";

            }
        }

        // std::cout << std::endl;
    
    }

    // std::cout << count << std::endl;

    return count;
}

void displayCave() {
    for (int h = 0; h < MAP_HEIGHT; h++) {
        for (int w = 0; w < MAP_WIDTH; w++) {
            // std::cout << map[h][w];
            if (map[h][w]) {
                std::cout << "#";
            } else {
                std::cout << ".";
            }

        }

        std::cout << std::endl;

    }

    std::cout << "\n";

}

void updateCells() {
    int count;
    
    for (int h = 1; h < MAP_HEIGHT - 1; h++) {
        for (int w = 1; w < MAP_WIDTH - 1; w++) {
            count = near(w, h);

            if (map[h][w] == DEAD && count >= 6) map[h][w] = ALIVE;
            
            if (map[h][w] == ALIVE && count <= 3) map[h][w] = DEAD;

        }

    }
}

int main() {
    genCave();

    for (int gen = 0; gen < generations; gen++) {
        updateCells();

        displayCave();
    }
    
    displayCave();

    return 0;
}

