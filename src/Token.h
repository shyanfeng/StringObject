#ifndef Token_H
#define Token_H

#include "Text.h"
#include "StringObject.h"

typedef enum {
  NULL_TOKEN,
  NUMBER_TOKEN,
  OPERATOR_TOKEN,
  IDENTIFIER_TOKEN
} TokenType;

typedef enum {
  ILLEGAL_OP,
  PLUS_OP,            // + sign (prefix)
  MINUS_OP,           // - sign (prefix)
  ADD_OP,             // +  (infix)
  SUB_OP,             // -  (infix)
  MUL_OP,             // *  (infix)
  DIV_OP,             // /  (infix)
  MOD_OP,             // %  (infix)
  BITWISE_AND_OP,     // &  (infix)  
  BITWISE_OR_OP,      // |  (infix)  
  BITWISE_XOR_OP,     // ^  (infix)  
  BITWISE_NOT_OP,     // ~  (infix)  
  LOGICAL_AND_OP,     // && (infix)  
  LOGICAL_OR_OP,      // || (infix)  
  LOGICAL_NOT_OP,     // !  (prefix)
  OPENING_BRACKET_OP, // (  (prefix)
  CLOSING_BRACKET_OP, // )  (prefix)
} OperatorID;

typedef enum {
  ILLEGAL_AFFIX,
  PREFIX,
  INFIX,
  POSTFIX
} Affix;

typedef enum {
  NO_ASSOCIATIVITY,
  LEFT_TO_RIGHT,
  RIGHT_TO_LEFT
} Associativity;

typedef struct {
  char *symbol;
  OperatorID id;
  int precedence;
  Affix affix;
  Associativity assoc;  
} OperatorInfo;

typedef struct {
  TokenType type;
  int value;
} Token;

typedef struct {
  TokenType type;
  int value;
} Number;

typedef struct {
  TokenType type;
  OperatorInfo *info;
} Operator;

typedef struct {
  TokenType type;
  Text *name;
  Number *number;
} Identifier;

Number *numberNew(int value);
Operator *operatorNewBySymbol(char *symbol);
Operator *operatorNewByID(OperatorID id);
Identifier *identifierNew(Text *name);
Token *getToken(String *str);

#endif // Token_H
