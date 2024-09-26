//---------------------------------------------------------
// Demo           : 03_Moving_point_SDL
// Fichier        : 03_Moving_Point_SDL_Windows.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 03 - 2023-01-16
// But            : SDL2 démo
// Modifications  : argc / argv for Windows
// Remarque(s)    : remember (0,0) is on the top left corner
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <SDL.h>

using namespace std;

int main(int argc, char* argv[]) {

   //--------------------------------------------------------------------------
   // int argc, char* argv[] are important for SDL2 on Windows
   (void)argc;       // use these arguments
   (void)argv;       // .. to avoid a warning

   //--------------------------------------------------------------------------
   //    Instructions
   //--------------------------------------------------------------------------
   cout << "This program is an SDL2 demo."            << endl
        << " - use the array keys to move the point"  << endl
        << " - click to position the icon"            << endl
        << " - close the window to terminate the app" << endl
        << endl;

   //--------------------------------------------------------------------------
   //    SDL settings
   //--------------------------------------------------------------------------
   SDL_Window*    window         = nullptr;
   SDL_Renderer*  renderer       = nullptr;
   bool           appIsRunning   = true;
   
   const int      WINDOW_WIDTH   = 80;
   const int      WINDOW_HEIGTH  = 50;
   const int      SCALE          = 10;
   const int      STEP           =  1;

   SDL_Init(SDL_INIT_VIDEO);
   SDL_CreateWindowAndRenderer(WINDOW_WIDTH  * SCALE,
                               WINDOW_HEIGTH * SCALE,
                               SDL_WINDOW_SHOWN,
                               &window, &renderer);
   if (window == nullptr or renderer == nullptr) {
      cout << "SDL not ready ... quitting" << endl;
      exit(EXIT_FAILURE);
   }
   
   SDL_SetWindowTitle(window, "SDL Demo / Moving points");
   SDL_RenderSetScale(renderer, SCALE, SCALE);

   // point to show
   SDL_Point point;
   point.x = WINDOW_WIDTH  / 2;
   point.y = WINDOW_HEIGTH / 2;

   // image to show
   SDL_Rect  rectImage;
   SDL_Surface* surface = SDL_LoadBMP("icon.bmp");
   SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

   //--------------------------------------------------------------------------
   // main loop
   //--------------------------------------------------------------------------
   while (appIsRunning) {

      // Events management
      SDL_Event event;
      while (SDL_PollEvent(&event)) {

         switch (event.type) {
            case SDL_QUIT     :  appIsRunning = false;
                                 break;

            // mouse clicks
            case SDL_MOUSEBUTTONDOWN :
               rectImage.x = event.button.x / SCALE;
               rectImage.y = event.button.y / SCALE;
               rectImage.w = SCALE;
               rectImage.h = SCALE;
               break;

            // keyboard API for key pressed
            case SDL_KEYDOWN  :
               switch (event.key.keysym.scancode) {

                  case SDL_SCANCODE_W     :
                  case SDL_SCANCODE_UP    :  point.y -= STEP;
                                             break;
                  case SDL_SCANCODE_A     :
                  case SDL_SCANCODE_LEFT  :  point.x -= STEP;
                                             break;
                  case SDL_SCANCODE_S     :
                  case SDL_SCANCODE_DOWN  :  point.y += STEP;
                                             break;
                  case SDL_SCANCODE_D     :
                  case SDL_SCANCODE_RIGHT :  point.x += STEP;
                                             break;
                  // other "unknown" cases
                  default:                   break;
               } // case SDL_KEYDOWN => switch event.key.keysym.scancode
               
            } // switch event.type
         
      } // while PollEvent

      //-----------------------------------------------------------------------
      // bounderies
      //-----------------------------------------------------------------------
      // right boundary
      if (point.x >= WINDOW_WIDTH)
         point.x = WINDOW_WIDTH - 1;

      // left boundary
      if (point.x < 0)
         point.x = 0;

      // bottom boundary
      if (point.y >= WINDOW_HEIGTH)
         point.y = WINDOW_HEIGTH - 1;

      // upper boundary
      if (point.y < 0)
         point.y = 0;

      //-----------------------------------------------------------------------
      // draw the point
      //-----------------------------------------------------------------------
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
      SDL_RenderClear(renderer);

      SDL_RenderCopy(renderer, texture, NULL, &rectImage);

      SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
      SDL_RenderDrawPoint(renderer, point.x, point.y);

      SDL_RenderPresent(renderer);
      
   } // app running

   // destroy SDL ressources
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   SDL_Quit();

   return EXIT_SUCCESS;
}
