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
#include "Stage.hpp"

//------------------------------------------------------------------------------
namespace hpc {

/// ゲーム進行を記録するクラス。
class Recorder
{
public:
    /// @name コンストラクタ
    //@{
    Recorder();
    //@}

    /// @name ダンプ
    //@{
    /// 最終結果を出力する。
    void dumpResult(bool aIsSilent) const;
    /// 記録内容をJSONとして出力する。
    void dumpJson() const;
    //@}

    /// @name 記録
    //@{
    /// ステージの初期化後に実行される関数。
    void afterInitializeStage(const Stage& aStage);
    /// ターンを進めた後に実行される関数。
    void afterAdvanceTurn(const Stage& aStage);
    /// ステージが終了した後に実行される関数。
    void afterFinishStage();
    /// 全ステージが終了した後に実行される関数。
    void afterFinishAllStages();
    //@}

    /// @name 問い合わせ
    //@{
    /// ゲーム全体での総ターン数。
    int totalTurn() const;
    //@}

private:
    /// @name 内部構造体
    //@{
    /// エサ情報。
    struct FoodRecord
    {
        /// 位置。
        Point pos;
        /// 高さ。
        int height;
        /// 食べられたターン。
        int eatenTurn;
    };
    /// カメ情報。
    struct TurtleRecord
    {
        /// 位置。
        Point pos;
        /// 同じ位置にいるカメの数。
        int count;
        /// 同じ位置にいるカメの番号。
        int indices[Parameter::MaxTurtleCount];
    };
    /// ターン情報。
    struct TurnRecord
    {
        /// カメ情報。
        TurtleRecord turtles[Parameter::MaxTurtleCount];
        /// カメ情報の数。
        int turtleRecordCount;
    };
    /// ステージ情報。
    struct StageRecord
    {
        /// ターン数。
        int turn;
        /// カメの数。
        int turtleCount;
        /// エサの数。
        int foodCount;
        /// エサ情報。
        FoodRecord foods[Parameter::MaxFoodCount];
        /// ターン情報。
        TurnRecord turnRecords[Parameter::GameTurnLimit + 1];
    };
    /// ゲーム情報。
    struct GameRecord
    {
        /// ゲーム全体での総ターン数。
        int totalTurn;
        /// ステージ情報。
        StageRecord stageRecords[Parameter::GameStageCount];
    };
    //@}

    /// @name 内部実装
    //@{
    /// ステージ情報を JSON として出力する。
    void dumpJsonStage(const StageRecord& aRecord) const;
    /// ターン情報を JSON として出力する。
    void dumpJsonTurn(const TurnRecord& aRecord) const;
    /// 現在のターン情報を記録する。
    void writeTurnRecord(int aStageNumber, int aTurn, const Stage& aStage);
    //@}

    /// @name プライベートメンバ変数
    //@{
    /// ゲーム情報。
    GameRecord mGameRecord;
    /// 現在記録中のステージ番号。
    int mCurrentStageNumber;
    /// 現在記録中のターン番号。
    int mCurrentTurn;
    //@}
};

} // namespace
// EOF
