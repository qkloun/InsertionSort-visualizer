#include <iostream>
#include <random>
#include <ranges>
#include <algorithm>
#include <vector>
#include <SDL2/SDL.h>
//Insert sort simulation

void draw_state(std::vector<int>& v, SDL_Renderer* renderer, unsigned int red, unsigned int blue) {

    // Sets the color of the bars
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderClear(renderer);

    //SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

    int index = 0;
    for (int i = 0; i < v.size(); i++) {
        if (index == red)
            //Sets the color of the Index bar
            SDL_SetRenderDrawColor(renderer,255, 0, 0, 255);
        else if (index == blue)
            //Sets the color of the pivot(the bar that moves through the vector)
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        else
            //Sets the color of the background
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        
        // Draw from top to bottom (99 - v[i] is the adjusted height)
        //The v[i] makes the height of the screen known
        SDL_RenderDrawLine(renderer, index, 0, index, 99-v[i]);
        index += 1;
    }
}

int main() {
    //Creates the random numbers
    std::random_device rd;

    //Makes sure that the random numbers are in between those 2 numbers
    std::uniform_int_distribution<> d(1, 99);

    //Makes a vextor that is named v taht will hold the random numbers.
    std::vector<int> v;

    // Put random numbers in vector
    for (int i = 0; i < 100; i++) {
        v.push_back(d(rd));
    }

    //Creates an error message if the code fails
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    //creates the window on the computer, giving it a name and the x,y co-ordinates
    //on the screen, while also determining the dimensions of the code
    SDL_Window* window = SDL_CreateWindow("Sorting Visualization", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN); // Adjusted window size
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    //Another error handler in case the renderer doesn't work
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    
    //
    SDL_RenderSetScale(renderer, 5, 5); // Adjusted scale factor

    bool running = true;
    SDL_Event e;

    // Insertion sort algorithm 
    for (unsigned int i = 1; i < v.size() && running; i++) {
        //Makes the key the current item at the index
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] < key) { // Sort from largest to smallest
            v[j + 1] = v[j];
            j--;

            //Closes the code when the tab is closed
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) {
                    running = false;
                    break;
                }
            }

            // Draw the state of the sort
            draw_state(v, renderer, i, j);

            // Show to window
            SDL_RenderPresent(renderer);
        }
        //Makes sure that vector is correct
        v[j + 1] = key;

        // Draw the state of the sort and makes the animation not cause epilepsy
        draw_state(v, renderer, i, j);

        //The speed of the bars moving and the animations speed
        SDL_Delay(20);  
    }

    //Prints out the numbers after they have been sorted in the terminal
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    //Checks if the vector was sorted properly and prints "Sorted" if the vector was sorted
    if (std::ranges::is_sorted(v, std::greater<>())) { // Check if sorted in descending order
        std::cout << "\nsorted\n";
    }

    // Makes sure that the window doesn't close after the vector was sorted.
    bool wait = true;
    while (wait) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                wait = false;
            }
        }
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}