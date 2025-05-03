/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@42.sp.br>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:03:18 by fcardozo          #+#    #+#             */
/*   Updated: 2025/05/03 19:40:27 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

const int MAX_FILE_SIZE = 4096;
const int MAX_LINES = 128;
const int MAX_CHARACTERS = 256; 

char *ft_readfile(char *filename)
{
  int file;
  char *f_buffer;
  
  file = open(filename, O_RDONLY);
  f_buffer = malloc(sizeof(char) * MAX_FILE_SIZE);
  read(file, f_buffer, MAX_FILE_SIZE);
  return f_buffer; 
}

char **ft_aloc_linesbuffer(void)
{
  int c_line;
  char **lines_buff;

  c_line = 0; 
  lines_buff = (char **) malloc (sizeof(char *) * MAX_LINES); 
  while (c_line < MAX_LINES)
  {
    lines_buff[c_line] = (char *) malloc (sizeof(char) * MAX_CHARACTERS); 
    ++c_line;
  }
  return lines_buff;
}

void  ft_free_linesbuffer(char **lines_buff)
{
  int c_line; 

  c_line = 0;
  while (c_line < MAX_LINES)
  {
    free(lines_buff[c_line]);    
    ++c_line;
  }
}

char *ft_strcrop(char *buff, char *str, int c_start, int c_end)
{
  int i;
  
  i = 0; 
  while (i + c_start < c_end)
  {
    buff[i] = str[i + c_start];
    ++i; 
  }
  buff[i] = '\0';
  return buff;
}

char **ft_splitlines(char *text_buff)
{
  int   line = 0;
  int   lc_start = 0;
  int   c_buff = 0;
  char  **ls_buff = ft_aloc_linesbuffer(); 
 
  while (text_buff[c_buff] != '\0')
  {
    if (text_buff[c_buff] == '\n')
    {
      ft_strcrop(ls_buff[line], text_buff, lc_start, c_buff);       
      lc_start = c_buff + 1;
      ++line;
    }
    ++c_buff;
  } 
  free(text_buff); 
  return ls_buff; 
}

char **ft_gdictionary(char *filename)
{
  char *dictionary = ft_readfile(filename); 
  char **f_lines = ft_splitlines(dictionary); 
  return f_lines;
}
