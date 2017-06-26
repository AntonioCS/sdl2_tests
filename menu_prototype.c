

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* args[]) {
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;    
    SDL_Window* window = NULL;

    int img_flags = IMG_INIT_JPG | IMG_INIT_PNG;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) == 0 && (IMG_Init(img_flags) & img_flags) == img_flags) {
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
        //SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
        window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        SDL_Renderer *gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        SDL_Texture *arrow = IMG_LoadTexture(gRenderer, "menu_arrow.png");
        int quit = 0;

        //Event handler
        SDL_Event e;
        //SDL_Color White = {255, 255, 255}; // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color
        /* Declaring the surface. */       
        
        SDL_Rect x = {
          .x = 140,
          .y = 100,
          .w = 100,
          .h = 30                
        };
        
        SDL_Rect arrow_coords = {
          .x = 90,
          .y = 30,          
          .w = 46,
          .h = 34
        };
        
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
            SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
            SDL_RenderClear(gRenderer);

            x.y = 30;
            SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
            SDL_RenderFillRect(gRenderer,&x);
            
            x.y += 40;
            SDL_RenderFillRect(gRenderer,&x);
            
            x.y += 40;
            SDL_RenderFillRect(gRenderer,&x);
            
            SDL_RenderCopy(gRenderer, arrow, NULL, &arrow_coords);  
   
            //Update screen
            SDL_RenderPresent(gRenderer);

        }

        SDL_DestroyRenderer(gRenderer);

    } else {
        printf("ERROR: Unable to initialize SDL\n");
        exit(-1);
    }
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}