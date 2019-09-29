#include "concrete_handler.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

int main()
{
	IHandler *manager = new Manager();
	IHandler *director = new Director();
	IHandler *ceo = new CEO();

	// ְ���������� -> �ܼ� -> �ܲ�
	manager->SetSuccessor(director);
	director->SetSuccessor(ceo);

	manager->HandleRequest(1);
	manager->HandleRequest(2);
	manager->HandleRequest(5);
	manager->HandleRequest(10);

	SAFE_DELETE(manager);
	SAFE_DELETE(director);
	SAFE_DELETE(ceo);

	//getchar();

	return 0;
} 