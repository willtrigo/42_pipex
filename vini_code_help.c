 /*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
 /*                                                +#+#+#+#+#+   +#+           */
 /*   Created: 2024/03/15 03:37:45 by dande-je          #+#    #+#             */
 /*                                                                            */
 /* ************************************************************************** */
 
enum	e_default_pipex
 	LEFT_REDIRECT,
 	RIGHT_REDIRECT,
 	EXEC,
	APPEND,
	HEREDOC,
 	CMD_NOT_FOUND = 127,
 	SIGINT_INTERRUPT = 130,
 	RW_R_R = 0644,
struct s_ast
 {
	t_ast	*left;
	t_ast	*right;
	char	*type;
	int		type;
	char	*ast_right;
	char	**exec;
	char	*infile;
	char	*outfile;
	int		infile_open;
	int		outfile_open;
 };
 
 typedef struct s_pipex	t_pipex;
 struct s_pipex
 {
	int		max_ac;
 	char	**env;
	char	*heredoc[2];
 	char	**left_cmd;
 	char	**right_cmd;
 	char	*cmd;

	 struct s_pipex
 	char	*outfile;
 	int		infile_open;
 	int		outfile_open;
	t_ast	*ast;
 };
 
#include <stdio.h>
 #include <stdlib.h>
 #include "ft_non_standard/ft_non_standard.h"
 #include "ft_non_standard/ft_sprintf.h"
 #include "ft_set.h"
 #include "ft_pipex.h"
 #include "ft_parse.h"
#include "ft_string.h"
#include "ft_stdlib.h"

t_ast	*build_tree(int argc, char **argv, int max);

void	verify_arg(int argc, char **argv, t_ast *ast, int max)
{
	argc--;
	if (argc == 0)
	{
		ast->type = LEFT_REDIRECT;
		ast->infile = *argv;
		return ;
	}
	else if (argc == max)
	{
		build_tree(--argc, argv, max);
		ast->type = RIGHT_REDIRECT;
		ast->outfile = argv[argc - 1];
	}
	else
		ast->type = PIPE;
	ast->left = build_tree(argc, argv, max);
	if (!argc)
		return ;
	ast->right = build_tree(argc, argv, max);
}

t_ast	*build_tree(int argc, char **argv, int max)
{
	t_ast	*ast;

	ast = ft_calloc(1, sizeof(t_ast));
	if (!ast)
	{
		printf("deu ruim\n");
		exit (EXIT_FAILURE);
	}
	verify_arg(argc, argv, ast, max);
	return (ast);

}
 
 void	ft_set_pipex_environ(int argc, char **argv, t_pipex *data)
 {
	data->max_ac = argc;
 	data->env = ft_parse_getenv(__environ);
	data->left_cmd = ft_split(argv[LEFT_ARG], ' ');
	data->right_cmd = ft_split(argv[RIGHT_ARG], ' ');
	data->infile = *argv;
	data->outfile = *(argv + --argc);
	//capturar heredoc e tratar erros e etc
	if (!ft_strncmp("here_doc", *argv, ft_strlen("here_doc")))
	{
		data->heredoc[0] = *argv;
		data->heredoc[1] = *(argv + 1);

	}
	else if (argc == 4)
	{
		data->left_cmd = ft_split(argv[LEFT_ARG], ' ');
		data->right_cmd = ft_split(argv[RIGHT_ARG], ' ');
		data->infile = *argv;
		data->outfile = *(argv + --argc);
	}
	else
		data->ast = build_tree(argc, argv, data->max_ac);

 }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enum for AST node types
typedef enum {
    AST_COMMAND,
    AST_WORD,
    AST_PIPE,
    AST_REDIRECT_IN,
    AST_REDIRECT_OUT,
    AST_HERedoc
} ASTNodeType;

// Structure for AST nodes
typedef struct ASTNode {
    ASTNodeType type;
    union {
        char *word;  // For AST_WORD nodes
        struct ASTNode *left;
        struct ASTNode *right; // For binary nodes (AST_COMMAND, AST_PIPE)
        char *filename;  // For redirection nodes (AST_REDIRECT_IN, AST_REDIRECT_OUT)
        struct {
            char *delimiter;
            char *content; // For AST_HERedoc nodes
        } heredoc;
    } data;
    struct ASTNode *next; // For chaining commands (AST_COMMAND)
} ASTNode;

// Function prototypes
ASTNode *ast_create_node(ASTNodeType type);
ASTNode *ast_create_word_node(char *word);
ASTNode *ast_create_command_node(ASTNode *left, ASTNode *right);
ASTNode *ast_create_pipe_node(ASTNode *left, ASTNode *right);
ASTNode *ast_create_redirect_in_node(char *filename);
ASTNode *ast_create_redirect_out_node(char *filename);
ASTNode *ast_create_heredoc_node(char *delimiter, char *content);
void ast_print(ASTNode *node, int indent);
void ast_free(ASTNode *node);

// Function to create a new AST node
ASTNode *ast_create_node(ASTNodeType type) {
    ASTNode *node = malloc(sizeof(ASTNode));
    if (!node) {
        perror("malloc");
        exit(1);
    }
    node->type = type;
    node->next = NULL;
    return node;
}

// Function to create a word node
ASTNode *ast_create_word_node(char *word) {
    ASTNode *node = ast_create_node(AST_WORD);
    node->data.word = strdup(word); // Allocate memory for the word
    if (!node->data.word) {
        perror("strdup");
        exit(1);
    }
    return node;
}

// Function to create a command node (binary tree)
ASTNode *ast_create_command_node(ASTNode *left, ASTNode *right) {
    ASTNode *node = ast_create_node(AST_COMMAND);
    node->data.left = left;
    node->data.right = right;
    return node;
}

// Function to create a pipe node (binary tree)
ASTNode *ast_create_pipe_node(ASTNode *left, ASTNode *right) {
    ASTNode *node = ast_create_node(AST_PIPE);
    node->data.left = left;
    node->data.right = right;
    return node;
}

// Function to create a redirect-in node
ASTNode *ast_create_redirect_in_node(char *filename) {
    ASTNode *node = ast_create_node(AST_REDIRECT_IN);
    node->data.filename = strdup(filename); // Allocate memory for the filename
    if (!node->data.filename) {
        perror("strdup");
        exit(1);
    }
    return node;
}

// Function to create a redirect-out node
ASTNode *ast_create_redirect_out_node(char *filename) {
    ASTNode *node = ast_create_node(AST_REDIRECT_OUT);
    node->data.filename = strdup(filename); // Allocate memory for the filename
    if (!node->data.filename) {
        perror("strdup");
        exit(1);
    }
    return node;
}

ASTNode *ast_create_heredoc_node(char *delimiter, char *content) {
    ASTNode *node = ast_create_node(AST_HERedoc);
    node->data.heredoc.delimiter = strdup(delimiter); // Allocate memory for the delimiter
    if (!node->data.heredoc.delimiter) {
        perror("strdup");
        exit(1);
    }
    node->data.heredoc.content = strdup(content); // Allocate memory for the content
    if (!node->data.heredoc.content) {
        perror("strdup");
        exit(1);
    }
    return node;
}
