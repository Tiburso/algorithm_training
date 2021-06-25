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
		~Node() {}

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

    void printId() {
        cerr << id << "\n";
    }

	void addAdjacent(Factory* f, int w) {
		Node n(f, w);
        
		adj.push_back(n);
	}

    bool isEnemy() {
        return this->team == Team::Enemy;
    }

	bool isFriend() {
		return this->team == Team::Friend;
	}

    // nao faz nada 
	void moveWorkers(int w, Factory& f) {
		if ( workers - w < 0) {
			workers = 0;
			f.workers += workers;
		}
		
		else {
			workers -= w;
			f.workers += w;
		}
	}

	string chooseAction(int &bombCount) {
		stringstream ss;

        if ( workers > 10 && production < 3 ) {
            ss << "INC " << this->id << ";";
        }

		for ( Node &n : adj) {

			if ( n.destiny->production > 0 && !n.destiny->isFriend() ) {
                if  ( n.destiny->isEnemy() && n.destiny->production == 3 && bombCount > 0 ) {
                    ss << "BOMB " << this->id << " " << n.destiny->id << ";";
                    bombCount--;
                    continue;
                }

                if ( this->workers >= n.destiny->workers+1 ) {
                    ss << "MOVE " << this->id << " " << n.destiny->id << " " <<  n.destiny->workers+1 << ";";

                    this->workers -=  n.destiny->workers+1;
                }
                
			}

            if ( workers == 0 ) break;
		}

		return ss.str();
	}

};


/* Map Class  */

class Map {
private:
	int nFactories;
    int bombCount = 2;
	vector<Factory*> factories;

public:
	Map(int numberFactories) {
		this->nFactories = numberFactories;

        factories = vector<Factory*>(numberFactories);

		for (int id = 0; id < numberFactories; id++) {
			Factory* f = new Factory(id); 
			addFactory(f, id);
		} 

        
	}

	~Map() {}

	void addAdjacency(int id1, int id2, int weigth) {
		Factory* f1 = factories[id1];
		Factory* f2 = factories[id2]; 

        f1->addAdjacent(f2, weigth);
		f2->addAdjacent(f1, weigth);
       
	}

	void addFactory(Factory* factory, int id) {
		factories[id] = factory;
	}

	Factory* factoryById(int id) {
		return factories[id];
	}

	string attack() {
		string s = "";

		for (Factory* f : factories) {

            if ( f->isFriend() ) {
				string tmp = f->chooseAction(bombCount); 

				if ( tmp != "") {
					s += tmp;	
				}
				 
			}
		}

		s += "WAIT"; 

		return s;
	}

};


/* Main function */

int main()
{
    int factoryCount; // the number of factories
    cin >> factoryCount; cin.ignore();

    Map map(factoryCount);

    //cout << "MSG OI???" << "\n";

    int linkCount; // the number of links between factories
    cin >> linkCount; cin.ignore();
    
    
    for (int i = 0; i < linkCount; i++) {
        int factory1;
        int factory2;
        int distance;

        cin >> factory1 >> factory2 >> distance; cin.ignore();

        map.addAdjacency(factory1, factory2, distance);

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
            int arg4; // turns before it starts producing again 
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