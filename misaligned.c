#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MAJOR_COLOR_COUNT 5
#define MINOR_COLOR_COUNT 5

const char* majorColor[MAJOR_COLOR_COUNT] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[MINOR_COLOR_COUNT] = {"Blue", "Orange", "Green", "Brown", "Slate"};

typedef struct {
    int index;
    const char* major;
    const char* minor;
} ColorMapEntry;

void generateColorMap(ColorMapEntry colorMap[]) {
    for (int i = 0; i < MAJOR_COLOR_COUNT; i++) {
        for (int j = 0; j < MINOR_COLOR_COUNT; j++) {
            colorMap[i * MINOR_COLOR_COUNT + j] = (ColorMapEntry){.index = i * MINOR_COLOR_COUNT + j, .major = majorColor[i], .minor = minorColor[i]};
        }
    }
}

void printColorMap(const ColorMapEntry colorMap[]) {
    for (int i = 0; i < MAJOR_COLOR_COUNT * MINOR_COLOR_COUNT; i++) {
        printf("%d | %s | %s\n", colorMap[i].index, colorMap[i].major, colorMap[i].minor);
    }
}

void testGenerateColorMap() {
    ColorMapEntry colorMap[MAJOR_COLOR_COUNT * MINOR_COLOR_COUNT];
    generateColorMap(colorMap);
    for (int i = 0; i < MAJOR_COLOR_COUNT; i++) {
        for (int j = 0; j < MINOR_COLOR_COUNT; j++) {
            int index = i * MINOR_COLOR_COUNT + j;
            assert(colorMap[index].index == index);
            assert(strcmp(colorMap[index].major, majorColor[i]) == 0);
            assert(strcmp(colorMap[index].minor, minorColor[j]) == 0);
        }
    }
}

int main() {
    testGenerateColorMap();  
    ColorMapEntry colorMap[MAJOR_COLOR_COUNT * MINOR_COLOR_COUNT];
    generateColorMap(colorMap);
    printColorMap(colorMap);
    
    printf("All tests passed (maybe!)\n");
    return 0;
}
