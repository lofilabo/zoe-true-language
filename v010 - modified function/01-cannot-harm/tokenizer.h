/**
 * Structures and functions for grouping lexemes into tokens.  The tokenizer
 * reads through an array of lexemes (generated by the lexer) and groups them
 * into tokens based on their structure.  In addition, some lexemes with
 * semantic meaning (such as integers, floats, strings, and booleans) will have
 * their values extracted and stored.
 *
 * \file   tokenizer.h
 *
 * \author Justin J. Meza
 *
 * \date   2010-2012
 */

#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lexer.h"
#include "error.h"

#undef DEBUG

/**
 * Represents a token type.  All of the token type names correspond to either
 * the semantic type of token data or the lexemes which make up the particular
 * token.
 *
 * \note Remember to update the keywords array (below) with the token image.
 */
typedef enum {
	TT_INTEGER,     /**< Integer literal. */
	TT_FLOAT,       /**< Decimal literal. */
	TT_STRING,      /**< String literal. */
	TT_IDENTIFIER,  /**< Identifier literal. */
	TT_BOOLEAN,     /**< Boolean literal. */
	TT_IT,          /**< \ref impvar "Implicit variable". */
	TT_ITZLIEKA,    /**< Inherited object declaration. */
	TT_NOOB,        /**< Nil keyword. */
	TT_NUMBR,       /**< Integer keyword. */
	TT_NUMBAR,      /**< Decimal keyword. */
	TT_TROOF,       /**< Boolean keyword. */
	TT_YARN,        /**< String keyword. */
	TT_BUKKIT,      /**< Array. */
	TT_EOF,         /**< End of file. */
	TT_NEWLINE,     /**< Newline. */
	TT_HAI,         /**< Beginning of main block. */
	TT_KTHXBYE,     /**< End of main block. */
	TT_HASA,        /**< Variable declaration. */
	TT_ITZA,        /**< Variable type initialization. */
	TT_ITZ,         /**< Variable value initialization. */
	TT_RNOOB,       /**< Deallocation. */
	TT_R,           /**< Assignment. */
	TT_ANYR,        /**< User-defined function argument separator. */
	TT_AN,          /**< Built-in function argument separator. */
	TT_SUMOF,       /**< Addition. */
	TT_DIFFOF,      /**< Subtraction. */
	TT_PRODUKTOF,   /**< Multiplication. */
	TT_QUOSHUNTOF,  /**< Division. */
	TT_MODOF,       /**< Modulo. */
	TT_BIGGROF,     /**< Greater than. */
	TT_SMALLROF,    /**< Less than. */
	TT_BOTHOF,      /**< Logical AND. */
	TT_EITHEROF,    /**< Logical OR. */
	TT_WONOF,       /**< Logical XOR. */
	TT_NOT,         /**< Logical NOT. */
	TT_MKAY,        /**< Infinite arity argument delimiter. */
	TT_ALLOF,       /**< Infinite arity logical AND. */
	TT_ANYOF,       /**< Infinite arity logical OR. */
	TT_BOTHSAEM,    /**< Equality. */
	TT_DIFFRINT,    /**< Inequality. */
	TT_MAEK,        /**< Cast. */
	TT_A,           /**< Cast target separator. */
	TT_ISNOWA,      /**< In-place cast. */
	TT_VISIBLE,     /**< Print. */
	TT_SMOOSH,      /**< String concatenation. */
	TT_BANG,        /**< Exclamation point (!) */
	TT_GIMMEH,      /**< Input. */
	TT_ORLY,        /**< Conditional. */
	TT_YARLY,       /**< True branch. */
	TT_MEBBE,       /**< Else branch. */
	TT_NOWAI,       /**< False branch. */
	TT_OIC,         /**< Conditional and switch delimiter. */
	TT_WTF,         /**< Switch. */
	TT_OMG,         /**< Case. */
	TT_OMGWTF,      /**< Default case. */
	TT_GTFO,        /**< Break or return without value. */
	TT_IMINYR,      /**< Loop beginning. */
	TT_UPPIN,       /**< Auto increment loop variable. */
	TT_NERFIN,      /**< Auto decrement loop variable. */
	TT_YR,          /**< Function name delimiter. */ 
	TT_TIL,         /**< Do until. */
	TT_WILE,        /**< Do while. */
	TT_IMOUTTAYR,   /**< Loop ending. */
	TT_HOWIZ,       /**< Function definition beginning. */
	TT_IZ,          /**< Function scope delimiter. */
	TT_IFUSAYSO,    /**< Function definition end. */
	TT_FOUNDYR,     /**< Return with value. */
	TT_SRS,         /**< Indirect variable access. */
	TT_APOSTROPHEZ, /**< Array slot access ('Z). */
	TT_OHAIIM,      /**< Alternate array declaration. */
	TT_IMLIEK,      /**< Alternate inherited object declaration. */
	TT_KTHX,        /**< End of alternate array declaration. */
	TT_IDUZ,        /**< System command. */
	TT_CANHAS,      /**< Library import declaration. */
	TT_QUESTION,    /**< End of library import declaration. */

	TT_ENDOFTOKENS  /**< Sentinel end of this enum -- don't move it! */
} TokenType;

