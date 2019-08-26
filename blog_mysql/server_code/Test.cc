#include "httplib.h"

void Handler(const httplib::Request& req,httplib::Response& resp){
  (void)req;
  resp.set_content("<html><h1>hello</h1><html>", "test/html");
}
int main(){
  using namespace httplib;
  Server server;
  server.Get("/", Handler);
  server.listen("0.0.0.0", 9090);
  return 0;
}
