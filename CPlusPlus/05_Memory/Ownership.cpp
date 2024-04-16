#include "Ownership.h"
#include <memory>

#include "Structure.h"

void Owner::Do()
{
	Structure* NewRStruct = new Structure;                                 // 소유권을 가지고 있지 않고, Raw 포인터로 참조함
	std::unique_ptr<Structure> NewUStruct = std::make_unique<Structure>(); // 자신만이 유일한 소유권을 가짐
	std::shared_ptr<Structure> NewSStruct = std::make_shared<Structure>(); // 소유권을 공유할 수 있고, 공유하면 레퍼런스 카운트가 증가함
	std::weak_ptr<Structure> wStruct;                                      // 소유권이 없으며, 참조해도 레퍼런스 카운트가 증가하지 않음
	wStruct = NewSStruct;

	delete NewRStruct;
}
