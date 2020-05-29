#include <iostream>
#include <map>

int main ()
{
  std::multimap<int,int> mymultimap;
  std::multimap<int,int>::iterator it,itlow,itup;

  mymultimap.insert(std::make_pair(10,10));
  mymultimap.insert(std::make_pair(20,121));
  mymultimap.insert(std::make_pair(30,1001));
  mymultimap.insert(std::make_pair(30,1002));
  mymultimap.insert(std::make_pair(40,2002));
  mymultimap.insert(std::make_pair(50,11011));
  mymultimap.insert(std::make_pair(50,11012));
  mymultimap.insert(std::make_pair(60,44));
  mymultimap.insert(std::make_pair(70,45));
  mymultimap.insert(std::make_pair(80,46));

  itlow = mymultimap.lower_bound (30);  // itlow points to b
  itup = mymultimap.upper_bound (30);   // itup points to e (not d)

  std::cout << (*itlow).first << " => " << (*itlow).second << '\n';
  std::cout << (*itup).first << " => " << (*itup).second << '\n';
  // print range [itlow,itup):
//  for (it=itlow; it!=itup; ++it)
//    std::cout << (*it).first << " => " << (*it).second << '\n';

  return 0;
//30 => 1001
//60 => 44

}
