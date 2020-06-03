//hr0710.c
extern void my_strlen(char * d) ; //需要调用的汇编函数原型并加extern关键字
int main ()
{
	char * srcstr = "0123456" ;
	my_strlen(srcstr);
	return 0 ;
}
