#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>
#include <assert.h>
#include <unordered_map>

using namespace std;

typedef tuple<int, int> Location;

// hash function
namespace std {
	template <>
	struct hash<tuple<int, int> > {
		inline size_t operator()(const tuple<int, int>& location) const {
			int x, y;
			tie(x, y) = location;
			return x * 1812433252 + y;
		}
	};
}

int main() {

	fstream outfile("input.txt", ios::out | ios::trunc);
	assert(outfile.is_open());
	unordered_map<Location, int> nodes;

	int no_waypoints;
	cin >> no_waypoints;
	outfile << no_waypoints << "\n";

	srand(time(NULL));

	int randomX, randomY,cost = 0;
	while(nodes.size() < no_waypoints)
	{
		randomX = (rand() % 99) + 1;
		randomY = (rand() % 99) + 1;
		cost = (rand() % 100) + 1;

		if (!nodes.count({ randomX , randomY })) {
			nodes[{ randomX, randomY }] = cost;
			outfile << randomX << " "<< randomY <<" "<< cost <<"\n";
		}
	}
	outfile << 0;
	return 0;
}