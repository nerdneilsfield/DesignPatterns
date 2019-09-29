#include "concrete_colleague.h"
#include "concrete_mediator.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

int main()
{
	// ����
	IColleague *landlord = new ConcreteColleague("Tom");

	// ���
	IColleague *jerry = new ConcreteColleague("Jerry");
	IColleague *tuffy = new ConcreteColleague("Tuffy");

	// �н��� - �������
	ConcreteMediator mediator;
	mediator.registerColleague(jerry);
	mediator.registerColleague(tuffy);

	// ����ͨ���н齫��Ϣ���ͳ�ȥ
	landlord->sendMessage(mediator, "Xi'erqi, two bedroom house, 6000/month.");

	SAFE_DELETE(jerry);
	SAFE_DELETE(tuffy);

	//getchar();

	return 0;
}