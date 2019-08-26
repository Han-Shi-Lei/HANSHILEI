///////////////////////////////////////////////////////////////
/////////通过这个程序使用MySQL API实现数据的插入功能///////////
///////////////////////////////////////////////////////////////

#include <cstdio>
#include <cstdlib>
#include <mysql/mysql.h>

int main(){

  //1.初始化句柄  句柄其实就是一个遥控器
  MYSQL* connect_fd = mysql_init(NULL);

  //2.建立连接
  //mysql_init 返回的指针
  //主机地址
  //用户名
  //密码
  //数据库名
  //端口号
  //unix_socket
  //client_flag
  if(mysql_real_connect( connect_fd, "127.0.0.1", "root", "970303", "blog_system", 3306, NULL, 0) == NULL){
    printf("连接失败！%s\n", mysql_error(connect_fd));
    return 1;
  }
  //连接成功
  printf("连接成功！\n");

  //3.设置编码格式  server已经设置为utf8
  //客户端也必须设置为utf8
  mysql_set_character_set(connect_fd, "utf8");

  //4.拼接SQL语句
  char sql[1024 * 4] = {0};
  char title[] = "立一个flag";
  char content[] = "我要拿30w年薪";
  int tag_id = 1;
  char date[] = "2019/07/25";
  sprintf(sql,"insert into blog_table values(null, '%s', '%s', %d, '%s')", title, content, tag_id, date);
  printf("sql: %s\n", sql);

  //5.让数据库服务器执行sql
  int ret = mysql_query(connect_fd, sql);
  if(ret < 0){
    printf("执行sql失败！%s\n", mysql_error(connect_fd));
    mysql_close(connect_fd);
    return 1;
  }
  printf("插入成功！\n");
  //断开连接
  mysql_close(connect_fd);

  return 0;
}
