//------------------------------------------------------------------------------
/// @file
/// @author   ハル研究所プログラミングコンテスト実行委員会
///
/// @copyright  Copyright (c) 2019 HAL Laboratory, Inc.
/// @attention  このファイルの利用は、同梱のREADMEにある
///             利用条件に従ってください。
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
#include "Action.hpp"
#include "Array.hpp"
#include "Food.hpp"
#include "Parameter.hpp"
#include "Point.hpp"
#include "Random.hpp"

//------------------------------------------------------------------------------
namespace hpc {

/// カメの行動の配列。
using Actions = Array<Action, Parameter::MaxTurtleCount>;
/// カメの位置の配列。
using TurtlePositions = Array<Point, Parameter::MaxTurtleCount>;
/// エサの配列。
using Foods = Array<Food, Parameter::MaxFoodCount>;

/// ステージ。
class Stage
{
public:
    /// @name コンストラクタ
    //@{
    Stage();
    //@}

    /// @name 問い合わせ
    //@{
    /// 現在のターン数。
    int turn() const;
    /// カメの位置の配列。
    const TurtlePositions& turtlePositions() const;
    /// エサの配列。
    const Foods& foods() const;
    //@}

    /// @name 内部関数用
    //@{
    /// 初期化する。
    void initialize(int aTurtleCount, int aFoodCount, int aDistribution, const RandomSeed& aStageRandomSeed);
    /// 更新する。
    void update(const Actions& aActions);
    /// ターンを進める。
    void advanceTurn();
    /// 終了したかどうか。
    bool isEnd() const;
    //@}

private:
    /// @name プライベートメンバ変数
    //@{
    /// 現在のターン数。
    int mTurn;
    /// カメの位置の配列。
    TurtlePositions mTurtlePositions;
    /// エサの配列。
    Foods mFoods;
    //@}
};

} // namespace
// EOF
