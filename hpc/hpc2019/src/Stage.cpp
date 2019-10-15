//------------------------------------------------------------------------------
/// @file
/// @author   ハル研究所プログラミングコンテスト実行委員会
///
/// @copyright  Copyright (c) 2019 HAL Laboratory, Inc.
/// @attention  このファイルの利用は、同梱のREADMEにある
///             利用条件に従ってください。
//------------------------------------------------------------------------------

#pragma once
#include "Stage.hpp"

//------------------------------------------------------------------------------
#include "Assert.hpp"
#include "Math.hpp"
#include "Print.hpp"

//------------------------------------------------------------------------------
namespace hpc {

//------------------------------------------------------------------------------
Stage::Stage()
: mTurn()
, mTurtlePositions()
, mFoods()
{
}

//------------------------------------------------------------------------------
int Stage::turn() const
{
    return mTurn;
}

//------------------------------------------------------------------------------
const TurtlePositions& Stage::turtlePositions() const
{
    return mTurtlePositions;
}

//------------------------------------------------------------------------------
const Foods& Stage::foods() const
{
    return mFoods;
}

//------------------------------------------------------------------------------
void Stage::initialize(int aTurtleCount, int aFoodCount, int aDistribution, const RandomSeed& aStageRandomSeed)
{
    Random random(aStageRandomSeed);
    mTurn = 0;

    bool isEmpty[Parameter::StageHeight][Parameter::StageWidth];
    for (int y = 0; y < Parameter::StageHeight; ++y) {
        for (int x = 0; x < Parameter::StageWidth; ++x) {
            isEmpty[y][x] = true;
        }
    }

    // カメの初期化
    int turtleCount = 0;
    while (turtleCount < aTurtleCount) {
        int x = random.randTerm(Parameter::StageWidth);
        int y = random.randTerm(Parameter::StageHeight);
        // 何も配置されていない座標にカメを配置する。
        if (isEmpty[y][x]) {
            Point pos(x, y);
            mTurtlePositions.add(pos);
            isEmpty[y][x] = false;
            ++turtleCount;
        }
    }

    // エサの初期化
    int foodCount = 0;
    while (foodCount < aFoodCount) {
        int x = random.randTerm(Parameter::StageWidth);
        int y = random.randTerm(Parameter::StageHeight);
        // 何も配置されていない座標にエサを配置する。
        if (isEmpty[y][x]) {
            Point pos(x, y);
            int height = random.randMinTerm(1, aTurtleCount + 1);
            // 一様な乱数から、aDistributionで指定された回数だけ、1に寄せる。
            // 低いものを増やして分業を促すため。
            for (int i = 0; i < aDistribution; ++i) {
                height = random.randMinTerm(1, height + 1);
            }
            Food food(pos, height);
            mFoods.add(food);
            isEmpty[y][x] = false;
            ++foodCount;
        }
    }
}

//------------------------------------------------------------------------------
void Stage::update(const Actions& aActions)
{
    HPC_ASSERT(aActions.count() == mTurtlePositions.count());

    // カメを移動させる。
    int turtleCount[Parameter::StageHeight][Parameter::StageWidth] = {};
    for (int i = 0; i < mTurtlePositions.count(); ++i) {
        Point nextPoint = mTurtlePositions[i];
        // 移動先の座標をステージの範囲内に収める。
        switch (aActions[i]) {
            case Action_Wait:
                break;
            case Action_MoveUp:
                nextPoint.y = Math::Max(nextPoint.y - 1, 0);
                break;
            case Action_MoveDown:
                nextPoint.y = Math::Min(nextPoint.y + 1, Parameter::StageHeight - 1);
                break;
            case Action_MoveLeft:
                nextPoint.x = Math::Max(nextPoint.x - 1, 0);
                break;
            case Action_MoveRight:
                nextPoint.x = Math::Min(nextPoint.x + 1, Parameter::StageWidth - 1);
                break;
            default:
                HPC_ASSERT_NOT_REACHED();
        }
        mTurtlePositions[i] = nextPoint;
        ++turtleCount[nextPoint.y][nextPoint.x];
    }

    // エサを食べる。
    for (int i = 0; i < mFoods.count(); ++i) {
        Point foodPos = mFoods[i].pos();
        if (!mFoods[i].isEaten() && mFoods[i].height() <= turtleCount[foodPos.y][foodPos.x]) {
            mFoods[i].setIsEaten(true);
        }
    }
}

//------------------------------------------------------------------------------
void Stage::advanceTurn()
{
    ++mTurn;
}

//------------------------------------------------------------------------------
bool Stage::isEnd() const
{
    for (Food food : mFoods) {
        if (!food.isEaten()) {
            return false;
        }
    }
    return true;
}

} // namespace
// EOF
