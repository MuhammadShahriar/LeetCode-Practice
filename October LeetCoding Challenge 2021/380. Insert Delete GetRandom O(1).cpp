#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;


typedef long long ll;

typedef tree< ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
void erase ( ordered_set &s, ll val )
{
	auto it = s.upper_bound(val);

	if ( it == s.begin() && val == *s.begin() ) s.erase ( s.upper_bound(val) );
	else s.erase ( s.upper_bound(val) );
}

class RandomizedSet {
public:
    ordered_set s;
    map<int, bool> vis;
    RandomizedSet() {
        s.clear();
        vis.clear();
    }
    
    bool insert(int val) {
        if ( vis[val] ) return 0;
        s.insert(val);
        vis[val] = 1;
        return 1;
    }
    
    bool remove(int val) {
        if ( vis[val] == 0 ) return 0;
        erase(s, val);
        vis[val] = 0;
        return 1;
    }
    
    int getRandom() {
        return *s.find_by_order(rand() % s.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */