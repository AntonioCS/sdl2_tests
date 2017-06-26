
#include <SDL.h>
#include <stdio.h>

int main(int argc, char* args[]) {
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    SDL_Window* window = NULL;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
        //SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
        window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        SDL_Renderer *gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        int quit = 0;

        //Event handler
        SDL_Event e;

        while (!quit) {
            //Handle events on queue
            while (SDL_PollEvent(&e) != 0) {
                //User requests quit
                if (e.type == SDL_QUIT) {
                    quit = 1;
                }
                if (e.type == SDL_KEYDOWN) {
                    switch (e.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            quit = 1;
                            break;
                    }
                }
            }

            //Clear screen 
            SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
            SDL_RenderClear(gRenderer);

            //Render red filled quad 
            SDL_Rect fillRect = {SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
            
            fillRect.x = 0;
            SDL_SetRenderDrawColor(gRenderer, 0, 51, 51, 0xFF);
            SDL_RenderFillRect(gRenderer, &fillRect);
            
            
            fillRect.x = SCREEN_WIDTH / 4;
            SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
            //SDL_RenderDrawRect(gRenderer, &fillRect);
            SDL_RenderFillRect(gRenderer, &fillRect);
                                    

            //Update screen
            SDL_RenderPresent(gRenderer);

        }

    } else {
        printf("ERROR: Unable to initialize SDL\n");
        exit(-1);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}