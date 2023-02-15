#include <map>
#include "map.hpp"
#include "./utils/make_pair.hpp"
#include <iostream>
#include <vector>
#include "./utils/pair.hpp"

#ifndef NS
	#define NS std
#endif

template <class Key, class T>
void	print(NS::map<Key, T>& lst)
{
	for (typename NS::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}

int main ()
{
  NS::map<char,int> mymap;
  NS::map<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;

  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)

  std::cout << "low : " << itlow->first << '\n';
  std::cout << "up : " << itup->first << '\n';

 	mymap.erase(itlow,itup);        // erases [itlow,itup)

mymap.show();
  // print content:
  for (NS::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
 }
