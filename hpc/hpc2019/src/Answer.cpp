//------------------------------------------------------------------------------
/// @file
/// @author   ハル研究所プログラミングコンテスト実行委員会
///
/// @copyright  Copyright (c) 2019 HAL Laboratory, Inc.
/// @attention  このファイルの利用は、同梱のREADMEにある
///             利用条件に従ってください。
//------------------------------------------------------------------------------

#include "Answer.hpp"

//------------------------------------------------------------------------------
namespace hpc {

//------------------------------------------------------------------------------
/// コンストラクタ。
/// @detail 最初のステージ開始前に実行したい処理があればここに書きます。
Answer::Answer()
{
}

//------------------------------------------------------------------------------
/// デストラクタ。
/// @detail 最後のステージ終了後に実行したい処理があればここに書きます。
Answer::~Answer()
{
}

//------------------------------------------------------------------------------
/// 各ステージ開始時に呼び出される処理。
/// @detail 各ステージに対する初期化処理が必要ならここに書きます。
/// @param aStage 現在のステージ。
void Answer::initialize(const Stage& aStage)
{
}

//------------------------------------------------------------------------------
/// 各ターンのカメの行動を指定する。
/// @detail 各カメの行動を指定し、aActionsの要素に追加してください。
///         aActions[i]がi番目のカメの行動になります。
///         aActionsの要素数がaStage.turtlePositions()の要素数と異なる場合、アサートに失敗します。
/// @param[in] aStage 現在のステージ。
/// @param[out] aActions 各カメの行動を指定する配列。
void Answer::setActions(const Stage& aStage, Actions& aActions)
{
    // 解答コードのサンプルです。

    // まだ食べられていないエサを1つ選んで目的地に設定する。
    Point targetFoodPosition;
    for (Food food : aStage.foods()) {
        if (!food.isEaten()) {
            targetFoodPosition = food.pos();
            break;
        }
    }

    // すべてのカメを目的地に向かって移動させる。
    for (Point turtlePosition : aStage.turtlePositions()) {
        if (turtlePosition.x < targetFoodPosition.x) {
            aActions.add(Action_MoveRight);
        } else if (turtlePosition.x > targetFoodPosition.x) {
            aActions.add(Action_MoveLeft);
        } else if (turtlePosition.y < targetFoodPosition.y) {
            aActions.add(Action_MoveDown);
        } else if (turtlePosition.y > targetFoodPosition.y) {
            aActions.add(Action_MoveUp);
        } else {
            // 移動する必要がなければ、その場で待機する。
            aActions.add(Action_Wait);
        }
    }
}

//------------------------------------------------------------------------------
/// 各ステージ終了時に呼び出される処理。
/// @detail 各ステージに対する終了処理が必要ならここに書きます。
/// @param aStage 現在のステージ。
void Answer::finalize(const Stage& aStage)
{
}

} // namespace
// EOF
