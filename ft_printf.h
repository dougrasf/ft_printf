/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:09:32 by dofranci          #+#    #+#             */
/*   Updated: 2022/08/03 21:57:44 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putnbr2(unsigned int n);
int	ft_putnbr(int n);
int	ft_putptr2(unsigned long int n);
int	ft_putptr(unsigned long long int n);
int	ft_putx(unsigned int n, char conv);
int	ft_putchar(char c);
int	ft_putstr(char *s);

#endif
