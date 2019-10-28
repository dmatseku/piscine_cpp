#pragma once

#include	"Object.hpp"
#include <fstream>

class	List
{
public:
	struct	node
	{
		Object* cont;
		node*   prev;
		node*   next;
	};

private:
	node*	_root;
	int		_size;

public:
	~List();
	List();
	List(List const & copy);

	List &		    operator=(List const & l);
	void *		    operator[](int i);

	void		    push(Object	*content);
	void		    erase(int index);
	void            check_out_screen(int x);
	int			    size();
	node*           delete_node(node const * del_node);
	node*			begin();
	node*			end();
};
