// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chunk.generated.h"

enum class EBlock;
enum class EDirection;
class FastNoiseLite;
class UProceduralMeshComponent;


UCLASS()
class SILENTSURVIVAL_API AChunk : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChunk();

	UPROPERTY(EditAnywhere, Category="Chunk")
	int Size = 32;

	UPROPERTY(EditAnywhere, Category="Chunk")
	int Scale = 1;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	TObjectPtr<UProceduralMeshComponent> Mesh;
	TObjectPtr<FastNoiseLite> Noise;

	TArray<EBlock> Blocks;

	TArray<FVector> VertexData;
	TArray<int> TriangleData;
	TArray<FVector2D> UVData;

	int VertexCount = 0;

	const FVector BlockVertexData[8] = {
	 FVector(1,1,1),
	 FVector(1,0,1),
	 FVector(1,0,0),
	 FVector(1,1,0),
	 FVector(0,0,1),
	 FVector(0,1,1),
	 FVector(0,1,0),
	 FVector(0,0,0)
	};

	const int BlockTriangleData[24] = {
		0,1,2,3,
		5,0,3,6,
		4,5,6,7,
		1,4,7,2,
		5,4,1,0,
		3,2,7,6
	};

	void GenerateBlocks();

	void GenerateMesh();

	void ApplyMesh() const;

	bool Check(FVector Position) const;

	void CreateFace(EDirection Direction, FVector Position);

	TArray<FVector> GetFaceVertices(EDirection Direction, FVector Position) const;

	FVector GetPositionInDirection(EDirection Direction, FVector Position) const;

	int GetBlockIndex(int X, int Y, int Z) const;






};
