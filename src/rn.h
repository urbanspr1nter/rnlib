//
// Created by roger on 8/28/2022.
//

#ifndef RNLIB_RN_H
#define RNLIB_RN_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;
namespace rn {
    /**
     * Reads a file and returns a string representation
     * of the contents.
     * @param filename
     * @return
     */
    string read_str_from_file(string filename);

    /**
     * Reads a file and returns a wide-character string
     * representation of the contents.
     * @param filename
     * @return
     */
    wstring read_wstr_from_file(string filename);

    /**
     * Saves string data to a specified file.
     * @param filename
     * @param data
     * @param return_status
     */
    void save_str_to_file(string filename, string data, int* return_status);

    /**
     * Saves wide-character stirng data to a specified file.
     * @param filename
     * @param data
     * @param return_status
     */
    void save_wstr_to_file(string filename, wstring data, int* return_status);

    /**
     * Checks to see if the character is a whitespace character.
     * White space is considered to be: space, tab, carriage return, new line
     * @param c
     * @return
     */
    bool isWhitespace(char c);

    /**
     * Trims leading spaces off a wide-character string.
     * @param str
     * @return
     */
    wstring wstr_l_trim(wstring str);

    /**
     * Trims trailing spaces off a wide-character string.
     * @param str
     * @return
     */
    wstring wstr_r_trim(wstring str);

    /**
     * Trims both leading and trailing spaces off from a wide-character string.
     * @param str
     * @return
     */
    wstring wstr_trim(wstring str);

    /**
     * Collapse repeating spaces from a string. For example, 3 consecutive whitepace will
     * just result in a single whitespace.
     * @param str
     * @return
     */
    wstring wstr_collapse_repeating(wstring str);

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

    template<typename T> struct ListNode {
        ListNode(T initialValue, ListNode* next = nullptr):
            _value{initialValue}, _next{next} {}
        void setNext(ListNode *node) {
            this->_next = node;
        }
        void setValue(T newValue) {
            this->_value = newValue;
        }
        T getValue() {
            return this->_value;
        }
        ListNode* getNext() {
            return this->_next;
        }
    private:
        T _value;
        ListNode* _next;
    };

    template<typename T> void print_list(ListNode<T>* start) {
        ListNode<T> *t = start;

        while(t != nullptr) {
            if (t->getNext() == nullptr) {
                cout << t->getValue();
            } else {
                cout << t->getValue() << ", ";
            }
            t = t->getNext();
        }
    };

    template<typename T>
    struct BinaryTreeNode {
        BinaryTreeNode(T initialValue, BinaryTreeNode* left = nullptr, BinaryTreeNode* right = nullptr):
            _value{initialValue}, _left{left}, _right{right} {}
        void setLeft(BinaryTreeNode* left) {
            this->_left = left;
        }
        void setRight(BinaryTreeNode* right) {
            this->_right = right;
        }
        void setValue(T newValue) {
            this->_value = newValue;
        }
        BinaryTreeNode* getLeft() {
            return this->_left;
        }
        BinaryTreeNode* getRight() {
            return this->_right;
        }
        T getValue() {
            return this->_value;
        }
    private:
        T _value;
        BinaryTreeNode *_left;
        BinaryTreeNode *_right;
    };

    // end
}

#endif //RNLIB_RN_H
