
#include "node.cpp"

template <class Generic>
class Stack {

    private:

        int stack_count = 0;
        Node<Generic> *stack_top = NULL;

    public:

        Stack() {

        }

        void push(Generic item) {

            if(stack_count > 0) {

                Node<Generic> *node = new Node<Generic>(item);
                node->set_next(stack_top);
                stack_top = node;
                stack_count++;

            } else {

                stack_top = new Node<Generic>(item);
                stack_count++;

            }

        }

        Generic pop() {

            Node<Generic> *temp = NULL;
            Generic temp_value;

            if(stack_count > 0) {

                temp = stack_top;
                temp_value = temp->get_value();

                stack_top = stack_top->get_next();
                stack_count--;

                temp = NULL;

            }

            return temp_value;
        }

        Generic top() {
            return stack_top->get_value();
        }

        int size() {
            return stack_count;
        }

        bool is_empty() {
            return stack_count == 0? true : false;
        }

        // push
        // pop
        // top
        // size
        // is_empty
        // to_array()

};