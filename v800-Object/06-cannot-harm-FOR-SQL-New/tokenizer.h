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
	"",            		/* TT_INTEGER */
	"",            		/* TT_FLOAT */
	"",            		/* TT_STRING */
	"",            		/* TT_IDENTIFIER */
	"",            		/* TT_BOOLEAN */
	"IT",          		/* TT_IT */		/* You Did This! 'IT' -> 	''   	---LATEST - > ''   */
	"ITZ LIEK A",  		/* TT_ITZLIEKA */	/* You Did This! 'ITZ LIEK A' ->''   	---LATEST - > ''   */
	"zoe_nill",        	/* TT_NOOB */		/* You Did This! 'NOOB' -> 	'zoe_nill'   	---LATEST - > ''   */
	"zoe_integer",       	/* TT_NUMBR */		/* You Did This! 'NUMBR' -> 	'zoe_integer'  	---LATEST - > ''   */
	"zoe_decimal",      	/* TT_NUMBAR */		/* You Did This! 'NUMBAR' -> 	'zoe_decimal'   ---LATEST - > ''  */
	"zoe_boolean",       	/* TT_TROOF */		/* You Did This! 'TROOF' -> 	'zoe_boolean'   ---LATEST - > ''  */
	"zoe_string",        	/* TT_YARN */		/* You Did This! 'YARN' -> 	'zoe_string'   	---LATEST - > ''  */
	"zoe_array",      	/* TT_BUKKIT */		/* You Did This! 'BUKKET' -> 	'zoe_array'   	---LATEST - > ''  */
	"",            		/* TT_EOF */
	"",            		/* TT_NEWLINE */
	"oh look",     		/* TT_HAI */		/* You Did This! 'HAI' -> 'oh look' */  /* use 'oh look!' or 'oh look !'   ---LATEST - > ''  */
	"I see",       		/* TT_KTHXBYE */	/* You Did This! 'KTHXBYE' -> 'I see'*/ /* use ' I see' or 'I see !'   ---LATEST - > ''  */
	"define",       	/* TT_HASA */		/* You Did This! 'HAS A' -> 'define'   		---LATEST - > ''  */
	"-of->",       		/* TT_ITZA */		/* You Did This! 'ITZ A' -> '=oftype==>'   	---LATEST - > '-typ->' 	NEW!! DONE!!      */
	"=",           		/* TT_ITZ */		/* You Did This! 'ITZ' -> '='     		---LATEST - > ''      */
	"R NOOB",      		/* TT_RNOOB */
	"<-=-",     		/* TT_R */		/* You Did This! 'R' -> '<==='   		---LATEST - > '<-=-'			NEW!! DONE!!      */	
	"zAnd",       	/* TT_ANYR */		/* You Did This! 'AN YR' -> 'zoe_and_this'   	---LATEST - > 'zAnd'  */	
	"{.}",    /* TT_AN */		/* You Did This! 'AN' -> 'zoe_do_maths_with'   	---LATEST - > '{.}'  */	
	"z+",      		/* TT_SUMOF */		/* You Did This! 'SUM OF' -> 'zoe_+'   		---LATEST - > 'z+'   		NEW!! DONE!! */
	"z-",     		/* TT_DIFFOF */		/* You Did This! 'DIFF OF' -> 'zoe_-'   	---LATEST - > 'z-'   		NEW!! DONE!! */
	"z*",  			/* TT_PRODUKTOF */	/* You Did This! 'PRODUKT OF' -> 'zoe_*'   	---LATEST - > 'z*'   	NEW!! DONE!! */
	"z/", 			/* TT_QUOSHUNTOF */	/* You Did This! 'UOSHUNT OF' -> 'zoe_/'   	---LATEST - > 'z/'   	NEW!! DONE!! */
	"z%",      		/* TT_MODOF */		/* You Did This! 'MOD OF' -> 'zoe_%'   		---LATEST - > 'z%'  		NEW!! DONE!! */		
	"z>",    		/* TT_BIGGROF */	/* You Did This! 'BIGGR OF' -> 'zoe_>>>'   	---LATEST - > 'z>'  		NEW!! DONE!! */
	"z<",   		/* TT_SMALLROF */	/* You Did This! 'SMALLR OF' -> 'zoe_<<<'   	---LATEST - > 'z<'  	NEW!! DONE!! */
	"zBoth",     		/* TT_BOTHOF */		/* You Did This! 'BOTH OF' -> 'zoe_both'   	---LATEST - > ''  		NEW!! N o T  FiNiSHED!! */
	"zEith",   		/* TT_EITHEROF */	/* You Did This! 'EITHER OF OF' -> 'zoe_either'	---LATEST - > ''  	NEW!! N o T  FiNiSHED!! */
	"zOne",      		/* TT_WONOF */		/* You Did This! 'WON OF' -> 'zoe_either'   	---LATEST - > ''  		NEW!! N o T  FiNiSHED!! */
	"zNot",        		/* TT_NOT */		/* You Did This! 'NON OF' -> 'zoe_either'   	---LATEST - > ''  		NEW!! N o T  FiNiSHED!! */
	"]--<",        	/* TT_MKAY */		/* You Did This! 'MKAY' -> 'zoe_call_now'   	---LATEST - > ']--<'  */
	"ALL OF",      		/* TT_ALLOF */		/* You Did This! 'ALL OF' -> ''   	---LATEST - > ''  */
	"ANY OF",      		/* TT_ANYOF */		/* You Did This! 'ANY OF' -> ''   	---LATEST - > ''  */
	"zoe_same",   		/* TT_BOTHSAEM */	/* You Did This! 'BOTH SAEM' -> 'zoe_same' 	---LATEST - > ''  */
	"zoe_different",    	/* TT_DIFFRINT */ 	/* You Did This! 'DIFFRINT'  -> 'zoe_different'	---LATEST - > ''   */
	"zBuild",        	/* TT_MAEK */		/* You Did This! 'MAEK'  -> 'zBuild'		---LATEST - > ''   */
	"A",           		/* TT_A */
	"zNow",    		/* TT_ISNOWA */		/* You Did This! 'IS NOW A' -> 'zNow' 		---LATEST - > ''  */
	"pencil",       	/* TT_VISIBLE */   	/* You Did This! 'VISIBLE' -> 'pencil' 		---LATEST - > ''  */
	"toysoldiers>--[",      	/* TT_SMOOSH */	     	/* You Did This! 'SMOOSH' -> 'toysoldiers'	---LATEST - > 'toysoldiers>--['  */
	"!",           		/* TT_BANG */
	"zoe_pleaseInput",      /* TT_GIMMEH */	 	/* You Did This! 'GIMMEH' -> 'zoe_pleaseInput'	---LATEST - > ''  */
	"zoe_match",       	/* TT_ORLY */		/* You Did This! 'O RLY' -> 'zoe_match'		---LATEST - > ''  */
	"zoe_pass",      	/* TT_YARLY */		/* You Did This! 'YA RLY' -> 'zoe_pass'		---LATEST - > ''  */
	"zoe_else",       	/* TT_MEBBE */		/* You Did This! 'MEBBE' -> 'zoe_else'		---LATEST - > ''  */
	"zoe_fail",      	/* TT_NOWAI */		/* You Did This! 'NO WAI' -> 'zoe_fail'		---LATEST - > ''  */
	"zoe_oh_I_see",         /* TT_OIC */		/* You Did This! 'OIC' -> 'zoe_oh_I_see'	---LATEST - > ''  */
	"zoe_whichone",         /* TT_WTF */		/* You Did This! 'WTF' -> 'zoe_whichone'	---LATEST - > ''  */
	"zoe_Isee",         	/* TT_OMG */  		/* You Did This! 'OMG' -> 'zoe_Isee'		---LATEST - > ''  */
	"zoe_ohIsee",      	/* TT_OMGWTF */		/* You Did This! 'OMGWTF' -> 'zoe_ohIsee'	---LATEST - > ''  */
	"zoe_exit",        	/* TT_GTFO */		/* You Did This! 'GTFO' -> 'zoe_exit'		---LATEST - > ''  */
	"zoe_loop_begin",    	/* TT_IMINYR */		/* You Did This! 'IM IN YR' -> 'zoe_inside_loop' --LATEST - > ''  */
	"zoe_inthis",       	/* TT_UPPIN */		/* You Did This! 'UPPIN' -> 'zoe_inthis'	---LATEST - > ''  */
	"zNerfin",      	/* TT_NERFIN */		/* You Did This! 'NERFIN' -> 'zNerfin'		---LATEST - > ''  */
	"<--[",		/* TT_YR */		/* You Did This! 'YR' -> 'zoe_pass_this'	---LATEST - > 'zIntoF'  and then '<--['    */
	"zoe_until",         	/* TT_TIL */		/* You Did This! 'TIL' -> 'zoe_until'		---LATEST - > ''  */
	"while",        	/* TT_WILE */		/* You Did This! "WILE" -> ''			---LATEST - > 'while' 	*/
	"zoe_loop_end", 	/* TT_IMOUTTAYR */	/* You Did This! 'IM OUTTA YR' -> 'zoe_loop_end' --LATEST - > ''  */
	"function",      	/* TT_HOWIZ */		/* You Did This! 'HOW IZ' -> 'function'   	---LATEST - > ''  */
	"wish_to_call",         /* TT_IZ */		/* You Did This! 'IZ' -> 'wish_to_call'   	---LATEST - > ''  */
	"end_of_function", 	/* TT_IFUSAYSO */	/* You Did This! 'IF U SAY SO' -> 'end_of_function'   ---LATEST - > ''  */
	"zReturn",    /* TT_FOUNDYR */	/* You Did This! 'FOUND YR' -> 'zoe_return_from_function'   ---LATEST - > 'zReturn'  */	
	"zSeriously",         	/* TT_SRS */		/* You Did This! 'SRS' -> 'zSeriously'   ---LATEST - > ''  */
	"--toBaby-->",       /* TT_APOSTROPHEZ */  	/* You Did This! "'Z" -> '--arrMember-->'   	---LATEST - > '--toBaby-->'  */
	"O HAI IM",    		/* TT_OHAIIM */		/* You Did This! "O HAI IM" -> ''   		---LATEST - > ''  <------NOT YET EVEN STARTED*/
	"IM LIEK",     		/* TT_IMLIEK */		/* You Did This! "IM LIEK" -> ''   		---LATEST - > ''  <------NOT YET EVEN STARTED*/
	"KTHX",        		/* TT_KTHX */		/* You Did This! "KTHX" -> ''   		---LATEST - > ''  <------NOT YET EVEN STARTED*/
	"I DUZ",       		/* TT_IDUZ */		/* You Did This! "I DUZ" -> ''   		---LATEST - > ''  <------NOT YET EVEN STARTED*/
	"CAN HAS",     		/* TT_CANHAS */		/* You Did This! "CAN HAS" -> ''   		---LATEST - > ''  <------NOT YET EVEN STARTED*/
	"?",           		/* TT_QUESTION */	/* You Did This! "" -> ''   			---LATEST - > ''  <------NOT YET EVEN STARTED*/
	""             		/* TT_ENDOFTOKENS */ 	/* You Did This! "" -> ''   			---LATEST - > ''  <------NOT YET EVEN STARTED*/
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
