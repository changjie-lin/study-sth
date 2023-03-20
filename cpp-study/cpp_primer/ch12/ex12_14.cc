#include <memory>
#include <iostream>
#include <string>

using std::string;

struct destination {
	string URI;
	destination(string uri = "example.com:9981") : URI(uri) {}
};

struct connection {
	destination *dest;
};

connection connect(destination* dest) {

	connection conn;
	conn.dest = dest;
	std::cout << "Setup connection to " << conn.dest->URI << std::endl;
	return conn;
}

void disconnect(connection conn) {
	std::cout << "Stop connection to " << conn.dest->URI << std::endl;
}

void end_connection(connection *p) { disconnect(*p); }

void f(destination &d) {

	connection c = connect(&d);
	std::shared_ptr<connection> p(&c, end_connection);
}

int main() {

	destination d("cpp-primer.org:8080"), p("fluent-python.org:8000");
	f(d);
	f(p);

	return 0;
}
