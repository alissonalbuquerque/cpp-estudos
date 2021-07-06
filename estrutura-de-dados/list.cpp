
#include "node.cpp"

template<class Generic>
class List {

    private:
        int list_count = 0;
        Node<Generic> *back = NULL;
        Node<Generic> *front = NULL;

    public:

        bool add(Generic item) {

            if(list_count == 0) {   

                front = new Node<Generic>(item);
                back = front;
                list_count++;

                return true;
            } else {

                back->set_next(new Node<Generic>(item));
                back = back->get_next();
                list_count++;

                return true;
            }

            return false;

        }

        Generic remove(int index) {

            Node<Generic> *node = NULL;
            Node<Generic> *node_temp = NULL;

            Generic temp = front->get_value();

            node = front;

            if(index == 0) {

                temp = front->get_value();
                front = front->get_next();
                node = NULL;

            } else if(index == list_count-1) {

                for(int i = 0; i < index-2; i++) {
                    node = node->get_next();
                    node->set_next(NULL);
                    temp = node->get_value();
                }

            } else {

                for(int i = 0; i < index-1; i++) {
                    node = node->get_next();
                }

                node_temp = node->get_next();
                node->set_next(node_temp->get_next());

                temp = node_temp->get_value();
                node_temp = NULL;
                
            }

            list_count--;
            return temp;

        }

        bool insert(int index, Generic item) {

            Node<Generic> *node = NULL;

            node = front;
            
            if(index > 0) {

                for(int i = 0; i < index; i++) {
                    node = node->get_next();
                }

            }

            node->set_value(item);

            return true;
        }

        Generic get(int index) {

            Node<Generic> *node = NULL;

            node = front;
            
            if(index > 0) {

                for(int i = 0; i < index; i++) {
                    node = node->get_next();
                }

            }

            Generic item = node->get_value();
            node = NULL;

            return item;
        }

        bool swap(int index_1, int index_2) {

            Node<Generic> *node_1 = NULL;
            Node<Generic> *node_2 = NULL;

            node_1 = front;
            node_2 = front;

            if(index_1 > 0) {
                for(int i = 0; i < index_1; i++) {
                    node_1 = node_1->get_next();
                }
            }

            if(index_2 > 0) {
                for(int j = 0; j < index_2; j++) {
                    node_2 = node_2->get_next();
                }
            }

            Generic temp = node_1->get_value();
            node_1->set_value(node_2->get_value());
            node_2->set_value(temp);

            node_1 = NULL;
            node_2 = NULL;

            return true;
        }

        int size() {
            return list_count;
        }

        bool is_empty() {
            return list_count == 0? true : false;
        }

};

// add
// remove
// insert
// get
// swap
// clear
// size
// is_empty
// to_array