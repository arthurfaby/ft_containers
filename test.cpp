#include <map>
#include "map.hpp"
#include "./utils/make_pair.hpp"
#include <iostream>
#include <vector>

#ifndef NS
	#define NS std
#endif

int	main(void)
{
	std::vector<std::pair<int, int> >	v;

	v.push_back(std::make_pair(1, 1));
	v.push_back(std::make_pair(2, 1));
	v.push_back(std::make_pair(3, 1));
	v.push_back(std::make_pair(4, 1));
	v.push_back(std::make_pair(5, 1));
	v.push_back(std::make_pair(6, 1));
	v.push_back(std::make_pair(7, 1));
	v.push_back(std::make_pair(8, 1));
	v.push_back(std::make_pair(9, 1));
	v.push_back(std::make_pair(10, 1));
	const NS::map<int, int>	m(v.begin(), v.end());
	/* NS::map<int, int>	m(v.begin(), v.end()); */

	NS::map<int, int>::const_iterator	it = m.begin();
	/* NS::map<int, int>::iterator	it = m.begin(); */
	--it;
	for (int i = 0; i < 20; ++i, --it)
		std::cout << it->first << std::endl;
}
