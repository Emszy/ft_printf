#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> 
# include <wchar.h>
# include "libft/libft.h"


typedef struct s_flags
{

	int hash;
	int zero_spacer;
 	int neg;
 	int width;
 	int plus_sign;
 	int space;
 	int modula;
	int precision;
	int hh;
  	int h;
 	int l;
 	int ll; 
	int j; 
	int z;
            

}				t_flags;

typedef struct s_types
{
	char *s; // putstr
 	int S; // wide char
 	int p; // "void * (pointer to void) in an implementation-defined format."
 	int d; // "Handles int"
 	int D; //  "handles int"
 	int i; // "Handles int"
 	int f; 	//contain decimal
	int F; 	// contain decimal
 	int o; // "Unsigned Int in Octal"
 	int O; // Unsigned int in octal
 	int u; // "Print Decimal (Unsigned int)"
 	int U; // "unsigned int "
 	int x; // "unsigned int as a hexadecimal number. x uses lower-case letters and ."
 	int X; // "unsigned int as a hexadecimal number. X uses upper-case"
 	int c; // "char"
 	int C; // "Handles Wide Character type: int or wint_t"

 	
}				t_conversions;

t_flags		init_flags(t_flags flags);
t_flags		check_wid(char *fmt, t_flags flags, va_list ap);
t_flags		check_precis(char *fmt, t_flags flags, va_list ap);
t_flags		check_flags(char *fmt, t_flags flags, va_list ap);
t_flags		check_mod(char *fmt, t_flags flags);



# endif