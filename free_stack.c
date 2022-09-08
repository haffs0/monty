#include "monty.h"
/**
 * free_stack - free double linked lists
 * @head: a pointer to the head
 * Return: nothing
 */
void free_stack(stack_t *head)
{
	stack_t *current;

	if (head == NULL)
		return;

	current = head;

	while (current != NULL)
	{
		head = current;
		current = current->next;
		free(head);
	}
}
