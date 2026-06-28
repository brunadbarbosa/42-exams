#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    enum {
        ADD,
        MULTI,
        VAL
    }   type;
    int val;
    struct node *l;
    struct node *r;
}   node;

node    *new_node(node n)
{
    node *ret = calloc(1, sizeof(node));
    if (!ret)
        return (NULL);
    *ret = n;
    return (ret);
}

void    destroy_tree(node *n)
{
    if (!n)
        return ;
    destroy_tree(n->l);
    destroy_tree(n->r);
    free(n);
}

void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n");
}

int accept(char **s, char c)
{
    if (**s == c)
    {
        (*s)++;
        return (1);
    }
    return (0);
}

int expect(char **s, char c)
{
    if (accept(s, c))
        return (1);
    unexpected(**s);
    return (0);
}

node    *parse_expr(char **s);

node	*parse_factor(char **s)
{
	if (accept(s, '('))
	{
		node	*inside = parse_expr(s);
		if (!inside || !expect(s, ')'))
		{
			destroy_tree(inside);
			return NULL;
		}
		return inside;
	}

	if (!isdigit(**s))
	{
		unexpected(**s);
		return NULL;
	}

	int val = 0;
	while (isdigit(**s))
	{
		val = val * 10 + (**s - '0');
		(*s)++;
	}
	return new_node((node){VAL, val, NULL, NULL});
}

node	*parse_term(char **s)
{
	node	*left = parse_factor(s);
	if (!left)
		return NULL;

	while (accept(s, '*'))
	{
		node *right = parse_factor(s);
		if (!right)
		{
			destroy_tree(left);
			return NULL;
		}
		left = new_node((node){MULTI, 0, left, right});
	}

	return left;
}

node    *parse_expr(char **s)
{
    node	*left = parse_term(s);
	if (!left)
		return NULL;
	
	while (accept(s, '+'))
	{
		node	*right = parse_term(s);
		if (!right)
		{
			destroy_tree(left);
			return NULL;
		}
		left = new_node((node){ADD, 0, left, right});
	}
    return (left);
}

int eval_tree(node *tree)
{
	if (!tree)
		return (0);
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
            return (tree->val);
    }
	return (0);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
	char	*s = argv[1];
    node *tree = parse_expr(&s);
    if (!tree)
        return (1);
	if (*s)
    {
        unexpected(*s);
        destroy_tree(tree);
        return 1;
    }
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
}