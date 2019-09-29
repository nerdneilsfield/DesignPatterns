#include "originator.h"
#include "care_taker.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

int main()
{
	Life *life = new Life();
	PandoraBox *box = new PandoraBox(life);

	// ���ò�����һ����ʷʱ��
	life->SetDateTime("2000/10/01 00:00:00");
	box->Save();

	// ���ò�����һ����ʷʱ��
	life->SetDateTime("2010/10/01 00:00:00");
	box->Save();

	// ����һ����ʷʱ��
	life->SetDateTime("2018/10/01 00:00:00");

	// ��Խ
	box->Undo();
	std::cout << "Actual date time is " << life->GetDateTime() << std::endl;

	// �ٴδ�Խ
	box->Undo();
	std::cout << "Actual date time is " << life->GetDateTime() << std::endl;

	SAFE_DELETE(life);
	SAFE_DELETE(box);

	//getchar();

	return 0;
}
