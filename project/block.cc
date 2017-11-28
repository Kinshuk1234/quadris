#include "block.h"

using namespace std;

void Block::translateX(bool toRight) {
	// gameBoard should be validating this increment
	if(toRight) {
		// increment pos.x by 1
		for(int i=0; i<orientations.size(); ++i) {
			for(int j=0; i<4; ++j) {
				orientations.at(i).at(j).x += 1;
			}
		}
	} else {
		// decrement pos.x by 1
		for(int i=0; i<orientations.size(); ++i) {
			for(int j=0; i<4; ++j) {
				orientations.at(i).at(j).x -= 1;
			}
		}
	}
}

void Block::translateY() {
	// gameBoard should be validating this increment
	for(int i=0; i<orientations.size(); ++i) {
			for(int j=0; i<4; ++j) {
				orientations.at(i).at(j).y += 1;
			}
		}
}

void BlockL::checkOrientation(const BlockL &b) {
	int count = 0;
	for(int i=0; i<4; ++i) {
		for(int j=0; j<4; ++j) {
			if(orientations.at(i).at(j) != b.orientations.at(i).at(j)) {
				break;
			}
			count += 1;
		}
		if(count==4) {
			currOrientation = i;
			break;
		}
	}
}

void BlockL::rotate_cw() {
	// gameBoard should validate this rotation
	currOrientation = (currOrientation + 1) % 4;
}

void BlockL::rotate_ccw() {
	// gameBoard should validate this rotation
	currOrientation = (currOrientation - 1) % 4;
}