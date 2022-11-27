#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

//# include "map.hpp"
# include <iostream>
# include <iomanip>
# include <list>
# include "container.hpp"
//# include "iterator.hpp"


# define BLACK 0
# define RED 1

namespace ft{
    template <typename value_type>
    struct Node
    {
        
        //key_type    key;
        value_type   value;
        Node        *parent;
        Node        *left;
        Node        *right;
        int         colour;

   

    };


    template <typename value_type, typename key_type, typename Compare = ft::less<value_type>, class Allocator = std::allocator<Node<value_type> > >
        class rb_tree
        {
            public:
            typedef Node<value_type> NodePtr;
            typedef rb_tree<value_type, key_type, Compare, Allocator>     Self ;    

            private:
            Allocator   _alloc;
            Compare     _comp;
            NodePtr *root;
            NodePtr *null_node;
            size_t    _size;
            public:

            rb_tree() 
            {
                std::allocator<value_type> val_alloc;
                value_type  val;
    
                null_node = _alloc.allocate(1);
                root = null_node;
                val_alloc.construct(&null_node->value, val);
                null_node->left = NULL;
                null_node->right = NULL ;
                null_node->colour = BLACK ;
                _size = 0;
            }
            rb_tree(const Compare comp, const Allocator alloc) : _alloc(alloc), _comp(comp), _size(0)
            {
                std::allocator<value_type> val_alloc;

                value_type  val;

                null_node = _alloc.allocate(1);
                root = null_node;
                val_alloc.construct(&null_node->value, val);
                null_node->left = NULL;
                null_node->right = NULL ;
                null_node->colour = BLACK ;
            }
            rb_tree(const  Self &rhs) : _alloc(rhs._alloc), _comp(rhs._comp), _size(0)
            {
               null_node = _alloc.allocate(1);
               root = null_node;
               NodePtr *nd = rhs.tree_min();

               while (nd != rhs.get_null_node())
               {
                    insert(nd->value);
                    nd = rhs.next(nd);
               }

            }
            ~rb_tree()
            {
               
                clear(root);
                
                std::allocator<value_type> val_alloc;
                val_alloc.destroy(&null_node->value);
                _alloc.destroy(null_node);
                _alloc.deallocate(null_node, 1);
            }

            NodePtr *next(NodePtr *node) const
        {
            NodePtr *current = node;
            if (current == null_node)
                return null_node;
            if (current == tree_max())
            {
                return null_node;
            }
            if (current->right != null_node)
            {
                current = current->right;
                while (current && current->left != null_node)
                    current = current->left;
            }
            else
            {
          
                NodePtr   *parent = current->parent;
               while (current == parent->right)
               {
                    current = parent;
                    parent = parent->parent;
               }
               if (current->right != parent)
                current = parent;
            }
            return current ;
        }
            Self    &operator=(const Self &rhs)
            {
                null_node = _alloc.allocate(1);
                root = null_node;
                _size = 0;
                NodePtr *nd = rhs.tree_min();

                while (nd != rhs.get_null_node())
                {
                    insert(nd->value);
                    nd = rhs.next(nd);
                }

                return *this;

            }
        void    left_rotate(NodePtr *x)
            {
                NodePtr *pt_right = x->right;
                x->right = pt_right->left;

                if (pt_right->left != null_node)
                    pt_right->left->parent = x;
                pt_right->parent = x->parent;
                if (x->parent == NULL)
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
                if (x->parent == NULL)
                   root = pt_left;
                else if (x->parent->right == x)
                    x->parent->right = pt_left;
                else
                    x->parent->left = pt_left;
                pt_left->right = x;
                x->parent = pt_left;
            }

            void init_null_node(NodePtr  *node, const value_type &value)
            {
                std::allocator<value_type>  val_alloc;
                node->left = null_node;
                node->right = null_node;
                node->parent = NULL;
                node->colour = RED;
                val_alloc.construct(&node->value, value);
            }
       
