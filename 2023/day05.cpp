#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdint>

using namespace std;

int main(void)
{
	vector<uint64_t> vals;
	string line;

	getline(cin, line);
	uint64_t og_val;
	istringstream iss(line.substr(7));
	while(iss >> og_val)
		vals.push_back(og_val);

	vector<bool> done_yet(vals.size(), false);

	getline(cin, line); // Skip empty line
	while(!cin.eof()) {
		getline(cin, line); // Skip map name
		getline(cin, line);
		do {
			uint64_t dest, src, len;
			iss = istringstream(line);
			iss >> dest >> src >> len;

			for(auto val = vals.begin(); val != vals.end(); ++val)
				if(!done_yet[val - vals.begin()] && *val >= src && *val < src + len) {
					*val -= src;
					*val += dest;
					done_yet[val - vals.begin()] = true;
				}
			getline(cin, line);
		} while(!cin.eof() && !line.empty());

		fill(done_yet.begin(), done_yet.end(), false);
	}

	const auto min_loc = min_element(vals.cbegin(), vals.cend());
	cout << *min_loc << '\n';
	return 0;
}

