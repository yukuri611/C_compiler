#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

//
//main.c
//



extern char *user_input;


//
// tokenize.c
//

// トークンの種類
typedef enum {
    TK_RESERVED, // 記号
    TK_IDENT,    // 識別子
    TK_NUM, // 整数トークン 
    TK_EOF,      // 入力の終わりを表すトークン
    TK_RETURN, // return
} TokenKind;

typedef struct Token Token;

struct Token {
    TokenKind kind;
    Token *next;
    int val; 
    char *str;
    int len;
};

void error(char *fmt, ...);
void error_at(char *loc, char *fmt, ...);
bool at_eof();
Token *new_token(TokenKind kind, Token *cur, char *str, int len);
void tokenize();
bool startswith(char *p, char *q);
int is_alnum(char c);


extern Token *token;

//
// parse.c
//

typedef enum {
    ND_ADD, // +
    ND_SUB, // -
    ND_MUL, // *
    ND_DIV, // /
    ND_ASSIGN, // = 
    ND_LVAR, // ローカル変数
    ND_EQ,  // ==
    ND_NE,  // !=
    ND_LT,  // <
    ND_LE,  // <=
    ND_NUM, // 整数
    ND_RETURN, // return
} NodeKind;

typedef struct Node Node;

struct Node {
    NodeKind kind;
    Node *lhs;
    Node *rhs;
    int val;
    int offset;
};

Node *expr();

extern Node *code[100];

void program();

typedef struct LVar LVar;

struct LVar {
    LVar *next;
    char *name;
    int len;
    int offset;
};

extern LVar *locals;

LVar *find_lvar(Token *tok);


//
// codegen.c
// 

void codegen();