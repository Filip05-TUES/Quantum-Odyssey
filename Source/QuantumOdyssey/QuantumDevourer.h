#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "PaperFlipbookComponent.h"
#include <Kismet/GameplayStatics.h>
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "QuantumDevourer.generated.h"

UCLASS()
class QUANTUMODYSSEY_API AQuantumDevourer : public APaperCharacter
{
    GENERATED_BODY()

public:
    AQuantumDevourer();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    FTimerHandle DeathTimerHandle;
    UFUNCTION(BlueprintCallable)
    void CheckForDeath();

    UFUNCTION(BlueprintCallable)
    void HandleDeath();

    UFUNCTION(BlueprintCallable)
    void TakeDamage(int Damage);

    UFUNCTION(BlueprintCallable)
    void HandleAnimationFire();

    UFUNCTION(BlueprintCallable)
    void HandleAnimationDeath();

    UFUNCTION(BlueprintCallable)
    void HandleHeal();

    UFUNCTION(BlueprintCallable)
    void HandleAnimationLaser();

    UFUNCTION(BlueprintCallable)
    void HandleAnimationBlock();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    int Health;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
    bool IsDamageReduced;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
    int DamageTaken;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
    bool IsDead;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
    int BurnDuration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
    int EntangleDuration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
    bool IsUsingLaser;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cooldowns")
    int EnhanceCooldown;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cooldowns")
    int EntangleCooldown;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cooldowns")
    int EchoCooldown;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
    bool IsUsingArm;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
    class UPaperFlipbook* DeathAnimation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
    class UPaperFlipbook* FireAnimation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
    class UPaperFlipbook* IdleAnimation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
    class UPaperFlipbook* HealAnimation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
    class UPaperFlipbook* LaserAnimation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
    class UPaperFlipbook* BlockAnimation;
};
