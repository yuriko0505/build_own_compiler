#include <assert.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* tokenize.c */
typedef enum {
    TK_PUNCT, // 記号
    TK_NUM,      // 整数トークン
    TK_EOF,      // 入力の終わりを表すトークン
} TokenKind;
typedef struct Token Token;
struct Token {
    TokenKind kind; // トークンの型
    Token *next;    // 次の入力トークン
    int val;        // kindがTK_NUMの場合、その数値
    char *loc;      // トークン文字列
    int len;        // トークン長
};
void error(char *fmt, ...);
void error_at(char *loc, char *fmt, ...);
void error_tok(Token *tok, char *fmt, ...);
bool equal(Token *tok, char *op);
Token *skip(Token *tok, char *op);
Token *tokenize(char *input);

/* parse.c */
typedef enum {
    ND_ADD, // +
    ND_SUB, // -
    ND_MUL, // *
    ND_DIV, // /
    ND_NEG, // unary -
    ND_EQ,  // ==
    ND_NE,  // !=
    ND_LT,  // <
    ND_LE,  // <=
    ND_NUM, // Integer
} NodeKind;
typedef struct Node Node;
struct Node {
    NodeKind kind; // Node kind
    Node *lhs;     // Left-hand side
    Node *rhs;     // Right-hand side
    int val;       // Used if kind == ND_NUM
};
Node *parse(Token *tok);

/* codegen.c */
void codegen(Node *node);
