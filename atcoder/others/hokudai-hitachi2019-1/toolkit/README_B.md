# Hitachi Hokudai Labo & Hokkaido University Contest 2019-1 B サンプルプログラム

* これは、Hitachi Hokudai Labo & Hokkaido University Contest 2019-1 B で使われるサンプルプログラムの説明になります。本プログラムを使用することで、ローカル環境で解答プログラムの得点計算が行えます。
* 本プログラムの使用は自己責任でお願いいたします。これらのプログラムを使用することで発生したあらゆる損害に関して、北海道大学と日立製作所は補償いたしません。
* 得点計算を行うプログラムは、実際のコンテストで解答プログラムの得点計算を行うプログラムと同一ですが、実際のコンテストで使用するテストケースやシードは非公開となります。このため、これらのプログラムによって計算された得点は、当コンテストの得点を保証するものではありません。

## サンプルプログラムの概要

`scripts` フォルダ内には以下のコードが格納されています。

* `judge.cpp`
    * このプログラムは、judge の役割を担うプログラムです。
* `interactive.py`
    * このプログラムは、ローカル環境でインタラクティブに judge 側と contestant 側のプログラムを動作させるためのものです。
* `sample_code/sample.cpp`, `sample_code/sample.py`
    * このプログラムは、提出していただく問題の解答のサンプルとなるプログラムです。こちらのコードを参考にしながら解答を作成しても構いません。

## コンパイルについて

`judge.cpp` を以下のようにコンパイルし、`judge` という名前の実行ファイルを作成します。

```bash
g++ -std=gnu++11 -o judge judge.cpp
```
* C++11 オプションを指定しない場合、コンパイルができない可能性があります。

また、解答コードを作っていただき、実行ファイルを作成します。コンパイルが必要な言語である場合はコンパイルしてください。以下、`contestant` という実行ファイルを作成したものとして説明します。

## テストケースの生成・インタラクティブ処理

`interactive.py` を以下のように実行します。

```bash
./interactive.py --judge './judge <case-type> <seed>' --contestant ./contestant
```
- `<case-type>`: グラフのケースの種類を指定します。
    - `1`: 頂点数を 200 から 400 までの間でランダムに指定します。
    - `2`: 頂点数を 400 に固定します。
- `<seed>`: ランダム生成プログラムの実行に必要なシードを指定します。

以下は、乱数シード 2048 で、頂点数がランダムのケースの実行例です。

```bash
./interactive.py --judge './judge 1 2048' --contestant ./contestant
```

`interactive.py` を実行すると、以下の 2 つのファイルが生成されます。
- `contestant.out` : コンテスタントの標準出力の log ファイル
- `judge.out`: ジャッジ側の標準出力の log ファイル


これらのファイルを B 問題の Visualizer に入力として与えることで、答えを可視化することができます。(詳しくは visualizer の `README.md` を参照してください)

また、実行ファイル `judge`, `contestant` 間のインタラクティブな挙動と、このテストケースに対するスコアが標準出力で表示されます。

## 謝辞

本コードに含まれる `interactive.py` は `https://github.com/sharmaeklavya2/croupier` で公開されているコードを参考にしてコーディングされています。参考コードは [MIT Licence](https://opensource.org/licenses/MIT) をもとに公開されています。
