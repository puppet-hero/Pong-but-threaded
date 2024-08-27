#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

void *runner(void *param);          /* threads call this function */
void *ball(void *param);
void *paddle(void *param);

const int windowHeight = 400;       /* resolution */
const int windowWidth = 680;

int main(int argc, char *argv[]){
    pthread_t thread1;              /*thread identifiers*/
    pthread_t thread2;              
    pthread_t thread3;
    pthread_t thread4;
    pthread_attr_t attr;            /*set of thread attributes */

    /* set up SDL view*/
    SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("Pong", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	// Game logic
	bool running = true;

	// Continue looping and processing events until user exits
	while (running){
		SDL_Event event;
		while (SDL_PollEvent(&event)){
		    if (event.type == SDL_QUIT) {
	            running = false;
			} else if (event.type == SDL_KEYDOWN) {
	            if (event.key.keysym.sym == SDLK_ESCAPE){
				    running = false;
				}
			}
		}

		// Clear the window to black
		SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);
		SDL_RenderClear(renderer);

		// Set the draw color to be white
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

        // Draw the net
        for (int y = 0; y < WINDOW_HEIGHT; ++y){
	        if (y % 9){
	         	SDL_RenderDrawPoint(renderer, WINDOW_WIDTH / 2, y);
	        }
        }

		// Present the backbuffer
		SDL_RenderPresent(renderer);

        pthread_attr_init(&attr);  /* set the default attributes of the thread */
        pthread_create(&thread1, &attr, runner, argv[1]);  /* create the threads */
        pthread_create(&thread2, &attr, runner, argv[1]); 
        pthread_create(&thread3, &attr, runner, argv[1]); 
        pthread_create(&thread4, &attr, runner, argv[1]); 

        pthread_join(thread1, NULL); /* wait for threads to exit */
        pthread_join(thread2, NULL); 
        pthread_join(thread3, NULL); 
        pthread_join(thread4, NULL); 

        printf("thread: %ld\n", thread1);   // [UNNEEDED]
        printf("thread: %ld\n", thread2);
	}
    /* add error checking for sdl api calls*/

	// Cleanup
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
/* this is the function the threads execute */
void *runner(void *param){
    char *text;
    text = (char *) param;
  
    printf("text: %s\n", text);

    pthread_exit(0);
}

void *ball(void *param){
    // put the ball at the middle position
    // send it in a random direction at  set speed
    // on collision sendoffs
}

void *paddle(void *param){

}