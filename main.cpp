#include <iostream>
#include <string>

using namespace std;

struct Food {
    string id;        
    string name;       
    double price;      
    int quantity; 
};

struct Order {
    string id;
    string customerName;
    string address;
    Food food;
    int quantity;
    string status;
};

struct Restaurant {
    string name;
    string address;
    string phone;
    
    Food foods[100];
    int foodCount = 0;
    
    Order orders[100];
    int orderCount = 0;
};