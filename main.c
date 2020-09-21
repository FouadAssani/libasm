/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 22:57:07 by fassani           #+#    #+#             */
/*   Updated: 2020/09/21 23:02:35 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <strings.h>
#include <string.h>

// gcc main.c -L -lasm libasm.a


int create_read_file()
{
	char *str = "C’est seulement par un surplus de technologie que nous pourrons avoir une réelle démocratie à l’échelle planétaire, une démocratie ou l’opinion de chacun comptera, ou le moindre sujet entraînera un vote rapide, ou chacun recevra une éducation bien plus efficace et sera mis au courant des problèmes et des solutions possibles";

	int fd = 0;
	if(!(fd = open("read_file", O_WRONLY | O_CREAT | O_TRUNC, 0644)))
		return (0);
	write(fd, str,ft_strlen(str));
	close(fd);
	return (fd);
}

int t_ft_strlen()
{
	printf("\n\nTest : ft_strlen *******************************************************\n\n");
	printf("ft_strlen(\"\") : [%zu]\n",ft_strlen(""));
	printf("   strlen(\"\") : [%zu]\n",strlen(""));

	printf("ft_strlen(\"42\") : [%zu]\n",ft_strlen("42"));
	printf("   strlen(\"42\") : [%zu]\n",strlen("42"));

	printf("ft_strlen(\"42 BORN TO CODE ?\") : [%zu]\n",ft_strlen("42 BORN TO CODE ?"));
	printf("   strlen(\"42 BORN TO CODE ?\") : [%zu]\n",strlen("42 BORN TO CODE ?"));
	return (1);
}

int t_ft_write()
{
	printf("\n\nTest : ft_write *******************************************************\n\n");
	printf("ft_write(\"\") : [%ld]\n",ft_write(1,"",ft_strlen("")));
	printf("   write(\"\") : [%ld]\n",write(1,"",ft_strlen("")));

	printf("ft_write(\"42 BORN TO CODE ?\") : [%ld]\n",ft_write(1,"42 BORN TO CODE ? ",ft_strlen("42 BORN TO CODE ? ")));
	printf("   write(\"42 BORN TO CODE ?\") : [%ld]\n",write(1,"42 BORN TO CODE ? ",ft_strlen("42 BORN TO CODE ? ")));

	errno = 0;
	printf("errno ft_write(13, \"Issac Asimov\", ft_strlen(\"Issac Asimov\")) : ");
	ft_write(13, "Issac Asimov", ft_strlen("Issac Asimov"));
	printf("%d\n", errno);
	errno = 0;
	printf("errno    write(13, \"Issac Asimov\", ft_strlen(\"Issac Asimov\")) : ");
	write(13, "Issac Asimov", ft_strlen("Issac Asimov"));
	printf("%d\n", errno);
	errno = 0;

	int fd = 0;
	if(!(fd = open("write_file", O_WRONLY | O_CREAT | O_TRUNC, 0644)))
		return (0);

	ft_write(fd, "\"ft_write :\nScience is interesting, and if you don't agree you can fuck off\"\nRichard Dawkins\n\n", ft_strlen("\"ft_write :\nScience is interesting, and if you don't agree you can fuck off\"\nRichard Dawkins\n\n"));
	write(fd, "\"write :\nScience is interesting, and if you don't agree you can fuck off\"\nRichard Dawkins\n\n", ft_strlen("\"write :\nScience is interesting, and if you don't agree you can fuck off\"\nRichard Dawkins\n\n"));

	printf("lisez le fichier write_file\n");
	close(fd);
	return (1);
}


int t_ft_read()
{
	printf("\n\nTest : ft_read *******************************************************\n\n");
	char read_buff[326];
	bzero(read_buff,325);

	int fd = 0;

	if (!create_read_file())
	{
		printf("Error : impossible de créer le fichier \"read_file\"\n");
		return (0);
	}
	if(!(fd = open("read_file", O_RDONLY)))
		return (0);

	ft_read(fd, read_buff, 325);
	printf("ft_read(fd, read_buff, 325) : [%s]\n\n", read_buff);
	lseek(fd, 0L, SEEK_SET);
	bzero(read_buff,325);
	read(fd, read_buff, 325);
	printf("   read(fd, read_buff, 325) : [%s]\n", read_buff);

	errno = 0;
	printf("errno ft_read(13, read_buff, 325) : ");
	ft_read(13, read_buff, 325);
	printf("[%d]\n", errno);
	errno = 0;
	printf("errno    read(13, read_buff, 325) : ");
	read(13, read_buff, 325);
	printf("[%d]\n", errno);
	errno = 0;
	close(fd);
	return (1);
}

int t_ft_strcmp()
{
	printf("\n\nTest : ft_strcmp *******************************************************\n\n");
	printf("ft_strcmp(\"\" ,\"\") : [%d]\n", ft_strcmp("" ,""));
	printf("   strcmp(\"\" ,\"\") : [%d]\n", strcmp("" ,""));

	printf("ft_strcmp(\"a\" ,\"b\") : [%d]\n", ft_strcmp("a" ,"b"));
	printf("   strcmp(\"a\" ,\"b\") : [%d]\n", strcmp("a" ,"b"));

	printf("ft_strcmp(\"b\" ,\"a\") : [%d]\n", ft_strcmp("b" ,"a"));
	printf("   strcmp(\"b\" ,\"a\") : [%d]\n", strcmp("b" ,"a"));

	printf("ft_strcmp(\"a\" ,\"a\") : [%d]\n", ft_strcmp("a" ,"a"));
	printf("   strcmp(\"a\" ,\"a\") : [%d]\n", strcmp("a" ,"a"));

	printf("ft_strcmp(\"hack world and make it great again\" ,\"Z\") : [%d]\n", ft_strcmp("hack world and make it great again" ,"Z"));
	printf("   strcmp(\"hack world and make it great again\" ,\"Z\") : [%d]\n", strcmp("hack world and make it great again" ,"Z"));

	printf("ft_strcmp(\"Build it, Break it,\" ,\"Build it, Break it, Fix it\") : [%d]\n", ft_strcmp("Build it, Break it," ,"Build it, Break it, Fix it"));
	printf("   strcmp(\"Build it, Break it,\" ,\"Build it, Break it, Fix it\") : [%d]\n", strcmp("Build it, Break it," ,"Build it, Break it, Fix it"));
	return (1);
}

int t_ft_strcpy()
{
	printf("\n\nTest : ft_strcpy *******************************************************\n\n");
	char read_buff[326];
	bzero(read_buff,325);
	ft_strcpy(read_buff, "\"If the design takes too long to build, it's a bad design\"\nElon Musk");
	printf("ft_strcpy : [%s]\n", read_buff);
	bzero(read_buff,325);
	strcpy(read_buff, "\"If the design takes too long to build, it's a bad design\"\nElon Musk");
	printf("   strcpy : [%s]\n", read_buff);

	bzero(read_buff,325);
	ft_strcpy(read_buff, "");
	printf("ft_strcpy(read_buff, \"\") : [%s]\n", read_buff);
	bzero(read_buff,325);
	strcpy(read_buff, "");
	printf("   strcpy(read_buff, \"\") : [%s]\n", read_buff);
	return (1);
}

int t_ft_strdup()
{
	printf("\n\nTest : ft_strdup *******************************************************\n\n");
	printf("ft_strdup(\"\") : [%s]\n",ft_strdup(""));
	printf("   strdup(\"\") : [%s]\n",ft_strdup(""));

	printf("ft_strdup(\"Form, Fonction, Performance\") : [%s]\n",ft_strdup("Form, Fonction, Performance"));
	printf("   strdup(\"Form, Fonction, Performance\") : [%s]\n",ft_strdup("Form, Fonction, Performance"));
	return (1);
}

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		printf("\n*******************libasm**************************\n");
		t_ft_strlen();
		t_ft_write();
		t_ft_read();
		t_ft_strcmp();
		t_ft_strcpy();
		t_ft_strdup();

	}
	else if (argc == 2)
	{
		printf("\n*******************libasm**************************\n");
		if (!ft_strcmp(argv[1] ,"ft_strlen"))
			t_ft_strlen();
		else if (!ft_strcmp(argv[1] ,"ft_write"))
			t_ft_write();
		else if (!ft_strcmp(argv[1] ,"ft_read"))
			t_ft_read();
		else if (!ft_strcmp(argv[1] ,"ft_strcmp"))
			t_ft_strcmp();
		else if (!ft_strcmp(argv[1] ,"ft_strcpy"))
			t_ft_strcpy();
		else if (!ft_strcmp(argv[1] ,"ft_strdup"))
			t_ft_strdup();
		else
			printf("Error : illegal option\n");

	}
	return (0);
}
