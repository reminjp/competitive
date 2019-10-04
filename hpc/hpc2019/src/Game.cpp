//------------------------------------------------------------------------------
/// @file
/// @author   ハル研究所プログラミングコンテスト実行委員会
///
/// @copyright  Copyright (c) 2019 HAL Laboratory, Inc.
/// @attention  このファイルの利用は、同梱のREADMEにある
///             利用条件に従ってください。
//------------------------------------------------------------------------------

#pragma once
#include "Game.hpp"

//------------------------------------------------------------------------------
#include "Assert.hpp"
#include "Stage.hpp"

//------------------------------------------------------------------------------
namespace hpc {

//------------------------------------------------------------------------------
Game::Game()
: mIsRandomSeedSet(false)
, mGivenRandomSeed(RandomSeed::DefaultSeed())
, mRecorder()
, mTimer()
{
}

//------------------------------------------------------------------------------
void Game::changeSeed(RandomSeed aSeed)
{
    mIsRandomSeedSet = true;
    mGivenRandomSeed = aSeed;
}

//------------------------------------------------------------------------------
void Game::run(Answer* aAnswer)
{
    HPC_ASSERT(aAnswer != nullptr);

    // 乱数関連の定数定義。
    // ここの randomSeed および randomSpin は
    // サーバーの評価環境と配布パッケージとで異なります。
    const uint randomSeedX = 0x81eacc80;
    const uint randomSeedY = 0xcb9412ed;
    const uint randomSeedZ = 0x1acb27dc;
    const uint randomSeedW = 0x21a234f3;
    const int randomSpinX = 0xFFF;
    const int randomSpinY = 0xFF;

    Random gameRandom =
        Random(
            mIsRandomSeedSet ?
            mGivenRandomSeed :
            RandomSeed(
                randomSeedX,
                randomSeedY,
                randomSeedZ,
                randomSeedW
                )
            );

    // ゲーム開始
    mTimer.start();
    gameRandom.spin(randomSpinX);

    for (int i = 0; i < Parameter::GameStageCount; ++i) {
        // ステージ開始
        gameRandom.spin(randomSpinY);
        auto randomSeed = gameRandom.generateRandomSeed();

        // ステージ生成
        Stage stage;
        int turtleCount = i / 3 % 20 + 6;
        int foodCount = i / 60 % 4 * 20 + 40;
        int distribution = 2 - i % 3;
        stage.initialize(turtleCount, foodCount, distribution, randomSeed);
        aAnswer->initialize(stage);
        mRecorder.afterInitializeStage(stage);

        while (!stage.isEnd() && stage.turn() < Parameter::GameTurnLimit) {
            // ターン開始
            Actions actions;
            aAnswer->setActions(stage, actions);
            stage.update(actions);
            stage.advanceTurn();
            mRecorder.afterAdvanceTurn(stage);
        }

        mRecorder.afterFinishStage();
        aAnswer->finalize(stage);
    }
    mRecorder.afterFinishAllStages();

    mTimer.stop();
}

//------------------------------------------------------------------------------
const Recorder& Game::recorder() const
{
    return mRecorder;
}

//------------------------------------------------------------------------------
const Timer& Game::timer() const
{
    return mTimer;
}

} // namespace
// EOF
