/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@42.sp.br>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:03:18 by fcardozo          #+#    #+#             */
/*   Updated: 2025/05/03 18:05:41 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>

char *ft_readfile(char *filename)
{
  const int BUFF_SIZE = 2048; 
  const int FILE = open(filename, O_RDONLY);
  char *BUFFER = malloc(sizeof(char) * BUFF_SIZE);
  
  read(FILE, BUFFER, BUFF_SIZE);
  return BUFFER; 
}

const int MAX_LINES = 128;
const int MAX_CHARACTERS = 256; 

char **ft_linesbuffer(void)
{
  char **BUFF_LINES = (char **) malloc (sizeof(char *) * MAX_LINES);
  
  int bf_line = 0; 
  while (bf_line < MAX_LINES)
  {
    BUFF_LINES[bf_line] = (char *) malloc (sizeof(char) * MAX_CHARACTERS); 
    ++bf_line;
  }
  
  return BUFF_LINES;
}

void  ft_storeline(char **lines_bff, int line, char *start, char *end)
{
  int counter; 
  
  counter = 0; 
  while ((start + counter) != end)
  {
    lines_bff[line][counter] = *start;
    ++counter;
    ++start;
  }
  lines_bff[line][counter] = '\0';
}

char **ft_splitlines(char *text_bff)
{
  char **lines_bff = ft_linesbuffer();
  int bf_char = 0;
  int l_character = 0; 
  int *l_start = text_bff; 
  
  while (text_bff[l_character] != '\0')
  {
    if (text_bff[l_character] = '\n')
    {
      // ft_storeline(lines_bff, line, line_start, &text_bff[character]); 
      
    }
    character++;
  }

  printf("%d, %d, %s", line, character, line_start);
  // printf("%p", lines_buffer[127]);

  // int c_character = 0;
  // int c_line = 0; 
  
  // // "Ola, estou te programando\n Outra linha."


  // while (buffer[c_character] != '\0')
  // {
  //   if (buffer[c_character] == '\n')
  //     c_line++; 
  //   c_character++;
  // }

  // printf("%d", c_line);
  
}

void  main(void)
{
 char *dictionary = ft_readfile("numbers.dict"); 
 char **f_lines = ft_splitlines(dictionary); 
//  printf("%s", dictionary);
 // limpando a memoria 
 free(dictionary);
}

