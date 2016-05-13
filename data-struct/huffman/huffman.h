#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "../bin_tree/node.h"

template<typename T>
class HuffNode : public Node<T> {
public:
    typedef std::list<HuffNode<T> *> List;
    class Compare {
    public:
        bool operator()(HuffNode<T> *n1, HuffNode<T> *n2) {
            return n1->weight() < n2->weight();
        }
    };
public:
    HuffNode(float w, T d,
             HuffNode<T> *l = nullptr,
             HuffNode<T> *r = nullptr)
        : Node<T>(d, l, r) {
        _weight = w;
    }
    //~HuffNode();

    inline float weight() {
        return _weight;
    }
    inline void weight(float w) {
        _weight = w;
    }

    const string &getString() override {
        static string str;

        Node<T>::_oss.clear();
        Node<T>::_oss << "(" <<_weight << ","
                      << this->_data << ")";
        str = Node<T>::_oss.str();

        return str;
    }

    static HuffNode<T> *Build(List *l) {
        assert(!l->empty());

        l->sort(Compare());

        //cout << n->weight() << endl;
        while(1 != l->size()) {
            auto n1 = l->front();
            l->pop_front();
            auto n2 = l->front();
            l->pop_front();

            auto nn = new HuffNode<T>(n1->weight() + n2->weight(), "", n1, n2);

            l->push_front(nn);
            //insert(l, nn);
            //find a proper position insert the node into List
            /*
            for(typename List::iterator
                it = l->begin();
                it != l->end(); it++) {
                HuffNode<T> *n = *it;
                if(nn->weight() < n->weight()) {
                    l->insert(it, nn);
                    break;
                }
            }
            //lst->push_back(node); // */
        }

        return l->front();
    }

private:
    float _weight;
};

#endif // HUFFMAN_H
