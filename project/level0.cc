#include "level0.h"
#include "blocki.h"
#include "blockj.h"
#include "blockl.h"
#include "blocko.h"
#include "blocks.h"
#include "blockt.h"
#include "blockz.h"
using namespace std;

Level0::Level0(string filename)
: v{} {
	char blockType;
	ifstream f{filename};
	while(f >> blockType) {
		v.emplace_back(blockType);	
	}
}

Block* Level0::getBlock() {
	char firstLetter = *v.begin();
	if (firstLetter == 'I') {
		v.erase(v.begin());
		return new BlockI;
	}
	else if (firstLetter == 'J') {
		v.erase(v.begin());
		return new BlockJ;
	}
	else if (firstLetter == 'L') {
		v.erase(v.begin());
		return new BlockL;
	}
	else if (firstLetter == 'O') {
		v.erase(v.begin());
		return new BlockO;
	}
	else if (firstLetter == 'S') {
		v.erase(v.begin());
		return new BlockS;
	}
	else if (firstLetter == 'Z') {
		v.erase(v.begin());
		return new BlockZ;
	}
	else {
		v.erase(v.begin());
		return new BlockT;
	}
}

Level0::~Level0() {}
