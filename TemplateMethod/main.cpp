#include "concrete_class.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

int main()
{
	// ����У��
	Company *alibaba = new Alibaba();
	alibaba->Recruit();

	// ��ѶУ��
	Company *tencent = new Tencent();
	tencent->Recruit();

	SAFE_DELETE(tencent);
	SAFE_DELETE(alibaba);

	//getchar();

	return 0;
}
