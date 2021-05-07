#include "storage/tsmap.h"

#include <map>
using namespace std;
int main() {
    TSCached::TSMap *tsMap = new TSCached::TSMap();
    string db = "test";
    string tableName = "tem";
    map<string,string> tags;
    tags["location"] = "SH";
    tags["owner"] = "JZG";
    TSCached::Point point(db,tableName,tags);
    for (int i = 0; i < 100; ++i) {
        TSCached::Field field;
        field.fields["item"] = i+1;
        field.fields["otem"] = i+2;
        point.Insert(field);
    }
    tsMap->Insert(point);
    TSCached::QueryPoints queryPoints(point);
    tsMap->Query(queryPoints);
    queryPoints.Print();
    return 0;
}
