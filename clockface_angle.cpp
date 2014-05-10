// Given the number of seconds that have elapsed during a day, find
// the angle between the minute and second hand.

#include <cmath>

int find_clockface_angle(int seconds){
	int min_angle = ( seconds % 43200 ) / 360; // 43200 = 60 * 60 * 12
	int sec_angle = ( seconds % 60 ) / 60;
	return abs(min_angle - sec_angle);
}
