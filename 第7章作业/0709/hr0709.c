//hr0709.c
//��Ҫ���õ�C����ԭ�ͼ���N!
int FACT(int n)
{
	int i=1;
	int result=1;
	if(n==0)
		result=1;
	else if(n<0)
		result=0;
	else{
		for(i=1;i<=n;i++){
			result=result*i;
		}
	}
	return(result);
}