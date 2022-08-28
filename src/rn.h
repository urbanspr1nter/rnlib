//
// Created by roger on 8/28/2022.
//

#ifndef RNLIB_RN_H
#define RNLIB_RN_H

#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;
namespace rn {
    bool str_is_eq(string first, string second);
    vector<string> str_split(string str, char delimiter);
    map<string, string> vec_to_map(vector<string> keys, vector<string> values);

    class CsvReader {
        vector<string> _toVector(string line);
        vector<string> _columns;
        ifstream* _file;
        bool _end{ false };
    public:
        CsvReader(string filename, bool parseColumns = false);
        ~CsvReader();
        vector<string> next();
        map<string, string> nextAsMap();
        void close();
        bool hasNext();
    };
}

#endif //RNLIB_RN_H
