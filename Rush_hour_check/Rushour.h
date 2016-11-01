//
//  Rushour.h
//  RushHour
//
//  Created by Imama Noor on 8/31/16.
//  Copyright © 2016 Imama. All rights reserved.
//

#ifndef Rushour_h
#define Rushour_h


#endif /* Rushour_h */
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef std::pair<float, float> Range;
class Rushhour{
public:
    vector< Range > ranges;
    int AddTimeSpan(float a,float b);
    bool IsRushHour(float time);
    static bool RangeCompare(const Range &a, const Range &b);
    void merge();
};

bool Rushhour::RangeCompare(const Range &a, const Range &b) {
    return a.first < b.first ;
};
void Rushhour::merge() {
    vector<Range> res;
    
    if (ranges.empty())
        return;
    
    sort(ranges.begin(), ranges.end(), Rushhour::RangeCompare);
    res.push_back(ranges[0]);
    vector<Range>::iterator it = ranges.begin();
    it++;
    while (it != ranges.end()){
        if (res.back().second>=it->first){
            res.back().second=max(res.back().second, it->second);
        }else{
            res.push_back(*(it));
        }
        it++;
    }
    ranges = res;
    
};

int Rushhour::AddTimeSpan(float a,float b){
    
    if ( a > 0 && a < 24.000000001 && b > 0 && b < 24.00000001) {
        if (a <= b) {
            ranges.push_back(Range(a,b));
            merge();}
        else if(b < a) {
            ranges.push_back(Range(b,a));
            merge();}
        return 0;
    }
    else {
        cerr<<"invalid input for start and end time\n";
        return -1;
    }
    
};
bool Rushhour::IsRushHour(float time){
    return std::find_if(ranges.begin(), ranges.end(),[&time](const Range & p)
                        { return (p.first < time + .0000001) && (p.second > time - .0000001); }) != ranges.end();
    
};
