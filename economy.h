#ifndef HS_ECONOMY
#define HS_ECONOMY

//TODO: How do we model the impact of affiliation, enemies, wants and needs? Do we keep a list of items along with a demand rating? For every trade entity (planet, ship, station, etc.)?
//TODO: Also, how does supply impact on supply? If a trade entity receives food, will that increase the likelihood of lifeforms being produced?
//TODO: How closely should we track the movement of supply and demand outside of the player's actions?

//TODO: Would it be helpful to keep a #define for every trade item that matches its index in the economy_items Vector?

#define TRADE_ITEM_SOLID	0
#define TRADE_ITEM_LIQUID	1
#define TRADE_ITEM_GAS		2
#define TRADE_ITEM_LIFE		3
#define TRADE_ITEM_TECH		4
#define TRADE_ITEM_STRANGE	5
#define TRADE_ITEM_COUNT	6

typedef struct Trade_Item
{
	int type;
	char* name;
	char* description;
	int base_value;
	//bool quest_item; TODO: Do we want to track this stuff?
	//int stolen_from; TODO: Do we want to track this stuff?
	//int bought_from; TODO: Do we want to track this stuff?
} Trade_Item;

typedef struct Trade_Inventory_Item
{
	int qty;
	Trade_Item* item;
} Trade_Inventory_Item;

typedef struct Trade_Entity
{
	int creds;
	int* cargo_limits;

	Vector **cargo_items;

} Trade_Entity;

#endif