static const char *keywords[] = {
	"",            /* TT_INTEGER */
	"",            /* TT_FLOAT */
	"",            /* TT_STRING */
	"",            /* TT_IDENTIFIER */
	"",            /* TT_BOOLEAN */
	"IT",          /* TT_IT */
	"ITZ LIEK A",  /* TT_ITZLIEKA */
	"zoe_nill",        /* TT_NOOB */	/* You Did This! 'NOOB' -> 	'zoe_nill' */
	"zoe_integer",       /* TT_NUMBR */	/* You Did This! 'NUMBR' -> 	'zoe_integer' */
	"zoe_decimal",      /* TT_NUMBAR */	/* You Did This! 'NUMBAR' -> 	'zoe_decimal' */
	"zoe_boolean",       /* TT_TROOF */	/* You Did This! 'TROOF' -> 	'zoe_boolean' */
	"zoe_string",        /* TT_YARN */	/* You Did This! 'YARN' -> 	'zoe_string' */
	"zoe_array",      /* TT_BUKKIT */	/* You Did This! 'BUKKET' -> 	'zoe_array' */
	"",            /* TT_EOF */
	"",            /* TT_NEWLINE */
	"oh look",     /* TT_HAI */	/* You Did This! 'HAI' -> 'oh look' */  /* use 'oh look!' or 'oh look !' */
	"I see",       /* TT_KTHXBYE */	/* You Did This! 'KTHXBYE' -> 'I see'*/ /* use ' I see' or 'I see !' */
	"define",       /* TT_HASA */	/* You Did This! 'HAS A' -> 'define' */
	"=oftype==>",       /* TT_ITZA */	/* You Did This! 'ITZ A' -> '=oftype==>'       */
	"=",           /* TT_ITZ */	/* You Did This! 'ITZ' -> '='       */
	"R NOOB",      /* TT_RNOOB */
	"<===",     /* TT_R */	/* You Did This! 'R' -> '<==='       */	
	"zoe_and_this",       /* TT_ANYR */		/* You Did This! 'AN YR' -> 'zoe_and_this' */	
	"zoe_do_maths_with",     /* TT_AN */	/* You Did This! 'AN' -> 'zoe_do_maths_with' */	
	"zoe_+",      /* TT_SUMOF */	/* You Did This! 'SUM OF' -> 'zoe_+' */
	"zoe_-",     /* TT_DIFFOF */			/*  You Did This! 'DIFF OF' -> 'zoe_-' */
	"zoe_*",  /* TT_PRODUKTOF */		/*  You Did This! 'PRODUKT OF' -> 'zoe_*' */
	"zoe_/", /* TT_QUOSHUNTOF */		/*  You Did This! 'QUOSHUNT OF' -> 'zoe_/' */
	"zoe_%",      /* TT_MODOF */			/* You Did This! 'MOD OF' -> 'zoe_%' */
	"zoe_>>>",    /* TT_BIGGROF */			/* You Did This! 'BIGGR OF' -> 'zoe_>>>' */
	"zoe_<<<",   /* TT_SMALLROF */		/* You Did This! 'SMALLR OF' -> 'zoe_<<<' */
	"zoe_both",     /* TT_BOTHOF */			/* You Did This! 'BOTH OF' -> 'zoe_both' */
	"zoe_either",   /* TT_EITHEROF */		/* You Did This! 'EITHER OF' -> 'zoe_either' */
	"WON OF",      /* TT_WONOF */
	"NOT",         /* TT_NOT */
	"zoe_call_now",        /* TT_MKAY */			/* You Did This! 'MKAY' -> 'zoe_call_now' */
	"ALL OF",      /* TT_ALLOF */
	"ANY OF",      /* TT_ANYOF */
	"zoe_same",   /* TT_BOTHSAEM */	 		/* You Did This! 'BOTH SAEM' -> 'zoe_same'       */
	"zoe_different",    /* TT_DIFFRINT */ 		/* You Did This! 'DIFFRINT'  -> 'zoe_different'  */
	"MAEK",        /* TT_MAEK */
	"A",           /* TT_A */
	"IS NOW A",    /* TT_ISNOWA */
	"scribble",       /* TT_VISIBLE */   /* You Did This! 'VISIBLE' -> 'scribble' */
	"SMOOSH",      /* TT_SMOOSH */	     
	"!",           /* TT_BANG */
	"GIMMEH",      /* TT_GIMMEH */
	"zoe_match",       /* TT_ORLY */		 /* You Did This! 'O RLY' -> 'zoe_match' */
	"zoe_pass",      /* TT_YARLY */		 /* You Did This! 'YA RLY' -> 'zoe_pass' */
	"zoe_else",       /* TT_MEBBE */		 /* You Did This! 'MEBBE' -> 'zoe_else' */
	"zoe_fail",      /* TT_NOWAI */			 /* You Did This! 'NO WAI' -> 'zoe_fail' */
	"zoe_oh_I_see",         /* TT_OIC */			 /* You Did This! 'OIC' -> 'zoe_oh_I_see' */
	"WTF",         /* TT_WTF */
	"OMG",         /* TT_OMG */
	"OMGWTF",      /* TT_OMGWTF */
	"GTFO",        /* TT_GTFO */
	"zoe_loop_begin",    /* TT_IMINYR */	/* You Did This! 'IM IN YR' -> 'zoe_inside_loop' */
	"zoe_inthis",       /* TT_UPPIN */		/* You Did This! 'UPPIN' -> 'zoe_inthis' */
	"NERFIN",      /* TT_NERFIN */
	"zoe_pass_your",	/* TT_YR */			/* You Did This! 'YR' -> 'zoe_pass_your' */
	"zoe_until",         /* TT_TIL */			/* You Did This! 'TIL' -> 'zoe_until' */
	"WILE",        /* TT_WILE */
	"zoe_loop_end", /* TT_IMOUTTAYR */		/* You Did This! 'IM OUTTA YR' -> 'zoe_loop_end' */
	"function",      /* TT_HOWIZ */		 /* You Did This! 'HOW IZ' -> 'function' */
	"wish_to_call",          /* TT_IZ */			 /* You Did This! 'IZ' -> 'wish_to_call' */
	"end_of_function", /* TT_IFUSAYSO */		 /* You Did This! 'IF U SAY SO' -> 'end_of_function' */
	"zoe_return_from_function",    /* TT_FOUNDYR */	/* You Did This! 'FOUND YR' -> 'zoe_return_from_function' */	
	"SRS",         /* TT_SRS */
	"'Z",          /* TT_APOSTROPHEZ */
	"O HAI IM",    /* TT_OHAIIM */
	"IM LIEK",     /* TT_IMLIEK */
	"KTHX",        /* TT_KTHX */
	"I DUZ",       /* TT_IDUZ */
	"CAN HAS",     /* TT_CANHAS */
	"?",           /* TT_QUESTION */
	""             /* TT_ENDOFTOKENS */
};

