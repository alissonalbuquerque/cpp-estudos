
#include <cstddef> // import pointer NULL

template <class Generic>
class Node {

    private:

        Generic value;
        Node *next = NULL;

    public:

        Node() {

        }

        Node(Generic v) {
            value = v;
        }

        Generic get_value() {
            return value;
        }

        void set_value(Generic v) {
            value = v;
        }

        Node* get_next() {
            return next;
        }

        void set_next(Node * n) {
            next = n;
        }
        
};
