#include <bits/stdc++.h>
using namespace std;

#define SERVER_WEIGHT 3   // Number of  copies of physical servers
#define MAX_SERVERS   50  // Maximum number of servers
#define MAX_LOCATIONS (SERVER_WEIGHT * MAX_SERVERS * 1000) // Max indexes where servers can be placed

/*  DataStructure would look like this 
typedef struct _Server {
    int id;        // unique id of server 0 <= id < MAX_SERVERS in the cluster
    int ipaddress; // ip address of the server in the cluster
} Server;

typedef struct _Obj {
    int    key;    // unique key identifying the object 0 <= key < 4095
    void * value;  // abstract object data
} Obj;
*/

/*State maintained by a node*/
unordered_map<int,unordered_set<int>>       server_to_locations_map; // given a server id , the list of locations can be obtained
unordered_map<int,unordered_set<int>>       location_to_objects_map; // given a location , List of objects being served at this location can be obtained
int locations_to_server[MAX_LOCATIONS]; // index is a location , value is the server id serving the location

unordered_set<int> servers;
unordered_set<int> objects;
unordered_set<int> servers_down;

/*Cluster configuration*/
int num_servers;
int num_objects;

//Create servers and objects based on cluster config
void create_servers_and_objects(int num_servers, int num_objects ) {
    for(int i=0;i<num_servers;i++){
        servers.insert(i);
    }  
    for(int i=0;i<num_objects;i++){
        objects.insert(i);
    }
}

//User input - This could at some point come from environment variable ot a db
void get_cluster_config() {
    do {
       cout << "Enter Num servers  (1 to 50, 0 to quit ): " << endl; 
       cin >> num_servers;
    } while (num_servers < 0 || num_servers > 50);
   
    if(num_servers == 0){
        cout << "Quit - Number of servers is 0" << endl;
        exit(0);
    }

    do {
       cout << "Enter Num Objects  (1 to 4095, 0 to quit) : " << endl; 
       cin >> num_objects;
    } while (num_objects < 0 || num_objects > 4095);
   
    if(num_objects == 0){
        cout << "Quit - Number of objects is 0" << endl;
        exit(0);
    }
    
}

//Stub that handles sending of event to server - server doen/up
void send_server_event(int server_id , bool shutdown){
    if(shutdown && servers.find(server_id) != servers.end()) {
        servers_down.insert(server_id);
    } 
    if(!shutdown && servers_down.find(server_id) != servers_down.end()) {
        servers_down.erase(server_id);
    }
}

//User input - This later could be a called when a server crashes or a network connection is lost 
bool handle_event(){
    int event;
    int server_id;
    cout << "0 to bring down a server , 1 to bring up a server anyother value to shutdown the cluster : " << endl;
    cin >> event;
    
    if (!(event >= 0 && event <= 1)) {
        // shutdown cluster
        return true;
    }

    do {
       cout << "Enter Server number : 0 to " << num_servers-1 << " "<< endl; 
       cin >> server_id;
    } while (server_id < 0 || server_id >= num_servers);
    
    send_server_event(server_id , event==0);
    return false;
}

//Start afresh
void clear_all_states() {
    //clear all states
    for(int i=0;i<MAX_LOCATIONS;i++){
        locations_to_server[i]=-1; // no server assigned
    }
    // clear all maps
    server_to_locations_map.clear();
    location_to_objects_map.clear();
}

//Update the state when a server is serving from a location in the consistent Hash ring
void place_server_at_location(int location, int server_id) {
    bool is_server_down = servers_down.find(server_id) != servers_down.end();
    locations_to_server[location] = server_id;
    server_to_locations_map[server_id].insert(location);
    cout << "Server : " << server_id << " is at location : " << location;
    cout << (is_server_down?" Down":" Up") << endl;
}

//For all servers place SERVER_WEIGHT number of servers in the consistent hash ring 
void place_servers_at_locations() {
    int locations_to_skip_per_server = (MAX_LOCATIONS / (num_servers * SERVER_WEIGHT)); // approximate interval for placing srevers
    int location_for_nth_server = 0;
    int server_location;
    // Clear all internal states used for locations,objects and servers
    clear_all_states();
    // Place the servers
    for (int weight=0;weight< SERVER_WEIGHT;weight++){
        for (auto itr = servers.begin();itr != servers.end();itr++) {
            server_location =  location_for_nth_server * locations_to_skip_per_server;
            // place the servet at this location
            place_server_at_location(server_location, *itr);
            location_for_nth_server++;
        }
    }
    
}

// circular buffer for consistent hash ring with index 0 to MAX_LOCATIONS - 1
int get_next_location(int location) {
    if (location == MAX_LOCATIONS -1 ) {
        return 0;
    }
    return location + 1;
}

// given any location , return the server that serves this location if possible
// implements the core Consistent hash ring algorithm
int get_server_for_location(int object_location) {
    
    if(locations_to_server[object_location] != -1 &&
       servers_down.find(locations_to_server[object_location]) == servers.end()){
        // serve the object from this server
        return locations_to_server[object_location];
    }
    // else find the nearest server traversing clockwise to server the object
    for(int next_location = get_next_location(object_location);
            next_location!=object_location;
            next_location = get_next_location(next_location)){
        // if server is available and not down 
        if(locations_to_server[next_location] != -1 && 
           servers_down.find(locations_to_server[next_location]) == servers.end()){
            return locations_to_server[next_location];
        }
    }
    // unable to find a server for the object location
    return -1;
}

// Evident from the name - for every object to ber served , find the server .
// implements the sharding algo
void schedule_objects_to_servers() {
    int object_location;
    hash<string> obj_hash;
    cout << "schedule_objects_to_servers start " << endl;
    //schedule the objects - get a hash(object) modulo MAX_LOCATIONS
    for (auto itr = objects.begin();itr != objects.end();itr++) {
        object_location = obj_hash(to_string(*itr)) % MAX_LOCATIONS;
        cout << "object : " << *itr << " is at location : " << object_location << endl;
        int server_id = get_server_for_location(object_location);
        if (server_id != -1 ) {
            cout << "Object : " << *itr << " Served by : " << server_id << endl;
        } else {
            cout << "Unable to serve Object : " << *itr << endl;
        }
    }
    
}

int main()
{   
    bool shutdown=false;
    cout << "Consistent # Circular buffer Max locations : " << MAX_LOCATIONS << endl;
    get_cluster_config();
    create_servers_and_objects(num_servers, num_objects);
    
    // Run the cluster for ever    
    do {        
        place_servers_at_locations();
        schedule_objects_to_servers();        
        // listen for server down / up event
        shutdown = handle_event();        
    } while(!shutdown);
    cout << "Shutting down cluster" << endl;  
   return 0;
}
