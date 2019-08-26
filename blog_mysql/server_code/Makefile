FLAG=-std=c++11 -L/usr/lib64/mysql -lmysqlclient -ljsoncpp -pthread 

blog_server:blog_server.cc db.hpp httplib.h
	g++ blog_server.cc -o blog_server $(FLAG)

.PHONY:clean
clean:
	rm blog_server
