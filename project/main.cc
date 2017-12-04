#include <iostream>
#include "quadris.h"
#include "gameboard.h"
#include <map>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, const char * argv[]) {

	///////////////////////////////////////////////////
	cout << "Hello Quadris!" << endl;
	cout << "--------------" << endl << endl;
	//Quadris q;
	// q.init();

	
	bool withBonus = false;
	bool withGraphics = true;
	int seed = 1;
	string filename = "sequence.txt";
	int startLevel = 0;

	////////////////////////////////////////////////////

	for(int i=0; i<argc; ++i) {

		string arg = argv[i];

		if(arg=="-text") {
			withGraphics = false;

		} else if(arg=="-seed") {

			int num;
            istringstream ss(argv[i + 1]);
            ss >> num;
            seed = num;

		} else if(arg=="-scriptfile") {

			filename = argv[i + 1];


		} else if(arg=="-startlevel") {

			int num;
            istringstream ss(argv[i + 1]);
            ss >> num;
            startLevel = num;
		} else if (arg == "-enablebonus") {
			withBonus = true;
		}
	}
	Quadris q{withBonus, seed, withGraphics, filename, startLevel};
	q.init();
	
}
