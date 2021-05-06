#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <memory>
#include <map>
#include <sstream>

using namespace std;


/* Everything related to Factory */

enum Team {
	Friend = 1, Enemy = -1, Neutral = 0
};

class Factory {
private:

	struct Node {
		Factory* destiny;
		int distance;

		Node(Factory *_dest, int w) : destiny(_dest), distance(w) {}
		~Node() { delete destiny; }

	};


	Team team;
	int workers;
	int production;
	int id;

	list<Node> adj;

public:
	Factory(int _id) : team(Team::Neutral), workers(0), production(0), id(_id) {}
	Factory(Team _team, int w , int p) : team(_team), workers(w), production(p) {}
	~Factory() {}

	void updateAttributes(int _team, int w, int p) {
		this->team = static_cast<Team>(_team);
		this->workers = w;
		this->production = p;
	}

	void addAdjacent(Factory* f, int w) {
		Node n(f, w);
		adj.push_back(n);	
	}

	bool isFriend() {
		return this->team == Team::Friend;
	}

	string chooseTarget() {
		stringstream ss;

		int min_dist = INT32_MAX;
		int dest_id = 0;

		//cerr << "Cheguei aqui " << this->id << endl; 

		for ( Node &n : adj) {
			if ( n.destiny->production != 0 && !n.destiny->isFriend() ) {
				if ( min_dist < n.distance ) {
					min_dist = n.distance;
					dest_id = n.destiny->id;
				}
			}
		}

		if ( min_dist != INT32_MAX ) {
			ss << "MOVE " << this->id << " " << dest_id << " " << this->workers << " ";
			ss << "; MSG Attack factory " << dest_id << " ";
		}

		return ss.str();
	}

};


/* Map Class  */

class Map {
private:
	int V;
	map<int, Factory*> factories;

public:
	Map(int v) {
		this->V = v;

		for (int id = 0; id < v; id++) {
			Factory* f = new Factory(id); 
			addFactory(f, id);
		}
	}

	~Map() {}

	bool existsFactory(int id) {
		return (factories.find(id) != factories.end());
	}

	void addAdjacency(int id1, int id2, int weigth) {
		Factory* f1 = factories[id1];
		Factory* f2 = factories[id2]; 

		f1->addAdjacent(f2, weigth);
		cerr << "f1" << endl;
		f2->addAdjacent(f1, weigth);
		cerr << "f2" << endl;
	}

	void addFactory(Factory* factory, int id) {
		factories[id] = factory;
	}

	Factory* factoryById(int id) {
		return factories[id];
	}

	string attack() {
		string s = "";

		for (auto &p : factories) {
			Factory* f = p.second;

			if ( f->isFriend() ) {
				string tmp = f->chooseTarget(); 

				if ( tmp != "") {
					s += tmp;
					s += "; ";	
				}
				 
			}
		}

		s += "WAIT "; 

		return s;
	}

};


/* Main function */

int main()
{
    
    int factoryCount; // the number of factories
    cin >> factoryCount; cin.ignore();

    Map map(factoryCount);

    int linkCount; // the number of links between factories
    cin >> linkCount; cin.ignore();
    
    for (int i = 0; i < linkCount; i++) {
        int factory1;
        int factory2;
        int distance;

        cin >> factory1 >> factory2 >> distance; cin.ignore();

        map.addAdjacency(factory1, factory2, distance);

        cerr << i << endl;
    }


    // game loop
    while (1) {
        int entityCount; // the number of entities (e.g. factories and troops)
        cin >> entityCount; cin.ignore();

        // Updating the map
        for (int i = 0; i < entityCount; i++) {
            int entityId;
            string entityType;
            int arg1; // team
            int arg2; // workers
            int arg3; // production
            int arg4;
            int arg5;
            cin >> entityId >> entityType >> arg1 >> arg2 >> arg3 >> arg4 >> arg5; cin.ignore();

            if (entityType == "FACTORY") {
            	Factory* f = map.factoryById(entityId);

        		
            	f->updateAttributes(arg1, arg2, arg3);
            }

        }

        //Moving the robots
        string s = map.attack();

        cout << s << endl;

    }
}