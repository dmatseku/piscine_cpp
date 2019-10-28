#include	"List.hpp"
#include	<iostream>

List::List()
{
	_root = 0;
	_size = 0;
}

List::~List()
{
	node const  *ptr;

	while (_root)
	{
		delete _root->cont;
		ptr = _root;
		_root = _root->next;
		delete ptr;
	}
}

List::List(List const & l)
{
	*this = l;
}

List&			List::operator=(List const& l)
{
	if (this != &l)
	{
		this->_root = l._root;
		this->_size = l._size;
	}
	return *this;
}

void*			List::operator[](int i)
{
	if (i >= this->_size) {
		return 0;
	}

	node	* ptr = this->_root;
	
	while (i != 0){
		ptr = ptr->next;
		--i;
	}
	return ptr->cont;
}



void			List::push(Object *const cont)
{
	node	*ptr = new node();

	this->_size++;
	ptr->cont = cont;
	ptr->next = this->_root;
	ptr->prev = 0;

	if (ptr->next)
	{
		ptr->next->prev = ptr;
	}

	this->_root = ptr;
}

void			List::erase(int i)
{
	node	*del = this->_root;

	while (i--)
		del = del->next;
    del->cont->f = 0;
	if (_size == 0)
		_root = 0;
}

int				List::size()
{
	return _size;
}

void            List::check_out_screen(const int x)
{
    node const *    node = this->_root;
    while (node)
    {
        Point const&  point = node->cont->getPosition();
        if (point.getX() < 0 || point.getX() > x || !node->cont->f)
        {
            node = delete_node(node);
            this->_size--;
            continue;
        }
        node = node->next;
    }
}
List::node*     List::delete_node(node const * del_node)
{
    if (del_node->prev)
    {
		del_node->prev->next = del_node->next;
	}

    if (del_node->next)
    {
		del_node->next->prev = del_node->prev;
	}

    node const * const tmp = del_node;
    node* const res = del_node->next;

    if (this->_root == tmp)
    {
		this->_root = res;
	}

    delete tmp->cont;
    delete tmp;
    
	return res;
}


List::node*		List::begin()
{
	return this->_root;
}

List::node*		List::end()
{
	node* tmp = this->_root;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return tmp;
}
