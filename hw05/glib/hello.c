#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <glib/gprintf.h>
int main(int argc, char** argv) {
     GList* list = NULL;
     //list = g_list_append(list, "Hello world!");
     //char* str = g_list_first(list)->data;
     list = g_strsplit_set("Hello World"," ",-1);
     char* str1 = g_list_nth_data(list,1);
     printf("The first item is '%s'\n", str1);
     return 0;
}