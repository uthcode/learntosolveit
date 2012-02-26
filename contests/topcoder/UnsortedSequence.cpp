#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class UnsortedSequence {
public:
    vector <int> getUnsorted(vector <int> s) {
        vector <int> res;
        vector <int> empty;
        vector <int>::iterator it;
        stable_sort(s.begin(),s.end());
        res = s;
        int last_element;
        int total_len;
        total_len = res.size()-1;
        last_element = res[res.size()-1];
        res.erase(res.begin()+res.size()-1);
        // insert it at the correct place
        if (res.size() == 0)
            return empty;


        int counter;
        counter = total_len;
        for (it=res.end(); it>=res.begin(); it--)
            if (*it < last_element)
                break;
            else
                counter--;

        if (counter < 0)
            return empty;
        
        res.insert(res.begin()+counter,last_element);
        
        return res;
    }

};
