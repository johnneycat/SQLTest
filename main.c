#include <stdio.h>
#include <mysql/mysql.h>
#include <mysql/mysqld_error.h>

int main()
{
    printf("Hello World!\n");

    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char *server = "localhost";
    char *user = "root";
    char *password = "root";
    char *database = "foo";

    conn = mysql_init(NULL);
    /* Connect to database */
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        printf("connect failed !\n");
        exit(1);
    }
    printf("connect ok !\n");

    /* send SQL query */
    if (mysql_query(conn, "show tables"))
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    res = mysql_use_result(conn);

    /* output table name */
    printf("MySQL Tables in mysql database:\n");
    while ((row = mysql_fetch_row(res)) != NULL)
    printf("%s \n", row[0]);

    /* close connection */
    mysql_free_result(res);
    mysql_close(conn);

    char p = 'abcd';
    char* q= "helloworld";
    printf("p: %c\n", p);
    printf("q: %s", q);

    return 0;
}
