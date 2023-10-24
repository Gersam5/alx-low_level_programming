#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct dlistint_s
{
    int n;
    struct dlistint_s *next;
    struct dlistint_s *prev;
} dlistint_t;

void add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new;

    new = malloc(sizeof(dlistint_t));
    if (new == NULL)
    {
        printf("Error\n");
        return;
    }
    new->n = n;
    new->next = NULL;
    new->prev = *head;
    if (*head != NULL)
        (*head)->next = new;
    *head = new;
}

int sum_dlistint(dlistint_t *head)
{
    int sum = 0;

    while (head != NULL)
    {
        sum += head->n;
        head = head->next;
    }
    return (sum);
}

int main(void)
{
    dlistint_t *head;
    size_t n;

    head = NULL;
    add_dnodeint_end(&head, 8);
    add_dnodeint_end(&head, 9);
    n = sum_dlistint(head);
    printf("-> %lu elements\n", n);
    return (0);
}
