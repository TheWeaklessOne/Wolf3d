#include "wolf.h"

static void	fn_reverse(char *start, char *end)
{
	char	tmp;

	end[1] = 0;
	while (start + 1 <= end)
	{
		tmp = end[0];
		end--[0] = start[0];
		start++[0] = tmp;
	}
}

static void	fn_write_int_str(t_itoa *itoa)
{
	while (itoa->value >= itoa->base)
	{
		if (itoa->i == itoa->b_op)
		{
			itoa->buffer++[0] = ' ';
			itoa->i = 0;
		}
		itoa->tmp = itoa->value / itoa->base;
		itoa->buffer++[0] = itoa->alphabet[(int)
				(itoa->value - itoa->tmp * itoa->base)];
		itoa->value = itoa->tmp;
		itoa->i++;
		itoa->count++;
	}
	if (itoa->i == itoa->b_op)
		itoa->buffer++[0] = ' ';
	itoa->buffer[0] = itoa->alphabet[itoa->value];
	if (itoa->base != 2)
		return ;
	itoa->count = ((itoa->count + 3) & -4) - itoa->count;
	while (itoa->count > 0)
	{
		itoa->count--;
		itoa->buffer++[1] = 0x30;
	}
}

static void	fn_prev(t_itoa *itoa)
{
	if ((itoa->option & ITOA_SIGNED) != 0)
	{
		if ((intmax_t)itoa->value < 0)
		{
			itoa->value = ~itoa->value + 1;
			itoa->buffer++[0] = '-';
			itoa->start++;
		}
		else if ((itoa->option & ITOA_PLUS) != 0)
		{
			itoa->buffer++[0] = '+';
			itoa->start++;
		}
	}
	if ((itoa->option & ITOA_GROUPED) == 0)
		return ;
	itoa->b_op = (itoa->base == 2) ? 4 : 3;
}

static int		ft_itoa_base(char *buffer, uintmax_t value,
							uint_fast8_t base, uint_fast8_t option)
{
	t_itoa		itoa;

	if (base > 36 || base < 2)
		return (0);
	itoa.base = base;
	itoa.buffer = buffer;
	itoa.str = buffer;
	itoa.start = buffer;
	itoa.value = value;
	itoa.option = option;
	itoa.i = 0;
	itoa.count = 1;
	itoa.b_op = 0xFF;
	itoa.alphabet = (itoa.option & ITOA_UPPER) != 0 ? ITOA_ABC :
					"0123456789abcdefghijklmnopqrstuvwxyz";
	fn_prev(&itoa);
	if ((itoa.option & ITOA_NOT_ONE) != 0 && itoa.value < itoa.base)
	{
		itoa.buffer++[0] = 0x30;
		itoa.buffer[0] = itoa.alphabet[(int)(itoa.value)];
		return (itoa.buffer + 1 - itoa.str);
	}
	fn_write_int_str(&itoa);
	fn_reverse(itoa.start, itoa.buffer);
	return (itoa.buffer + 1 - itoa.str);
}

char		*ft_itoa(int n)
{
	intmax_t	value;
	char		*out;
	int			count;
	int			i;
	char		buffer[sizeof(uintmax_t) * 4 + 1];

	value = n;
	count = ft_itoa_base(buffer, value, 10, ITOA_LOWER | ITOA_SIGNED);
	out = malloc(count + 1);
	if (out == 0)
		ft_crash("Itoa malloc error!");
	i = 0;
	while (i < count)
	{
		out[i] = buffer[i];
		i++;
	}
	out[i] = 0;
	return (out);
}
