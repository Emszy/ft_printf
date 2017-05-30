#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> 
# include <wchar.h>
# include "libft/libft.h"

# define MAX_INT 2147483647

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
void		prepend_width(t_flags flags, int width);
void		print_char(va_list ap, t_flags flags);
void		putwide(wchar_t chr);
void		chars(va_list ap, t_flags flags, char specifier);
char		*wide_to_s(wint_t w);
void		limit_print(char *str, int len);
void		make_string(char *s, t_flags flags);
void		l_str(wchar_t *ws, t_flags flags);
void		str_parse(va_list ap, t_flags flags, char c);
char		*ft_remalloc(char *str, size_t size);
int			get_size(uintmax_t num, int base);
void		number_print(char *str, t_flags flags);
void		num_to_s(uintmax_t number, t_flags flags, char before);
intmax_t 	promo_check(va_list ap, t_flags flags, char *fmt);
void		num_parse(va_list ap, t_flags flags, char *fmt);
void		u_to_s(uintmax_t num, t_flags flags);
uintmax_t 	promoting_u(va_list ap, t_flags flags, char *fmt);
void		unum_parse(va_list ap, t_flags flags, char *fmt);






# endif