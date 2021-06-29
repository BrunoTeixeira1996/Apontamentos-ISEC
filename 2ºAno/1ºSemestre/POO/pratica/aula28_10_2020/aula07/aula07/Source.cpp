#include "televisao.h"


int main() {

	televisao tv({ "rtp1","rtp2","rtp3","sic","tvi","natgeo","foxcrime" });

	//tv.liga();
	cout << tv.getAsString();

	return 0;
}