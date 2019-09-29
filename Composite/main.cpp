#include "composite.h"
#include "leaf.h"

int main()
{
	// ����һ�����νṹ
	// �������ڵ�
	Component *pRoot = new Composite("������˾�������У�");

	// ������֧
	Component *pDepart1 = new Composite("������̣��������ܣ�");
	pDepart1->Add(new Leaf("������ʹ�������죩"));
	pDepart1->Add(new Leaf("������ʹ������"));
	pRoot->Add(pDepart1);

	Component *pDepart2 = new Composite("�������ɣ��������");
	pDepart2->Add(new Leaf("��ɽ���������"));
	pDepart2->Add(new Leaf("��ɽ��Ī��"));
	pDepart2->Add(new Leaf("��ɽ������Ⱥ��"));
	pDepart2->Add(new Leaf("̩ɽ�����ŵ�����"));
	pDepart2->Add(new Leaf("��ɽ������ʦ̫��"));
	pRoot->Add(pDepart2);

	// ���Ӻ�ɾ��Ҷ��
	pRoot->Add(new Leaf("���֣���֤��ʦ��"));
	pRoot->Add(new Leaf("�䵱�����������"));
	Component *pLeaf = new Leaf("��ǣ���׺���");
	pRoot->Add(pLeaf);

	// С��ֱ�Ӳõ�
	pRoot->Remove(pLeaf);

	// �ݹ����ʾ��֯�ܹ�
	pRoot->Operation(1);

	// ɾ��������ڴ�
	SAFE_DELETE(pRoot);

	//getchar();

	return 0;
}