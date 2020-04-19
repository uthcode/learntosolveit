#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	mkdir("foobar",'644');
}