            bool    insert(const value_type &value)
            {
                NodePtr *y = NULL;
                NodePtr *x = this->root;
                NodePtr *new_node = _alloc.allocate(1);
                std::allocator<value_type>  val_alloc;
                init_null_node(new_node, value);


                while (x && x != null_node)   //Traverse the tree until you reach a null_node pointer
                {
                    y = x;              //Saving the x parent into y for when we exit the loop when x = null_node
                    
                    if (!(_comp(value, x->value) || _comp(x->value, value)))
                    {
                        val_alloc.destroy(&new_node->value);
                        _alloc.deallocate(new_node, 1);
                        return 0 ;
                    }
                    if (!_comp(value, x->value))
                        x = x->right;
                    else if (_comp(value, x->value))
                        x = x->left;
                    
                }
                new_node->parent = y;   // y is the parent of the last NIL leaf we found be traversing tree
                if (y == NULL) // parent of root is null_node so set y to Black and declare as root
                {
                    this->root = new_node;
                    new_node->colour = BLACK;
                    _size++;
                    return 1;
                }
                else if (_comp(value, y->value))      // if we're not at root, need to assign the new node to either left or right of y
                    y->left = new_node;
                else
                    y->right = new_node;
                if (new_node->parent == null_node)
                {
                    new_node->colour =BLACK;
                    return 1;
                }
                if (new_node->parent->parent == null_node) // if the parent is root, pretty straight forward insertion and no rearranging/ recoloring to be done
                {
                    _size++;
                    return 1;
                }
                _size++;
                return insertFix(new_node); //let's check if what we inserted follows the RB tree rules
            }



