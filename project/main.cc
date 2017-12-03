#include <iostream>
#include "quadris.h"
#include "gameboard.h"
#include <map>
#include <vector>
#include <sstream>

using namespace std;


int main(int argc, const char * argv[]) {

	////////////////////////////////////////////////////
	cout << "Hello Quadris!" << endl;
	cout << "--------------" << endl << endl;
	//Quadris q;
	// q.init();

	Quadris q{};
	////////////////////////////////////////////////////

	for(int i=0; i<argc; ++i) {

		string arg = argv[i];

		if(arg=="-text") {

			q.isGraphics(true);

		} else if(arg=="-seed") {

			int num;
            istringstream ss(argv[i + 1]);
            ss >> num;
            q.setSeed(num);

		} else if(arg=="-scriptfile") {

			q.setFilename(argv[i + 1]);


		} else if(arg=="-startlevel") {

			int num;
            istringstream ss(argv[i + 1]);
            ss >> num;
            q.startLevel(num);

		}
	}

	q.init();
	
}

