#include <bits/stdc++.h>

using namespace std;
class Compare
{
public:
    bool operator() (pair<unsigned long long , int> &v1, pair<unsigned long long , int> &v2)
    {
        return v1.first > v2.first;
    }
};
class LRUCache {
private:
    int n;
    map<int,pair<unsigned long long , int> > kv;
    priority_queue<pair<unsigned long long , int >,vector < pair<unsigned long long , int > >,Compare> min_heap;
    map<int,pair<unsigned long long , int> >::iterator itr;
public:
    static unsigned long long curr_time;
    LRUCache(int capacity) {
        n=capacity;
        LRUCache::curr_time=0;
    }
    
    int get(int key) {
        itr=kv.find(key);
        pair<unsigned long long , int> val;
        if(itr==kv.end()){
            for(auto i:kv){
                //cout << " Key : " << i.first << " timestamp : " << i.second.first << " value : "<< i.second.second << endl;
            }
            return -1;
        }else{
            //update timestamp
            itr->second.first = LRUCache::curr_time++;
            val=itr->second;
            for(auto i:kv){
                //cout << "Get  Key : " << i.first << " timestamp : " << i.second.first << " value : "<< i.second.second << endl;
            }
            return val.second;
        }
    }
    
    void put(int key, int value) {
        itr=kv.find(key);
        
        if(itr != kv.end()){
            // if key already exisits just update value and timestamp in the map
            itr->second.first = LRUCache::curr_time++;
            itr->second.second = value;

        }else if(kv.size() == n){
            // find a replacement
            pair<unsigned long long , int> pq_top;
            pair<unsigned long long , int> map_kv;
            pq_top = min_heap.top();
            map_kv=kv[pq_top.second];
            
            //cout << " Key m : " << pq_top.second << " timestamp m : " << map_kv.first << " time stamp pq : " << pq_top.first <<  endl;
            
            while(pq_top.first < map_kv.first){
                // we had a get that is after the put. update the ts in min_pq
                // pop the element and push with new timestamp
                min_heap.pop();
                pq_top.first=map_kv.first;
                min_heap.push(pq_top);
                // check the current 
                pq_top = min_heap.top();
                map_kv=kv[pq_top.second];
                //cout << " Key m : " << pq_top.second << " timestamp m : " << map_kv.first << " time stamp pq : " << pq_top.first <<  endl;
            }

            // LRU is pq_top, remove the element from min_heap
            min_heap.pop();

            // remove the old element from map
            kv.erase(pq_top.second);

            // update the time for new values 
            unsigned long long time;
            time = LRUCache::curr_time++;

            // push the new element into min_heap
            pq_top.first=time;
            pq_top.second=key;
            min_heap.push(pq_top);

            // insert the new element into map
            pair<unsigned long long , int> ts_val;
            ts_val.first=time;
            ts_val.second=value;
            kv[key]=ts_val;

        }else{
            // insert into min_heap and map
            pair<unsigned long long , int> ts_val;
            pair<unsigned long long , int> ts_key;
            unsigned long long time;
            time = LRUCache::curr_time++;
            ts_val.first=time;
            ts_val.second=value;
            ts_key.first=time;
            ts_key.second=key;

            kv[key]=ts_val;
            min_heap.push(ts_key);

            //cout << "Put :  Key m : " << key << " pq t: " <<  ts_key.first << " map t : " << ts_val.first << endl;

        }
    }
};

unsigned long long LRUCache::curr_time=0;
int main()
{
    LRUCache cache(2);
    cout << endl;
    cout << cache.get(2);
    cout << endl;
    cache.put(2,6);
    cout << cache.get(1);
    cout << endl;
    cache.put(1,5);
    cache.put(1,2);
    cout << cache.get(1);
    cout << endl;
    cout << cache.get(2);
    cout << endl;
}

