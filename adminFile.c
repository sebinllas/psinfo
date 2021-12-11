// quiar esta implementacion, esta definida en str.c

/* cargar contenido del archivo */
char* load_content_file(char* pid)
{
    char *path = calloc(14 + len_str(pid) + 1, 1);
    append_str(path, "/proc/");
    append_str(path, pid);
    append_str(path, "/status");

    FILE *fp;
    fp = fopen(path, "r");
    if (fp == NULL)
    {
        fputs("File error or non-existent process\n", stderr);
        exit(1);
    }

    char *buf = calloc(1500, 1);
    //fgets(buf, 1500, fp);
    fread(buf, 1500, 1, fp);

    return buf;
} 

void print_list(int pc, char *pid[])
{
    for(int i=2; i<pc; i++)
    {
        char *buf = load_content_file(pid[i]);
        printf("%s", show_description_many_process(buf, pid[i]));
    }
}