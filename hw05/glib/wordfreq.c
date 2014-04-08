#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <glib/gprintf.h>

gchar *read_file(){
    gchar *contents;
    g_file_get_contents ("ramayana.txt", &contents, NULL, NULL);
    return contents;
}

gchar **tokenize(gchar *contents){
    return g_strsplit_set(contents,"\t\n\r:;,./\\(){}[]\t ",-1);
}

GHashTable *make_histogram(gchar **tokens){
    GHashTable *histogram = g_hash_table_new(g_str_hash,g_int_equal);
    int i = 0;
    int *value = malloc(sizeof(gint));

    while(*tokens != NULL){
        value = (gint*) g_hash_table_lookup(histogram,(gpointer) *tokens);
        if (value == NULL){
            value = malloc(sizeof(gint));
            *value = 0;
        }
        *value += 1;
        g_hash_table_insert (histogram, (gpointer) *tokens, (gpointer) value);
        
        tokens++;
    }
    return histogram;
}

int main(int argc, char** argv) {
    gchar *contents;
    gchar **tokens = NULL;
    GHashTable *histogram = NULL;
    contents = read_file();
    tokens = tokenize(contents);
    histogram = make_histogram(tokens);
    GHashTableIter iter;
    gpointer key, value;

    g_hash_table_iter_init (&iter, histogram);
        while (g_hash_table_iter_next (&iter, &key, &value))
        {
           printf("%s has %i. \n",(gchar*) key,*(gint*)value) ;
        }

    

}