/**
 * Stores token data with semantic meaning.
 */
typedef union {
	long long i;   /**< Integer data. */
	float f; /**< Decimal data. */
} TokenData;

/**
 * Stores a token type and any parsed values.
 */
typedef struct {
	TokenType type;    /**< The type of token. */
	TokenData data;    /**< The stored data of type \a type. */
	char *image;       /**< The characters that comprise the token. */
	const char *fname; /**< The name of the file containing the token. */
	unsigned int line; /**< The line number the token was on. */
} Token;

/**
 * \name Utilities
 *
 * Functions for performing helper tasks.
 */
/**@{*/
int isInteger(const char *);
int isFloat(const char *);
int isString(const char *);
int isIdentifier(const char *);
Token *isKeyword(LexemeList *, unsigned int *);
/**@}*/

/**
 * \name Token modifiers
 *
 * Functions for creating and deleting tokens.
 */
/**@{*/
Token *createToken(TokenType, const char *, const char *, unsigned int);
void deleteToken(Token *);
int addToken(Token ***, unsigned int *, Token*);
void deleteTokens(Token **);
unsigned int acceptLexemes(LexemeList *, unsigned int, const char *);
/**@}*/

/**
 * \name Lexeme tokenizer
 *
 * Generates tokens from lexemes.
 */
/**@{*/
Token **tokenizeLexemes(LexemeList *);
/**@}*/

#endif /* __TOKENIZER_H__ */
