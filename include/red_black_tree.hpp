#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

//# include "map.hpp"
# include <iostream>
# include <iomanip>
# include <list>
//# include <iterator.hpp>


# define BLACK 0
# define RED 1

namespace ft{
    template <typename key_type, typename value_type>
    struct Node
    {
        
        key_type    key;
        value_type   value;
        Node        *parent;
        Node        *left;
        Node        *right;
        int         colour;
     
        Node(key_type key, value_type value, Node *null_node)
        {
            this->key = key;
            this->value = value;
            this->parent = NULL;
            this->left = null_node;
            this->right = null_node;
            this->colour = RED;
        }
        Node(void)
        {
            this->key = 0;
            this->value = 0;
            this->parent = NULL;
            this->left = NULL;
            this->right = NULL;
            this->colour = BLACK;
        }

    };


    template <typename key_type, typename value_type>
        class rb_tree
        {
            typedef Node<key_type, value_type> NodePtr;

            private:
            NodePtr *root;
            NodePtr *null_node;
            public:

            rb_tree()
            {
                null_node = new Node<key_type, value_type>;
                null_node->colour = 0;
                null_node->left = NULL;
                null_node->right = NULL;
                root = null_node;
            }
        void    left_rotate(NodePtr *x)
            {
                NodePtr *pt_right = x->right;
                x->right = pt_right->left;

                if (pt_right->left != null_node)
                    pt_right->left->parent = x;
                pt_right->parent = x->parent;
                if (x->parent == null_node)
                    this->root = pt_right;
                else if (x->parent->left == x)
                    x->parent->left = pt_right;
                else
                    x->parent->right = pt_right;
                pt_right->left = x;
                x->parent = pt_right;
            }

            void    right_rotate(NodePtr *x)
            {
                NodePtr *pt_left = x->left;
                x->left = pt_left->right;

                if (pt_left->right != null_node)
                    pt_left->right->parent = x;
                pt_left->parent = x->parent;
                if (x->parent == null_node)
                   root = pt_left;
                else if (x->parent->right == x)
                    x->parent->right = pt_left;
                else
                    x->parent->left = pt_left;
                pt_left->right = x;
                x->parent = pt_left;
            }

            void    insert(key_type key, value_type value)
            {
                NodePtr *y = null_node;
                NodePtr *x = this->root;
                NodePtr *new_node = new Node<key_type, value_type>(key, value, null_node);

                while (x != null_node)   //Traverse the tree until you reach a null_node pointer
                {
                    y = x;              //Saving the x parent into y for when we exit the loop when x = null_node
                    if (key > x->key)
                        x = x->right;
                    else
                        x = x->left;
                }
                new_node->parent = y;   // y is the parent of the last NIL leaf we found be traversing tree
                if (y == null_node) // parent of root is null_node so set y to Black and declare as root
                {
                this->root = new_node;
                new_node->colour = BLACK;
                return ;
                }
                else if (key < y->key)      // if we're not at root, need to assign the new node to either left or right of y
                    y->left = new_node;
                else
                    y->right = new_node;
                if (new_node->parent->parent == null_node) // if the parent is root, pretty straight forward insertion and no rearranging/ recoloring to be done
                    return ;
                insertFix(new_node); //let's check if what we inserted follows the RB tree rules
            }

            void insertFix(NodePtr *new_node)
            {
                NodePtr *uncle;
                
                while (new_node->parent->colour == RED) // if my parent is red it means double red and we have to fix things
                {
                    if (new_node->parent == new_node->parent->parent->left)
                    {
                        uncle = new_node->parent->parent->right;
                        if (uncle != null_node && uncle->colour == RED) //if uncle is red and parent is red
                        {
                            uncle->colour = BLACK;
                            new_node->parent->colour = BLACK;
                            new_node->parent->parent->colour = RED;
                            new_node = new_node->parent->parent; //move up the tree to verify that the change we made here doesn't incur double red on the next level
                        }
                        else 
                        {
                            if (new_node == new_node->parent->right)
                            {
                                new_node = new_node->parent;
                                left_rotate(new_node);
                            }
                            new_node->parent->colour = BLACK;
                            new_node->parent->parent->colour = RED;
                            right_rotate(new_node->parent->parent);
                        }     
                    }
                    else
                    {
                        uncle = new_node->parent->parent->left;
                        if (uncle != null_node && uncle->colour == RED)
                        {
                            uncle->colour = BLACK;
                            new_node->parent->colour = BLACK;
                            new_node->parent->parent->colour = RED;
                            new_node = new_node->parent->parent; //move up the tree to verify that the change we made here doesn't incur double red on the next level

                        }
                        else 
                        {
                            if (new_node == new_node->parent->left)
                            { 
                                new_node = new_node->parent;
                                right_rotate(new_node);
                            }
                            new_node->parent->colour = BLACK;
                            new_node->parent->parent->colour = RED;
                            left_rotate(new_node->parent->parent);
                               
                        }
                    } 
                    if (new_node == root)
                        break ;
                }
                root->colour = BLACK;

            }

