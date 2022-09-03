//
// Created by roger on 8/28/2022.
//
#include "rn.h"

string rn::read_str_from_file(std::string filename) {
    ifstream inf { filename };
    string result;

    if (!inf) {
        return result;
    }

    while (inf) {
        string line;
        getline(inf, line);
        result += line;
    }

    inf.close();

    return result;
}

wstring rn::read_wstr_from_file(std::string filename) {
    wifstream inf { filename };
    wstring result;

    if (!inf) {
        return result;
    }

    while (inf) {
        wstring line;
        getline(inf, line);
        result += line;
    }

    inf.close();

    return result;
}

int rn::save_wstr_to_file(std::string filename, std::wstring data) {
    wofstream of {filename};
    if (!of) {
        return 1;
    }

    of << data;

    of.close();

    return 0;
}

int rn::save_str_to_file(std::string filename, std::string data) {
    ofstream of {filename};
    if (!of) {
        return 1;
    }

    of << data;

    of.close();

    return 0;
}

bool rn::str_is_eq(const string first, const string second) {
    return first.compare(second) == 0;
}

vector<string> rn::str_split(string str, char delimiter) {
    vector<string> result;

    string word = "";
    for (size_t i = 0; i < str.length(); i++) {
        if (str.at(i) == delimiter) {
            result.push_back(word);
            word = "";
        }
        else {
            word += str.at(i);
        }
    }

    result.push_back(word);

    return result;
}

bool rn::isWhitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

wstring rn::wstr_trim(wstring str) {
    wstring result;

    size_t start = 0;
    size_t end = 0;
    for (size_t i = 0; i < str.length(); i++) {
        wchar_t c = str.at(i);

        if (isWhitespace(c)) {
            continue;
        } else {
            start = i;
            break;
        }
    }

    for (size_t i = str.length() - 1; i > 0; i--) {
        wchar_t c = str.at(i);
        if (isWhitespace(c)) {
            continue;
        } else {
            end = i;
            break;
        }
    }

    if (start >= str.length() || start > end) {
        return result;
    }

    for (size_t i = start; i <= end; i++) {
        wchar_t c = str.at(i);
        result += c;
    }

    return result;
}

map<string, string> rn::vec_to_map(vector<std::string> keys, vector<std::string> values) {
    map<string, string> result;

    if (keys.size() != values.size()) {
        return result;
    }

    for (size_t i = 0; i < keys.size(); i++) {
        result.emplace(keys[i], values[i]);
    }

    return result;
}

rn::CsvReader::CsvReader(const string filename, bool parseColumns) {
    this->_file = new std::ifstream();
    this->_file->open(filename);

    if (!this->_file->good()) {
        this->_file = nullptr;
        this->_end = true;
    }
    else {
        if (parseColumns) {
            this->_columns = this->next();
        }
    }
}

rn::CsvReader::~CsvReader() {
    this->_file->close();
}

map<string, string> rn::CsvReader::nextAsMap() {
    map<string, string> result;

    if (this->_columns.empty() || this->_file == nullptr) {
        return result;
    }

    vector<string> keys = this->_columns;
    vector<string> values = this->next();

    result = vec_to_map(keys, values);

    return result;
}

vector<string> rn::CsvReader::next() {
    vector<string> result;

    if (this->_file == nullptr) {
        return result;
    }

    string line;
    getline(*this->_file, line);

    if (this->_file->eof()) {
        this->_end = true;
    }

    if (line.length() == 0) {
        return result;
    }

    return this->_toVector(line);
}

void rn::CsvReader::close() {
    this->_file->close();
}

bool rn::CsvReader::hasNext() {
    return !this->_end;
}

vector<string> rn::CsvReader::_toVector(string line) {
    vector<string> result;

    string word{ "" };
    bool inQuotes = false;

    for (size_t i = 0; i < line.length(); i++) {
        char c = line.at(i);

        if (c == '"') {
            inQuotes = !inQuotes;
        }
        else if (c == ',' && !inQuotes) {
            result.push_back(word);

            word = "";
        }
        else {
            word += c;
        }
    }

    result.push_back(word);

    return result;
}

