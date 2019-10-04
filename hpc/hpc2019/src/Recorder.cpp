//------------------------------------------------------------------------------
/// @file
/// @author   ハル研究所プログラミングコンテスト実行委員会
///
/// @copyright  Copyright (c) 2019 HAL Laboratory, Inc.
/// @attention  このファイルの利用は、同梱のREADMEにある
///             利用条件に従ってください。
//------------------------------------------------------------------------------

#pragma once
#include "Recorder.hpp"

//------------------------------------------------------------------------------
#include "Print.hpp"

//------------------------------------------------------------------------------
namespace hpc {

//------------------------------------------------------------------------------
Recorder::Recorder()
: mGameRecord()
, mCurrentStageNumber()
, mCurrentTurn()
{
}

//------------------------------------------------------------------------------
void Recorder::dumpJson() const
{
    HPC_PRINTF("["); {
        for (int i = 0; i < Parameter::GameStageCount; ++i) {
            if (i != 0) {
                HPC_PRINTF(",");
            }
            dumpJsonStage(mGameRecord.stageRecords[i]);
        }
    } HPC_PRINTF("]");

    HPC_PRINTF("\n");
}

//------------------------------------------------------------------------------
void Recorder::dumpResult(bool aIsSilent) const
{
    if (!aIsSilent) {
        HPC_PRINTF("stage | turn\n");
        for (int i = 0; i < Parameter::GameStageCount; ++i) {
            HPC_PRINTF("% 5d | % 4d\n", i, mGameRecord.stageRecords[i].turn);
        }
    }
    HPC_PRINTF("TotalTurn: %d\n", mGameRecord.totalTurn);
}

//------------------------------------------------------------------------------
void Recorder::afterInitializeStage(const Stage& aStage)
{
    StageRecord& stageRecord = mGameRecord.stageRecords[mCurrentStageNumber];

    mCurrentTurn = 0;

    stageRecord.turtleCount = aStage.turtlePositions().count();
    stageRecord.foodCount = aStage.foods().count();
    for (int i = 0; i < aStage.foods().count(); ++i) {
        stageRecord.foods[i].pos = aStage.foods()[i].pos();
        stageRecord.foods[i].height = aStage.foods()[i].height();
        stageRecord.foods[i].eatenTurn = Parameter::GameTurnLimit;
    }

    writeTurnRecord(mCurrentStageNumber, 0, aStage);
}

//------------------------------------------------------------------------------
void Recorder::afterAdvanceTurn(const Stage& aStage)
{
    StageRecord& stageRecord = mGameRecord.stageRecords[mCurrentStageNumber];

    ++mCurrentTurn;

    for (int i = 0; i < aStage.foods().count(); ++i) {
        if (stageRecord.foods[i].eatenTurn == Parameter::GameTurnLimit && aStage.foods()[i].isEaten()) {
            stageRecord.foods[i].eatenTurn = mCurrentTurn;
        }
    }

    writeTurnRecord(mCurrentStageNumber, mCurrentTurn, aStage);
}

//------------------------------------------------------------------------------
void Recorder::afterFinishStage()
{
    StageRecord& stageRecord = mGameRecord.stageRecords[mCurrentStageNumber];
    stageRecord.turn = mCurrentTurn;
    mGameRecord.totalTurn += mCurrentTurn;
    ++mCurrentStageNumber;
}

//------------------------------------------------------------------------------
void Recorder::afterFinishAllStages()
{
}

//------------------------------------------------------------------------------
int Recorder::totalTurn() const
{
    return mGameRecord.totalTurn;
}

//------------------------------------------------------------------------------
void Recorder::dumpJsonStage(const StageRecord& aRecord) const
{
    HPC_PRINTF("["); {
        HPC_PRINTF("%d,", Parameter::GameTurnLimit);
        HPC_PRINTF("%d,", Parameter::StageWidth);
        HPC_PRINTF("%d,", Parameter::StageHeight);
        HPC_PRINTF("%d,", aRecord.turtleCount);
        HPC_PRINTF("%d,", aRecord.foodCount);
        HPC_PRINTF("%d,", aRecord.turn);

        // エサ情報
        HPC_PRINTF("["); {
            for (int i = 0; i < aRecord.foodCount; ++i) {
                if (i != 0) {
                    HPC_PRINTF(",");
                }
                HPC_PRINTF("["); {
                    HPC_PRINTF("%d,", aRecord.foods[i].pos.x);
                    HPC_PRINTF("%d,", aRecord.foods[i].pos.y);
                    HPC_PRINTF("%d,", aRecord.foods[i].height);
                    HPC_PRINTF("%d", aRecord.foods[i].eatenTurn);
                } HPC_PRINTF("]");
            }
        } HPC_PRINTF("],");

        // ターンのログ
        HPC_PRINTF("["); {
            for (int i = 0; i <= aRecord.turn; ++i) {
                if (i != 0) {
                    HPC_PRINTF(",");
                }
                dumpJsonTurn(aRecord.turnRecords[i]);
            }
        } HPC_PRINTF("]");
    } HPC_PRINTF("]");
}

//------------------------------------------------------------------------------
void Recorder::dumpJsonTurn(const TurnRecord& aRecord) const
{
    // カメ情報
    HPC_PRINTF("["); {
        for (int i = 0; i < aRecord.turtleRecordCount; ++i) {
            if (i != 0) {
                HPC_PRINTF(",");
            }
            HPC_PRINTF("["); {
                HPC_PRINTF("%d,", aRecord.turtles[i].pos.x);
                HPC_PRINTF("%d,", aRecord.turtles[i].pos.y);
                HPC_PRINTF("["); {
                    for (int j = 0; j < aRecord.turtles[i].count; ++j) {
                        if (j != 0) {
                            HPC_PRINTF(",");
                        }
                        HPC_PRINTF("%d", aRecord.turtles[i].indices[j]);
                    }
                } HPC_PRINTF("]");
            } HPC_PRINTF("]");
        }
    } HPC_PRINTF("]");
}

//------------------------------------------------------------------------------
void Recorder::writeTurnRecord(int aStageNumber, int aTurn, const Stage& aStage)
{
    TurnRecord& turnRecord = mGameRecord.stageRecords[aStageNumber].turnRecords[aTurn];

    Array<int, Parameter::MaxTurtleCount> turtleIndices[Parameter::StageHeight][Parameter::StageWidth];
    for (int i = 0; i < aStage.turtlePositions().count(); ++i) {
        Point pos = aStage.turtlePositions()[i];
        turtleIndices[pos.y][pos.x].add(i);
    }

    for (int y = 0; y < Parameter::StageHeight; ++y) {
        for (int x = 0; x < Parameter::StageWidth; ++x) {
            if (turtleIndices[y][x].count() > 0) {
                TurtleRecord& turtleRecord = turnRecord.turtles[turnRecord.turtleRecordCount];
                turtleRecord.pos = Point(x, y);
                turtleRecord.count = turtleIndices[y][x].count();
                for (int i = 0; i < turtleIndices[y][x].count(); ++i) {
                    turtleRecord.indices[i] = turtleIndices[y][x][i];
                }
                turnRecord.turtleRecordCount++;
            }
        }
    }
}

} // namespace
// EOF
