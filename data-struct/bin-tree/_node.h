#ifndef Node_T_H
#define Node_T_H

#include <sstream>
#include <iostream>
#include <string>
#include <functional>
#include <list>
#include <assert.h>

using namespace std;

template<typename T>
class Node_t {
public:
    typedef std::list<Node_t<T> *> List;

public:
    Node_t(T d, Node_t<T> *l = nullptr, Node_t<T> *r = nullptr) {
        _data = d;
        _left = l;
        _right = r;
    }

    inline const T data() {
        return _data;
    }
    inline void data(T dat) {
        _data = dat;
    }

    inline const Node_t<T> *left() {
        return _left;
    }
    inline void left(Node_t<T> *l) {
        _left = l;
    }

    inline const Node_t<T> *right() {
        return _right;
    }
    inline void right(Node_t<T> *r) {
        _right = r;
    }

    typedef function<void(void *)> Callback;

    void print() {
        List l1, l2;
        l1.push_back(this);
        string tree = "";

        //root
        cout << getString() << endl;

        while(!l1.empty()) {
            l2.clear();

            for(auto n : l1) {
                tree = "[";
                //print the child trees of a tree
                auto le = n->_left;
                auto ri = n->_right;
                if(le) {
                    tree += le->getString();
                    l2.push_back(le);
                }
                tree += ":";
                if(ri) {
                    tree += ri->getString();
                    l2.push_back(ri);
                }
                tree += "]";
                cout << tree << " ";
            }
            cout << endl;

            l1.swap(l2);
        }
    }

    void traversal(Callback cb) {
        if(left()) {
            cb(this);
            _left->traversal(cb);
        }
        if(right()) {
            cb(this);
            _right->traversal(cb);
        }
    }
    void traversal(Callback cbl, Callback cbr) {
        if(left()) {
            cbl(this);
            _left->traversal(cbl, cbr);
        }
        if(right()) {
            cbr(this);
            _right->traversal(cbl, cbr);
        }
    }

protected:
    T _data;
    Node_t<T> *_left;
    Node_t<T> *_right;

    static string _str;
    static ostringstream _oss;
public:
    virtual const string& getString() {
        _oss.clear();
        _oss << _data;
        _str = _oss.str();
        return _str;
    }
};

template<class T>
string Node_t<T>::_str;
template<class T>
ostringstream Node_t<T>::_oss;

#endif // Node_T_H
