#include "refined_abstraction.h"
#include "concrete_implementor.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

int main()
{
	// �������� - ��ơ�����
	IElectricalEquipment *light = new Light();
	IElectricalEquipment *fan = new Fan();

	/**
	* �������� - ����ʽ���ء���λ����
	* ������ʽ���غ͵�ƹ�������������λ���غͷ��ȹ�������
	**/
	ISwitch *pullChain = new PullChainSwitch(light);
	ISwitch *twoPosition = new TwoPositionSwitch(fan);

	// ���ơ��ص�
	pullChain->On();
	pullChain->Off();

	// �򿪷��ȡ��رշ���
	twoPosition->On();
	twoPosition->Off();

	SAFE_DELETE(twoPosition);
	SAFE_DELETE(pullChain);
	SAFE_DELETE(fan);
	SAFE_DELETE(light);

	//getchar();

	return 0;
}