#ifndef _TEXT_MACROS
#define _TEXT_MACROS


#include "cross_lib.h"
#include "standard_libs.h"

#include "letters.h"

#define printCenteredMessage(Text) \
	printCenteredMessageOnRow((YSize>>1), Text)


#if !defined(NO_TEXT_COLOR) && !defined(NO_PRINT)
	#define printCenteredMessageWithCol(col, Text) \
		printCenteredMessageOnRowWithCol((YSize>>1), col, Text)	
#else		
	#define printCenteredMessageWithCol(col, Text) \
		printCenteredMessageOnRow((YSize>>1), Text)
#endif


#if !defined(NO_PRINT)
	#if !defined(NO_TEXT_COLOR) 
		void printCenteredMessageOnRowWithCol(uint8_t row, uint8_t col, char *Text);
	#endif
	void printCenteredMessageOnRow(uint8_t row, char *Text);
#else
    #define printCenteredMessageOnRowWithCol(row,col,Text)
	#define printCenteredMessageOnRow(row,Text)
#endif


#endif // _TEXT_MACROS

