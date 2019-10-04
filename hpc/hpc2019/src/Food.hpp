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
#include "Point.hpp"

//------------------------------------------------------------------------------
namespace hpc {

/// エサ。
class Food
{
public:
    /// @name コンストラクタ
    //@{
    Food();
    Food(Point aPos, int aHeight);
    //@}

    /// @name 各種問い合わせ
    //@{
    /// エサの位置。
    const Point& pos() const;
    /// エサの高さ。
    int height() const;
    /// すでに食べられたか。
    bool isEaten() const;
    /// 食べられたかどうかを設定する。
    void setIsEaten(bool isEaten);
    //@}

private:
    /// @name プライベートメンバ変数
    //@{
    /// 位置。
    Point mPosition;
    /// 高さ。
    int mHeight;
    /// 食べられたかどうか。
    bool mIsEaten;
    //@}
};

} // namespace
// EOF
