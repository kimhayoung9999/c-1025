// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyRocket.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UProjectileMovementComponent;
class UParticleEmitter;


UCLASS()
class PROJECT1025_API AMyRocket : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyRocket();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY (VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UBoxComponent* Box;

	UPROPERTY (VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* Rocket;

	UPROPERTY (VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UProjectileMovementComponent* Movement;

	UPROPERTY (VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UParticleEmitter* Emitter;
	UFUNCTION()
	void OnOverlapBegin (class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
