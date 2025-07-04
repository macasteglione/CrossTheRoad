/**
 * @file Constants.h
 * @brief Archivo de constantes del juego.
 * @author macasteglione
 * @date 2025-06-28
 */

#ifndef CONSTANTS_HEADER
#define CONSTANTS_HEADER

// Ventana del juego
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TARGET_FPS 60

// Character
#define CHARACTER_DEFAULT_SPEED 1.0f

// Player
#define PLAYER_SPRITE_SHEET "assets/playerSprites.png"
#define PLAYER_SPRITE_FRAMES 3
#define PLAYER_SPRITE_ROWS 4
#define PLAYER_SPRITE_LEFT 2
#define PLAYER_SPRITE_RIGHT 3
#define PLAYER_SPRITE_UP 1
#define PLAYER_SPRITE_DOWN 4

// Car
#define CAR_LEFT -1
#define CAR_RIGHT 1
#define CAR_SPRITE_SHEET "assets/jeep_1/Ride.png"
#define CAR_SPRITE_ROWS 2
#define CAR_SPRITE_FRAMES 8
#define CAR_SPRITE_LEFT 0
#define CAR_SPRITE_RIGHT 1

// Server
#define MAX_LINE 1024
#define SERVER_PORT 28002

#endif // !CONSTANTS_HEADER
