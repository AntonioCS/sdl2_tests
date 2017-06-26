/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fonts.c
 * Author: António Simões <antoniocs@gmail.com>
 *
 * Created on 19 May 2016, 09:31
 */

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* args[]) {
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    SDL_Window* window = NULL;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) == 0 && TTF_Init() == 0) {
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
        //SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
        window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        SDL_Renderer *gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        int quit = 0;

        //Event handler
        SDL_Event e;
        float bla = 12120.304;
        char ble[200] = { 0 };
        int total = snprintf(ble, 200, "%f", bla);
        
        printf("Text: %s -- TOTAL: %d --- %f\n", ble, total, bla);

        TTF_Font* Sans = TTF_OpenFont("prstart.ttf", 55); //this opens a font style and sets a size
        int w, h;
        if (TTF_SizeText(Sans, "Teste", &w, &h)) {
            // perhaps print the current TTF_GetError(), the string can't be rendered...
        } else {
            printf("width=%d height=%d\n", w, h);
        }

        SDL_Color White = {255, 255, 255}; // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color


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

            SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "Teste", White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

            SDL_Texture* Message = SDL_CreateTextureFromSurface(gRenderer, surfaceMessage); //now you can convert it into a texture

            SDL_Rect Message_rect; //create a rect
            Message_rect.x = 25; //controls the rect's x coordinate 
            Message_rect.y = 25; // controls the rect's y coordinte
            Message_rect.w = w; // controls the width of the rect
            Message_rect.h = h; // controls the height of the rect
            //Message_rect.w = 150; // controls the width of the rect
            //Message_rect.h = 120; // controls the height of the rect


            SDL_RenderCopy(gRenderer, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture


            //Update screen
            SDL_RenderPresent(gRenderer);

        }

    } else {
        printf("ERROR: Unable to initialize SDL\n");
        exit(-1);
    }

    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
