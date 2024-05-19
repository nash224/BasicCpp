#pragma once
#pragma once
#include <list>

// 기하구조를 표현하고
// 부모자식관계를 처리한다.

enum class ColType
{
	// 캡슐
	// 2D에서의 충돌은 모두가 한축이 같아야 한다.
	// 우리는 충돌이 2D가 더 느려요.
	LINE2D, // z를 0으로 만들고 충돌 구 50 60개를 돌릴수가 있다.
	SPHERE2D, // z를 0으로 만들고 충돌 구 50 60개를 돌릴수가 있다.
	AABBBOX2D, // z를 0으로 만들고 충돌 Axis-Aligned Bounding 회전하지 않은 박스
	OBBBOX2D, // z를 0으로 만들고 충돌 Oriented Bounding Box 회전한 박스 <= 을 1번할 연산량으로
	LINE3D, // z를 0으로 만들고 충돌 구 50 60개를 돌릴수가 있다.
	SPHERE3D,
	AABBBOX3D,
	OBBBOX3D,
	MAX,
};


class CollisionData
{
public:
	union
	{
		// 다이렉트 x에서 지원해주는 충돌용 도형
		DirectX::BoundingSphere SPHERE;
		DirectX::BoundingBox AABB;
		DirectX::BoundingOrientedBox OBB;
	};

	CollisionData()
		: OBB()
	{

	}
};

class GameEngineTransform;
class CollisionParameter
{
public:
	CollisionData& Left;
	CollisionData& Right;
	ColType LeftType = ColType::AABBBOX2D;
	ColType RightType = ColType::AABBBOX2D;

	inline int GetLeftTypeToInt() const
	{
		return static_cast<int>(LeftType);
	}

	inline int GetRightTypeToInt() const
	{
		return static_cast<int>(RightType);
	}

	CollisionParameter(
		CollisionData& _Left,
		CollisionData& _Right,
		ColType _LeftType = ColType::AABBBOX2D,
		ColType _RightType = ColType::AABBBOX2D
	)
		:
		Left(_Left),
		Right(_Right),
		LeftType(_LeftType),
		RightType(_RightType)
	{

	}
};

//
//cbuffer TransformData : register(b0)
//{
//	float4 Scale;
//	float4 Rotation;
//	float4 Quaternion;
//	float4 Position;
//
//	float4 LocalScale;
//	float4 LocalRotation;
//	float4 LocalQuaternion;
//	float4 LocalPosition;
//
//	float4 WorldScale;
//	float4 WorldRotation;
//	float4 WorldQuaternion;
//	float4 WorldPosition;
//
//	float4x4 ScaleMatrix; // 크
//	float4x4 RotationMatrix; // 자
//	float4x4 PositionMatrix; // 이
//	float4x4 RevolutionMatrix; // 공
//	float4x4 ParentMatrix; // 공
//
//	float4x4 LocalWorldMatrix;
//	// 월드 공간
//	float4x4 WorldMatrix;
//
//
//	float4x4 ViewMatrix;
//	float4x4 ProjectionMatrix;
//	float4x4 ViewPort;
//
//	// 로컬 => 월드 => 뷰 => 프로젝션 
//	float4x4 WorldViewProjectionMatrix;
//};

class float4
{
public:
	static float4 ONENULL;
	static float4 ZERONULL;
	static float4 ZERO;
};

class float4x4
{

};

// 왜 굳이. 
class TransformData
{
public:
	float4 LocalScale;
	float4 LocalRotation;
	float4 LocalQuaternion;
	float4 LocalPosition;

	float4 WorldScale;
	float4 WorldRotation;
	float4 WorldQuaternion;
	float4 WorldPosition;

	float4x4 ScaleMatrix;      // 크
	float4x4 RotationMatrix;   // 자
	float4x4 PositionMatrix;   // 이
	float4x4 RevolutionMatrix; // 공
	float4x4 ParentMatrix;     // 부

	float4x4 LocalWorldMatrix;
	float4x4 WorldMatrix;


	float4x4 ViewMatrix;
	float4x4 ProjectionMatrix;
	float4x4 ViewPort;

	// 로컬 => 월드 => 뷰 => 프로젝션 
	float4x4 WorldViewProjectionMatrix;

	void LocalCalculation()
	{
		ScaleMatrix.Scale(Scale);
		RotationMatrix.RotationDeg(Rotation);
		PositionMatrix.Position(Position);

		LocalWorldMatrix = ScaleMatrix * RotationMatrix * PositionMatrix * RevolutionMatrix;
		WorldMatrix = LocalWorldMatrix;
	}

	void WorldViewProjectionCalculation()
	{
		WorldViewProjectionMatrix = WorldMatrix * ViewMatrix * ProjectionMatrix;
	}

	void operator=(const TransformData& _Other)
	{
		memcpy_s(this, sizeof(TransformData), &_Other, sizeof(TransformData));
	}

	TransformData()
	{

	}

	TransformData(const TransformData& _Other)
	{
		memcpy_s(this, sizeof(TransformData), &_Other, sizeof(TransformData));
	}
};

class GameEngineTransform;

GameEngineTransform::GameEngineTransform() {};
GameEngineTransform::~GameEngineTransform() {};
void GameEngineTransform::TransformUpdate() {}
void GameEngineTransform::CalChilds() {}

// 설명 :
class GameEngineTransform
{
public:
	// constrcuter destructer
	GameEngineTransform();
	~GameEngineTransform();

	// delete Function
	GameEngineTransform(const GameEngineTransform& _Other) = delete;
	GameEngineTransform(GameEngineTransform&& _Other) noexcept = delete;
	GameEngineTransform& operator=(const GameEngineTransform& _Other) = delete;
	GameEngineTransform& operator=(GameEngineTransform&& _Other) noexcept = delete;

	void TransformUpdate();
	void CalChilds();

	void SetParent(GameEngineTransform& _Parent)
	{
		Parent = &_Parent;
		Parent->Childs.push_back(this);
		TransformUpdate();
	}
	void SetTransformData(const TransformData& Data)
	{
		TransData = Data;
	}

private:

	GameEngineTransform* Parent = nullptr;
	std::list<GameEngineTransform*> Childs;
	TransformData TransData;

};


