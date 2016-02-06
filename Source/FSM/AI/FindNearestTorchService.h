

#pragma once

#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "FindNearestTorchService.generated.h"

/**
 * 
 */
UCLASS()
class FSM_API UFindNearestTorchService : public UBTService_BlackboardBase
{
	GENERATED_BODY()

	UFindNearestTorchService(const class FObjectInitializer& PCIP);

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, Category = Blackboard)
	struct FBlackboardKeySelector NearestTorchExists;
	
};
