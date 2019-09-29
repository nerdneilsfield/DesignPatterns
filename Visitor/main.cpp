#include "concrete_visitor.h"
#include "object_structure.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

int main()
{
	City *city = new City();

	// ���� - ��¥������ٸ
	IPlace *bellTower = new BellTower();
	IPlace *warriors = new TerracottaWarriors();

	// ������ - �ο͡���๤
	IVisitor *tourist = new Tourist();
	IVisitor *cleaner = new Cleaner();

	// ���Ӿ���
	city->Attach(bellTower);
	city->Attach(warriors);

	// ���ܷ���
	city->Accept(tourist);
	city->Accept(cleaner);

	SAFE_DELETE(cleaner);
	SAFE_DELETE(tourist);
	SAFE_DELETE(warriors);
	SAFE_DELETE(bellTower);
	SAFE_DELETE(city);

	//getchar();

	return 0;
}