            void    real_print(NodePtr *ptr, int space)
            {
                if (!ptr || ptr == null_node )
                    return;
                //space += 4;
                if (ptr->right == null_node && ptr->left == null_node)
                {
                    std::cout
                    << (ptr->colour == BLACK ? "\033[90m" : "\033[31m") << std::setw(space)
                    << ptr->value << "\033[0m" << std::endl;
                    return ;
                }
                if (ptr->left != null_node)
                    real_print(ptr->left, space - 4);
                if (ptr->right != null_node)
                    real_print(ptr->right, space + 4);

                

                // getwchar();
            }

            void    print()
            {
               //int levels = count_levels() * 2;

                // std::cout
                //     << (root->colour == BLACK ? "\033[90m" : "\033[31m") << std::setw(levels)
                //     << root->value << "\033[0m" << std::endl;
               //real_print(root, levels);
               prt(root);
            //    std::cout << "LEVELS  " << levels << std::endl;
            //    int space  = (levels * 4);
            //    NodePtr ptr = root;
            //   std::cout << (ptr->colour == BLACK ? "\033[90m" : "\033[31m");
            //   std::cout << std::setw(space) << ptr->value << "\033[0m" << std::endl;
            //   print_left(ptr->left, space - 1, levels);
            //   print_right(ptr->right, space , levels);

            }

            void print_left(NodePtr *ptr, int space, int levels)
            {
                if (!ptr || ptr == null_node)
                    return;
                NodePtr *tmp;
                int         i = 0;
                

                tmp = ptr;
                while (i < levels)
                {
                    space -= 2;
                    std::cout << (ptr->colour == BLACK ? "\033[90m" : "\033[31m");
                    std::cout << std::setw(space) << ptr->value << "\033[0m" << std::endl;
                    i++;
                }
            }

            int count_levels()
            {
                NodePtr *ptr = root;
                int i = 0;
                int j = 0;
                int res = 0;
                //NodePtr *tmp = NULL;
                
                while (ptr != null_node)
                {
                    //tmp = ptr;
                    i++;
                    ptr = ptr->right;
                }
                ptr = root;
                while (ptr != null_node)
                {
                    //tmp = ptr;
                    j++;
                    ptr = ptr->left;
                }
                if (i > j)
                    res = i;
                else
                    res = j;
                return (res);
            }
     

                int max_depth(NodePtr* n)
                {
                if (!n) return 0;
                return 1 + std::max(max_depth(n->left), max_depth(n->right));
                }

                void prt(NodePtr* n)
                {
                    struct node_depth
                    {
                        NodePtr* n;
                        int lvl;
                        node_depth(NodePtr* n_, int lvl_) : n(n_), lvl(lvl_) {}
                    };

                    int depth = max_depth(n);

                    char buf[1024];
                    int last_lvl = 0;
                    int offset = (1 << depth) - 1;

                    // using a queue means we perform a breadth first iteration through the tree
                    std::list<node_depth> q;

                    q.push_back(node_depth(n, last_lvl));
                    while (q.size())
                    {
                        const node_depth& nd = *q.begin();

                        // moving to a new level in the tree, output a new line and calculate new offset
                        if (last_lvl != nd.lvl)
                        {
                        std::cout << "\n";

                        last_lvl = nd.lvl;
                        offset = (1 << (depth - nd.lvl)) - 1;
                        }

                        // output <offset><data><offset>
                        if (nd.n)
                        {
                            std::cout << (nd.n->colour == BLACK ? "\033[90m" : "\033[31m");
                        sprintf(buf, " %*s%d%*s", offset, " ", nd.n->key, offset, " ");
                        }
                        
                        else
                        sprintf(buf, " %*s", offset << 1, " ");
                        std::cout << buf;

                        if (nd.n)
                        {
                        q.push_back(node_depth(nd.n->left, last_lvl + 1));
                        q.push_back(node_depth(nd.n->right, last_lvl + 1));
                        }

                        q.pop_front();
                    }
                    std::cout << "\n";
                }

            };
}





#endif