            bool insertFix(NodePtr *new_node)
            {
                NodePtr *uncle;
                
                while (new_node->parent->colour == RED) // if my parent is red it means double red and we have to fix things
                {
                    if (new_node->parent == new_node->parent->parent->left)
                    {
                        uncle = new_node->parent->parent->right;
                        if (uncle->colour == RED) //if uncle is red and parent is red
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
                        if (uncle->colour == RED)
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
                return 1;

            }

            void    rb_transplant_node(NodePtr  *original, NodePtr *replace)
            {
                if (original->parent == NULL)
                {
                    root = replace;
                }
                else if (original == original->parent->left)
                {
                    original->parent->left = replace;
                }
                else
                {
                    original->parent->right = replace;
                }
                replace->parent = original->parent;
                
            }

            void    delete_node(value_type key)
            {
                NodePtr *del_node = find_node(root, key);
                std::allocator<value_type> val_alloc;
                NodePtr *x, *y ;
                bool og_colour ;
                
                if (del_node == NULL || del_node == null_node)
                    return  ;
                og_colour = del_node->colour;
                y = del_node;
                 if (!del_node->left || del_node->left == null_node)
                {
                    x = del_node->right;
                    rb_transplant_node(del_node, del_node->right);
                }
                else if (!del_node->right || del_node->right == null_node)
                {
                    x = del_node->left;
                    rb_transplant_node(del_node, del_node->left);
                }
                else
                {
                    y = min(del_node->right);
                    og_colour = y->colour;
                    x = y->right;
                    if (y->parent == del_node)
                        x->parent = y;
                    else
                    {
                        rb_transplant_node(y, y->right);
                        y->right = del_node->right;
                        y->right->parent = y;

                    }
                    rb_transplant_node(del_node, y);
                    y->left =del_node->left;
                    y->left->parent = y;
                    y->colour = del_node->colour;
                }
                val_alloc.destroy(&del_node->value);
               _alloc.deallocate(del_node, 1);
               _size--;
                if (og_colour == BLACK)
                    delete_fix(x);
                
            }

            void    delete_fix(NodePtr *x)
            {
                NodePtr *sibling;

           
                while (x != root && x->colour == BLACK)
                {
                    // CASE 1 : X is the left child of parent
                    if (x == x->parent->left)
                    {
                        //assign sibling as right of parent
                        sibling = x->parent->right;
                        //if the sib is red switch colours with the parent
                        if (sibling->colour == RED)
                        {
                            sibling->colour = BLACK;
                            x->parent->colour = RED;
                            // left rotate and then assign sibling as right child of xs parent to be sure
                            left_rotate(x->parent);
                            sibling = x->parent->right ;
                        }
                        //CASE II : BOTH CHILDREN OF SIBLING ARE BLACK
                        if ( sibling->left->colour == BLACK && sibling->right->colour == BLACK)
                        {
                            sibling->colour = RED;
                             x = x->parent;
                        } 
                        else  //CASE III :  RIGHT CHILD IS BLACK
                        {
                            if(sibling->right->colour == BLACK)
                            {
                                sibling->left->colour = BLACK;
                                sibling->colour = RED;
                                right_rotate(sibling);
                                sibling = sibling->parent->right;
                            }
                            sibling->colour = x->parent->colour;  //CASE IV LEFT CHILD
                            x->parent->colour = BLACK;
                            sibling->right->colour = BLACK;
                            left_rotate(x->parent);
                            x = root;
                        }                   
                        
                    }
                    else // SAME PROCESS BUT IF THE DELETED IS ON THE  RGIHT
                    {
                        sibling = x->parent->left;
                        // CASE I
                        if (sibling && sibling->colour == RED)
                        {
                            sibling->colour = BLACK;
                            x->parent->colour = RED;
                            right_rotate(x->parent);
                            sibling = x->parent->left;
                        }
                        //  CASE II
                        if (sibling && sibling->right->colour == BLACK && sibling->right->colour == BLACK)
                        {
                            sibling->colour = RED;
                            x = x->parent;
                        }
                        // CASE III
                        else 
                        {
                            if (sibling && sibling->left->colour == BLACK)
                            {
                                sibling->right->colour = BLACK;
                                sibling->colour = RED;
                                left_rotate(sibling);
                                sibling = x->parent->left;
                            }
                            sibling->colour = x->parent->colour;
                            x->parent->colour = BLACK;
                            sibling->left->colour = BLACK;
                            right_rotate(x->parent);
                            x = root;
                        }

                    }
                }
                x->colour = BLACK;
            }

            NodePtr *min(NodePtr    *node)
            {
                if (node == null_node)
                    return null_node;
                while (node->left != null_node)
                    node = node->left;
                return node;
            }

            NodePtr *tree_min()const
            {
                NodePtr    *node = root;
                if (node == null_node)
                    return null_node;
                while (node->left != null_node)
                    node = node->left;
                return node;
            }

            NodePtr *max(NodePtr    *node) const
            {
                if (node == null_node)
                    return null_node;
                while (node->right != null_node)
                    node = node->right;
                return node;
            }

            NodePtr *tree_max() const
            {
                NodePtr    *node = root;
                if (!node || node == null_node)
                    return null_node;
                while (node->right != null_node)
                    node = node->right;
                return node;
            }
            void clear(NodePtr  *node)
            {
                 std::allocator<value_type> val_alloc;
                _size = 0;
                if (!node || node == null_node)
                    return ;
                if (node->left && node->left != null_node)
                    clear(node->left);
                if (node->right && node->right != null_node)
                    clear(node->right);
                if (node || node != null_node)
                {
                    val_alloc.destroy(&node->value);
                    _alloc.destroy(node);
                    _alloc.deallocate(node,1);

                }
            }
            void    tree_clear()
            {
                clear(root);
                root = null_node;
            }
            void    tree_swap(Self& swp)
            {
                NodePtr *save_null, *save_root;
                size_t save_size;

                save_null = swp.null_node;
                save_root = swp.root;
                save_size = swp._size;

                this->null_node = save_null;
                this->root = save_root;
                this->_size = save_size;
            }
            NodePtr *increment_tree(NodePtr *current)
            {
                if (current->right != null_node)
                {
                    current = current->right;
                    while (current->left != null_node)
                        current = current->left;
                }
                else
                {
                    NodePtr *y = current->parent;
                    while (current  && current == y->right)
                    {
                        current = y->parent;
                        y = y->parent;
                    }
                }
            }

            NodePtr *get_null_node() const
            {
                return null_node ;
            }

            bool is_empty() const
            {
                return (_size == 0);
            }

            size_t size() const 
            {
                return _size;
            }
            size_t  tree_size(const NodePtr   *root) const
            {
                if (!root)
                    return 0 ;
                return (1 + tree_size(root->left) + tree_size(root->right));
            }

            NodePtr *find_node(NodePtr *node, value_type value) const
            {
                if (node == null_node || (!(_comp(value, node->value) || _comp(node->value, value))))
                {
                    return node;
                }
                if (_comp(value, node->value))
                {
                    return find_node(node->left, value);
                }
                return find_node(node->right, value);
            } 

            NodePtr *begin() 
            {
                NodePtr *res = root;
                if(_size == 0)
                    return NULL;
                if (res->left == NULL)
                    return res ;
                while (res && res->left != null_node)
                    res = res->left;
                return res;
            }

            NodePtr *end() 
            {
                NodePtr *res= root;

                if (res->right == NULL)
                    return res ;
                while (res && res->right != null_node)
                    res = res->right;
                return res;
            }

            NodePtr *begin() const
            {
                NodePtr *res = root;

                if(_size == 0)
                    return NULL;
                if (res->left == NULL)
                    return res ;
                while (res && res->left != null_node)
                    res = res->left;
                return res;
            }

            const NodePtr *end() const
            {
                NodePtr *res;
                res = root;

                if (res->right == NULL)
                    return res ;
                while (res && res->right != null_node)
                    res = res->right;
                return res;
            }

            void    real_print(NodePtr *ptr, int space)
            {
                if (!ptr || ptr == NULL )
                    return;
                //space += 4;
                if (ptr->right == NULL && ptr->left == NULL)
                {
                    std::cout
                    << (ptr->colour == BLACK ? "\033[90m" : "\033[31m") << std::setw(space)
                    << ptr->value.first << "\033[0m" << std::endl;
                    return ;
                }
                if (ptr->left != NULL)
                    real_print(ptr->left, space - 4);
                if (ptr->right != NULL)
                    real_print(ptr->right, space + 4);

                

                // getwchar();
            }

            // void    print()
            // {
               //int levels = count_levels() * 2;

                // std::cout
                //     << (root->colour == BLACK ? "\033[90m" : "\033[31m") << std::setw(levels)
                //     << root->value << "\033[0m" << std::endl;
               //real_print(root, levels);
               //prt(root);
            //    std::cout << "LEVELS  " << levels << std::endl;
            //    int space  = (levels * 4);
            //    NodePtr ptr = root;
            //   std::cout << (ptr->colour == BLACK ? "\033[90m" : "\033[31m");
            //   std::cout << std::setw(space) << ptr->value << "\033[0m" << std::endl;
            //   print_left(ptr->left, space - 1, levels);
            //   print_right(ptr->right, space , levels);

            //}

            // void print_left(NodePtr *ptr, int space, int levels)
            // {
            //     if (!ptr || ptr == NULL)
            //         return;
            //     NodePtr *tmp;
            //     int         i = 0;
                

            //     tmp = ptr;
            //     while (i < levels)
            //     {
            //         space -= 2;
            //         std::cout << (ptr->colour == BLACK ? "\033[90m" : "\033[31m");
            //         std::cout << std::setw(space) << ptr->value << "\033[0m" << std::endl;
            //         i++;
            //     }
            // }

            // int count_levels()
            // {
            //     NodePtr *ptr = root;
            //     int i = 0;
            //     int j = 0;
            //     int res = 0;
            //     //NodePtr *tmp = NULL;
                
            //     while (ptr != NULL)
            //     {
            //         //tmp = ptr;
            //         i++;
            //         ptr = ptr->right;
            //     }
            //     ptr = root;
            //     while (ptr != NULL)
            //     {
            //         //tmp = ptr;
            //         j++;
            //         ptr = ptr->left;
            //     }
            //     if (i > j)
            //         res = i;
            //     else
            //         res = j;
            //     return (res);
            // }
     

            //     int max_depth(NodePtr* n)
            //     {
            //     if (!n) return 0;
            //     return 1 + std::max(max_depth(n->left), max_depth(n->right));
            //     }

            //     void prt(NodePtr* n)
            //     {
            //         struct node_depth
            //         {
            //             NodePtr* n;
            //             int lvl;
            //             node_depth(NodePtr* n_, int lvl_) : n(n_), lvl(lvl_) {}
            //         };

            //         int depth = max_depth(n);

            //         char buf[1024];
            //         int last_lvl = 0;
            //         int offset = (1 << depth) - 1;

            //         // using a queue means we perform a breadth first iteration through the tree
            //         std::list<node_depth> q;

            //         q.push_back(node_depth(n, last_lvl));
            //         while (q.size())
            //         {
            //             const node_depth& nd = *q.begin();

            //             // moving to a new level in the tree, output a new line and calculate new offset
            //             if (last_lvl != nd.lvl)
            //             {
            //             std::cout << "\n";

            //             last_lvl = nd.lvl;
            //             offset = (1 << (depth - nd.lvl)) - 1;
            //             }

            //             // output <offset><data><offset>
            //             if (nd.n)
            //             {
            //                 std::cout << (nd.n->colour == BLACK ? "\033[90m" : "\033[31m");
            //             sprintf(buf, " %*s%d%*s", offset, " ", nd.n->value.first, offset, " ");
            //             }
                        
            //             else
            //             sprintf(buf, " %*s", offset << 1, " ");
            //             std::cout << buf;

            //             if (nd.n)
            //             {
            //             q.push_back(node_depth(nd.n->left, last_lvl + 1));
            //             q.push_back(node_depth(nd.n->right, last_lvl + 1));
            //             }

            //             q.pop_front();
            //         }
            //         std::cout << "\n";
            //     }

            };
}





#endif