
#include <functional>
#include <numeric>
#include <string>
#include <utility>
#include <list>
#include <unordered_map>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class UndergroundSystem
{
public:
	// time: O(1)
	void checkIn(int id, string start_station, int t)
	{
		checkins.push_back(std::make_pair(id, timestamp(start_station, t)));
	}

	// time: O(n) + O(1) optimal, O(n * m) worst
	void checkOut(int id, string end_station, int t)
	{
		auto checkin = std::find_if(begin(checkins), end(checkins),
				[id](const auto& pair) { return pair.first == id; });
		int diff = t - checkin->second.t;
		auto& entry = accums[checkin->second.station][end_station];
		++entry.first;
		entry.second += diff;

		checkins.erase(checkin);
	}

	// time: O(1) optimal, O(n * m) worst
	double getAverageTime(string start_station, string end_station)
	{
		const auto& times = accums[start_station][end_station];
		return times.second / times.first;
	}

private:
	struct timestamp
	{
		std::string station;
		int t;
		timestamp(std::string station, int t) : station(station), t(t)
		{}
	};
	
	std::list<std::pair<int, timestamp>> checkins;
	std::unordered_map<std::string, std::unordered_map<std::string, std::pair<int, double>>> accums;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

int main(int argc, char** argv)
{
}
