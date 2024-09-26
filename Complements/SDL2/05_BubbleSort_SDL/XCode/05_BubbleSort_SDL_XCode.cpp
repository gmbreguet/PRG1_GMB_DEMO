//-----------------------------------------------------------------------------
// Demo           : 05_BubbleSort_SDL_XCode
// Fichier        : 05_BubbleSort_SDL_XCode.cpp
// Auteur(s)      : (C) BREGUET Guy-Michel
// Date           : 02 - 2023-01-10
// But            : visualiser un tri avec SDL
// Modifications  : argc / argv for Windows
// Remarque(s)    : remember (0,0) is on the top left corner
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//    SDL installation and XCode config
//    - SDL download       : www.libsdl.org
//    - SDL documentation  : https://wiki.libsdl.org/SDL2/CategoryAPI
//    - CLion on Windows   : https://www.youtube.com/watch?v=SjH_z0x7dWU 
//    - Quick SDL on Mac   : https://github.com/rosejoshua/QuickSDL2MAC
//    - SDL on Mac / XCode : https://lazyfoo.net/tutorials/SDL/01_hello_SDL/mac/xcode/index.php
//-----------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <vector>
#include <random>
#include <algorithm>

#include <SDL2/SDL.h>

using namespace std;

//-----------------------------------------------------------------------------
void drawVector(const vector<int>& v,
                SDL_Renderer*      renderer,
                int                height,
                int                red,
                int                green) {

   for (size_t i=0; i<v.size(); ++i) {
      
      // red values
      if (int(i) == red)
         SDL_SetRenderDrawColor(renderer, 255,   0,   0, SDL_ALPHA_OPAQUE);
      
       // green values
      else if (int(i) == green)
         SDL_SetRenderDrawColor(renderer,   0, 255,   0, SDL_ALPHA_OPAQUE);
      
       // others in white
      else
         SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
      
      // draw the line
      SDL_RenderDrawLine(renderer, (int)i, height, (int)i, height - v[i]);
   }
}

//-----------------------------------------------------------------------------
int main(int argc, char* argv[]) {

   //--------------------------------------------------------------------------
   // int argc, char* argv[] are important for SDL2 on Windows
   (void)argc;       // use these arguments
   (void)argv;       // .. to avoid a warning

   //--------------------------------------------------------------------------
   //    SDL settings
   //--------------------------------------------------------------------------
   const int  SCREEN_WIDTH  =  800;
   const int  SCREEN_HEIGTH =  600;
   const int  NBRE_VALUES   =   50;
   const int  SDL_DELAY     =  100;

   // SDL library
   SDL_Window*    window         = nullptr;
   SDL_Renderer*  renderer       = nullptr;
   SDL_Event      event;
   bool           appIsRunning   = true;

   SDL_Init(SDL_INIT_VIDEO);
   SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGTH, SDL_WINDOW_SHOWN, &window, &renderer);
   if (window == nullptr or renderer == nullptr) {
      cout << "SDL not ready ... quitting" << endl;
      return EXIT_FAILURE;
   }
   SDL_RenderSetScale(renderer, (float)SCREEN_WIDTH/(float)NBRE_VALUES, (float)SCREEN_HEIGTH/(float)NBRE_VALUES);
   //--------------------------------------------------------------------------

   // populate a random vector<int>
   random_device rd;
   uniform_int_distribution d(1, NBRE_VALUES);
   vector<int> v(NBRE_VALUES);
   for (int& e : v)
      e = d(rd);

   while(appIsRunning) {
      
      // visualize while sorting the vector<int>
      // std buble sort
      for (size_t i=0; appIsRunning and i<v.size() - 1; ++i) {
         
         for (size_t j=1; j<v.size() - i; ++j) {

            if (v[j - 1] > v [j]) {
               swap(v[j - 1], v[j]);
            }

            //-----------------------------------------------------------------
            //    SDL drawing
            //-----------------------------------------------------------------
            SDL_PollEvent(&event);
            if (event.type == SDL_QUIT) {
               appIsRunning = false;
               break;
            }
            
            // clear the screen => all black
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(renderer);

            // draw the vector                   red     green
            drawVector(v, renderer, NBRE_VALUES, int(j), int(v.size() - i));

            // SDL display the window
            SDL_RenderPresent(renderer);
            SDL_Delay(SDL_DELAY);
            //-----------------------------------------------------------------
         }
      }
      appIsRunning = false;
   }  // app running

// cout << "press ENTER to quit ...";
// cin.ignore(numeric_limits<streamsize>::max(), '\n');

   // clear SDL ressources
   SDL_DestroyWindow(window);
   SDL_DestroyRenderer(renderer);
   SDL_Quit();
   
   return EXIT_SUCCESS;
}
