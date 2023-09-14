/*//
//  Just some routines to implement remove, insert and get_random func by hash table and list.
//*/


class RandomizedSet {
public:
    RandomizedSet() {

    }

    bool insert(int val) {
        if (map.count(val))
        {
            return false;
        }
        map[val] = set.size();
        set.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (map.count(val))
        {
            int index = map[val];
            int lastvalue = set.back();
            set[index] = lastvalue;
            set.pop_back();
            map[lastvalue] = index;
            map.erase(val);
            return true;
        }
        return false;
    }

    int getRandom() {
        int randomIndex = rand() % set.size();
        return set[randomIndex];
    }
private:
    vector<int> set;
    unordered_map<int, int> map;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */