# include "map.hpp"
# include "container.hpp"

template <typename key_type, typename value_type>
struct Node
{
    key_type    key;
    value_type   value_type;
    Node        *parent;
    Node        *left;
    Node        *right;
};