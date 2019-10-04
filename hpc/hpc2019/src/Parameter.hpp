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
namespace hpc {

class Parameter
{
public:
    /// ステージ数。
    static const int GameStageCount = 240;
    /// 各ステージのターン数。
    static const int GameTurnLimit = 1000;
    /// ステージの横幅。
    static const int StageWidth = 60;
    /// ステージの縦幅。
    static const int StageHeight = 30;
    /// カメの最大数。
    static const int MaxTurtleCount = 25;
    /// エサの最大数。
    static const int MaxFoodCount = 100;
};

} // namespace
// EOF
