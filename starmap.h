#ifndef HS_STARMAP
#define HS_STARMAP

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "util/vector.h"
#include "planets.h"

#define FACTION_COLOR_NONE (SDL_Color){255, 255, 255, 255}
#define FACTION_COLOR_SNEEB (SDL_Color){220, 75, 175, 255}
#define FACTION_COLOR_KRULL (SDL_Color){75, 185, 60, 255}
#define FACTION_COLOR_PLINK (SDL_Color){135, 120, 245, 255}

#define TRAVEL_FACTION_NONE 0
#define TRAVEL_FACTION_SNEEB 1
#define TRAVEL_FACTION_KRULL 2
#define TRAVEL_FACTION_PLINK 3

typedef struct Travel_Node NODE;

typedef struct Travel_Node
{
	int depth;
	int x;
	int y;
	int f;
	struct Planet *p;
	bool connected;
	NODE *connections[4];
} Travel_Node;

typedef struct Travel_NodeDefs
{
	int merge_dist;
	int max_depth;
	int spread;
	int jitter;
	int bounds;
	int max_connection_dist; //something around merge_dist + spread + jitter
	int faction; //-1 gives nodes random factions
} Travel_NodeDefs;

SDL_Texture *t_stars1;
SDL_Texture *t_stars2;
SDL_Texture *t_stars3;
SDL_Texture *t_stars4;
SDL_Texture *t_stars5;
SDL_Texture *t_stars6;
SDL_Texture *t_node;
SDL_Texture *t_node_current;

int current_node;
int half_node_sprite;
int inhabited_planet_count;
int t_sectorX;
int t_sectorY;

int starmap_setup();
int starmap_move_sector(int direction);
void update_starmap_icons();
int starmap_go(int destination);

void make_child_nodes(Vector *node_list, Travel_Node *n, int max_depth, int spread, int jitter, int merge_dist, int bounds, int direction);
int get_line_intersection(Travel_Node *p0, Travel_Node *p1, Travel_Node *p2, Travel_Node *p3);
bool check_connection(Vector *node_list, Travel_Node *na1, Travel_Node *na2);
bool add_connection(Travel_Node *local_node, Travel_Node *remote_node);
void configure_connections(Vector *node_list, Travel_Node *n, int max_connection_dist);
void make_tree(Vector *node_list, Travel_NodeDefs defs, int root_x, int root_y);
void starmap_draw(Vector *node_list);
void generate_starmap();

#endif