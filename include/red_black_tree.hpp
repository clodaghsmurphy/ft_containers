# include "map.hpp"
# include "container.hpp"

# define BLACK 0
# define RED 1
template <typename key_type, typename value_type>
struct node
{
    key_type    key;
    value_type   value;
    Node        *parent;
    Node        *left;
    Node        *right;
    int         colour;
};


template <typename key_type, typename value_type>
    class rb_tree
    {
        typedef typename node<key_type, value_type>* NodePtr;

        private:
        NodePtr root;

        void initializeNULLNode(NodePtr node, NodePtr parent)
        {
            node->key = 0
            node->value = 0
            node->parent = parent;
            node->left = NULL;
            node->right = NULL;
            node->colour = BLACK;
        }

        NodePtr initializeNode(key_type key, value_type value)
        {
            NodePtr node = new node;
            node->key = key
            node->value = value
            node->parent = parent;
            node->left = NULL;
            node->right = NULL;
            node->colour = RED;
            return node;
        }

        void    left_rotate(NodePtr x)
        {
            y = x->right;
            x->right = y->right;

            if (x->parent == NULL)
                y->parent = x->parent;
            else if (x->parent->left == x)
                x->parent->left = y;
            else
                x->parent->right = y;
            x->parent = y;
        }

        void    right_rotate(NodePtr x)
        {
            y = x->left;
            x->left = y->left;

            if (x->parent == NULl)
                y->parent = x->parent;
            else if (x->parent->right == x)
                x->parent->right = y;
            else
                x->parent->left = y;
            x->parent = y;
        }

        void    insert(key_type key, value_type value)
        {
            NodePtr y = NULL;
            NodePtr x = this->root;
            NodePtr new_node = initializeNode(key, value);

            while (x != NULL)
            {
                
            }
        }
    };