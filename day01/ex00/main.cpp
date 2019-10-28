#include <vector>
#include <iostream>
#include "Pony.hpp"

static void	ponyOnTheHeap()
{
	Pony* heap_pony = new Pony("Heap Pony");
	heap_pony->set_age(10);
	heap_pony->set_height(20);
	heap_pony->set_jump_height(2);
	heap_pony->set_speed(30);
	heap_pony->set_weight(100);
	std::cout
		<< "Name: " << heap_pony->get_name() << std::endl
		<< "Age: " << heap_pony->get_age() << std::endl
		<< "Height: " << heap_pony->get_height() << std::endl
		<< "Jump Height: " << heap_pony->get_jump_height() << std::endl
		<< "Speed: " << heap_pony->get_speed() << std::endl
		<< "Weight: " << heap_pony->get_weight() << std::endl;
	delete heap_pony;
}

static void ponyOnTheStack()
{
	Pony stack_pony("Stack Pony");
	stack_pony.set_age(5);
	stack_pony.set_height(10);
	stack_pony.set_jump_height(3);
	stack_pony.set_speed(50);
	stack_pony.set_weight(70);
	std::cout
		<< "Name: " << stack_pony.get_name() << std::endl
		<< "Age: " << stack_pony.get_age() << std::endl
		<< "Height: " << stack_pony.get_height() << std::endl
		<< "Jump Height: " << stack_pony.get_jump_height() << std::endl
		<< "Speed: " << stack_pony.get_speed() << std::endl
		<< "Weight: " << stack_pony.get_weight() << std::endl;
}

int main()
{
	std::cout << "___Pony on the heap___" << std::endl;
	ponyOnTheHeap();
	std::cout << std::endl;
	std::cout << "___Pony on the stack___" << std::endl;
	ponyOnTheStack();
	return (0);
}