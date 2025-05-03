/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@42.sp.br>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:58:34 by fcardozo          #+#    #+#             */
/*   Updated: 2025/05/03 17:00:39by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void  ft_putchar(char character)
{
  write(1, &character, 1); 
}

void  ft_putbr()
{
  ft_putchar('\n'); 
}

int ft_strlen(char *str)
{
  int contador; 

  contador = 0;
  while (str[contador] != '\0')
  {
    contador++; 
  }

  return contador;
}

void  ft_putstr(char *str)
{
  int i;
  
  i = 0;
  while (str[i] != '\0')
  {
    ft_putchar(str[i]);   
    i++;
  }
}

void  ft_putint(unsigned long integer)
{
  char last_digit; 
  unsigned long remaining;
  
  last_digit = (integer % 10) + '0';
  remaining = integer / 10;

  if (remaining > 0)
    ft_putint(remaining);

  ft_putchar(last_digit);
}
