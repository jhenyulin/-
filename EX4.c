#include <stdio.h>

// Enumeration for representing directions
typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
} Direction;

// Struct to represent position
typedef struct {
    int x;
    int y;
    Direction direction;
} Position;

// Function to update position based on instruction
void updatePosition(Position *pos, char instruction) {
    switch (instruction) {
        case 'G':
            switch (pos->direction) {
                case NORTH:
                    pos->y++;
                    break;
                case EAST:
                    pos->x++;
                    break;
                case SOUTH:
                    pos->y--;
                    break;
                case WEST:
                    pos->x--;
                    break;
            }
            break;
        case 'L':
            pos->direction = (pos->direction - 1 + 4) % 4;
            break;
        case 'R':
            pos->direction = (pos->direction + 1) % 4;
            break;
    }
}

// Function to check if the robot is in a circular path
int isInCircularPath(char *instructions) {
    Position pos = {0, 0, NORTH}; // Starting position
  
    Direction initialDirection = pos.direction;
    int initialX = pos.x;
    int initialY = pos.y;

    // Simulate the robot's movements until either a circular path is detected or all instructions are executed
    for (int i = 0; i < 4; i++) {
        for (char *instr = instructions; *instr != '\0'; instr++) {
            updatePosition(&pos, *instr);
        }
        if (pos.x == initialX && pos.y == initialY && pos.direction == initialDirection) {
            return 1; // Circular path detected
        }
    }
    return 0; // Circular path not detected
}

int main() {
    char instructions[101];
    while (scanf("%s", instructions) != EOF) {
        printf("%s\n", isInCircularPath(instructions) ? "TRUE" : "FALSE");
    }
    return 0;
}
