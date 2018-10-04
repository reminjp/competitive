﻿//------------------------------------------------------------------------------
/// @file
/// @author   ハル研究所プログラミングコンテスト実行委員会
///
/// @copyright  Copyright (c) 2018 HAL Laboratory, Inc.
/// @attention  このファイルの利用は、同梱のREADMEにある
///             利用条件に従ってください。
//------------------------------------------------------------------------------
#pragma once

//------------------------------------------------------------------------------
#include <ctime>

//------------------------------------------------------------------------------
namespace hpc {

/// 時間管理クラス。
class Timer
{
public:
    /// @name コンストラクタ
    //@{
    Timer();
    //@}

    /// @name 操作
    //@{
    /// タイマー始動。
    void start();
    /// タイマー停止。
    void stop();
    //@}

    /// @name 問い合わせ
    //@{
    /// 経過秒数を取得。
    double elapsedSec() const;
    //@}

private:
    /// @name プライベートメンバ変数
    //@{
    /// 開始時間。
    std::clock_t mTimeBegin;
    /// 停止時間。
    std::clock_t mTimeEnd;
    //@}
};

} // namespace
// EOF
